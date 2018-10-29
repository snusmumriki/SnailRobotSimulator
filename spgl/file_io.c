#include <stdio.h>
#include <stdlib.h>

#include "file_io.h"

char **robot_input(char *file_in, int *frame_h, int *frame_w) {	
	fp = fopen(file_in, "r");
	fscanf(fp, "%i%i", &rows_num, &columns_num);

	frame = malloc(sizeof(char*) * rows_num);
	for (int i = 0; i < rows_num; i++) {
		frame[i] = calloc(sizeof(char), columns_num + 1);
		fscanf(fp, "%s", frame[i]);
	}

	fclose(fp);
	return frame;
}

int robot_output(char *file_out, 
								int nodes_num, int edges_num, int eyes_num, int tails_num,
								int (*adj_list)[2], int *offset, int *eye_list, int *tail_list) {

	return 0;
}

char **target_input(char *file_in) {
	
	return NULL;
}

int target_output(char *file_out) {

	return 0;
}

char **garbage_input(char *file_in, int *frame_h, int *frame_w) {

	return frame;
}

int garbage_output(char *file_out, int circles_num, int (*pos_list)[2], int *rad_list) {

	return 0;
}
