#define ROTATION_0 -1
#define ROTATION_1 1

#include <stdlib.h>

#include "r_optimizer.h"
#include "rbt.h"

#define IN(x, limit) ((x) >= 0 && (x) < limit)

Pos *extPos(Frame frame, Pos init_pos, int rotation, int side) {
	Step bs = steps[rotation];
	bs.i = -bs.i;
	bs.j = -bs.j;
	Step step = steps[ROTATE(rotaton + side)];

	int center = 1;
	int convergent = 0;
	int space = 0;
	Pos *ext_pos = mallloc(sizeof(Pos));
	*ext_pos = init_pos;

	for (int i = init_pos.i, int j = init_pos.j; 
									IN(i, frame.h) && IN(j, frame.w); 
									i += step.i, j += step.j) {
		char current = frame.mt[i][j];

		if (current == EXT_CHAR)
				return ext_pos;

		if (current == SPACE_CHAR) {
			if (convergent >= 2)
				*ext_pos = {i, j};
			center = 0;
			convergent = 0;
		} else {
			int bi = i + bs.i;
			int bj = i + bs.j;
			int bi_in = IN(bi, frame.h);
			int bj_in = IN(bj, frame.w);
			int ext_line = (bi_in && bj_in && frame.mt[bi][bj] == SPACE_CHAR || !bi_in && !bj_in);
			convergent += (ext_line || center);
		}
	}

	return ext_pos;
}

void isolate(Frame frame, Pos init_pos, Pos ext_pos, int rotation, int side) {
	Step step = steps[rotation + side];

	for (int i = init_pos.i, int j = init_pos.j; 
									i != ext_pos.i && j != ext_pos.j; 
									i += step.i, j += step.j) {
		if (frame.mt[i][j] == SPACE_CHAR)
			frame.mt[i][j] = VDEF_CHAR;
	}
}

void fill(Frame frame, Pos init_pos) {
	
}

void optimizeLimb(Frame frame, Pos init_pos, int rotation) {
	Step step = steps[rotation];

	for (int i = init_pos.i, int j = init_pos.j; 
									IN(i, frame.h) && IN(j, frame.w); 
									i += step.i,  j += step.j) {
			Pos pos = {i, j};

			Pos ext_pos0 = extPos(frame, pos, rotation, ROTATION_0);
			Pos ext_pos1 = extPos(frame, pos, rotation, ROTATION_1);
			isolate(frame, pos, ext_pos0, rotation, ROTATION_0);
			isolate(frame, pos, ext_pos1, rotation, ROTATION_1)
		}
}

char optimizeFrame(Frame *frame) {

}

void optimizeRobot(Frame frame) {
	
}
