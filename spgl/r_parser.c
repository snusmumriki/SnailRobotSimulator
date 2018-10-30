#include <stdlib.h>

#include "r_parser.h"

Pos *posList(int frame_h, int frame_w, char **frame, int *nodes_num, int *eyes_num) {
	int n_num = 0;
	int e_num = 0;

	for (int i = 0; i < frame_h; i++) {
		for (int j = 0; j < frame_w; j++) {
			if (frame[i][j] != SPACE_CHAR)
				n_num++;
			if (frame[i][j] == EYE_CHAR)
				e_num++;
		}

	Pos *pos_list = malloc(sizeof(Pos) * n_num);
	n_num = 0;

	for (int i = 0; i < frame_h; i++) {
		for (int j = 0; j < frame_w; j++) {
			if (frame[i][j] != SPACE_CHAR)
				pos_list[n_num].i = i;
				pos_list[n_num].j = j;
				n_num++;
			}
		}

	*nodes_num = n_num;
	*eyes_num = e_num;	
	return pos_list;
}

int *eyeList(int eyes_num, int nodes_num, Pos *pos_list, char **frame) {
	int k = 0;
	int *eye_list = malloc(sizeof(Pos) * eyes_num);

	for (int i = 0; i < nodes_num; i++) {
		Pos pos = pos_list[i];	
		if (frame[pos.i][pos.j] == EYE_CHAR)
				eye_pos[k++] = i;
	}

	return eye_list;
}

Edg *edgeList(int nodes_num, Pos *pos_list, int *edges_num) {
	int e_num = 0;
	Edg *edge_list = malloc(sizeof(Edg) * nodes_num * ADJ_NUM / 2);
	
	for (int i = 0; i < nodes_num; i++)
		for(int j = i; j < nodes_num; j++) {
			Pos pos0 = posList[i];
			Pos pos1 = posList[j];
			if (pos0.i+2 == pos1.i && pos0.j = pos1.j) {
				edge_list[e_num].nd0 = i;
				edge_list[e_num].nd1 = j;
				e_num++;
			}
		}

	for (int i = 0; i < nodes_num; i++)
		for(int j = i; j < nodes_num; j++) {
			Pos pos0 = pos_ist[i];
			Pos pos1 = pos_ist[j];
			if (pos0.i+1 == pos1.i && pos0.j+1 = pos1.j) {
				edge_list[e_num].nd0 = i;
				edge_list[e_num].nd1 = j;
				e_num++;
			}
		}

	for (int i = 0; i < nodes_num; i++)
		for(int j = i; j < nodes_num; j++) {
			Pos pos0 = pos_list[i];
			Pos pos1 = pos_list[j];
			if (pos0.i+1 == pos1.i && pos0.j-1 = pos1.j) {
				edge_list[e_num].nd0 = i;
				edge_list[e_num].nd1 = j;
				e_num++;
			}
		}

	*edges_num = e_num;
	return edge_list;
}

Adj *adjList(int nodes_num, Pos *pos_list, int edges_num, Edg *edge_list) {
	Adj *adj_list = malloc(sizeof(Adj) * nodes_num);
	
	for (int i = 0; i < nodes_num * ADJ_NUM; i++)
		((int*) adj_list)[i] = -1;

	for (int i = 0; i < edges_num; i++) {
		int node0 = edge_list[i].nd0;
		int node1 = edge_list[i].nd1;
		int diff = pos_list[node0].j - pos_list[node1].j;

		((int*) (adj_list + node0))[BASE_1 + diff] = node1;
		((int*) (adj_list + node1))[BASE_0 + diff] = node0;
	}

	return adj_nums;
}
