#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#define MAX_EDGES 100

Edge parse(FILE *file)
{
	fopen(file, "r");
	Edge *edge = malloc(sizeof(Edge) * MAX_EDGES);
	for(int i = 0; i < MAX_EDGES && !feof(file); i++)
	{
		Point *A = malloc(sizeof(Point));
		Point *B = malloc(sizeof(Point));
		fscanf(file, "%s %lf %lf", edge[i].name, &edge[i].A->id, &edge[i].B->id,&edge[i].weight);
		free(A);
		free(B);
	}
	free(edge);
	return *edge;
}

void f_out(Point *point, FILE *file)
{
	fopen(file, "w");
	for(int i = 0; i < MAX_EDGES; i++)
	{
		fprintf(file, "%d, %lf, %lf", point[i].id, point[i].cords.x, point[i].cords.y);
	}
}