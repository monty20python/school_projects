/***************
Name: David Bendel
****************/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

const int SIZE = 2826;
const int ARRAY_SIZE = 3000;

struct HashedObj
{
    string name;
    int key;
};

void hash_fn( HashedObj * obj )
{
    int temp = obj->name.length();
    long fib = 0;
    if(temp != 0)
    {
    	// use n = obj.name.length() to get nth fibbonaci number's last two digits
    	fib = (1/sqrt(5))*(pow(((1+sqrt(5))/2), temp) - pow(((1 - sqrt(5))/2), temp));
    	obj->key = fib % 100;
    }
    
    
}

int main()
{
    HashedObj table[ARRAY_SIZE];

    int collisions = 0;
    string input[ARRAY_SIZE];
    int j = 1;
    for( int i = 0; i < SIZE; ++i)
    {
        cin >> input[i];
    }
    
    for(int i = 0; i < ARRAY_SIZE; ++i)
    {
    	HashedObj obj;
        obj.key = 0;
        obj.name = "\0";

        obj.name = input[i];
        hash_fn(&obj);

        if(obj.key == 0)
        	obj.name = "empty";
        
        if(table[obj.key].name.empty() )
        {
            table[obj.key] = obj;
        }
        else if( !(table[obj.key].name.empty()) )
        {
        	int j = 1;
            while( !(table[(obj.key + j)].name.empty()) )
            {
            	if(j <= ARRAY_SIZE)
            	{
 	               j++;
 	            }
 	            else
 	            	j = obj.key - ARRAY_SIZE;
            }
            table[(obj.key + j) ] = obj;
            collisions = collisions + j;    
        }
        
    }

    for(int i = 0; i < ARRAY_SIZE; ++i)
        cout << table[i].name << endl;
    cout << "Collisions: " << collisions << endl;
    
    return 0;
}
