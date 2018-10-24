#include <math.h>

#include "unit.h" 

double hypot(double a, double b) {
	return sqrt(a*a + b*b);
}

double triangle_cos(double a, double  b, double c) {
	return (a*a + b*b - c*c) / (2.0 * a * b);
}

double pti(double x) {
	return sqrt(1.0 - x*x);
}

void node_normalize(Node *node, Drive *drive0, Drive *drive1) {
	Node *node0 = drive0->node;
	Node *node1 = drive1->node;

	double a = hypot(node1->x - node0->x, node1->y - node0->y);
	double b = *(drive0->state);
	double c = *(drive1->state);
	double cos_ = triangle_cos(a, b, c);
	double sin_ = pti(cos_);
	
	node->x = (float) (b * cos_) + node0->x;
	node->y = (float) (b * sin_) + node0->y;
}
