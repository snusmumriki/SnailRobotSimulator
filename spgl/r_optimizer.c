#include <stdlib.h>

#include "r_optimizer.h"

char **preSmooth(int *frame_h, int *frame_w, char **frame) {

}

void postSmooth(int frame_h, int frame_w, char **frame) {

}

void smoothTop_in(int frame_h, int frame_w, char **frame, int eye, int *pos_list) {

}

void smoothTop_out(int frame_h, int frame_w, char **frame, int eye, int *pos_list) {

}

void smoothBottom(int frame_h, int frame_w, char **frame) {

}

int node_isLinked(int node, int rotation, Adj *adj_list) {
	for (; node >= 0; node = ((int*) (adj_list + node))[ROTATE(rotation + 4)])
		if (!node) return 1;

	return 0;
}

void optimizeEyes(int frame_h, int frame_w, char **frame, 
									int eyes_num, int *eye_list, Pos *pos_list, Adj *adj_list) {
	for (int i = 0; i < eyes_num; i++) {
		Adj adj = adj_list[eye];
		Pos pos = pos_list[eye];

		if (adj.down_l >= 0 && adj.down_r >= 0) {
			smoothTop_out(frame_h, frame_w, frame, eye, offset);
		} else {
			if (!node_isLinked(eye, 1, middle, adj_list))
				smoothTop_in(frame_h, frame_w, frame, eye, middle, pos_list);
		}
	}
}

void optimizeTails(int frame_h, int frame_w, char **frame,
										int tails_num, int *tail_list, Pos *pos_list, Adj *adj_list) {
	for (int i = 0; i < eyes_num; i++) {
		Adj adj = adj_list[eye];
		Pos pos = pos_list[eye];

		if (adj.down_l >= 0 && adj.down_r >= 0) {
			smoothTop_out(frame_h, frame_w, frame, eye, offset);
		} else {
			if (!node_isLinked(eye, 1, middle, adj_list))
				smoothTop_in(frame_h, frame_w, frame, eye, middle, pos_list);
		}
	}
}

void optimizeTails(int frame_h, int frame_w, char **frame,
