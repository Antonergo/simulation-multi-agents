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
	
	bool is_destroyed; //permet de dire à ses habitants qu'ils ne doivent plus rentrer chez eux.
	
	energy life;
	energy life_max; //vie du batiment
	
	energy reserve; //quantite d'energie en reserve
	energy generate; //quantite d'energie generee par tour
	
	public :
	
	//constructeurs
	Property(int equipe, coord startX, coord startY, energy banque = 1000, energy interets = 1)
	{
		team = equipe;
		X = startX;
		Y = startY;
		reserve	= banque;
		generate = interets;
		
		is_destroyed = false;
	}
	
	~Property() {}
	//getters simples
	
	int get_team()			{return  team;}
	
	coord get_X()			{return X;}
	coord get_Y()		 	{return Y;}
	
	energy get_life()  		{return life;}
	energy get_life_max()	{return life_max;}
	energy get_reserve() 	{return reserve;}
	
	
	//getters complexes
	
	int get_population_max(); // = (int) f(reserves)
	
	//modificateurs
	
	void produce(); //créer de l'énergie, et peut être un nouvel habitant si les conditions le permettent
	energy receive_reserve(energy amount);
	energy receive_attack(energy damage);
	
	
};

#endif
