#ifndef __SPECIALTYPES__
#define __SPECIALTYPES__

#include <cstddef> //NULL

typedef unsigned long int id; //identifiant d'entité
typedef unsigned long int frame; //temps de jeu
typedef unsigned int coord; //coordonnées sur la grille de simulation
typedef double energy;


typedef enum direction
{
	NONE = 5,
	DOWN_LEFT = 1,
	LEFT_DOWN = 1,
	DOWN = 2,
	DOWN_RIGHT = 3,
	RIGHT_DOWN = 3,
	LEFT = 4,
	RIGHT = 6,
	UP_LEFT = 7,
	LEFT_UP = 7,
	UP = 8,
	UP_RIGHT = 9,
	RIGHT_UP = 9
} dir;

typedef enum movementkind
{
	FOUR = 4,
	EIGHT = 8
} movekind;

#endif
