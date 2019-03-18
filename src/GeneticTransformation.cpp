// Sebastian Pawlaczyk 2019

#include "GeneticTransformation.hpp"

#include <cstdlib>
#include <iostream>
#include <vector>

#include "Generator.hpp"

GeneticTransformation::GeneticTransformation(){}

Individual GeneticTransformation::crossover(const Individual& parentOne, const Individual& parentSecond)
{
	Generator generator;
	std::vector<double> coefficients(6, 0.0);

	int index = parentOne.getCoefficients().size() - generator.getDegree() - 1; // from what index we what to take coefficients
	for (int i = index; i < 6; i++)
	{
		double probability = generator.randomizeNumber(0, 100);

		if (probability < 45)
		{
			coefficients[i] = parentOne.getCoefficients()[i];
		}

		else if (probability < 90)
		{
			coefficients[i] = parentSecond.getCoefficients()[i];
		}

		else
		{
			coefficients[i] = mutation();
		}
	}

	return Individual{coefficients};
}

double GeneticTransformation::mutation()
{
	return (1 - (-1)) * ((double) rand() / (double) RAND_MAX) + (-1); // <-0.4 , 1>
}