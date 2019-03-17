// Sebastian Pawlaczyk 2019

#include "Individual.hpp"

#include <cmath>
#include <iostream>
#include <sstream>

Individual::Individual(std::vector<double> c)
: coefficients(c)
	, fitness(0)
{
	logFunctionToConsole();
}

void Individual::calculateFitness(const PositiveSet& pSet, const PositiveSet& nSet)
{
	for (const auto& point: pSet)
	{
		double y = calculateY(point.getX());
		if (!isAbove(y, point.getY()))
		{
			fitness++;
		}
	}

	for (const auto& point: nSet)
	{
		double y = calculateY(point.getX());
		if (!isBelow(y, point.getY()))
		{
			fitness++;
		}
	}

	std::cout << "FITNESS " << fitness << std::endl;
}

bool Individual::isAbove(double y_func, double y_point)
{
	if (y_func < y_point) return true;
	return false;
}

bool Individual::isBelow(double y_func, double y_point)
{
	if (y_func > y_point) return true;
	return false;
}

double Individual::calculateY(const double &x)
{
	double y;
	int degree = coefficients.size() - 1;
	y = 0;
	int i = 0;
	while (degree >= 0)
	{
		y += coefficients[i] * std::pow(x, degree);
		degree--;
		i++;
	}

	return y;
}

void Individual::logFunctionToConsole()
{
	std::ostringstream stream;
	stream << "y = ";

	int degree = coefficients.size() - 1;
	int i = 0;
	while (degree >= 0)
	{
		stream << coefficients[i] << "x^" << degree << " + ";
		degree--;
		i++;
	}
	std::cout << stream.str().substr(0, stream.str().size() - 3) << std::endl;
}

int Individual::getFitness() const
{
	return fitness;
}

std::vector<double> Individual::getCoefficients() const
{
	return coefficients;
}

bool operator<(const Individual& ind1, const Individual& ind2)
{
	return ind1.getFitness() < ind2.getFitness();
}