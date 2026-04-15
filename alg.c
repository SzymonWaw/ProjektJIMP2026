#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "file.h"
#define ITERATIONS 100

void tutte(Edge *edge, int e_count, bool *fixed)
{
	for(int i = 0; i < ITERATIONS; i++)
	{
		for(int j = 0; j < e_count; j++)
		{
			if(fixed[j])
			{
				continue;
			}

			double sum_x = 0.0;
			double sum_y = 0.0;
			int degree = 0;

			for(int k = 0; k < e_count; k++)
			{
				if(adj[j][k])
				{
					sum_x += x[k];
					sum_y += y[k];
					degree++;
				}
			}

			if(degree > 0)
			{
				x[j] = sum_x / degree;
				y[j] = sum_y / degree;
			}
		}
	}
}