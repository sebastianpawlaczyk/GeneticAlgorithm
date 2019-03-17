// Sebastian Pawlaczyk 2019

#ifndef SRC_STRUCT_SET_HPP
#define SRC_STRUCT_SET_HPP

#include <vector>

struct Set
{
public:
	Set(double x, double y)
	{
		x_ = x;
		y_ = y;
	}

	const double& getX() const
	{
		return x_;
	}

	const double& getY() const
	{
		return y_;
	}

private:
	double x_;
	double y_;
};

using Collection = std::vector<Set>;
using PositiveSet = Collection;
using NeativeSet = Collection;

#endif //SRC_STRUCT_SET_HPP
