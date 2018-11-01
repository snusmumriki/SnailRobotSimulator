#ifndef _RBT_H_
#define _RBT_H_

#define SPACE_CHAR '.'

#define DEF_CHAR '#'
#define EYE_CHAR 'E'
#define TAIL_CHAR 'T'

#define VDEF_CHAR '*'
#define VEYE_CHAR 'e'
#define VTAIL_CHAR 't'

#define ADJ_NUM 6

struct ps {
	int i;
	int j;
};
typedef struct ps Pos;
typedef struct ps Step;

typedef struct frame {
	int h;
	int w;
	char **mt;
} Frame;

const Step step[ADJ_NUM] = {
				{-1, 1},
				{-2, 0},
				{-1, -1},
				{1, -1},
				{2, 0},
				{1, 1}
}

#endif
