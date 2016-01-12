#ifndef __ANTITY__
#define __ANTITY__

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
	
	energy life;
	energy lifeMax;
	energy lifeDefense;
	
	energy hunger;
	energy hungerMax;
	energy hungerDefense;
	
	Property* origin;
	
	public :
	//Constructeurs / Destructeurs
	Antity (energy vie = 200.0, energy faim = 50.0);
	
	virtual ~Antity();
	
	//getters
	
	
	//modifiers (faim, vie, etc...)
	
	
	//fonctions d'affichage
	
	virtual void displayAll(); //affiche toutes les infos si selectionné
	virtual void displayOneLine(); //affiche des infos sur une seule ligne (ex : dans liste)
};




#endif
