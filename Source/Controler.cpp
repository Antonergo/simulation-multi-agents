#include "Controler.hpp"

#define WID_MIN 4
#define WID_MAX 40
#define HEI_MIN 4
#define HEI_MAX 20


Controler::Controler(coord largeur, coord hauteur, int n_teams)
{
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
}
