#ifndef VALID_H
#define VALID_H
#include "file.h"

int planar(Edge *edges, int edge_count);

static void dfs_ap(int u, int **adj, int *degree, int n);

#endif