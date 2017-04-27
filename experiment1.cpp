// C++ program to find minimum of coins
// to make a given change V
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<sstream>
#include<time.h>
#include<math.h>
#include<limits.h>

using namespace std;
const int MAX_ARRAY_SIZE = 100;
//used for seths xcode environment dont use for putty
//global change array contains list of coins used to make change
int change[MAX_ARRAY_SIZE] = {0};


/*******METHOD 2: Greedy Algorithm********/
int changegreedy(int coins[], int m, int V){
	int used[m+1];			//tracks actual coins used.
	int count = 0;			//tracks coin total count.
	for (int i=0;i<m+1;i++){
		used[i] = 0;		//init usage array
	}
	while (V>0){
	    for(int i=m-1; i>=0; i--){	//start at end, work back.
		if(coins[i] <= V){	//if largest, decrement. Else, skip.
		    V -= coins[i];
		    used[i] +=1;
		    count++;
		    break;		//break when valid value has been found.
		}
	    }
	}
// Uncomment this section for specific coin values.
//	for (int i=0; i<m; i++){
//		cout << used[i] << " ";
//	}
	cout << "greedy: ";
	return count;
}


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
            change[count] = coins[j];
            count++;
            start = start - coins[j];
        }
        // cout << "\n";
    }
	cout << "dp: ";
    return table[V];
    //return ret;
}

// Driver program to test above function
int main(int argc, char** argv)
{
    //amount we need to make change for
    int A = 0;
    //initialize denomination arrays
    int v1[7] = {1,2,6,12,24,48,60};
    int v2[5] = {1,5,10,25,50};
    int v3[5] = {1,6,13,37,150};
    int sizev1 = 7;
    int sizev2 = 5;
    int sizev3 = 5;
    //numCoins needed to make change
    int numCoins = 0;
    //loop through amounts to make change (1-50) with denominations v1
    cout<<"*** v1 (1-50) ***\n";
    for(int n=1; n<=50; n++)
    {
        A=n;
        //get amount we need to make change for
        /******** ALGORITHM 1 Brute Force or Divide and Conquer *******/
        /*
         *
         */
        
    
        /******** ALGORITHM 2 Greedy Method *******/
        numCoins = changegreedy(v1, sizev1, A);
	cout << numCoins << "\n"; 
        
        
        /*******METHOD 3: Dynamic Programming*****/
        numCoins = changedp(v1, sizev1, A);
        cout<<numCoins<<"\n";

    }
    
    //loop through amounts to make change (1-50) with denominations v2
    cout<<"*** v2 (1-50) ***\n";
    for(int n=1; n<=50; n++)
    {
        A=n;
        //get amount we need to make change for
        /******** ALGORITHM 1 Brute Force or Divide and Conquer *******/
        /*
         *
         */
        //
        
        /******** ALGORITHM 2 Greedy Method *******/
        numCoins = changegreedy(v2, sizev2, A);
	cout << numCoins << "\n"; 
       
        
        /*******METHOD 3: Dynamic Programming*****/
        numCoins = changedp(v2, sizev2, A);
        cout<<numCoins<<"\n";

        
    }
    //loop through amounts to make change (1-50) with denominations v3
    cout<<"*** v3 (1-50) ***\n";
    for(int n=1; n<=50; n++)
    {
        A=n;
        
        //get amount we need to make change for with each algorithm
        /******** ALGORITHM 1 Brute Force or Divide and Conquer *******/
        //numCoins = changeslow(v3, denominationsSize, A);
        //cout<<numCoins<<"\n";
        
        /******** ALGORITHM 2 Greedy Method *******/
        numCoins = changegreedy(v3, sizev3, A);
        cout<< numCoins<<"\n";
       
        
        
        /*******METHOD 3: Dynamic Programming*****/
        numCoins = changedp(v3, sizev3, A);
        cout<<numCoins<<"\n";
        
        
    }
    //loop through amounts to make change (2000-2200) with denominations v1
    cout<<"*** v1 (2000-2200) ***\n";
    for(int n=2000; n<=2200; n++)
    {
        A=n;
        //get amount we need to make change for
        /******** ALGORITHM 1 Brute Force or Divide and Conquer *******/
        /*
         *
         */
        //
        
        /******** ALGORITHM 2 Greedy Method *******/
        numCoins = changegreedy(v1, sizev1, A);
        cout<< numCoins<<"\n";
       
        
        /*******METHOD 3: Dynamic Programming*****/
        numCoins = changedp(v1, sizev1, A);
        cout<<numCoins<<"\n";
        
    }
    
    //loop through amounts to make change (2000-2200) with denominations v2
    cout<<"*** v2 (2000-2200) ***\n";
    for(int n=2000; n<=2200; n++)
    {
        A=n;
        //get amount we need to make change for
        /******** ALGORITHM 1 Brute Force or Divide and Conquer *******/
        /*
         *
         */
        //
        
        /******** ALGORITHM 2 Greedy Method *******/
        numCoins = changegreedy(v2, sizev2, A);
        cout<< numCoins<<"\n";
         
        
        /*******METHOD 3: Dynamic Programming*****/
        numCoins = changedp(v2, sizev2, A);
        cout<<numCoins<<"\n";
        
        
    }
    //loop through amounts to make change (2000-2200) with denominations v3
    cout<<"*** v3 (2000-2200) ***\n";
    for(int n=2000; n<=2200; n++)
    {
        A=n;
        
        //get amount we need to make change for with each algorithm
        /******** ALGORITHM 1 Brute Force or Divide and Conquer *******/
        //numCoins = changeslow(v3, denominationsSize, A);
        //cout<<numCoins<<"\n";
        
        /******** ALGORITHM 2 Greedy Method *******/
        numCoins = changegreedy(v3, sizev3, A);
        cout<< numCoins<<"\n";
      
        
        
        /*******METHOD 3: Dynamic Programming*****/
        numCoins = changedp(v3, sizev3, A);
        cout<<numCoins<<"\n";
        
    
        
        
    }
    return 0;
}

