#ifndef _R_OPTIMIZER_H_
#definr _R_OPTIMIZER_H_

char **preSmooth(int *frame_h, int *frame_w, char **frame);

void postSmooth(int frame_h, int frame_w, char **frame);

void smoothTop_in(int frame_h, int frame_w, char **frame, int eye, int *pos_list);

void smoothTop_out(int frame_h, int frame_w, char **frame, int eye, int *pos_list);

void smoothBottom(int frame_h, int frame_w, char **frame);

void optimizeEyes(int frame_h, int frame_w, char **frame, 
									int eyes_num, int *eye_list, Pos *pos_list, Adj *adj_list);

void optimizeTails(int frame_h, int frame_w, char **frame,
										int tails_num, int *tail_list, Pos *pos_list, Adj *adj_list);

#endif
