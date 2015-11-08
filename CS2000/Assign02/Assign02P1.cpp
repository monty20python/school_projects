#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>

using namespace std;

void GetPizzaPrices( double &, double & );
void GetPizzaShapes( char &, char & );
void GetPizzaSize( double & );
void GetPizzaSize( double &, double & );
void CalcPricePerSqIn( double, double, double &, char );
void CalcPricePerSqIn( double, double, double, double &, char );
void OutputPizzaInfo( double, double, double, bool );
void OutputPizzaInfo( double, double, double, double, bool );
void OutputResult( double, double );

const double PI = 3.14159,
             PRICE_BOUND = 0.0005;

int main()
{
    char shape1,
         shape2,
         reply;

    double diameter1,
           diameter2,
           length1,
           length2,
           width1,
           width2,
           price1,
           price2,
           pricePerSqIn1,
           pricePerSqIn2;

    bool pizza_number = false;

    do
    {
        GetPizzaPrices( price1, price2 );
        GetPizzaShapes( shape1, shape2 );

        if (shape1 == 'C' || shape1 == 'c')
        {
             // call GetPizzaSize
            GetPizzaSize( diameter1 );
             // call CalcPricePerSqIn
            CalcPricePerSqIn( diameter1, price1, pricePerSqIn1, shape1 );
        }
        else
        {
             // call GetPizzaSize
            GetPizzaSize( length1, width1 );
             // call CalcPricePerSqIn
            CalcPricePerSqIn( length1, width1, price1, pricePerSqIn1, shape1 );
        }

        if (shape2 == 'C' || shape2 == 'c')
        {
            GetPizzaSize( diameter2 );
            CalcPricePerSqIn( diameter2, price2, pricePerSqIn2, shape2 );
         // call GetPizzaSize
         // call CalcPricePerSqIn
        }
        else
        {
            GetPizzaSize( length2, width2 );
            CalcPricePerSqIn( length2, width2, price2, pricePerSqIn2, shape2 );
         // call GetPizzaSize
         // call CalcPricePerSqIn
        }

        cout << endl;
        if (shape1 == 'C' || shape1 == 'c')
            OutputPizzaInfo( price1, diameter1, pricePerSqIn1, pizza_number );
         // call OutputPizzaInfo
        else
            OutputPizzaInfo( price1, length1, width1, 
                             pricePerSqIn1, pizza_number );
         // call OutputPizzaInfo
        if (shape2 == 'C' || shape2 == 'c')
        {
            pizza_number = true;
            OutputPizzaInfo( price2, diameter2, pricePerSqIn2, pizza_number );
        }
         // call OutputPizzaInfo
        else
        {
            pizza_number = true;
            OutputPizzaInfo( price2, length2, width2, 
                             pricePerSqIn2, pizza_number );
        }
         // call OutputPizzaInfo
        OutputResult( pricePerSqIn1, pricePerSqIn2 );
         // call OutputResult
        cout << endl;
        pizza_number = false; //reset to default

        cout << "Do another comparison? (n = no, any other = yes) ";
        cin >> reply;
    }
    while (reply != 'n' && reply != 'N');

    cout << "Press Enter or Return when ready..." << endl;
    cin.ignore(999, '\n');
    cin.get();
    return EXIT_SUCCESS;
}

// definition for GetPizzaPrices
void GetPizzaPrices( double &price1, double &price2 )
{
    cout << "Please enter price of the first Pizza: ";
    cin >> price1;

    if( price1 <= 0 )
    {
        do
        {
            cout << "Price must be greater than 0.00" << endl
                 << "Please enter valid price: ";
            cin >> price1;
        } while ( price1 <= 0 );
    }

    cout << "Please enter price of the second Pizza: ";
    cin >> price2;

    if( price2 <= 0 )
    {
        do
        {
            cout << "Price must be greater than 0.00" << endl
                 << "Please enter valid price: ";
            cin >> price2;
        } while ( price2 <= 0 );
    }

}

