#include "Carre.hpp"

frame Carre::turn_current = 0;

//getters

bool Carre::is_fertile()
{
	return (this->quantity_max_seedable > (energy)1.0);
}
bool Carre::is_planted()
{
	return (this->quantity_seeded > (energy)0.0);
}

//modifiers

void Carre::fertilize(energy amount)
{
	this->quantity_max_seedable += amount;
}
