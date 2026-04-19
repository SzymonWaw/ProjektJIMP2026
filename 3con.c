#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "3con.h"
#include "file.h"

static int *disc, *low, *parent;
static int timer_val;
static int *is_ap;

static int is_connected_without(int **adj, int *degree, int n, int skip1, int skip2) {
    int *visited = calloc(n + 1, sizeof(int));
    int *stack   = malloc((n + 1) * sizeof(int));
    int top = 0, count = 0;

    int start = -1;
    for (int i = 1; i <= n; i++) {
        if (i != skip1 && i != skip2) {
            start = i;
            break;
        }
    }
    if (start == -1) { free(visited); free(stack); return 1; }

    stack[top++] = start;
    visited[start] = 1;

    while (top > 0) {
        int u = stack[--top];
        count++;
        for (int i = 0; i < degree[u]; i++) {
            int v = adj[u][i];
            if (v == skip1 || v == skip2) continue;
            if (!visited[v]) {
                visited[v] = 1;
                stack[top++] = v;
            }
        }
    }

    int expected = 0;
    for (int i = 1; i <= n; i++)
        if (i != skip1 && i != skip2) expected++;

    free(visited);
    free(stack);
    return count == expected;
}

int **build_adjacency(Edge *edges, int edge_count, int *point_count, int **out_degree) {
    int max_id = 0;
    for (int i = 0; i < edge_count; i++) {
        if (edges[i].A->id > max_id) max_id = edges[i].A->id;
        if (edges[i].B->id > max_id) max_id = edges[i].B->id;
    }
    *point_count = max_id;

    int **adj    = calloc(max_id + 1, sizeof(int *));
    int  *degree = calloc(max_id + 1, sizeof(int));

    for (int i = 0; i < edge_count; i++) {
        degree[edges[i].A->id]++;
        degree[edges[i].B->id]++;
    }

    for (int i = 1; i <= max_id; i++)
        adj[i] = malloc(degree[i] * sizeof(int));

    int *idx = calloc(max_id + 1, sizeof(int));
    for (int i = 0; i < edge_count; i++) {
        int a = edges[i].A->id;
        int b = edges[i].B->id;
        adj[a][idx[a]++] = b;
        adj[b][idx[b]++] = a;
    }
    free(idx);

    *out_degree = degree;
    return adj;
}

void free_adjacency(int **adj, int *degree, int n)
{
    for (int i = 1; i <= n; i++)
	{
        free(adj[i]);
	}
    free(adj);
    free(degree);
}

int connectivity(Edge *edges, int edge_count) {
    int  n;
    int *degree;
    int **adj = build_adjacency(edges, edge_count, &n, &degree);

    if (n < 4) {
        printf("Graf ma za mało wierzchołków, by być 3-spójny.\n");
        free_adjacency(adj, degree, n);
        return 0;
    }

    disc = calloc(n + 1, sizeof(int));
    low = calloc(n + 1, sizeof(int));
    parent = malloc((n + 1) * sizeof(int));
    is_ap = calloc(n + 1, sizeof(int));
    timer_val = 0;

    for (int i = 1; i <= n; i++) parent[i] = -1;

    int connected = 1;
    for (int i = 1; i <= n; i++)
        if (disc[i] == 0) { connected = 0; break; }

    if (!connected) {
        free(disc); free(low); free(parent); free(is_ap);
        free_adjacency(adj, degree, n);
        return 1;
    }

    int has_ap = 0;
    for (int i = 1; i <= n; i++)
        if (is_ap[i]) { has_ap = 1; break; }

    free(disc); free(low); free(parent); free(is_ap);

    if (has_ap) {
        free_adjacency(adj, degree, n);
        return 1;
    }

    for (int u = 1; u <= n; u++) {
        for (int v = u + 1; v <= n; v++) {
            if (!is_connected_without(adj, degree, n, u, v)) {
                free_adjacency(adj, degree, n);
                return 1;
            }
        }
    }

	free_adjacency(adj, degree, n);
	return 0;
}
