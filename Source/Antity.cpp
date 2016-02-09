#include "Antity.hpp"

id Antity::AntityCounter = 1;


Antity::Antity (coord startX, coord startY, energy vie, energy faim, Property * ville_natale)
{
	AntityIdentifier = Antity::AntityCounter;
	Antity::AntityCounter++;
	
	X = startX;
	Y = startY;
	
	life = vie;
	life_max = vie;
	
	hunger = faim;
	hunger_max = faim;
	
	carry = 0;
	carry_max = 100;
	
	deceased = false;
	
	origin = ville_natale;
	team = origin->get_team();
}
	
Antity::~Antity()
{
	std::cout << "Antity remove" << std::endl;
}

//getters

energy Antity::get_life()		{return life;}
energy Antity::get_life_max()	{return life_max;}
energy Antity::get_hunger()		{return hunger;}
energy Antity::get_hunger_max()	{return hunger_max;}

bool Antity::is_alive() 		{return !deceased;}

//modifiers (faim, vie, etc...)

energy Antity::pickup_reserve(energy amount)
{
	energy remain = 0;
	
	carry += amount;
	if (carry > carry_max)
	{
		remain = carry - carry_max;
		carry = carry_max;
	}
	
	return remain;
}

energy Antity::suffer_attack(energy amount)
{
	life -= amount;
	
	if (life <= 0)
	{
		deceased = true;
		life = 0;
	}
	
	return life;
}

//actions d'agent

direction Antity::choose_direction()
{ //dépend du job
	return (direction)5; //NONE
} 

//fonctions d'affichage

void Antity::display_all(std::ostream & os)
{ //afficher toutes les infos
	os << "Antity : " << AntityIdentifier << std::endl;
	os << "Vie   : " << life << " / " << life_max << std::endl;
	os << "Faim  : " << hunger << " / " << hunger_max << std::endl;
	os << "Carry : " << carry << " / " << carry_max << std::endl;
} 
void Antity::display_line(std::ostream & os)
{ //affiche des infos sur une seule ligne (ex : liste d'antités)
	os << AntityIdentifier;
	os << "-> vie:" << life;
	os << " faim:"  << hunger;
	os << " carry:" << carry;
	os << std::endl;
} 
