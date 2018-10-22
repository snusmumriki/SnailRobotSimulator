#include <stdlib.h>

#include "robot_parser.h"
#include "robot.h"

int **numSheme(int rows_num, int columns_num, char space, char **sheme, int *nodes_num, int *eyes_num) {
	int num = 0;
	int **num_sheme = malloc(sizeof(int*) * rows_num);
	for ( int i = 0; i < rows_num; i++) 
		num_sheme[i] = malloc(sizeof(int) * columns_num);
	
	for ( int i = 0; i < rows_num; i++) 
		for ( int j = 0; j < columns_num; j++) {
			if (sheme[i][j] != space) {
				num_sheme[i][j] = num;
				num++;
			} else num_sheme[i][j] = -1;

			if (i == 0) *eyes_num = num;
		}		
	
	*nodes_num = num;
	return num_sheme;
}

Edge *edgeList(int rows_num, int columns_num, int **num_sheme, int nodes_num, int *drives_num) {
	int num = 0;
	Edge *edge_list = malloc(sizeof(Edge) * nodes_num * MAX_COUP_NUM);
	
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

	*drives_num = num;
	return edge_list;
}

int *adjNums(int drives_num, Edge *edge_list) {
	int *adj_nums = calloc(sizeof(int), drives_num);
	
	for (int i = 0; i < drives_num; i++) {
		adj_nums[edge_list[i].node0]++;
		adj_nums[edge_list[i].node1]++;
	}
	
	return adj_nums;
}

Robot *parse_robot(int rows_num, int columns_num, char space, char **sheme) {
	int nodes_num;
	int eyes_num;
	int drives_num;
	
	int **num_sheme = numSheme(rows_num, columns_num, space, sheme, &nodes_num, &eyes_num);
	Edge *edge_list = edgeList(rows_num, columns_num, num_sheme, nodes_num, &drives_num);
	int *adj_nums = adjNums(drives_num, edge_list);
	
	Node *node_list = calloc(sizeof(Node), nodes_num);
	for (int i = 0; i < nodes_num; i++)
		node_list[i].drive = malloc(sizeof(Drive) * adj_nums[i]);
	
	for (int i = 0; i < rows_num; i++)
		free(num_sheme[i]);
	free(num_sheme);
	free(adj_nums);

	float *drive_state_list = malloc(sizeof(float) * drives_num);
	for (int i = 0; i < drives_num; i++) {
		drive_state_list[i] = DRIVE_INIT_STATE;
		Node *node0 = node_list + edge_list[i].node0;
		Node *node1 = node_list + edge_list[i].node1;
		
		node0->drive[node0->drives_num].node = node1;
		node0->drives_num++; 
		node1->drive[node1->drives_num].node = node0;
		node1->drives_num++; 
	}
	
	Robot *robot = malloc(sizeof(Robot));
	robot->nodes_num = nodes_num;
	robot->node_list = node_list;
	robot->drives_num = drives_num;
	robot->drive_state_list = drive_state_list;
	
	return robot;
}

