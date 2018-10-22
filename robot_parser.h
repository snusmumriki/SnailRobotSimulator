#include "robot.h"

typedef struct edge {
	unsigned int node0;
	unsigned int node1;
} Edge;

int numericSheme(int rows_num, int columns_num, char spase, char **sheme, int *nodes_num, int *eyes_num);

Edge *edgeList(int rows_num, int columns_num, int **num_sheme, int nodes_num, int *edges_num);

int *adjNums(int edges_num, Edge *edge_list);

Robot *parse_robot(int rows_num, int columns_num, char spase, char **sheme);
