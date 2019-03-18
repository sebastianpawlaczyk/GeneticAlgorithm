// Sebastian Pawlaczyk 2019

#ifndef SRC_GENETICTRANSFORMATION_HPP
#define SRC_GENETICTRANSFORMATION_HPP

#include "Individual.hpp"

class GeneticTransformation
{

public:
	GeneticTransformation();

	Individual crossover(const Individual& parentOne, const Individual& parentSecond);

private:
	double mutation();
};


#endif //SRC_GENETICTRANSFORMATION_HPP