// definition for GetPizzaShapes
void GetPizzaShapes( char &shape1, char &shape2 )
{
    cout << fixed << setprecision(2) 
         << "Please enter shape of first pizza ( C = Circular, R = Rectangular): ";
    cin >> shape1;

    if( shape1 != 'R' && shape1 != 'r' && shape1 != 'C' && shape1 != 'c' )
    {
        do
        {
            cout << "Shape must be circular or rectangular" << endl
                 << "Please enter valid shape (R,r,C,c): ";
            cin >> shape1;

        } while ( shape1 != 'R' && shape1 != 'r' && shape1 != 'C' && shape1 != 'c' );
    }

    cout << "Please enter shape of second pizza ( C = Circular, R = Rectangular): ";
    cin >> shape2;

    if( shape2 != 'R' && shape2 != 'r' && shape2 != 'C' && shape2 != 'c' )
    {
        do
        {
            cout << "Shape must be circular or rectangular" << endl
                 << "Please enter valid shape (R,r,C,c): ";
            cin >> shape2;

        } while ( shape2 != 'R' && shape2 != 'r' && shape2 != 'C' && shape2 != 'c' );
    }
}

// definitions for overloaded GetPizzaSize
void GetPizzaSize( double &diameter1 )
{
    cout << "Please enter diameter of pizza: ";
    cin >> diameter1;

    if( diameter1 <= 0 )
    {
        do
        {
            cout << "Diameter must be greater than zero" << endl
                 << "Please enter valid diameter: ";
            cin >> diameter1;
        } while ( diameter1 <= 0 );
    }
}

void GetPizzaSize( double &length1, double &width1 )
{
    cout << "Please enter pizza length: ";
    cin >> length1;

    if ( length1 <= 0 )
    {
        do
        {
            cout << "Width must be greater than zero" << endl
                 << "Please enter length: ";
            cin >> length1;

        } while ( length1 <= 0 );
    }

    cout << "Please enter pizza width: ";
    cin >> width1;

    if ( width1 <= 0 )
    {
        do
        {
            cout <<"Width must be greater than zero" << endl
                 << "Please enter width: ";
            cin >> width1;

        } while ( width1 <= 0 );
    }
}

// definitions for overloaded CalcPricePerSqIn
void CalcPricePerSqIn( double diameter1, double price1, 
                       double &pricePerSqIn1, char shape1 )
{
    pricePerSqIn1 = price1 / ( PI * pow(( diameter1 / 2.0 ), 2 ));
}

void CalcPricePerSqIn( double length1, double width1, double price1, 
                       double &pricePerSqIn1, char shape1 )
{
    pricePerSqIn1 = price1 / ( length1 * width1 );
}
// definitions for overloaded OutputPizzaInfo
void OutputPizzaInfo( double price1, double diameter1, 
                      double pricePerSqIn1, bool pizza_number )
{
    string number1;

    if ( pizza_number == true )
        number1 = "2nd";
    else
        number1 = "1st";

    cout << "Info for the " << number1 << " pizza: " << endl
         << setw(25) << "Price = $" << price1 << endl
         << setw(25) << "Diameter = " << diameter1 << " inches" << endl
         << setw(25) << setprecision(4) << "Per sq. in. = $" 
         << pricePerSqIn1 << setprecision(2) << endl;
}

void OutputPizzaInfo( double price1, double length1, double width1, 
                      double pricePerSqIn1, bool pizza_number )
{
    string number2;

    if ( pizza_number == true )
        number2 = "2nd";
    else if ( pizza_number == false )
        number2 = "1st";

    cout << "Info for the " << number2 << " pizza: " << endl
         << setw(25) << "Price = $" << price1 << endl
         << setw(25) << "Length = " << length1 << " inches" << endl
         << setw(25) << "Width = " << width1 << " inches" << endl
         << setw(25) << setprecision(4) << "Per sq. in. = $" 
         << pricePerSqIn1 << setprecision(2) << endl;
}

// definition for OutputResult
void OutputResult( double pricePerSqIn1, double pricePerSqIn2 )
{
    double price_difference;

    price_difference = pricePerSqIn1 - pricePerSqIn2;

    if( abs(price_difference) < PRICE_BOUND )
        cout << "The pizzas are equally good buys." << endl;
    else if ( price_difference < 0 )
        cout << "The first pizza is a better buy." << endl;
    else if ( price_difference > 0)
        cout << "The second pizza is a better buy." << endl;
}
