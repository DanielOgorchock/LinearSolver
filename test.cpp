#include <iostream>
#include "LinearSolver.h"

int main(int argc, char *argv[])
{
	double mat[]= 	{1, 1, 0,   1, -1, 6};
	unsigned int height=2;
	unsigned int width=3;
	
	double *res=linearSolver(width, height, mat);

	return 0;
}
