#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "3con.h"
#include "valid.h"

int planar(Edge *edges, int edge_count)
{
    int n;
    int *degree;
    int **adj = build_adjacency(edges, edge_count, &n, &degree);
    dfs_ap(1, adj, degree, n);
    int m = edge_count;

    if(n >= 3 && m > 3*n - 6)
    {
        free_adjacency(adj, degree, n);
        return 1;
    }

    int *visited = calloc(n + 1, sizeof(int));
    int *stack = malloc((n + 1) * sizeof(int));
    int top = 0;

    stack[top++] = 1;
    visited[1] = 1;

    while(top > 0)
    {
        int u = stack[--top];
        for(int i = 0; i < degree[u]; i++)
        {
            int v = adj[u][i];
            if(!visited[v])
            {
                visited[v] = 1;
                stack[top++] = v;
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            free(visited);
            free(stack);
            free_adjacency(adj, degree, n);
            return 1;
        }
	}

    free(visited);
    free(stack);
    free_adjacency(adj, degree, n);
    return 0;
}

static void dfs_ap(int u, int **adj, int *degree, int n)
{
    static int *disc, *low, *parent;
    static int timer_val;
    static int *is_ap;
    int children = 0;
    disc[u] = low[u] = ++timer_val;

    for (int i = 0; i < degree[u]; i++) {
        int v = adj[u][i];
        if (disc[v] == 0) {
            children++;
            parent[v] = u;
            dfs_ap(v, adj, degree, n);
            if (low[v] < low[u])
                low[u] = low[v];

            if (parent[u] == -1 && children > 1)
                is_ap[u] = 1;
            if (parent[u] != -1 && low[v] >= disc[u])
                is_ap[u] = 1;
        }
        else if (v != parent[u]) {
            if (disc[v] < low[u])
                low[u] = disc[v];
        }
    }
}