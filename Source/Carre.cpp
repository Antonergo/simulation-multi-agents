#include "Carre.hpp"

frame Carre::turn_current = 0;

//getters

bool Carre::is_fertile()
{
	return (quantity_max_seedable > 1.0);
}
bool Carre::is_planted()
{
	return (quantity_seeded > 0.0);
}

//algorithme d'évolution de la quantité d'énergie qu'une plante peut avoir en fonction du temps ou on l'a laissé pousser.
energy Carre::get_multiplied_quantity(energy amount)
{
	energy multiplier = 1.0 + ((energy)(turn_planted - turn_current)) / 100.0;
	
	return amount * multiplier;
}

//modifiers

void Carre::fertilize(energy amount)
{
	quantity_max_seedable += amount;
}


void Carre::plant(energy amount)
{
	if (quantity_seeded == 0)
	{
		quantity_seeded = amount;
		turn_planted = Carre::turn_current;
	}
	else
	{
		//il faut tout couper avant de pouvoir replanter
	}
}
	
void Carre::plunder(energy amount)
{
	if (amount > quantity_max_seedable) amount = quantity_max_seedable;
	
	
	energy result = quantity_seeded + amount * 2.0;
	quantity_max_seedable -= amount;
	
	if (quantity_max_seedable < 0)					quantity_max_seedable 	= 0;
	if (quantity_seeded > quantity_max_seedable)	quantity_seeded 		= quantity_max_seedable;
	
	energy_available += result;
}

void Carre::cut_plants(energy amount)
{
	if (amount > quantity_seeded) amount = quantity_seeded;
	quantity_seeded -= amount;
	
	energy_available += get_multiplied_quantity(amount);
}
