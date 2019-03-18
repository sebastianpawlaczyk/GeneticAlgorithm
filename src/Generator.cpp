// Sebastian Pawlaczyk 2019

#include "Generator.hpp"

#include <ctime>
#include <cstdlib>
#include <fstream>

#define POINTS 50
#define DEGREE 2

Generator::Generator():degree(DEGREE)
{}

std::vector<double> Generator::randomizeCoefficients()
{
	double randNumber;
	std::vector<double> coefficients;
	for (int i = 5; i >= 0; i--)
	{
		if (i <= degree)
		{
			//randNumber = std::rand() % 5; // <0,5>
			randNumber = (4 - (-4)) * ((double) rand() / (double) RAND_MAX) + (-4); // <-0.4 , 1>
			coefficients.push_back(randNumber);
			continue;
		}
		coefficients.push_back(0);
	}
	return coefficients;
}

Collection Generator::randomizePoints(bool positivePoints)
{
	double max_x = 1;
	double min_x = 0.25;
	double max_y = 0.7;
	double min_y = -1;
	std::string prefix = "negative";
	if (positivePoints)
	{
		max_x = 0;
		min_x = -1;
		max_y = 1;
		min_y = -0.5;
		prefix = "positive";
	}


	std::srand(std::time(nullptr));
	double randX;
	double randY;
	Collection set;
	std::ofstream file ("/home/seba/PycharmProjects/geneticPlot/data_" + prefix + ".txt");
	for (int i = 0; i < POINTS; i++)
	{
		//randX = std::rand() % 10 + 1; // <1,20>
		//randY = std::rand() % 100 + 1; // <1,20>
		randX = (max_x - (min_x)) * ( (double)rand() / (double)RAND_MAX ) + (min_x); // <-0.4 , 1>
		randY = (max_y - (min_y)) * ( (double)rand() / (double)RAND_MAX ) + (min_y); // <-0.4 , 1>
		file << randX << " " << randY << std::endl;
		set.push_back(Set(randX, randY));
	}
	file.close();
	return set;
}

int Generator::randomizeNumber(int min, int max)
{
	return std::rand() % max + min; // <min,max>
}

int Generator::getDegree() const
{
	return degree;
}
