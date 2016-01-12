#ifndef __IANTITY__
#define __IANTITY__

/**





*/
class IAntity
{
	private :
	int moveCan [9];
	dir moveWant;
	
	public :

	virtual ~IAntity();
	
	virtual void display_all() = 0;
	
	virtual int getFame() = 0;
	
	//constructeurs de copie, opérateur=
	

	virtual dir directionChoose (movekind type);
};


#endif
