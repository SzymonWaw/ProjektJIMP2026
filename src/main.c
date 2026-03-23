#include <stdio.h>
#include <stdlib.h>

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