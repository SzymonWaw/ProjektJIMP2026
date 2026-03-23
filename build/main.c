#include <stdio.h>
#include <stdlib.h>


typedef struct{
	int id;
	double x;
	double y;
} Point;

typedef struct{
	double weight;
	Point A;
	Point B;
} Edge;

int main(int argc, char **argv)
{
	FILE *file = fopen(argv[1], "r");
	if (!file)
	{
		perror("Usage: program <filename>");
		return EXIT_FAILURE;
	}

	while(!feof(file))
	{
		
	}
}