// Sebastian Pawlaczyk 2019

#include <algorithm>
#include <iostream>
#include <fstream>
#include "Agent.hpp"

#include "src/Generator.hpp"

Agent::Agent()
{
	prepareEnvironment();
}

void Agent::prepareEnvironment()
{
	Generator generator;

	for (int i = 0; i < 5; i++)
	{
		population_.push_back(generator.randomizeCoefficients());
	}

	pSet_ = generator.randomizePoints(true);
	nSet_ = generator.randomizePoints(false);
}

void Agent::startProcessing()
{
	bool found = false;

	while (!found)
	{
		for (auto& pop: population_)
		{
			pop.calculateFitness(pSet_, nSet_);
		}
		found = true;
	}

	std::sort(population_.begin(),population_.end());
	std::fstream file("/home/seba/PycharmProjects/geneticPlot/coefficients.txt");
	for (const auto& c : population_[0].getCoefficients())
	{
		file << c << " ";
	}
	file.close();
}