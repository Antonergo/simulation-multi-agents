#ifndef __CONTROLER__
#define __CONTROLER__

#include <iostream> //ostream
#include <list>
#include <vector>
#include <cstdlib> //std::rand

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
	std::vector		<Antity*> 		ants; //agents actifs
	std::list		<id>			ants_order; //ordre d'activité des agents (histoire de changer du tour par tour
	std::vector		<Property*> 	buildings; //agents passifs
	
	public :
	
	Controler(coord width = 10, coord height = 10, int n_teams = 2);
	~Controler();
	
	//getters
	
	//getters d'elements
	Carre & get_case(coord X, coord Y); 
	
	Antity & get_antity(id ID);
	Antity & get_antity(coord X, coord Y);
	
	
	//genesis
	/*
	void add_antity (Antity & ant, coord X, coord Y);
	void add_property (Property & prop, coord X, coord Y);
	*/
	
	//execute
	void execute();
	
	void play_turn(Antity & ant);
	void produce_ressources(); //all buildings get more ressources
	
	//display
	void show_all	(std::ostream & os); //Priority : Antity > Property > Terrain
	void show_grid	(std::ostream & os); //show only the terrain (and the values of energy on it)
	void show_teams	(std::ostream & os); //show only the team (Properties > Antities)
	
	
};

#endif
