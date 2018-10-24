#include <stdio.h>
#include <stdlib.h>

#include "preprocessor.h"

char **robotSheme(char *filename, int *rows_num, int *columns_num, char *space) {
	FILE *fp = fopen(filename, "r");
	
	fscanf(fp, "%i %i", rows_num, columns_num);
	char **sheme = malloc(sizeof(char*) * *rows_num);
	for (int i = 0; i < *rows_num; i++) {
		sheme[i] = calloc(sizeof(char), *rows_num + 1);
		fscanf(fp, "%s", sheme[i]);
	}
	*space = sheme[0][0];

	fclose(fp);

	return sheme;
}
