#include "Property.hpp"



int Property::get_population_max()
{
	return reserve/200;
}

void Property::produce() //créer de l'énergie, et peut être un nouvel habitant si les conditions le permettent
{
	
}

energy Property::receive_reserve(energy amount)
{
	reserve += amount;
	if (reserve < 0) reserve = 0;
}

energy Property::receive_attack(energy damage)
{
	life -= damage;
	if (life < 0)
	{
		life = 0;
		is_destroyed = true;
	}
}
