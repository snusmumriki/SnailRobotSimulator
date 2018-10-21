#define UNIT_CHAR '#'
#define MAX_ADJ 6

#include <stdlib.h>
#include <node.h>

int numericSheme(unsigned int rows_num, unsigned int row_size, char **sheme, int *nodes_num, int * eyes_num) {
	int num = 0;
	int init_size = sizeof(int*) * rows_num;
	int **num_sheme = malloc(init_size + sizeof(int) * row_size * rows_num);
	for (int i = 0; i < rows_num; i++) 
		num_sheme[i] = (*int) num_sheme + init_size + i * row_size;
	
	for (unsigned int i = 0; i < rows_num; i++) 
		for (unsigned int j = 0; j < row_size; j++) {
			if (sheme[i][j] == UNIT_CHAR) {
				num_sheme[i][j] = num;
				num++;
			} else num_sheme[i][j] = -1;

			if (j == 0) *eyes_num = num;
		}		
	
	*nodes_num = num;
	return num_sheme;
}

typedef struct adj_nodes {
	unsigned int num;
	int list[MAX_ADJ];
} AdjNodes;

void addNode(unsigned int rows_num, unsigned int row_size, int **num_sheme, AdjNodes *adj_nodes, unsigned int i, unsigned int j) {
	if (i >= 0 && i < rows_num && j >= 0 && j < row_size && num_sheme[i][j] >= 0) {
		adj_nodes->list[adj_nodes->num] = num_sheme[i][j];
		adj_nodes->num++;
	}
}

Adjacent *adjacencytList(unsigned int rows_num, unsigned int row_size, char **num_sheme, int *edges_num) {
	int num = 0;
	AdjNodes *adj_list = calloc(sizeof(Adj) * units_num);

	for (unsigned int i = 0; i < rows_num; i++) 
		for (unsigned int j = 0; j < row_size; j++) 
			if (num_sheme[i][j] >= 0) {
				addNode(rows_num, row_size, num_sheme, adj_list + num, i + 2, j);
				addNode(rows_num, row_size, num_sheme, adj_list + num, i - 2, j);
				addNode(rows_num, row_size, num_sheme, adj_list + num, i + 1, j + 1);
				addNode(rows_num, row_size, num_sheme, adj_list + num, i + 1, j - 1);
				addNode(rows_num, row_size, num_sheme, adj_list + num, i - 1, j + 1);
				addNode(rows_num, row_size, num_sheme, adj_list + num, i - 1, j + 1);
				num++;
			}

	*edges_num = num;
	return list;
}

Node *parse_nodes(unsigned int rows_num, unsigned int row_size, char **sheme) {
	int nodes_num;
	int eyes_num;
	int edges_num;
	int **num_sheme = numericSheme(rows_num, row_size, sheme, *nodes_num);
	AdjNodes *adj_list = adjacencytList(rows_num, row_size, num_sheme, *edges_num);
	
	Node *robot = malloc(sizeof(Node) * nodes_num);
	for (unsigned int i = 0; i < nodes_num; i++) {
		for (unsigned int j = 0; i < adj_list[i].num)
	}
}
