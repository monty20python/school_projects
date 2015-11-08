#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_ROW = 20,
	      MAX_COL = 20;

void seedrand();
int moveRandBound();
void caluculate();
void drawSpace();
void drawOutline();
//prototype calulate
//prototype draw outline

struct parameters
{
	int m,  //row bound
	    n,  //col bound
	    i,  //horz position
	    j,  //vert position
	    k;  //move bounds

	char border[MAX_ROW][MAX_COL];
	int space[MAX_ROW][MAX_COL]
};

int main()
{
	char ans;
	parameters s1;


	//seedrand();

	do
	{
		cout << "Enter row size of rectangular enclosure: ";
		cin >> s1.m;
		cout << "Enter col size of rectangular enclosure: ";
		cin >> s1.n;
		cout << "Enter row # of R2D2's initial position: ";
		cin >> s1.i;
		cout << "Enter col # of R2D2's initial position: ";
		cin >> s1.j;
		cout << "Enter maximum # of moves allowed: ";
		cin >> s1.k;

		//calc call
		//draw call

		cout << "Do another case? (n = No, any other = Yes): ";
		cin >> ans;

	} while( ans != 'N' || ans != 'n');



	return EXIT_SUCCESS;
}

void seedrand()
{
	srand((unsigned) time(NULL));
}

int moveRandBound()
{
	return ( rand() % 8);
}

void caluculate()
{

}

void drawSpace()
{

}

void drawOutline()
{
	for( int a = 0, b = s1.n, c = s1.m, d = s1.n; a < s1.m && a < s1.n && b > 0 )
	{
		s1.border[a][0] = '-';    // horiz line
		s1.border[s1.m][b] = ' |'; // vert line
		s1.border[c][s1.n] = '-'; // horiz line
		s1.border[0][d] = ' |';    // vert line
	}	
}
