

#ifndef VECTOR
#define VECTOR

#include <iostream>
using namespace std;



class vector
{	
		unsigned int length;
		int *vec;
	
	public:
		vector();
		vector(int);
		~vector();
		vector operator + (const vector & first);
		vector operator - (const vector & first);
		
		bool operator != (const vector &a);
		bool operator == (const vector &a);
		int   operator [](unsigned int position);
		
		vector &operator *= (int &scalar);
		vector &operator = (const vector & a);
		vector &operator -= (const vector &a);
		vector &operator += (const vector &a);
		vector operator * (int a);
		
		//vector operator *(const vector &a);
		friend vector operator * (int a , const vector &b);		

		friend ostream& operator << (ostream& out, const vector &a);
		friend istream& operator >> (istream& in, const vector &a);
		
	

};
#endif
