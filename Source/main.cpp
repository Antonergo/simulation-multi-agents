#include "Controler.hpp"
#include <ctime>

int main ()
{
	std::srand(std::time(NULL));	
	//ouvrir un Simulateur
	Controler game(20 ,12 ,2);
	
	//le lancer
	game.execute();
	
	//c'est tout pour main, rentrez chez vous.
	
	return 0;
}
