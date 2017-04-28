// C++ program to find minimum of coins
// to make a given change V
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <sstream>
#include<time.h>
#include<math.h>

using namespace std;
const int MAX_ARRAY_SIZE = 100;
//used for seths xcode environment dont use for putty
//global change array contains list of coins used to make change

/*******METHOD 3: Dynamic Programming*****/
// m is size of coins array (number of different coins)
int changedp(int coins[], int m, int V)
{
    // table[i] will be storing the minimum number of coins
    // required for i value. So table[V] will have result
    int table[V+1];
    int result[V+1];
    //int ret[V+1];
    int count = 0;
    // Base case (If given value V is 0)
    table[0] = 0;
    
    // Initialize all table values as Infinite
    for (int i=1; i<=V; i++) {
        table[i] = INT_MAX;
        result[i]= -1;
    }
    
    // Compute minimum coins required for all
    // values from 1 to V
    for (int i=1; i<=V; i++)
    {
        // Go through all coins smaller than i
        for (int j=0; j<m; j++)
            if (coins[j] <= i)
            {
                if (table[i] > 1+table[i-coins[j]]) {
                    table[i] = 1+table[i-coins[j]];
                    result[i] = j;
                }
            }
    }
    if (result[V] == -1) {
        cout << "No output\n" << endl;
    } else  {
        int start = V;
        //std::cout << "The coins are: \n";
        while(start != 0) {
            int j = result[start];
            //cout << coins[j] << " ";
            start = start - coins[j];
        }
        // cout << "\n";
    }
    return table[V];
    //return ret;
}

// Driver program to test above functions run time
int main(int argc, char** argv)
{
    clock_t t;
    //seed random number generator
    srand (time(NULL));
    //amount we need to make change for
    int A = 100000;
    //denominations array
    int v1[10];
    //numCoins needed to make change
    int numCoins = 0;
    
    //do timing trials using 10 random denominations  to make change A given above
    //A=100,200,500,1000,2000,5000,10000,20000,50000,100000
        //r
        for(int i=0; i<10; i++)
        {
            //make denominations with random numbers 5 or less 
            //note that is might not be possible to make change with random denominations
            //run one trial at a time and collect points for A values commented above
            v1[i] = rand() % 5;
        }
        t = clock();
        //insert function here for timing analysis

        //get amount we need to make change for
        /******** ALGORITHM 1 Brute Force or Divide and Conquer *******/
        /*
         *
         */
        //
        
        /******** ALGORITHM 2 Greedy Method *******/
        /*
         *
         */
        //
        
        
        /*******METHOD 3: Dynamic Programming*****/
        numCoins = changedp(v1, 10, A);
    
        //end timing
        t = clock() - t;
        //print time to make change
        std::cout<<((float)t)/CLOCKS_PER_SEC<<"\n";
    
    return 0;
}

