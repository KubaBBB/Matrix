#include "plik.h"
#include "macierz.h"
#include <iostream>
#include <new>
#include <stdlib.h>
using namespace std;

int main(void)
{
macierz a(2,2); macierz b(2,2);

cin >>a;
std::cin >>b;
						// << i >>
cout<<"A =\n"<<a<<endl<<"B =\n"<<b<<endl;

						// == i !=
int torf= a ==b;
cout<<"\nCzy sa takie same: "<<torf<<endl;
torf = a!=b;
cout<<"\nCzy sa rozne: " <<torf <<endl;
macierz c(2,2);

					// + i -
cout<<"a+b = \n";
cout <<a + b << endl;
cout<<"a-b = \n";
cout<< ( a-b)<<endl;
cout<<endl<<a<<endl;			

/*
						//+= i -=	
cout<<"a+=b"<<endl;
a+=b;
cout<<a<<endl;
cout<<" Najpierw a potem b"<<endl;
cout<<a<<endl<<b<<endl;
cout<<"a-=b"<<endl;
a-=b;
cout<<a<<endl;
*/

						// * int i * macierz
/*
macierz d(2,2);
cin>>d;
macierz e(d);
*/

/*
cout<<"a = b "<<endl;
a=b;
cout<<a;
*/




/*
<<	ok
>>	ok
==	ok
!=	ok
=
+	ok
-	ok
=+	ok
=-	ok
=* int
=* maci
*  int
*  macierz
copy
[]	ok


*/




return 0;


}
