#include "Vecteur3D.h"
#include <iostream>
#include <assert.h>
using namespace Geom;
Geom::Vecteur3D::Vecteur3D(float x, float y, float z)
{
	this->vect = new float[3];
	this->vect[0] = x; 
	this->vect[1] = y; 
	this->vect[2] = z;
}

Geom::Vecteur3D::Vecteur3D(const Vecteur3D& v)
{
	this->vect = new float[3];
	this->vect[0] = v.vect[0];
	this->vect[1] = v.vect[1];
	this->vect[2] = v.vect[2];
}

void Geom::Vecteur3D::afficher() const
{
std::cout << "(" << this->vect[0] << "," << this->vect[1] << "," << this->vect[2] << ")" << std::endl;
}

bool Geom::Vecteur3D::operator==(const Vecteur3D& v) const
{
	bool res=true;
	for (int i = 0; i < 3; i++)
	{
		/*if (this->vect[i] == v.vect[i]) {
			res=true;
		}
		else 
			res=false;
		break;*/
		res = res && (this->vect[i] == v.vect[i]);
	}
	
	return res;
}

bool Geom::Vecteur3D::operator!=(const Vecteur3D& v) const
{
	return !(this->operator==(v));
}

Vecteur3D& Geom::Vecteur3D::operator=(const Vecteur3D& v)
{
	if(this!=&v ) {
	delete[]this->vect;
	this->vect = new float[3];
	for (int i = 0; i < 3; i++)
	{
		this->vect[i] = v.vect[i];
	}
	}
	// else == auto-affectation== (this==&v)
	return *this;
}

Vecteur3D& Geom::Vecteur3D::operator+(const Vecteur3D& v) const
{  Vecteur3D* res = new Vecteur3D();
for (int i = 0; i < 3; i++)
{
	res->vect[i] = this->vect[i] + v.vect[i];
}
return *res;
}

float Geom::Vecteur3D::operator*(const Vecteur3D& v) const
{
	float s = 0;
	for (int i = 0; i < 3; i++)
	{
		s += this->vect[i] * v.vect[i];
	}
	return s;
}


 float & Geom::Vecteur3D::operator[](int index)
{
	assert(index >= 0 && index < 3); // en mode debug
    return this->vect[index];
	
}

Geom::Vecteur3D::~Vecteur3D()
{
	delete[] this->vect;
	this->vect = 0;
	std::cout << "destructeur" << std::endl;
}
