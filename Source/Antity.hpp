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
	
	int team;
	
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
	
	bool deceased;
	
	Property * origin;
	
	public :
	//Constructeurs / Destructeurs
	Antity (coord startX, coord startY, energy vie, energy faim, Property * ville_natale);
	
	virtual ~Antity();
	
	//getters

	energy get_life();
	energy get_life_max();
	energy get_hunger();
	energy get_hunger_max();
	bool is_alive();
	
	//modifiers (faim, vie, etc...)
	
	energy pickup_reserve(energy amount); //augmenter carry
	energy suffer_attack(energy damage); //diminuer life
	
	//actions d'agent
	
	virtual direction choose_direction(); //dépend du job et de l'etat de l'agent
	
	//fonctions d'affichage
	
	virtual void display_all(std::ostream & os); //affiche toutes les infos si selectionné
	virtual void display_line(std::ostream & os); //affiche des infos sur une seule ligne (ex : dans liste)
};




#endif
