#include "LinearSolver.h"
#include <iostream>


void printMat(unsigned int width, unsigned int height, double mat[])
{
	for(unsigned int row=0; row<height; ++row)
	{
		for(unsigned int col=0; col<width; ++col)
		{
			std::cout<<mat[row*width+col]<<"\t";	
		}
		std::cout<<std::endl;
	}
}	

double* linearSolver(unsigned int width, unsigned int height, double mat[])
{
	double *results=new double[height];

	//print initial matrix
	std::cout<<"Before:\n";
	printMat(width, height, mat);

	for(unsigned int col=0; col<width-1; ++col)
	{
		//normalize the row
		double normFactor=mat[col*width+col];
		for(unsigned int i=0; i<width; ++i)
		{
			mat[col*width+i]/=normFactor;
		}

		for(unsigned int row=0; row<height; ++row)
		{
			if(row==col)
			{
				continue;
			}
			

			double factor=-mat[col*width+col]/mat[row*width+col];
			for(unsigned int c=0; c<width; ++c)
			{
				unsigned int tmpI=row*width+c;
				mat[tmpI]+=mat[col*width+c]*factor;	
			}			
		}
	}
	
	//print ending matric
	std::cout<<"\nAfter:\n";
	printMat(width, height, mat);

	//store results
	for(unsigned int i=0; i<height; ++i)
	{
		results[i]=mat[i*width+width-1];
	}

	return results;
}
