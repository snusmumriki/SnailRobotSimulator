#include <stdlib.h>

#include "r_parser.h"

int **numSheme(int rows_num, int columns_num, char **sheme, int *nodes_num, int *eyes_num) {
	int n_num = 0;
	int e_num = 0;

	int **num_sheme = malloc(sizeof(int*) * rows_num);
	for (int i = 0; i < rows_num; i++) 
		num_sheme[i] = malloc(sizeof(int) * columns_num);
	
	for (int i = 0; i < rows_num; i++) 
		for (int j = 0; j < columns_num; j++) {
			if (sheme[i][j] != SPACE_CHAR)
				num_sheme[i][j] = n_num++;
			else num_sheme[i][j] = -1;

			if (sheme[i][j] == EYE_CHAR)
				e_num++;
		}

	*nodes_num = n_num;
	*eyes_num = e_num;	
	return num_sheme;
}

int *eyeList(int rows_num, int columns_num, char **sheme, int **num_sheme, int eyes_num) {
	int k = 0;
	int *eye_list = malloc(sizeof(int) * eyes_num);

	for (int i = 0; i < rows_num; i++)
		for (int j = 0; j < columns_num; j++)
			if (sheme[i][j] == EYE_CHAR)
				eye_list[k++] = num_sheme[i][j];

	return eye_list;
}

edge *edgeList(int rows_num, int columns_num, int **num_sheme, int nodes_num, int *edges_num) {
	int num = 0;
	edge *edge_list = malloc(sizeof(edge) * nodes_num * MAX_ADJ_NUM / 2);
	
	for (int j = 0; j < columns_num; j++) 
		for(int i = (j + 1) % 2; i < rows_num - 2; i += 2) {
			int node0 = num_sheme[i][j];
			int node1 = num_sheme[i+2][j];
			if (node0 >= 0 && node1 >= 0) {
				edge_list[num][0] = node0;
				edge_list[num][1] = node1;
				num++;
			}
		}

	for (int j = 0; j < columns_num - 1; j++) 
		for(int i = (j + 1) % 2; i < rows_num - 1; i += 2) {
			int node0 = num_sheme[i][j];
			int node1 = num_sheme[i+1][j+1];
			if (node0 >= 0 && node1 >= 0) {
				edge_list[num][0] = node0;
				edge_list[num][1] = node1;
				num++;
			}
		}

	for (int j = 1; j < columns_num; j++) 
		for(int i = (j + 1) % 2; i < rows_num - 1; i += 2) {
			int node0 = num_sheme[i][j];
			int node1 = num_sheme[i+1][j-1];
			if (node0 >= 0 && node1 >= 0) {
				edge_list[num][0] = node0;
				edge_list[num][1] = node1;
				num++;
			}
		}

	*edges_num = num;
	return edge_list;
}

int *nodeOffsets(int rows_num, int columns_num, int **num_sheme, int nodes_num) {
	int *offset = malloc(sizeof(int) * nodes_num);
	int m = columns_num / 2;

	for (int i = 0; i < rows_num; i++)
		for (int j = 0; j < columns_num; i++) {
			int node = num_sheme[i][j];
			if (node >= 0)
				offset[node] = j - m;
		}

	return offset;
}

adj *adjList(int nodes_num, int *offset, int edges_num, edge *edge_list) {
	adj *adj_list = malloc(sizeof(adj) * nodes_num);
		
	for (int i = 0; i < edges_num; i++) {
		int node0 = edge_list[i][0];
		int node1 = edge_list[i][1];
		int diff = offset[node0] - offset[node1];

		adj_list[node0][BASE_1 + diff] = node1;
		adj_list[node1][BASE_0 + diff] = node0;
	}
						
	return adj_nums;
}
