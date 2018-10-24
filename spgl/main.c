#include <stdio.h>
#include <stdlib.h>

#include "preprocessor.h"
#include "robot_parser.h"

int main() {
	int rows_num;
	int columns_num;
	char space;
	char **sheme = robotSheme("r.txt", &rows_num, &columns_num, &space);
	
	int nodes_num;
	int eyes_num;
	int edges_num;
	int **num_sheme = numSheme(rows_num, columns_num, space, sheme, &nodes_num, &eyes_num);
	Edge *edge_list = edgeList(rows_num, columns_num, num_sheme, nodes_num, &edges_num);
	int *adj_nums = adjNums(edges_num, edge_list);

	printf("%i %i\n", nodes_num, eyes_num);
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < columns_num; j++) {
			printf("%+i", num_sheme[i][j]);
		}
		printf("\n");
		free(sheme[i]);
	}
	
	free(sheme);
	free(num_sheme);

	printf("%i\n", edges_num);
	for (int i = 0; i < edges_num; i++)
		printf("%i %i\n", edge_list[i].node0, edge_list[i].node1);

	printf("\n");
	for (int i = 0; i < nodes_num; i++)
			printf("%i %i\n", i, adj_nums[i]);

	return 0;
}
