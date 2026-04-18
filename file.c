#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#define MAX_EDGES 100

Edge *parse(FILE *file, int *out_count)
{
	Edge *edge = malloc(sizeof(Edge) * MAX_EDGES);
	int count = 0;

	for(int i = 0; i < MAX_EDGES && !feof(file); i++)
	{
		edge[i].name = malloc(sizeof(char) * 2);
		edge[i].A = malloc(sizeof(Point));
		edge[i].B = malloc(sizeof(Point));
		fscanf(file, "%s %d %d %lf", edge[i].name, &edge[i].A->id, &edge[i].B->id, &edge[i].weight);
		count++;
	}
	*out_count = count;
	return edge;
}

void f_out(Point *points, FILE *file, int point_count, int binary)
{
	if(points == NULL || file == NULL)
	{
		return;
	}

	if(binary)
	{
		for(int i = 0; i < point_count; i++)
		{
			fwrite(&points[i].id, sizeof(int), 1, file);
			fwrite(&points[i].cords.x, sizeof(double), 1, file);
			fwrite(&points[i].cords.y, sizeof(double), 1, file);
		}
	}
	else
	{
		for(int i = 0; i < point_count; i++)
		{
			fprintf(file, "%d %.1f %.1f\n", points[i].id, points[i].cords.x, points[i].cords.y);
		}
	}
}


void free_edges(Edge *edges, int edge_count)
{
	if(edges == NULL)
	{
		return;
	}

	for(int i = 0; i < edge_count; i++)
	{
		free(edges[i].name);
		free(edges[i].A);
		free(edges[i].B);
	}
	free(edges);
}