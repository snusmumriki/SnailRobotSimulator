#ifndef _ROBOT_H_
#define _ROBOT_H_

#include "unit.h"

typedef struct robot {
	int nodes_num;
	struct node *node_list;

	int drives_num;
	float *drive_state_list;
} Robot;

typedef struct coup {
	int ni0;
	int ni1;
} Coup;

#endif
