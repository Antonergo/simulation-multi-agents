#ifndef __FIGHTER__
#define __FIGHTER__

#include "Antity.hpp"

class Fighter : public Antity
{
	private :
	
	energy strength;
	
	public :
	
	
	void attack(Antity & victim);
};


#endif
