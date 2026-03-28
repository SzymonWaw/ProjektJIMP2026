#ifndef FILE_H
#define FILE_H

typedef struct{
	double x;
	double y;
} Coordinates;

typedef struct{
	int id;
	Coordinates cords;
} Point;

typedef struct{
	char *name;
	double weight;
	Point *A;
	Point *B;
} Edge;

Edge* parse(FILE *file, int *out_count);

void f_out(Point *point, FILE *file, int point_count);

void free_edges(Edge *edges, int edge_count);

#endif