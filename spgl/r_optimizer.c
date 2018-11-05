#define DIR_0 -1
#define DIR_1 1

#include <stdlib.h>

#include "r_optimizer.h"
#include "rbt.h"

#define IN(x, limit) ((x) >= 0 && (x) < limit)

const Pos ipos_list[DIRS_NUM] = {

}

Pos *extPos(Frame frame, Pos init_pos, int init_dir, int dir) {
	Step back_step = steps[init_step + REV];
	Step step = steps[ROTATE(init_dir + dir)];

	int center = 1;
	int line = 0;
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
			if (line >= 2)
				*ext_pos = {i, j};
			center = 0;
			line = 0;
		} else {
			int bi = i + back_step.i;
			int bj = i + back_step.j;
			int bi_in = IN(bi, frame.h);
			int bj_in = IN(bj, frame.w);
			int ext_line = (bi_in && bj_in && frame.mt[bi][bj] == SPACE_CHAR || !bi_in && !bj_in);
			line += (ext_line || center);
		}
	}

	return ext_pos;
}

void isolate(Frame frame, Pos init_pos, Pos ext_pos, int init_dir, int dir) {
	Step step = step_list[init_dir + dir];

	for (int i = init_pos.i, int j = init_pos.j; 
									i != ext_pos.i && j != ext_pos.j; 
									i += step.i, j += step.j) {
		if (frame.mt[i][j] == SPACE_CHAR)
			frame.mt[i][j] = VDEF_CHAR;
	}
}

void optimizeLimb(Frame frame, Pos init_pos, int rotation) {
	Step step = step_list[rotation];

	for (int i = init_pos.i, int j = init_pos.j; 
									IN(i, frame.h) && IN(j, frame.w); 
									i += step.i, j += step.j) {
			Pos pos = {i, j};

			Pos ext_pos0 = extPos(frame, pos, rotation, DIR_0);
			Pos ext_pos1 = extPos(frame, pos, rotation, DIR_1);

			isolate(frame, pos, ext_pos0, rotation, DIR_0);
			isolate(frame, pos, ext_pos1, rotation, DIR_1);
		}
}

void fill(Frame frame) {
	int solid = 0;
	int **solid_map = malloc(sizeof(int*) * frame.h);
	for (int i = 0; i < frame.h; i++)
		solid_map = calloc(sizeof(char), frame.w);
	
	for (int k = 0; k < DIRS_NUM; k++) {
		step = steps[k];
		for (int i = init_pos.i, int j = init_pos.j; 
									IN(i, frame.h) && IN(j, frame.w); 
									i += step.i, j += step.j) {
			solid |= (frame.mt[i][j] != SPACE_CHAR);
			if (solid) solid_map[i][j]++;
		}
	}


}

char optimizeFrame(Frame *frame) {

}

void optimizeRobot(Frame frame) {
	
}
