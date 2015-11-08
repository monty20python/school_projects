/*
   File: prog1_dkb71.cpp

   Author: David Bendel
   C.S.1428.253
   Program: #1
   Due Date: 02/08/13

   Prix fixe (pronounced "prefix") menus are common in Europe. A prix fixe
   menu typically includes a number of pre-determined items presented as a
   multi-course meal at a set price. Prix fixe options may include just one
   menu selection or a few different menu selections. For example, one
   evening, a restaurant may offer a four course prix fixe menu of escargot
   for the first course, beef bourguignon (boo r-geen-yuhn) for the second,
   a cheese platter for the third, and creme brulee for dessert. A second
   option that same evening might include an appetizer of oysters on the
   half shell for the first course, followed by an endive (on deev) salad
   for the second, an entree of chicken marsala for the third, and chocolate
   ganache for dessert. The prix fixe menu for the evening (along with its
   cost) is typically posted on a message board outside the restaurant.

   The French restaurant Ma Cherie typically offers only one four course
   prix fixe meal each evening. On special occasions, however, they offer
   two five course prix fixe menu choices. For people who wish to celebrate
   Valentine's Day at Ma Cherie, two prix fix menu choices are offered.
   (The same menu choice is served for each member of a party.)

   Sample menu choices are shown below:

             39.95
        First Course: escargot
        Second Course: beef bourguignon
        Third Course: a cheese platter
        Dessert: creme brulee
        Ligueur: Chambord (shahn-bawr) black raspberry liqueur

        OR

             54.95
        First Course: oysters on the half shell
        Second Course: endive salad with sun-dried tomato
        Third Course: chicken marsala
        Dessert: chocolate ganache
        Liqueur: green chartreuse (shar trus) liqueur

   =======================================================================

   This program prompts the user for the price of the prix fixe meal
   ordered. It then prompts the user for the number of prix fixe meals
   ordered by the customer(s). The program calculates the total cost of
   the meal(s), the sales tax, the tip, and the total amount due. The
   program then prints in receipt form the individual price of one prix
   fixe meal, the number of prix fixe meals ordered, the total for all
   prix fixe meals ordered, the sales tax, the tip and total amount due.

   Sample layout of a receipt is shown below.

   Input (keyboard): prix fixe meal price (double)
                     number of guests     (integer)
   Constants:
          Sample Values:
              SALES TAX RATE = .0825      (double)
              TIP PERCENTAGE = .15        (double)
   Output (console):
          Sample Layout:

              Betty Boop
              C.S.1428.?  // '?' represents student's lecture section #
              --/--/--    // dashes represent due date, month/day/year
              <blank line>
              Prix Fixe Price:    $   50.00
                                    x     8
              Total for 8 meals:     400.00
              Sales Tax @8.25%        33.00
              15% Tip                 64.95
              Total Due:          $  497.95

   =======================================================================

   <Output will vary based on actual input and values used for constants.>
*/

#include <iostream>

#include <iomanip>

using namespace std;

int main()
{
    const double SALES_TAX_RATE = .0925,
                 TIP_PERCENTAGE = .20;

    int number_guests;
    double price_ordered,
           subtotal,
           tax_owed,
           total_with_tax,
           tip_total_tax,
           amount_owed;

    cout << "Enter Price of Prix Fixe Meals Ordered: ";
    cin >> price_ordered;
    cout << "Enter Number of Guests: ";
    cin >> number_guests;
    cout << endl << endl;

    subtotal = price_ordered * number_guests;
    tax_owed = subtotal * SALES_TAX_RATE;
    total_with_tax = subtotal + tax_owed;
    tip_total_tax = total_with_tax * TIP_PERCENTAGE;
    amount_owed = total_with_tax + tip_total_tax;

    cout << "David Bendel \n"
         << "C.S. 1428.253 \n"
         << "02/08/13 \n\n";

    cout << fixed << setprecision(2);

    cout << "Prix Fixe Price:     $ " << setw(8) << price_ordered << endl
         << "                      x" << setw(8) << number_guests << endl
         << "Total for " << number_guests << " meals:     "
         << setw(8) << subtotal << endl
         << "Sales Tax @" << SALES_TAX_RATE * 100 << "%       "
         << setw(8) << tax_owed << endl
         << setprecision(0) << TIP_PERCENTAGE * 100 << "% Tip                "
         << setprecision(2) << setw(8)  << tip_total_tax << endl
         << "Total Due:           $ "  << setw(8) << amount_owed << endl;

         return 0;
}
