#include <stdio.h>
#include <stdlib.h>
#include "file.h"

int main(int argc, char **argv)
{
	FILE *file = fopen(argv[1], "r");
	FILE *output = fopen(argv[2], "w");

	if(argc != 3) {
		printf("Nie podano odpowiedniej liczby argumentow");
		return 1;
	}

	if(file == NULL || output == NULL) {
		printf("Nie znaleziono pliku wejsciowego lub wyjsciowego");
		return 1;
	}
	
	int edge_count;
	Edge *edge = parse(file, &edge_count);

	int unique_count;
	Point *unique_points = extract_unique_points(edge, edge_count, &unique_count);

	f_out(unique_points, output, unique_count, 0);

	free_edges(edge, edge_count);
	free(unique_points);

	fclose(file);
	fclose(output);

	return 0;
}