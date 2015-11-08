#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
	double a,
	       b,
	       c,
	       plus,
	       minus,
	       minus1,
	       plus1;

	cout << "Enter a: ";
	cin >> a;

	cout << "Enter b: ";
	cin >> b;

	cout << "Enter c: ";
	cin >> c;

	plus = (-b + sqrt( pow(b,2) - ((4)*(a)*(c)) ));
	minus = ( -b - sqrt( pow(b,2) - ((4)*(a)*(c)) ));

	plus1 = plus / (2*(a));
	minus1 = minus / (2*(a));

	cout << "Positive: " << plus1 << endl
		 << "Negative: " << minus1 << endl;

	return EXIT_SUCCESS;


}

