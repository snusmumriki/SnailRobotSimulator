#define MAX_ADJ_NUM 6

#include "unit.h"

typedef struct robot {
	int nodes_num;
	Node *node;

	int drives_num;
	float *drive_length;
} Robot;
