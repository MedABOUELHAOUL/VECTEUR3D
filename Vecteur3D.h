#pragma once
namespace Geom {
class Vecteur3D
{
private: 
	float* vect; 
public: 
	Vecteur3D(float x=0.0, float y=0.0, float z = 0.0);
	Vecteur3D(const Vecteur3D& v); 
	void afficher() const;
	bool operator==(const Vecteur3D& v) const;
	bool operator!=(const Vecteur3D& v) const;
	Vecteur3D& operator=(const Vecteur3D& v);
	Vecteur3D& operator+(const Vecteur3D&) const;
	float operator*(const Vecteur3D&) const;
	 float& operator[](int index) ;
	~Vecteur3D();
};
};
