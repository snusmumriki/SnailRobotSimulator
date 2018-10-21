#define TYPE_EYE 0
#define TYPE_HEAD 1
#define TYPE_NECK 2
#define TYPE_BODY 3

typedef struct node {
	float pos_x;
	float pos_y;

	int type;
	int drives_num;
	Drive *drives;
} node;

typedef struct drive {
	float *length;
	Node *node;
} Drive;
