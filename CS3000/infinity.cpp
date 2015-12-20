/***************
Name: David Bendel
****************/

#include <iostream>

using namespace std;

long long table[46];

long long f1(int x)
{
    if(x <= 1)
    {
      return x;
    }
    else
    {
      return 2 * f1(x-1) + f1(x-2) + x * x -1;
    }
}
long long f2(int x)
{
    if(x <= 1)
    {
      return x;
    }
    else
    {
      return f2(x - 2) + 2 * f2(x-1) + x * x -1;
    }
}
long long f3(int x)
{
     if(table[x] == -1)
     {
      table[x] = f3(table[x-2]) + 2 * f3(table[x-1]) + x * x - 1;
     }
     return table[x];
}
int main(void)
{
  clock_t t;
  table[0] = table[1] = 1;

  for(int i = 2; i < 46; i++)
    table[i] = -1;

  t = clock();
  f1(45);
  t = clock() - t;
  cout << "f1(45) in " << t << " clicks"  << endl;

  t = clock();
  f2(45);
  t = clock() - t;
  cout << "f2(45) in " << t << " clicks"  << endl;

  t = clock();
  f3(45);
  t = clock() - t;
  cout << "f3(45) in " << t << " clicks"  << endl;

  return 0; 
}
