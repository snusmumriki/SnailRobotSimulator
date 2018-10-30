#include <stdio.h>
#include <stdlib.h>

#include "r_src.h"

int main() {
	Adj adj;
	adj.up_l = 0;
	adj.up = 1;
	adj.up_r = 2;
	adj.down_l = 3;
	adj.down = 4;
	adj.down_r = 5;

	for (int i = 0; i < ADJ_NUM; i++)
		printf("%i\n", ((int*) &adj)[i]);

	printf("done\n");
	return 0;
}
