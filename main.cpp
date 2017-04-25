// C++ program to find minimum of coins
// to make a given change V
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <sstream>
#include<time.h>
#include<math.h>
#include<limits.h>
using namespace std;
const int MAX_ARRAY_SIZE = 100;
//used for seths xcode environment dont use for putty
const string path = "/Users/westonse/Library/Autosave Information/Project2/Project2/";
//global change array contains list of coins used to make change
int change[MAX_ARRAY_SIZE] = {0};

void printResults(int coins[], int denominationsSize, int numCoins, int algorithm, int count)
{
    //std::string filename2 = path + "changeResults.txt";
    string filename2 = "./changeResults.txt";
    ofstream myfile2;
    //open new file if first time making change
    if(count>1)
    {
        myfile2.open (filename2.c_str(), ios::app);
    }
    //else append
    else
    {
        myfile2.open (filename2.c_str());
    }
    //print results to file
    int results[denominationsSize];
    int curCoin = 0;
    //print appropriate algorithm
    switch(algorithm) {
        case 1 : myfile2 << "   Algorithm changeslow\n";
        case 2 : myfile2 << "   Algorithm changegreedy\n";
        case 3 : myfile2 << "   Algorithm changedp\n";
    }
    //init results to 0
    for(int k = 0; k<denominationsSize; k++)
    {
        results[k] = 0;
    }
    //create result array based on the assignment requirements
    for(int i = 0; i<numCoins; i++)
    {
        //print each denomination
        curCoin = coins[i];
        myfile2<<curCoin<<" ";
        for(int j = 0; j<denominationsSize; j++)
        {
            if(change[i] == coins[j])
            {
                results[j]++;
            }
        }
        if(i == denominationsSize-1)
        {
            myfile2<<"\n";
        }
    }
    for(int l = 0; l<denominationsSize; l++)
    {
        myfile2<<results[l]<<" ";
        if(l == denominationsSize-1)
        {
            myfile2<<"\n"<<numCoins<<"\n";
            //cout<<"\n"<<numCoins;
            std::fill_n(results, denominationsSize, 0);
        }
        

    }
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
    return table[V];
    //return ret;
}

// Driver program to test above function
int main(int argc, char** argv)
{
    //line count variable used for psuedo state machine to determine odd or even line
    int lineCount = 0;
    //amount we need to make change for
    int V = 0;
    //line of text that holds each array
    string line;
    //sum holds sum, arraySize holds size of current array
    int arrayCount=0, denominationsSize = 0;
    //initialize array to 0 values
    int coins[MAX_ARRAY_SIZE] = {0};
    //numCoins needed to make change
    int numCoins = 0;
    int count = 0;
    //open file (user inputs file name from command line)
    //string path = argv[1];
    //used for seths xcode environment
    string fileIn = argv[1];
    string filename = "./" + fileIn;
    ifstream myfile(filename.c_str());
    
    //if file is valid open it
    if(myfile)
    {
        //parse the file line by line
        while(getline(myfile,line))
        {
            //increment arrayCount to keep track of number of arrays in file
            arrayCount++;
            //convert line to a stream object
            std::stringstream stream(line);
            //parse each array to determine size
            while(1) {
                int n;
                stream >> n;
                //once size of array is found pass to coin change functions
                //if we are at end of the line increment lineCount based on "odd even" state machine
                if(!stream)
                {
                    //keeps lineCount from being 2
                    if(lineCount == 2)
                    {
                        lineCount = 0;
                    }
                    //increment line count
                    else if(lineCount == 1)
                    {
                        lineCount++;
                    }
                    //break loop to not write over denominations array
                    else
                    {
                        lineCount++;
                        break;
                    }
                }
                //if we are on an even line then add to array
                if(lineCount==0)
                {
                    coins[denominationsSize] = n;
                    denominationsSize++;
                    
                }
                //else if we are on an odd line then get the amount we need to make change for
                //and run each algorithm on the input.
                else if (lineCount==1)
                {
                    //increment count for each time making change
                    count++;
                    //get amount we need to make change for
                    V=n;
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
                    numCoins = changedp(coins, denominationsSize, V);
                    printResults(coins,denominationsSize,numCoins,3,count);
                    
                    //reset variables for loop
                    numCoins = 0;
                    std::fill_n(coins, denominationsSize, 0);
                    denominationsSize = 0;
                    V=0;
                    lineCount = 0;
                    break;
                }
            }
            
        }
    }
    else
    {
        myfile.close();
        cout<<"File not valid exiting program\n";
        return -1;
    }
    //close the file
    myfile.close();
    

    

    return 0;


    
}
