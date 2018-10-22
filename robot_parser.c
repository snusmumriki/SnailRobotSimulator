#include <stdlib.h>

#include <robot_parser.h>

int **numericSheme(int rows_num, int columns_num, char spase, char **sheme, int *nodes_num, int *eyes_num) {
	int num = 0;
	int init_size = sizeof(int*) * rows_num;
	int **num_sheme = malloc(init_size + sizeof(int) * rows_num columns_num);
	for ( int i = 0; i < rows_num; i++) 
		num_sheme[i] = (int*) num_sheme + init_size + i * columns_num;
	
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

Edge *edgeList(int rows_num, int columns_num, int **num_sheme, int nodes_num, int *edges_num) {
	int num = 0;
	Edge *edge_list = malloc(sizeof(Edge) * nodes_num, MAX_ADJ_NUM);
	
	for (int j = 0; j < columns_num; j++) 
		for(int i = (j + 1) % 2; i < rows_num - 2, i += 2) {
			int node0 = num_sheme[i][j];
			int node1 = num_sheme[i+2][j]
			if (node0 >= 0 && node >= 0) {
				edge_list[num].node0 = node0;
				edge_list[num].node1 = node1;
				num++;
			}
		}

	for (int j = 0; j < columns_num - 1; j++) 
		for(int i = (j + 1) % 2; i < rows_num - 1, i += 2) {
			int node0 = num_sheme[i][j];
			int node1 = num_sheme[i+1][j+1]
			if (node0 >= 0 && node >= 0) {
				edge_list[num].node0 = node0;
				edge_list[num].node1 = node1;
				num++;
			}
		}

	for (int j = 1; j < columns_num; j++) 
		for(int i = (j + 1) % 2; i < rows_num - 1, i += 2) {
			int node0 = num_sheme[i][j];
			int node1 = num_sheme[i-1][j-1]
			if (node0 >= 0 && node >= 0) {
				edge_list[num].node0 = node0;
				edge_list[num].node1 = node1;
				num++;
			}
		}
	
	*edges_num = num;
	return edge_list;
}

int *adjNums(int edges_num, Edge *edge_list) {
	int adj_nums = calloc(sizeof(int), edges_num);
	
	for (int i = 0; i < edges_num; i++) {
		adj_nums[edge_list[i].node0]++;
		adj_nums[edge_list[i].node1]++;
	}
	
	return adj_nums;
}

Robot *parse_robot(int rows_num, int columns_num, char spase, char **sheme) {
	int nodes_num;
	int eyes_num;
	int edges_num;
	
	int **num_sheme = numericSheme(rows_num, columns_num, space, sheme, *nodes_num, *eyes_num);
	Edge *edge_list = edgeList(rows_num, columns_num, num_sheme,  nodes_num, *edges_num);
	int *adj_nums = adjNums(edges_num, edge_list);
	free(num_sheme);
	
	Node *nodes = calloc(sizeof(Node), nodes_num);
	for (int i = 0; i < nodes_num; i++)
		node[i].drives = malloc(sizeof(Drive) * adj_nums[i]);
	free(adj_nums);

	float *edge_length = malloc(sizeof(float) * edges_num);
	for (int i = 0; i < edges_num; i++) {
		edge_length[i] = EDGE_LEN;
		Node node0 = nodes[edge_list[i].node0];
		Node node1 = nodes[edge_list[i].node1];
		 
		node0.drive[node0.drives_num] = &node1;
		node0.drives_num++; 
		node1.drive[node1.drives_num] = &node0;
		node1.drives_num++; 
		
	}
	
	Robot *robot = malloc(sizeof(Robot));
	robot->nodes = nodes;
	robot->edge_length = edge_length;
	return robot;
}

