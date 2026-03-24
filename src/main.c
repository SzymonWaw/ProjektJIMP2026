#include <stdio.h>
#include <stdlib.h>
#include "file.h"

int main(int argc, char **argv)
{
	FILE *file = fopen(argv[1], "r");
	if (!file)
	{
		perror("Usage: program <filename>");
		return EXIT_FAILURE;
	}
	Edge edge = parse(file);
	fclose(file);
}