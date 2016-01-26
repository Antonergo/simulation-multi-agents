#include "Controler.hpp"
#include "Property.hpp"


#define WID_MIN 4
#define WID_MAX 40
#define HEI_MIN 4
#define HEI_MAX 20


Controler::Controler(coord largeur, coord hauteur, int n_teams)
{	
	//Create grid
	if (largeur >= WID_MIN && largeur <= WID_MAX && hauteur >= HEI_MIN && hauteur <= HEI_MAX)
	{
		this->width 	= largeur;
		this->height 	= hauteur;
		
		grid.resize( this->width * this->height );
	}
	else
	{
		//TODO : throw boundaries exception
	}
	
	std::cout << "taille du vecteur grille : " << width*height << " (" << width << " " << height << ")" << std::endl;
	
	//place Team buildings
	buildings.clear();
	for (int i = 1; i <= n_teams; ++i)
	{
		
		//determiner stats du batiment
		energy random = (((energy)std::rand() )/((energy)RAND_MAX)) - 0.5;
		
		energy bank = 1000.0	+	1500 * random;
		energy prod = 1.0		-	0.2  * random;
		
		Property *p = new Property(i, bank, prod);
		
		buildings.push_back(p);
		
		//determiner position du batiment sur la grille
		coord rX = (coord)((((float)std::rand() )/((float)RAND_MAX)) * (float)width);
		coord rY = (coord)((((float)std::rand() )/((float)RAND_MAX)) * (float)height);
		
		std::cout << i << ": [" << rX << " " << rY << "] (" << bank << " ++ " << prod << ")" << std::endl;
		
	}
	
}

Controler::~Controler()
{
	//delete Antities
	for (unsigned i = 0; i < ants.size(); ++i)
	{
		delete ants[i];
	}
	
	//delete Properties
	for (unsigned i = 0; i < buildings.size(); ++i)
	{
		delete buildings[i];
	}
}

void Controler::execute()
{
	std::cout << "debut de la simulation" << std::endl;
}


void Controler::show_all(std::ostream & os)
{
	for (coord i = 0; i < (coord)grid.size(); ++i)
	{
		if(i % width == width-1)
			os << std::endl;
		
		
	}
}
