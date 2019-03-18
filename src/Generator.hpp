// Sebastian Pawlaczyk 2019

#ifndef GENETICALGO_RANDOM_HPP
#define GENETICALGO_RANDOM_HPP

#include "struct/Set.hpp"

class Generator
{
public:
	Generator();

	std::vector<double> randomizeCoefficients();
	Collection randomizePoints(bool positivePoints);
	int randomizeNumber(int min, int max);

	int getDegree() const;

private:
	unsigned int degree;
};


#endif //GENETICALGO_RANDOM_HPP
