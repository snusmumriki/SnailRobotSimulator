#include <stdlib.h>

#include "r_optimizer.h"
#include "rbt.h"

#define IN(x, limit) ((x) >= 0 && (x) < limit)

char **addSpace(Frame frame) {

}

Pos *convergent_extPos(Frame frame, Pos pos, int rotation, int side) {
	Step bs = -step[rotation];
	Step step = step[ROTATE(rotaton + side)];

	int center = 1;	
	Pos buffer;
	Pos *ext_pos = mallloc(sizeof(Pos));

	for (int i = pos.i, int j = pos.j; 
									IN(i, frame.h) && IN(j, frame.w); 
									i += step.i, j += step.j) {
		char current = frame.mt[i][j];

		if (current == EXT_CHAR)
				return ext_pos;

		int bi = i + bs.i;
		int bj = i + bs.j;
		int i_in = IN(bi, frame.h);
		int j_in = IN(bj, frame.w);
		int ext_line = (i_in && j_in && frame.mt[bi][bj] == SPACE_CHAR || !i_in && !j_in)
		if (current != SPACE_CHAR && (ext_line || center))
			buffer = {i, j};
			
		if (current == SPACE_CHAR) {
			center = 0;
			*ext_pos = buffer;
		}
	}

	return ext_pos;
}

void smoothOver(Frame frame, Pos pos, Pos pos0, Pos pos1) {
	
}

void fill() {

}

void optimizeLimb(Frame frame, Pos pos, int rotation) {
	Step step = step[rotation];

	for (int i = pos.i, int j = pos.j; 
									IN(i, frame.h) && IN(j, frame.w); 
									i += step.i,  j += step.j) {
			Pos pos0 = convergent_extPos(frame, pos, rotation, -1);
			Pos pos1 = convergent_extPos(frame, pos, rotation, 1);
			smoothOver(frame, pos, pos0, pos1);
		}
}

