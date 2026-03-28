#include <stdio.h>
#include <stdlib.h>
#include "file.h"

int main(int argc, char **argv)
{
	FILE *file = fopen(argv[1], "r");
	FILE *output = fopen(argv[2], "w");

	if(file == NULL || output == NULL)
	{
		printf("Nie podano pliku wejsciowego lub wyjsciowego");
		return 1;
	}
	
	int edge_count;
	Edge *edge = parse(file, &edge_count);



	
	fclose(file);
	fclose(output);
	free_edges(edge, edge_count);
	return 0;
}