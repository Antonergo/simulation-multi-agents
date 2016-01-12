#ifndef __CARRE__
#define __CARRE__

#include "SpecialTypes.hpp"

/**




*/
class Carre
{
	private :
	//energy cross_cost;
	
	double quantity_seeded;
	double quantity_max_seedable;
	double time_grown;
	
	public :
	
	Carre (double max_seeds) :quantity_seeded(0),  quantity_max_seedable(max_seeds){}
	
	energy getHarvestable();
	
};

#endif
