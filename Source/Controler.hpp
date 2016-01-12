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
	coord width;
	coord height;
	std::vector 	<Carre> 		grid;
	
	//vecteur des agents (liste pour les actifs, car on les parcours à la suite)
	std::list		<Antity*> 		ants; //agents actifs
	std::vector		<Property*> 	buildings; //agents passifs
	
	public :
	
	Controler(coord width = 10, coord height = 10, int n_teams = 2);
	~Controler();
	
	//getters
	Carre & get_case(coord X, coord Y); 
	
	Antity & get_antity(id ID);
	Antity & get_antity(coord X, coord Y);
	
	
	//list of events :
	
	//add Antity
	//add Property
	//play one full turn
	
	
};

#endif
