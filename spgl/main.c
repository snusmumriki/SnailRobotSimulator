#include <stdio.h>
#include <stdlib.h>

#include "preprocessor.h"
#include "robot_parser.h"

int main() {
	parse_robot("r.spgl", "r.sn");
	printf("done\n");
	return 0;
}
