#include <stdio.h>
#include <stdlib.h>
#include "file.h"

int main(int argc, char **argv)
{
	FILE *file = argv[1];
	FILE *output = argv[2];
	if(file == NULL || output == NULL)
	{
		printf("Nie podano pliku wejsciowego lub wyjsciowego");
		return 1;
	}
	
	Edge edge = parse(file);
	fclose(file);
	fclose(output);
}