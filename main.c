#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "3con.h"

int main(int argc, char **argv)
{
	if(argc != 4) {
		printf("Nie podano odpowiedniej liczby argumentow");
		return 1;
	}
	
	int binary = atoi(argv[1]);
	FILE *file = fopen(argv[2], "r");
	FILE *output = fopen(argv[3], "w");

	if(binary != 0 && binary != 1){
		printf("Trzeci argument musi byc 0 lub 1");
		return 1;
	}

	if(file == NULL || output == NULL){
		printf("Nie znaleziono pliku wejsciowego lub wyjsciowego");
		return 1;
	}
	
	int edge_count;
	Edge *edge = parse(file, &edge_count);
	check_3connectivity(edge, edge_count);
	tutte(edge, edge_count, NULL);
	f_out(edge[0].A, output, edge_count * 2, binary);
	fclose(file);
	fclose(output);
	free_edges(edge, edge_count);
	return 0;
}