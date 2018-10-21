#define TYPE_EYE 0
#define TYPE_BODY 1
#define TYPE_SKIRT 2
#define TYPE_FIVE 3

#define CON_LEN 1.0

#include <math.h>

typedef struct unit {
	char type;
	
	float x;
	float y;;

	float left_data;
	float right_data;

	Connector *con0;
	Connector *con1;
	Connector *con2;
} Unit;

typedef struct drive {
	float length;
	Unit *unit;
} Drive;



void unit_updateConnectors() {
	
}

void unit_normalize(Unit *unit) {
	Unit *unit0 = unit->con0.unit;
	Unit *unit1 = unit->con1.unit;

	double a = hypot(unit1->x - unit0->x, unit1->y - unit0->y);
	double b = unit->con0.length;
	double c = unit->con1.length;
	double cos_ = getCos(a, b, c);
	double sin_ = getSin(cos_)
	
	unit->x = (float) (b * cos_) + left_unit->x;
	unit->y = (float) (b * sin_) + left_unit->y;
}

double hypot(double a, double b) {
	return sqrt(a*a + b*b);
}

double getCos(double a, double  b, double c) {
	return (a*a + b*b - c*c) / ( 2.0 * a * b);
}

double getSin(double cos_) {
	return sqrt(1.0 - cos_*cos_);
}
