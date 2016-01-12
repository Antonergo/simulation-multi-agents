#ifndef __CARRE__
#define __CARRE__

#include "SpecialTypes.hpp"

/**




*/
class Carre
{
	private :
	//energy cross_cost; //déplacement = perte d'énergie (faim)
	
	static frame turn_current;
	
	energy quantity_seeded;
	energy quantity_max_seedable;
	
	frame turn_planted;
	
	public :
	
	Carre () : quantity_seeded(0),quantity_max_seedable(0),turn_planted(0)
	{}
	
	~Carre()
	{}
	
	//getters
	
	bool get_is_fertile();
	bool get_is_planted();
	
	//modifications des plantations
	void fertilize(energy amount);
	void plant(energy amount); //le simulateur vérifie avant que si c'est déjà planté, on ne fait pas cette méthode
	
	energy plunder(energy amount); //le combattant ramasse tout, mais détruit la terre
	energy harvest(energy amount); //algo de ramassage : E = Qs * (coeff dépedant de la maturité des plantes)
	
	// affichage d'infos
	
};

#endif
