// Sebastian Pawlaczyk 2019

#ifndef GENETICALGO_AGENT_HPP
#define GENETICALGO_AGENT_HPP

#include "src/Individual.hpp"
#include "src/struct/Set.hpp"

class Agent
{
public:
	Agent();

	void startProcessing();

private:
	void prepareEnvironment();

	Population population_;
	PositiveSet pSet_;
	NeativeSet nSet_;
};


#endif //GENETICALGO_AGENT_HPP
