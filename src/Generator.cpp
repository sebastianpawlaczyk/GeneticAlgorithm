// Sebastian Pawlaczyk 2019

#include "Generator.hpp"

#include <ctime>
#include <cstdlib>
#include <fstream>

Generator::Generator():degree(2)
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
			randNumber = (1 - (-0.4)) * ((double) rand() / (double) RAND_MAX) + (-0.4); // <-0.4 , 1>
			coefficients.push_back(randNumber);
			continue;
		}
		coefficients.push_back(0);
	}
	return coefficients;
}

Collection Generator::randomizePoints(bool positivePoints)
{
	std::srand(std::time(nullptr));
	double randX;
	double randY;
	Collection set;
	std::ofstream file ("/home/seba/PycharmProjects/geneticPlot/data.txt");
	for (int i = 0; i < 50; i++)
	{
		//randX = std::rand() % 10 + 1; // <1,20>
		//randY = std::rand() % 100 + 1; // <1,20>
		randX = (1 - (0)) * ( (double)rand() / (double)RAND_MAX ) + (0); // <-0.4 , 1>
		randY = (0.5 - (-1)) * ( (double)rand() / (double)RAND_MAX ) + (-1); // <-0.4 , 1>
		file << randX << " " << randY << std::endl;
		set.push_back(Set(randX, randY));
	}
	file.close();
	return set;
}
