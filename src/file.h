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

Edge* parse(FILE *file);

void f_out(Point *points, FILE *file, int point_count, int is_binary);

void free_edges(Edge *edges, int edge_count);


#endif