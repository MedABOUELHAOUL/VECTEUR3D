#include "Element.h"
#include<iostream>
Element::Element(T data)
{
	this->Data = data; 
	this->next = nullptr;
}

void Element::afficher() const
{
	std::cout << this->Data << std::endl;
}

/*Element* Element::get_next() const
{
	return this->next;
}

void Element::set_next(Element* NV)
{
	this->next = NV;
}

void Element::set_Data(T NV)
{
	this->Data = NV;
}

T Element::get_data() const
{
	return this->Data;
}
*/
Element::~Element()
{
	std::cout << "destructeur de la classe Element" << std::endl;
}
