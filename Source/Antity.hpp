#ifndef __ANTITY__
#define __ANTITY__

#include <iostream>

#include "SpecialTypes.hpp"
#include "Property.hpp"
//#include <strings>

/**

*/
class Antity
{
	private :
	
	static id AntityCounter;
	id AntityIdentifier; 
	
	//std::string name;
	
	coord X;
	coord Y;
	
	coord target_X;
	coord target_Y;
	
	energy life;
	energy life_max;
	//energy lifeDefense;
	
	energy hunger;
	energy hunger_max;
	//energy hungerDefense;
	
	energy carry;
	energy carry_max;
	
	Property* origin;
	
	public :
	//Constructeurs / Destructeurs
	Antity (energy vie = 200.0, energy faim = 50.0);
	
	virtual ~Antity();
	
	//getters

	energy get_life();
	energy get_life_max();
	energy get_hunger();
	energy get_hunger_max();
	
	//modifiers (faim, vie, etc...)
	
	energy pick_reserve(energy skill);
	energy suffer_attack(energy skill);
	
	//actions d'agent
	
	virtual direction choose_direction();
	
	//fonctions d'affichage
	
	virtual void display_all(std::ostream & os); //affiche toutes les infos si selectionné
	virtual void display_line(std::ostream & os); //affiche des infos sur une seule ligne (ex : dans liste)
};




#endif
