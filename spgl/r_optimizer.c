#include <stdlib.h>

#include "r_optimizer.h"
#include "rbt.h"

char **preSmooth(Frame frame) {

}

int isConvergent(Frame frame, Pos pos, int rotation, Pos *pos0, Pos *pos1) {
	int central = 0;
	int left = 0;
	int right = 0;
	int ext = 0;

	Step step = step[ROTATE(rotaton + 2)];
	for (int i = pos.i; i >= 0 && i < frame.h; i += step.i)
		for (int j = pos.i; j >= 0 && j < frame.w; j += step.j) {
			
			}
}

int isBubble(Frame frame, Pos pos, int rotation, Pos *pos0, Pos *pos1) {

}

void addVirtNodes(Frame frame, Pos pos, Pos pos0, Pos pos1) {

}

void setExtNodes(Frame frame) {

}

void smoothOut(Frame frame, Pos pos, int rotation) {
	Step step = step[rotation];

	for (int i = pos.i; i >= 0 && i < frame.h, i += step.i)
		for (int j = pos.j; j >= 0 && j < frame.w; j += step.j) {
			Pos pos0;
			Pos pos1;
			if (isConvergent(frame, pos, rotation, &pos0, &pos1) 
											|| isBubble(frame, pos, rotation, &pos0, &pos1))
				addVirtualNodes(frame, pos, pos0, pos1);
		}
}

