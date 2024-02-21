#include "Basic.h"

//Generate a Random Double Value
double myRand()
{
	return double(double(rand()) / RAND_MAX);
}

//Generate a Random Double Value withing a given range
double RandRange(double min, double max)
{
	return min + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (max - min)));
}

//Generate a Random XZ Point
tuple<double, double> getXZ(double min, double max)
{
	return make_tuple(RandRange(min, max), RandRange(min, max));
}