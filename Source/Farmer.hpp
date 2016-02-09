#ifndef __FARMER__
#define __FARMER__

#include "Antity.hpp"

class Farmer : public Antity
{
	private :
	
	energy skill;
	
	public :
	
	Farmer(coord startX, coord startY, energy vie, energy faim, Property * ville_natale, energy competence) : 
		Antity(startX, startY, vie, faim, ville_natale)
	{
		skill = competence;
	}
	
	~Farmer()
	{
		std::cout << "Farmer remove" << std::endl;
	}
	
	void put_seeds();
	void harvest();
};

#endif
