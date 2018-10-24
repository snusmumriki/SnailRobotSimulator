#ifndef _ROBOT_PARSER_H_
#define _ROBOT_PARSER_H_

#define SPACE_CHAR '.'
#define MAX_ADJ_NUM 6

typedef struct edge {
	unsigned int node0;
	unsigned int node1;
} Edge;

int **numSheme(int rows_num, int columns_num, char **sheme, int *nodes_num);

Edge *edgeList(int rows_num, int columns_num, int **num_sheme, int nodes_num, int *edges_num);

int *adjNums(int edges_num, Edge *edge_list, int nodes_num);

int parse_robot(char *file_in, char *file_out);

#endif
