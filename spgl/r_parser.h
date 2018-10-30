#ifndef _ROBOT_PARSER_H_
#define _ROBOT_PARSER_H_

#define SPACE_CHAR '.'

#define DEF_CHAR '#'
#define EYE_CHAR 'E'
#define TAIL_CHAR 'T'

#define VDEF_CHAR '*'
#define VEYE_CHAR 'e'
#define VTAIL_CHAR 't'

#define ADJ_NUM 6
#define OFFSET_0 1
#define OFFSET_1 4 

typedef struct pos {
	int i;
	int j;
} Pos;

typedef struct edg {
	int nd0;
	int nd1;
} Edg;

typedef struct adj {
	int up_r;
	int up;
	int up_l;
	int down_l;
	int down;
	int down_r;
} Adj;

Pos *posList(int frame_h, int frame_w, char **frame, int *nodes_num, int *eyes_num);

int *eyeList(int eyes_num, int nodes_num, Pos *pos_list, char **frame);

Edg *edgeList(int nodes_num, Pos *pos_list, int *edges_num);

Adj *adjList(int nodes_num, Pos *pos_list, int edges_num, Edg *edge_list);


#endif
