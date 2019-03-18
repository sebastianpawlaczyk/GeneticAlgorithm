// Sebastian Pawlaczyk 2019

#include "Agent.hpp"

#include <algorithm>
#include <iostream>
#include <fstream>

#include "src/Generator.hpp"
#include "src/GeneticTransformation.hpp"

#define POPOULATION 10

Agent::Agent()
{
	prepareEnvironment();
}

void Agent::prepareEnvironment()
{
	Generator generator;

	for (int i = 0; i < POPOULATION; i++)
	{
		population_.push_back(generator.randomizeCoefficients());
	}

	pSet_ = generator.randomizePoints(true);
	nSet_ = generator.randomizePoints(false);
}

void Agent::startProcessing()
{
	Generator generator;
	GeneticTransformation transformation;
	
	while (true)
	{
		// Calculate fitness for new population
		for (auto& pop: population_)
		{
			pop.calculateFitness(pSet_, nSet_);
		}

		// Check if we can stop our algorithm
		std::sort(population_.begin(),population_.end());
		if (population_[0].getFitness() == 0)
		{
			break;
		}

		Population newPopulation;
		for (int i = 0; i < 1; i++)
		{
			newPopulation.push_back(population_[i]);
		}

		for (int i = 0; i < 9; i++)
		{
			Individual parentOne = population_[generator.randomizeNumber(0,5)];
			Individual parentSecond = population_[generator.randomizeNumber(0,5)];
			Individual child = transformation.crossover(parentOne, parentSecond);
			newPopulation.push_back(child);
		}
		std:: cout << "Fitness-> " << population_[0].getFitness() << std::endl;
		population_ = newPopulation;
	}
	std::sort(population_.begin(),population_.end());
	std:: cout << "Fitness new -> " << population_[0].getFitness() << std::endl;
	std::fstream file("/home/seba/PycharmProjects/geneticPlot/coefficients.txt");
	for (const auto& c : population_[0].getCoefficients())
	{
		file << c << " ";
	}
	file.close();
}