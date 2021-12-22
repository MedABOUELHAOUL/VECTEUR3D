#include "Pile.h"
#include <iostream>
Pile::Pile()
{
	this->Sommet = nullptr;
}


void Pile::empiler(Element E)
{
	Element* N = new Element(E.Data);
	N->next = this->Sommet; 
	this->Sommet = N;
}

void Pile::depiler()
{
	Element* tmp = this->Sommet;
	this->Sommet = this->Sommet->next; 
	delete tmp;
}

bool Pile::est_vide() const
{
	return (this->Sommet==nullptr);
}

void Pile::print_List() const
{
	Element* tmp = this->Sommet;
	while (tmp != nullptr) {
		tmp->afficher();
		tmp = tmp->next;
	}
}

void Pile::print_Pile() 
{
	Pile* P=new Pile();
	while (this->Sommet != nullptr) {
		P->empiler(*(this->Sommet)); 
		this->Sommet->afficher();
		this->depiler(); 
		//this->Sommet = this->Sommet->next;
	}
	while (P->Sommet != nullptr) {
		this->empiler(*(P->Sommet));
		P->depiler();
		//this->Sommet = this->Sommet->next;
	}
}

Element* Pile::top() const
{
	return this->Sommet;
}

Pile::~Pile()
{
	std::cout << "destructeur de la classe Pile" << std::endl;
	while (this->Sommet != nullptr) {
		this->depiler();
	}
}


