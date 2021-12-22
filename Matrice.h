#pragma once
class Matrice
{
public: 
	Matrice(int L, int C); 
	Matrice(const Matrice& v);
	void remplissage();
	void afficher() const; 
	Matrice& operator+(const Matrice&) const;
	Matrice& operator-(const Matrice&) const;
	Matrice& operator*(const Matrice&) const;
	~Matrice();

private: 
	int L, C;
	int** Mat;
};

