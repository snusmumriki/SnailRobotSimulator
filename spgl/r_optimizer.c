#include <stdlib.h>

#include "r_optimizer.h"

#define SGN(x) ((x > 0) - (x < 0))

void preSmooth(int frame_h, int frame_w, char **frame) {

}

void smoothTop(int frame_h, int frame_w, char **frame) {

}

void smoothBottom(int frame_h, int frame_w, char **frame) {

}

int checkMiddleLink(int rotation, int node, adj *adj_list) {

}

void optimizeEyes(int eyes_num, int *eye_list, adj *adj_list, int *offset,
									int frame_h, int frame_w, char **frame) {
	for (int i = 0; i < eyes_num; i++) {
		int eye = eye_list[i];
		int side = SGN(offset[eye]);
		adj nodes = adj_list[eye];

		switch(side) {
			case MIDDLE:
				if (nodes[UP] < 0)
					smoothTop(frame_h, frame_w, frame);
			return;

			case LEFT:
				
			break;

			case 1:

			break;
		}
	}
}
