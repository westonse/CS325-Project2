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
//const string path = "./";
//global change array contains list of coins used to make change
int change[MAX_ARRAY_SIZE] = {0};


void printGreedy(int coins[], int denominationsSize, int numCoins, int results[]){
	string filename2 = "./changeResults.txt";
	ofstream myfile2;

	myfile2.open (filename2.c_str(), ofstream::out | ofstream::app);
		myfile2 << "change Greedy\n";
		for (int i=0; i<denominationsSize; i++){
			myfile2 << coins[i] << " ";
		}
			myfile2 << "\n";
		for (int i=0; i<denominationsSize; i++){
		 	myfile2 << results[i] << " ";
		}
			myfile2 << "\n";
		myfile2 << numCoins << "\n";
	myfile2.close();
}


/*******METHOD 2: Greedy Algorithm********/
/*
 *    Algorithm assumes the array is already sorted.
 */
// m is size of coins array (number of different coins)
int changegreedy(int coins[], int m, int V, int results[]){
    int count = 0;			//holds total number of coins
    for (int i=0;i<m+1;i++){
	results[i] = 0;			//initialize results
    }
    while(V > 0){
	for (int i=m-1; i>=0; i--) {
	    if(coins[i] <= V){
		V -= coins[i];
		results[i] += 1;	//inc specific coin count
		count++;		//inc total count
		break;
	    }
	}
    }
    return count;
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
    int results[MAX_ARRAY_SIZE] = {0};
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
                    /******** ALGORITHM 2 Greedy Method *******/
	            numCoins = changegreedy(coins, denominationsSize, V, results);
	            printGreedy(coins, denominationsSize, numCoins, results);
                    std::fill_n(results, denominationsSize, 0);
                    /*******METHOD 3: Dynamic Programming*****/
                    
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
