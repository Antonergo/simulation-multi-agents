#ifndef __FIGHTER__
#define __FIGHTER__

#include "Antity.hpp"

class Fighter : public Antity
{
	private :
	
	energy strength;
	
	public :
	
	Fighter(coord startX, coord startY, energy vie, energy faim, Property * ville_natale, energy force) : 
		Antity(startX, startY, vie, faim, ville_natale)
	{
		strength = force;
	}
	
	~Fighter()
	{
		std::cout << "Fighter remove" << std::endl;
	}
	
	void attack(Antity * victim);
};


#endif
