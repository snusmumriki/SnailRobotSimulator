#include <stdio.h>
#include <stdlib.h>

#include "robot_parser.h"

int **numSheme(int rows_num, int columns_num, char **sheme, int *nodes_num) {
	int num = 0;
	int **num_sheme = malloc(sizeof(int*) * rows_num);
	for ( int i = 0; i < rows_num; i++) 
		num_sheme[i] = malloc(sizeof(int) * columns_num);
	
	for ( int i = 0; i < rows_num; i++) 
		for ( int j = 0; j < columns_num; j++) {
			if (sheme[i][j] != SPACE_CHAR) {
				num_sheme[i][j] = num;
				num++;
			} else num_sheme[i][j] = -1;
		}		
	
	*nodes_num = num;
	return num_sheme;
}

Edge *edgeList(int rows_num, int columns_num, int **num_sheme, int nodes_num, int *edges_num) {
	int num = 0;
	Edge *edge_list = malloc(sizeof(Edge) * nodes_num * (MAX_ADJ_NUM / 2 + 1));
	
	for (int j = 0; j < columns_num; j++) 
		for(int i = (j + 1) % 2; i < rows_num - 2; i += 2) {
			int node0 = num_sheme[i][j];
			int node1 = num_sheme[i+2][j];
			if (node0 >= 0 && node1 >= 0) {
				edge_list[num].node0 = node0;
				edge_list[num].node1 = node1;
				num++;
			}
		}

	for (int j = 0; j < columns_num - 1; j++) 
		for(int i = (j + 1) % 2; i < rows_num - 1; i += 2) {
			int node0 = num_sheme[i][j];
			int node1 = num_sheme[i+1][j+1];
			if (node0 >= 0 && node1 >= 0) {
				edge_list[num].node0 = node0;
				edge_list[num].node1 = node1;
				num++;
			}
		}

	for (int j = 1; j < columns_num; j++) 
		for(int i = (j + 1) % 2; i < rows_num - 1; i += 2) {
			int node0 = num_sheme[i][j];
			int node1 = num_sheme[i+1][j-1];
			if (node0 >= 0 && node1 >= 0) {
				edge_list[num].node0 = node0;
				edge_list[num].node1 = node1;
				num++;
			}
		}

	*edges_num = num;
	return edge_list;
}

int *adjNums(int edges_num, Edge *edge_list, int nodes_num) {
	int *adj_nums = calloc(sizeof(int), nodes_num);
	
	for (int i = 0; i < edges_num; i++) {
		adj_nums[edge_list[i].node0]++;
		adj_nums[edge_list[i].node1]++;
	}
	
	return adj_nums;
}

int parse_robot(char *file_in, char *file_out) {
	int rows_num;
	int columns_num;
	char **sheme;
	FILE *fp;

	fp = fopen(file_in, "r");
	fscanf(fp, "%i%i", &rows_num, &columns_num);
	printf("%i %i", rows_num, columns_num);
	sheme = malloc(sizeof(char*) * rows_num);
	for (int i = 0; i < rows_num; i++) {
		sheme[i] = calloc(sizeof(char), columns_num + 1);
		fscanf(fp, "%s", sheme[i]);
	}
	fclose(fp);
	
	int nodes_num;
	int edges_num;
	
	int **num_sheme = numSheme(rows_num, columns_num, sheme, &nodes_num);
	Edge *edge_list = edgeList(rows_num, columns_num, num_sheme, nodes_num, &edges_num);
	int *adj_nums = adjNums(edges_num, edge_list, nodes_num);
	
	fp = fopen(file_out, "w+");
	fprintf(fp, "%i\n", edges_num);
	for (int i = 0; i < edges_num; i++)
		fprintf(fp, "%i %i\n", edge_list[i].node0, edge_list[i].node1);
	
	fprintf(fp, "\n");
	fprintf(fp, "%i\n", nodes_num);
	for (int i = 0; i < nodes_num; i++)
		fprintf(fp, "%i %i\n", i, adj_nums[i]);
	fclose(fp);

	for (int i = 0; i < rows_num; i++) {
		free(sheme[i]);
		free(num_sheme[i]);
	}
	free(sheme);
	free(num_sheme);
	free(edge_list);
	free(adj_nums);

	return 0;
}

