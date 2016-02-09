#ifndef __CARRE__
#define __CARRE__

#include "SpecialTypes.hpp"
#include "Property.hpp"
#include "Antity.hpp"

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
	Antity * antity;
	
	public :
	
	Carre () : energy_available(0), quantity_seeded(0),quantity_max_seedable(0),turn_planted(0), building(NULL), antity(NULL)
	{}
	
	~Carre()
	{}
	
	//getters simples
	Antity * get_antity()		 	{return antity;}
	Property * get_property()	 	{return building;}
	energy get_max_seedable()	 	{return quantity_max_seedable;}
	energy get_energy_available()	{return energy_available;}
	
	//getters complexes
	
	bool is_fertile();
	bool is_planted();
	
	energy get_multiplied_quantity(energy amount); //ex : si on ramasse X plantes, chacun contenant Y graines, on ramasse X*Y graines
	
	//setters de génération
	void set_antity(Antity * a)		{antity = a;}
	void set_property(Property* p)	{building = p;}
	
	
	//modifications des plantations
	void fertilize(energy amount); //controler (ajout aleatoire)
	void plant(energy amount); //fermier (peut pas planter 2 fois)
	
	void plunder(energy amount); //le combattant ramasse, mais ça détruit la fertilité de la terre
	void cut_plants(energy amount); //le fermier coupe les plantes.
	
	//modification du temps (en frames)
	static void turn_increment() {++turn_current;}
	
	
	// affichage d'infos
	
};

#endif
