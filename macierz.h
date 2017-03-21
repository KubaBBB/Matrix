#ifndef MACIERZ
#define MACIERZ

#include "plik.h"
#include <iostream>
using namespace std;

class macierz {
	
	unsigned int wier;
	unsigned int kol;
	vector **tab;

	public:
	macierz();
	macierz(unsigned const int row, unsigned const int col);
	~macierz();
	macierz operator + (const macierz & b)const;
	macierz operator - (const macierz & b)const;

	bool operator != (const macierz &b);
	bool operator == (const macierz &b);
	macierz operator = ( const macierz &b);
	
	//macierz operator *(const macierz &b)const;
	macierz operator *(const int a)const;
	vector operator [] (unsigned const int a);

	macierz(const macierz & b);

	void operator -= ( const macierz &b  );
	void operator += ( const macierz &b  );
	void operator *= ( const macierz &b  );
	void operator *= ( const int a  );
	friend ostream& operator << ( ostream& on,const macierz &b );
	friend istream& operator >> ( istream& in,const macierz &b );

};

#endif
