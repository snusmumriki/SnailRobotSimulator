#ifndef _UNIT_H_
#define _UNIT_H_

#define TYPE_EYE 0
#define TYPE_HEAD 1
#define TYPE_NECK 2
#define TYPE_BODY 3

#define MAX_COUP_NUM 6
#define DRIVE_INIT_STATE 1.0

typedef struct drive {
	float *state;
	struct node *node;
} Drive;

typedef struct node {
	float x;
	float y;

	int type;
	int drives_num;
	struct drive *drive;
} Node;

#endif
