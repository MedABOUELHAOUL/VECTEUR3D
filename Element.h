
#pragma once
typedef int T;
class Element
{
public: 
	Element(T data);
	void afficher() const;
	// Element* get_next() const; // getters en lecture
	// void set_next(Element* NV);   // en Ecriture
	// void set_Data(T NV); 
	// T get_data() const;
 friend class Pile;
	//friend void Pile::empiler(Element* E);
	~Element(); 
private: 
T	Data; 
Element *next;
};

