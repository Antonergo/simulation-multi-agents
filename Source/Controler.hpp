#ifndef __CONTROLER__
#define __CONTROLER__

#include <list>
#include <vector>

#include "Carre.hpp"
#include "Antity.hpp"
#include "Property.hpp"
/**




*/
class Controler
{
	private :
	
	//matrice de carre
	std::vector 	<Carre> 		grid;
	
	//listes des agents
	std::list 		<Antity*> 		ants;
	std::list 		<Property*> 	buildings;
	
	public :
	
	Controler();
	~Controler();
	
	//list of events :
	
	//add Antity
	//add Property
	//
	
};

#endif
