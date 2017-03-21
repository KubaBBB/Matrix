#include <iostream>
#include "plik.h"
#include <iomanip>
using namespace std;


//konstruktory

vector :: vector()
{
	length=2;
	vec=new int[length];
	if( vec == NULL)
		{delete[] vec;
		cout<<endl<<"Blad alokacji"<<endl;
		return;
		}
	for(unsigned int i = 0 ; i < length ; i++ )
		vec[i]=0;
	return;
}





vector :: vector(int len)
{
	length=len;
	vec = new int[length];
	if( vec == NULL)
		{delete[] vec;
		cout<<endl<<"Blad alokacji"<<endl;
		return;
		}
	for(unsigned int i=0; i<length ; i++)
		vec[i]=0;
	return;
}



//destruktor

vector :: ~vector()
{
	delete[] vec;
}


//a -> b

vector& vector :: operator = (const vector & a)
{		
	if( length == a.length)
		{ for (unsigned  int i = 0 ; i < length ; i++ )
			vec[i] = a.vec[i];
		return *this;
		}
	else
		{std::cout<< " inne rozmiary ";
		return*this;
		}	
								//nie przypisuje dobrze
								//tylko 
}


//a+b=c

vector vector :: operator + (const vector & first)
{	
	unsigned int max_size = first.length > length ? first.length : length;
	vector sum(max_size);
	
	for( unsigned int i =0 ; i<max_size ; i++)
		{
		if ( i < length ) 
			sum.vec[i] += vec[i];
		if( i < first.length)
			sum.vec[i] +=first.vec[i];
		
		}
	return sum;
}



//a-b=c


vector vector :: operator - (const vector & first)
{	/*if( first.length == 0 || first.vec == NULL )
		return *this;					//core dumb
		
	if( length == 0 || vec == NULL)
		{vector sum( first.length);
		for(int i = 0 ; i < first.length ; i++)
			sum.vec[i] = -first.vec[i];
		return sum;
		}
	*/
	unsigned int max_length = length > first.length ? length : first.length;
	vector sum(max_length);
	
	for(unsigned  int i =0 ; i < max_length ; i++)
		{
		if(i<length)			
			sum.vec[i] +=vec[i];
		if(i<first.length)		
			sum.vec[i] -=first.vec[i];
		}
	return sum;

}



//A*a=c
//czy nie brakuje mnozenia??? dwoch wekorow??
vector &vector :: operator *= (int& scalar)
{	if( length != 0 || vec != NULL)
		for(unsigned int i =0 ; i<length ; i++)
			vec[i] *= scalar;
	return *this;
		
}


// if a == b ?

bool vector :: operator == (const vector & a)
{
if(a.length == 0 || a.vec == NULL || length != a.length)
	return false;
unsigned int l=0;
for(unsigned int i=0 ; i<length ; i++)
	if(vec[i] == a.vec[i])
		l++;
if( l == length)
	return true;
else
	return false;

}


//if a != b

bool vector :: operator != (const vector & a)
{if(a.length == 0 || a.vec == NULL || length != a.length)
	return true;

unsigned int l=0;
for(unsigned int i=0 ; i<length ; i++)	
	if( vec[i] == a.vec[i])
		l++;

if( l == length)
	return false;
else
	return true;

}


// []                                                      

int  vector :: operator [](unsigned int position)
{
return *(vec + position); 



}


vector &vector :: operator += (const vector &a)
{ 
	if(a.length == length)
		{for(unsigned int i = 0 ; i < length ; i++)
			vec[i] = a.vec[i] + vec[i];
		return *this;		
		}
	else
		{cout<<"blad rozmiarow"<<endl;
		return *this;
		}

}





vector &vector :: operator -=(const vector &a)
{

if(a.length == length)
		{for(unsigned int i = 0 ; i < length ; i++)
			vec[i] -= a.vec[i];
		return *this;		
		}
else
		{
		cout<<"blad rozmiarow"<<endl;
		return *this;
		}


}

vector operator *(int a , const vector &b)
{
if(b.length == 0 || b.vec == NULL)
	{cout<<"blad"<<endl;
	return b;
	}
for( unsigned int i = 0 ; i < b.length ; i++)
	b.vec[i] = a * b.vec[i];
return b;

}

/*vector vector :: operator * ( const vector &a)
{
int result=0;
for(unsigned int i=0 ; i<a.length ; i++)
	result = result + vec[i] * a.vec[i];

return result;


}
*/

vector vector ::operator * ( int a)
{vector c(length);
if( c.length != 0 || c.vec != NULL)
	for(unsigned int i = 0 ; i < c.length ; i++)
		c.vec[i] = a * vec[i];		

return c;
}

ostream& operator << (ostream& out, const vector &a)
{
if( a.length != 0 && a.vec != NULL)
	
	for(unsigned int i = 0 ; i < a.length ; i++)
		out  << a.vec[i]<<" ";	

return out;
}




istream& operator >> (istream& in, const vector &a)
{
if( a.length >=1 && a.vec != NULL)
	for(unsigned int i = 0 ; i<a.length ; i++)
		in >> a.vec[i];

return in;
}






