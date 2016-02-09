#include "Controler.hpp"
#include "Property.hpp"
#include "Farmer.hpp"
#include "Fighter.hpp"

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
		
		//determiner position du batiment sur la grille
		coord rX = (coord)((((float)std::rand() )/((float)RAND_MAX)) * (float)width);
		coord rY = (coord)((((float)std::rand() )/((float)RAND_MAX)) * (float)height);
		
		Property *p = new Property(i, rX, rY, bank, prod);
		
		buildings.push_back(p);
		
		//positionner les points d'accès tout autour de la base
		
		coord pos = rY * width + rX;
		coord pos_around;
		
		for (coord iY = rY-1; iY <= rY+1; ++iY)
		{
			for (coord iX = rX-1; iX <= rX+1; ++iX)
			{
				if (iY >= 0 && iY < height && iX >= 0 && iX < width)
				{ 
					//std::cout << "add access point in " << iY << " " << iX << std::endl;
					
					pos_around = iY * width + iX;
					grid[pos_around].set_property(p);
				}
			}
		}
		std::cout << "building " << i << ": [" << rY << " " << rX << " --> " << pos << "] (" << bank << " ++ " << prod << ")" << std::endl;
		
		//placer le chef antity de chaque base (une unité considérablement plus forte que les autres)
		Antity *a = new Fighter(rX+1, rY, 500, 100, p, 10);
		
		a->display_line(std::cout);
		
		if (rY >= 0 && rY < height && rX >= 0 && rX < width -1)
		{
			//std::cout << "add antity to " << rY << " " << rX+1 << std::endl;
			
			coord pos = rY * width + rX+1;
			grid[pos].set_antity(a);
		}
		
		ants.push_back(a);
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
	
	std::ostream & os = std::cout;
	
	show_all(os);
}


void Controler::show_all(std::ostream & os)
{
	for (coord i = 0; i < (coord)grid.size(); ++i)
	{
		char chara = ' '; //défaut : case vide
		
		coord x = i % width;
		coord y = i / width;
		Carre & carre = grid[i];
		Property * p = carre.get_property();
		Antity * a = carre.get_antity();
		
		//ordre de priorité d'affichage : les premiers sont prioritaires
		if (a)
		{
			//Antity
			chara = 'a';
		}
		else if (p)
		{
			//Batiment
			
			if (p->get_X() == x && p->get_Y() == y)
			{
				chara = 'B';
			}
			else
			{
				chara = '0' + p->get_team() % 10;
			}
		}
		else if (carre.get_energy_available() > 0.0)
		{
			//Energy au sol
			chara = 'e';
		}
		else if (carre.get_max_seedable() > 10.0)
		{
			//Terrain fertile
			chara = 'f';
		}
		
		os << chara;
		
		
		if(x == width-1)
			os << std::endl;
	}
}
