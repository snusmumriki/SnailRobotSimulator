#ifndef _R_OPTIMIZER_H_
#define _R_OPTIMIZER_H_

#include "rbt.h"

char **preSmooth(int *frame_h, int *frame_w, char **frame);

void smoothOut(int frame_h, int frame_w, char **frame, int i0, int j0, int rotation);

void smoothBottom(int frame_h, int frame_w, char **frame);

void optimizeEyes(int frame_h, int frame_w, char **frame, 
									int eyes_num, int *eye_list, Pos *pos_list, Adj *adj_list);

void optimizeTails(int frame_h, int frame_w, char **frame,
										int tails_num, int *tail_list, Pos *pos_list, Adj *adj_list);

#endif
