#include <iostream>
#include <cstdlib>
#include "macierz.h"
#include "plik.h"
using namespace std;
macierz :: macierz()
{

wier=2;
kol=2;
tab = new vector* [wier];

if( tab!= NULL)
	{
	*(tab) = new vector [kol];
	*(tab+1) = new vector [kol];

	}

}

macierz :: macierz (unsigned int row, unsigned int col)
{
wier = row;
kol = col; 

tab = new vector* [wier];

for( unsigned int i = 0 ; i < wier ; i++)
	tab[i] = new vector(kol);

}

macierz :: ~macierz()
{
 for(unsigned int i = 0 ; i<wier ; i++)
	delete tab[i];
delete tab;
}

macierz  macierz :: operator + (const macierz & b)const
{
macierz wynik( wier , kol);

if( wier == b.wier && kol == b.kol)
	{
	for( unsigned int i = 0 ; i < wier ; i++)
		(*(wynik.tab)[i]) = (*(tab)[i]) + (*(b.tab)[i]);
	return wynik;
	}
else
	{cout << "blad nie ten rozmiar"<<endl;
	return wynik;
	}

}


macierz :: macierz(const macierz & b)
{
tab = new vector*[b.wier];
if(tab != NULL)
	{
	wier = b.wier;
	kol = b.kol;
	for( unsigned int i = 0 ; i<wier ; i++)
		*(tab + i) = new vector(kol);
	for( unsigned int i = 0 ; i<kol ; i++)
		*(tab)[i] = *(b.tab)[i];
	
	}
else
	{cout<<"blad alokacji"<<endl;
	return;
	}

}



macierz macierz :: operator - (const macierz & b)const
{
macierz wynik( wier , kol);

if( wier == b.wier && kol == b.kol)
	{
	for( unsigned int i = 0 ; i < wier ; i++)
		*(wynik.tab[i]) = *(tab[i]) - *(b.tab[i]);
	return wynik;
	}
else
	{cout << "blad nie ten rozmiar"<<endl;
	return wynik;
	}

}


bool macierz :: operator != (const macierz &b)
{
if( wier != b.wier || kol != b.kol)
	return true;
for( unsigned int i = 0 ; i < wier ; i++)
	if( *(tab[i]) != *(b.tab[i]) )
		return true;
return false;

}

bool macierz :: operator == (const macierz &b)
{

if( wier != b.wier || kol != b.kol)
	return false;
for( unsigned int i = 0 ; i < wier ; i++)
	if( *(tab[i]) != *(b.tab[i]) )
		return false;
return true;

}


macierz macierz :: operator = ( const macierz &b)
{

if( this != &b)
	{for ( unsigned int i = 0 ; i < wier ; i++)
		delete *(tab + i);
	wier = b.wier;
	kol = b.kol;
	tab = new vector* [wier];
	if(tab != NULL)
		{for(unsigned int k = 0 ; k< wier ; k++)	
			*(tab + k ) = new vector(kol);
		for(unsigned int l = 0 ; l<wier ; l++)
			*(tab)[l] = *(b.tab)[l];
		}
	else
		return b;
	}
return *this;
} 



/*									/// cos dziwnego nie wiem 
macierz macierz :: operator *(const macierz &b)const
{
macierz wynik(wier,b.kol);
if( kol == b.wier )
	{for(unsigned int i = 0 ; i<wier ; i++)
		for(unsigned int j=0; j < kol ; j++)
			*(wynik[i])=(((*b.tab[j])*((*(tab[i]))[j])))+(*(wynik.tab[i]));
	for( unsigned int i = 0 ; i< wier ; i++)
		*(tab[i]) = *(wynik.tab[i]);
	return wynik;
	}
else
	{std::cout<<"zle rozmiary"<<endl;
	return wynik;
}
*/


/*
macierz macierz :: operator* (const int a)const
{
macierz nowa(wier,kol);
if(nowa.tab!=NULL)
	{for( unsigned int i = 0 ; i < wier ; i++)
		*(nowa.tab)[i] = a * (*(tab)[i]);
	return nowa;
	}
else
	{cout<<"Blad alokacji"<<endl;
	return *this;
	}

}
*/




vector macierz :: operator [] (unsigned int a)
{
if( wier >= a-1)
	return *(tab[a-1]);
else
	{std::cout<<"Poza obszarem"<<endl;
	return *(tab[0]);
	}

}



void macierz :: operator -= ( const macierz &b  )
{
if( wier == b.wier && kol == b.kol)
	{for(unsigned int i = 0 ; i<wier ; i++)
		*(tab[i]) = *(tab[i]) - *(b.tab[i]);
	return;
	}
else
	{std::cout<<"blad"<<endl;
	return;
	}

}


void macierz :: operator += ( const macierz &b  )
{
if( wier == b.wier && kol == b.kol)
	{for(unsigned int i = 0 ; i<wier ; i++)
		*(tab[i]) = *(tab[i]) + *(b.tab[i]);
	return;
	}
else
	{std::cout<<"blad"<<endl;
	return;
	}

}

								//tutaj tez
/*
void macierz :: operator *= ( const macierz &b  )
{
if(kol == b.kol && wier == b.wier)
	{macierz c(wier,kol);
		unsigned int i, j;
		for(i=0;i<wier;i++) {
			for(j=0;j<wier;j++) {
				*(c.tab[i])=*(b.tab[j])*((*(tab[i]))[j])+*(c.tab[i]);
	for(unsigned k = 0 ; k< wier ; k++)
		*(tab[i]) = *(c.tab[i]);
	return;
	}
else
	{std:cout<<"zle rozmiary"<<endl;
	return
	}

}
*/
/*
void macierz :: operator *= ( const int a  )
{
if( wier != 0 && kol != 0 && tab != NULL)
	{for( unsigned int i = 0 ; i<wier ; i++)
		*(tab[i]) *= a;
	return;
	}
}

*/
 ostream& operator<< ( ostream& on ,const macierz &b )		/// w programie naruszenie ochrony
{

	for(unsigned int i = 0 ; i<b.wier ; i++)
		on << (*(b.tab)[i])<<endl;
	return on;
}



istream& operator >> ( istream& in ,const macierz &b )
{
	vector **pointer = b.tab;
	for(unsigned int i = 0 ; i < b.wier ; i++)
		cin >> *(pointer)[i];
	return in;
}







