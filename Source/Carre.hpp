#ifndef __CARRE__
#define __CARRE__

#include "SpecialTypes.hpp"
#include "Property.hpp"

/**




*/
class Carre
{
	private :
	//energy cross_cost; //déplacement = perte d'énergie (faim)
	
	static frame turn_current;
	
	energy energy_available;
	energy quantity_seeded;
	energy quantity_max_seedable;
	
	frame turn_planted;
	
	Property * building;
	
	public :
	
	Carre () : energy_available(0), quantity_seeded(0),quantity_max_seedable(0),turn_planted(0), building(NULL)
	{}
	
	~Carre()
	{}
	
	//getters simples
	
	
	
	//getters complexes
	
	bool is_fertile();
	bool is_planted();
	
	//setters de génération
	void set_property(Property* p)	{building = p;}
	
	//modifications des plantations
	void fertilize(energy amount); //controler (ajout aleatoire)
	void plant(energy amount); //fermier (peut pas planter 2 fois)
	
	energy plunder(energy amount); //le combattant ramasse, mais ça détruit la fertilité de la terre
	void cut_plants(energy amount); //le fermier coupe les plantes.
	
	//modification du temps (en frames)
	static void turn_increment() {++turn_current;}
	
	
	// affichage d'infos
	
};

#endif
