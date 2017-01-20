/* 
Written by Gabriel Manners
Built for recursion lab LASA ADV CS 2016-2017
*/
#include <iostream>
#include <string>
using namespace std;

void beerTail(int x)
{
	if(x == 0)
		cout << "No more bottles of beer. Sucks" << endl;
	else{
		cout << x << " bottles of beer on the wall, " << x << " bottles of beer!" << " Take one down, pass it around, " << x-1 << " bottles of beer on the wall." << endl;
		beerTail(x-1);
	}
}

void beerNotTail(int x)
{
	if(x == 0)
		cout << "/n" << "No more bottles of beer. Sucks";
	else
	{
		cout << x << " bottles of beer on the wall, " << x << " bottles of beer!" << " Take one down, pass it around, " << x-1 << " bottles of beer on the wall." << endl;
		x = x-1;
		beerTail(x);
	}
}

	
int main(){

	cout << "Tail or not?  [T]/[N]";
	string result;
	cin >> result;
	if(result == "T")
	{beerTail(99);}
	else
	{beerNotTail(99);}

	return 0;
	
}
