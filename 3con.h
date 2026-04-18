#ifndef CON3_H
#define CON3_H

#include "file.h"

int **build_adjacency(Edge *edges, int edge_count, int *point_count, int **degree);

int check_3connectivity(Edge *edges, int edge_count);

void free_adjacency(int **adj, int *degree, int n);

int is_planar(Edge *edges, int edge_count);

#endif
