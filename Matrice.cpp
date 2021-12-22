#include "Matrice.h"
#include <iostream>
#include <assert.h>
using namespace std;
Matrice::Matrice(int L, int C)
{
	this->L = L; 
	this->C = C;
	this->Mat = new int* [this->L];
	for (int i = 0; i < this->L; i++)
	{
		this->Mat[i] = new int[this->C];
	}

}

Matrice::Matrice(const Matrice& v)
{
	this->L = v.L; 
	this->C = v.C;
	this->Mat = new int* [this->L]; 
	for (int i = 0; i < this->L; i++)
	{
		this->Mat[i] = new int[this->C]; 
		for (int j = 0; j < this->C; j++)
		{
			this->Mat[i][j] = v.Mat[i][j];
		}
	}

}

void Matrice::remplissage()
{
	for (int i = 0; i < this->L; i++)
	{
		for (int j = 0; j < this->C; j++)
		{
			cout << "donner la valeur" << i << "," << j << endl;
			cin >> this->Mat[i][j];
		}
	}
}

void Matrice::afficher() const
{
	for (int i = 0; i < this->L; i++)
	{
		for (int j = 0; j < this->C; j++)
		{
			cout << this->Mat[i][j] << " ";
			
		}
		cout << "\n";
	}
}

Matrice& Matrice::operator+(const Matrice& M) const
{
	Matrice* res = new Matrice(this->L, this->C); 

	for (int i = 0; i < this->L; i++)
	{
		for (int j = 0;  j < this->C;  j++)
		{
			res->Mat[i][j] = this->Mat[i][j] + M.Mat[i][j];
		}
	}
	return *res;
}
Matrice& Matrice::operator-(const Matrice& M) const
{
	Matrice* res = new Matrice(this->L, this->C);

	for (int i = 0; i < this->L; i++)
	{
		for (int j = 0; j < this->C; j++)
		{
			res->Mat[i][j] = this->Mat[i][j] - M.Mat[i][j];
		}
	}
	return *res;
}

Matrice& Matrice::operator*(const Matrice& M) const
{
	assert(this->L == M.C);

	Matrice* res = new Matrice(this->L, this->C); 

	for (int i = 0; i < this->L; i++)
	{
		for (int j = 0; j < this->C; j++)
		{
			int s = 0; 
			for (int k = 0; k < this->C; k++)
			{

				s = s + this->Mat[i][k] * M.Mat[k][j];
			}

			res->Mat[i][j] = s;
		}

	}
	return *res;



	// TODO: insérer une instruction return ici
}

Matrice::~Matrice()
{
	cout << "destructeur" << endl;
	for (int i = 0; i < this->L; i++)
	{
	   delete[]	this->Mat[i];
	   this->Mat[i] = nullptr;
	}
	delete[] this->Mat;
	this->Mat = nullptr;
}
