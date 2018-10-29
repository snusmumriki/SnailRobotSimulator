#ifndef _ROBOT_PARSER_H_
#define _ROBOT_PARSER_H_

#define SPACE_CHAR '.'
#define MAX_ADJ_NUM 6
#define BASE_0 1
#define BASE_1 4

typedef int edge[2];

typedef int adj[MAX_ADJ_NUM];

int **numSheme(int rows_num, int columns_num, char **sheme, int *nodes_num);

edge *edgeList(int rows_num, int columns_num, int **num_sheme, int nodes_num, int *edges_num);

int *adjNums(int edges_num, int (*edge_list)[2], int nodes_num);

int parse_robot(char *file_in, char *file_out);

#endif
