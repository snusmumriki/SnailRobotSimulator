#include "file_io.h"
#include "robot_parser.h"
#include "r_optimizer.h"

#include "parser.h"

int parseRobot(char *file_in, char *file_out) {
	int rows_num;
	int columns_num;
	char **sheme;
	FILE *fp;

	
	int nodes_num;
	int eyes_num;
	int edges_num;
	
	int **num_sheme = numSheme(rows_num, columns_num, sheme, &nodes_num, &eyes_num);
	edge *edge_list = edgeList(rows_num, columns_num, num_sheme, nodes_num, &edges_num);
	
	fp = fopen(file_out, "w+");
	fprintf(fp, "%i\n", edges_num);
	for (int i = 0; i < edges_num; i++)
		fprintf(fp, "%i %i\n", edge_list[i][0], edge_list[i][1]);
	
	fprintf(fp, "\n");
	fprintf(fp, "%i\n", nodes_num);
	for (int i = 0; i < nodes_num; i++)
		for (int j = 0; j < MAX_ADJ_NUM; j++)
		fprintf(fp, "%i %i\n", i, adj_list[i][j]);
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

int parseTarget(char *file_in, char *file_out) {

}

int parseGarbage(char *file_in, char *file_out) {

}
