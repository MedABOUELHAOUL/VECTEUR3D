#pragma once
#include"Element.h"
class Pile
{
public: 
	Pile(); 
	void empiler(Element E);
	void depiler(); 
	bool est_vide() const;
	void print_List() const; 
	void print_Pile() ;
	Element* top() const; 
	~Pile();
private: 
	Element* Sommet;
};

