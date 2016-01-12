#ifndef __ANTITY__
#define __ANTITY__

#include "SpecialTypes.hpp"
#include "InterfaceAntity.hpp"
#include "Property.hpp"
//#include <strings>

/**

*/
class Antity : public IAntity
{
	private :
	
	static id AntityCounter;
	id AntityIdentifier; 
	
	//std::string name;
	
	energy life;
	energy lifeMax;
	energy resilienceToThreats;
	
	energy hunger;
	energy hungerMax;
	energy resilienceToStarvation;
	
	Property* origin;
	
	public :
	//Constructeurs / Destructeurs
	
	virtual ~Antity();
	
	
	//Interfaçage IAntity
	
	virtual void displayAll();
	virtual void displayOneLine();
};




#endif
