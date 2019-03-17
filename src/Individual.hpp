// Sebastian Pawlaczyk 2019

#ifndef SRC_INDIVIDUAL_HPP
#define SRC_INDIVIDUAL_HPP

#include <vector>

#include "struct/Set.hpp"

class Individual
{
public:
	Individual(std::vector<double> c);

	void calculateFitness(const PositiveSet& pSet, const PositiveSet& nSet);
	int getFitness() const;
	std::vector<double> getCoefficients() const;

private:
	bool isAbove(double y_func, double y_point);
	bool isBelow(double y_func, double y_point);
	double calculateY(const double& s);
	void logFunctionToConsole();

	std::vector<double> coefficients;
	int fitness;
};

bool operator<(const Individual& ind1, const Individual& ind2);

using Population = std::vector<Individual>;

#endif //SRC_INDIVIDUAL_HPP
