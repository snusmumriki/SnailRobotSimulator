#include <stdlib.h>

#include <robot_parser.h>
#include <node.h>

int numericSheme( int rows_num,  int row_size, char **sheme,  int *nodes_num,  int *eyes_num) {
	int num = 0;
	int init_size = sizeof(int*) * rows_num;
	int **num_sheme = malloc(init_size + sizeof(int) * row_size * rows_num);
	for ( int i = 0; i < rows_num; i++) 
		num_sheme[i] = (*int) num_sheme + init_size + i * row_size;
	
	for ( int i = 0; i < rows_num; i++) 
		for ( int j = 0; j < row_size; j++) {
			if (sheme[i][j] == NODE_CHAR) {
				num_sheme[i][j] = num;
				num++;
			} else num_sheme[i][j] = -1;

			if (j == 0) *eyes_num = num;
		}		
	
	*nodes_num = num;
	return num_sheme;
}


Adjacency *adjacencyList(int rows_num, int row_size, int **num_sheme, int nodes_num) {
	int node = 0;
	int *adj_list[MAX_ADJ] = malloc(sizeof(int) * MAX_ADJ * nodes_num);
	int *adj_nums = calloc(sizeof(int), nodes_num);

	for (int i = 0; i < rows_num; i++) 
		for (int j = 0; j < row_size; j++) 
			if (num_sheme[i][j] >= 0) {
				for (int k = 0; k < MAX_ADJ; k++) {
					adj_list[node][k] = -1;
					int i1 = i + steps[k].i;
					int j1 = j + steps[k].j;
					if (i1 >= 0 && i1 < rows_num && j1 >= 0 && j1 < row_size && num_sheme[i1][j1] >= 0) {
						adj_list[node][adj_nums[node]] = num_sheme[i1][j1];
						adj_nums[node]++;
					}
				}
				node++;
			}
	Adjacency *adj = malloc(sizeof(Adj));
	adj->list = adj_list;
	adj->nums = adj_nums;	
	return adj;
}

Edge *edgeList(int *adj_list, int nodes_num, int *edges_num) {
	int num = 0;
	for (int i = 0; i < nodes_num; i++)
		for(int j = 0; j < MAX_ADJ; j++)
			if (adj_list[i][j] >= 0 && adj_list[i][j] < i)
				adj_list[i][j] = -1;
			else num++;

	Edge *edge_list = malloc(sizeof(Edge) * num);
	int k = 0;	
	for (int i = 0; i < nodes_num; i++)
		for(int j = 0; j < MAX_ADJ; j++)
			if (adj_list[i][j] >= 0) {
				edge_list[k].node0 = i;
				edge_list[k].node1 = adj_list[i][j];
				k++;
			}
	
	*edges_num = num;
	return edge_list;
}


Robot *parse_robot(int rows_num,  int row_size, char **sheme) {
	int nodes_num;
	int eyes_num;
	int edges_num;
	
	int **num_sheme = numericSheme(rows_num, row_size, sheme, *nodes_num, *eyes_num);
	Adjacency *adj = adjacencytList(rows_num, row_size, num_sheme, nodes_num);
	free(num_sheme);
	
	Edge *edge_list = edgeList(adj->list, nodes_num, edges_num);
	int *adj_nums = adj->nums;
	free(adj->list);
	free(adj)
	
	Node *nodes = calloc(sizeof(Node), nodes_num);
	for (int i = 0; i < nodes_num; i++)
		node[i].edges = malloc(sizeof(Node*) * adj_nums[i]);
	free(adj_nums);

	float *edge_length = malloc(sizeof(float) * edges_num);
	for ( int i = 0; i < edges_num; i++) {
		edge_length[i] = EDGE_LEN;
		int node0 = edge_list[i].node0;
		int node1 = edge_list[i].node1;
		 
		nodes[node0].edges[nodes[node0].edges_num] = nodes + node1;
		nodes[node0].edges_num++; 
		nodes[node1].edges[nodes[node1].edges_num] = nodes + node0;
		nodes[node1].edges_num++; 
		
	}
	
	Robot *robot = malloc(sizeof(Robot));
	robot->nodes = nodes;
	robot->edge_length = edge_length;
	return robot;
}

