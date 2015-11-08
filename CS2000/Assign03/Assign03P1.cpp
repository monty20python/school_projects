#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>

using namespace std;

void PrepareFiles(ifstream* finPtr, ofstream* foutPtr);
char ReadCustomerType(ifstream* finPtr);
void ReadSalesData(ifstream* fin, int* itemsPtr, double* pricePtr);
void ReadSalesData(ifstream* fin, int* itemsPtr, double* pricePtr, int* discountPtr);
void ProcSalesData(ofstream* fout, int items, double price, int discount = 0);

const int MAX_LENGTH_FN = 30;  // maximum length for filenames

int main()
{
   ifstream fin;
   ofstream fout;
   char customerType;
   int itemsSold, percentDiscount;
   double pricePerItem;

   PrepareFiles(&fin, &fout);

   customerType = ReadCustomerType(&fin);
   if ( toupper(customerType) == 'R' )
   {
      ReadSalesData(&fin, &itemsSold, &pricePerItem);
      ProcSalesData(&fout, itemsSold, pricePerItem);
   }
   else
   {
      ReadSalesData(&fin, &itemsSold, &pricePerItem, &percentDiscount);
      ProcSalesData(&fout, itemsSold, pricePerItem, percentDiscount);
   }

   fin.close();
   fout.close();
   return EXIT_SUCCESS;
}

void PrepareFiles(ifstream* fin, ofstream* fout)
{
   char inputFilename[MAX_LENGTH_FN + 1],
        outputFilename[MAX_LENGTH_FN + 1];

   cout << "Input filename (up to " << MAX_LENGTH_FN << " characters): ";
   cin.get(inputFilename, MAX_LENGTH_FN + 1, '\n');
   cin.ignore(999, '\n');
   cout << "Output filename (up to " << MAX_LENGTH_FN << " characters): ";
   cin.get(outputFilename, MAX_LENGTH_FN + 1, '\n');
   cin.ignore(999, '\n');

   (*fin).open(inputFilename, ios::in);
   if ((*fin).fail())
   {
      cerr << "Error opening input file " << inputFilename;
      exit(EXIT_FAILURE);
   }

   (*fout).open(outputFilename, ios::out);
   if ((*fout).fail())
   {
      cerr << "Error opening output file " << outputFilename;
      exit(EXIT_FAILURE);
   }
}

char ReadCustomerType(ifstream* finPtr)
{
   char customerType;

   *finPtr >> customerType;
   return customerType;
}

void ReadSalesData(ifstream* finPtr, int* itemsPtr, double* pricePtr)
{
   *finPtr >> *itemsPtr >> *pricePtr;
}

void ReadSalesData(ifstream* finPtr, int* itemsPtr, double* pricePtr, int* discountPtr)
{
   *finPtr >> *itemsPtr >> *pricePtr >> *discountPtr;
}

void ProcSalesData(ofstream* foutPtr, int items, double price, int discount)
{

   *foutPtr << setiosflags(ios::fixed | ios::showpoint) << setprecision(2)
            << items << '\t' << price << '\t' << discount << '\t'
            << items * price * (1.0 - discount / 100.0) << endl;
}
