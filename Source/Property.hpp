#ifndef __PROPERTY__
#define __PROPERTY__

#include "SpecialTypes.hpp"

/**




*/
class Property
{
	private :
	
	int team;
	
	coord X; //coordonnees du point capital
	coord Y;
	
	bool is_destroyed;
	
	energy life;
	energy life_max;
	
	energy reserve; //quantite d'energie en reserve
	energy generate; //quantite d'energie generee par tour
	
	public :
	
	//constructeurs
	Property(int equipe, energy banque = 1000, energy interets = 1)
	{
		this->team 		= equipe;
		this->reserve 	= banque;
		this->generate 	= interets;
	}
	
	~Property() {}
	//getters simples
	
	energy get_life() 		{return life;}
	energy get_life_max()	{return life_max;}
	energy get_reserve()	{return reserve;}
	
	//getters complexes
	
	int get_population_max(); // = (int) f(reserves)
	
	//modificateurs
	
	void produce();
	energy pick_reserve(energy skill);
	energy receive_attack(energy skill);
	
	
};

#endif
