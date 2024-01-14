/** 
 * Project - Eight number in a cross (Recursive)
 * I used the majority of the code from eight numbers in a cross and changed the main and move function for the recursive program.
 * */
 
#include <iostream>
using namespace std;

bool adjacentCheck (int q[], int c){ // function to check the neighbour list 
    //check to see if an adjacent square has a consecutive number
    //check to see if a number has already been placed
    //there are no more squares when its -1 that means we are done checking 
    int helperArray[8][4]={
                        {-1, -1, -1, -1}, //index 0 doesn't need to check for any other squares
                        {0, -1, -1, -1}, //index 0 is 1's square
                        {1, -1, -1, -1}, //square 2, we are checking square 1
                        {0, 1, 2, -1}, //square 3, we are checking square 0, 1, and 2
                        {1, 2, 3, -1}, //square 4, we are checking square 1, 2, and 3
                        {0, 3, 4, -1}, //square 5, we are checking square 0, 3, and 5
                        {3, 4, 5, -1}, //square 6, we are checking square 3, 4, and 5
                        {2, 4, 6, -1} //square 7, we are checking square 2, 4, and 6
        
    }; 
    //this is similiar to the row test we did in 8 queens 
    for(int i=0; i<c; i++){ //this is a test where we locate a number in cross at the index c 
        if(q[i]==q[c]) //if the array of i is equal to the array of c
        return false; //and if it is not true then we return false
    }
    
    //loop to go through the helperArray
    for(int i=0; helperArray[c][i]!=-1; i++){ 
        if(abs(q[c]-q[helperArray[c][i]])==1) return false; //if there's a error then it means they are squares with a consecutive number, therefore then the absolute value is 1
    }
    return true; //if this is valid, then move to the next square
};
 
//print the solutions in a cross shape
void printCross(int q[]){
    static int solutions=1; 
    cout << endl;
    cout << "solution -> " << solutions++ <<endl;
    cout << endl;
    cout << "  " << q[1] << " " << q[2] << endl;
    cout << q[0] << " " << q[3] << " " << q[4] << " " << q[7] << endl;
    cout << "  " << q[5] << " " << q[6] << endl;
}

void move(int q[], int c) //here we are trying to place a square in index i
{ //if we have exceeded the last square that means we have found a solution 
   if (c == 8) // if c is equal to the size of the array 8 
      printCross(q); //then we call the print function
   else 
   	for (q[c] = 1; q[c] <= 8; q[c]++) //enter the for loop to test whether or not the values assigned in the move function are valid 
      if (adjacentCheck(q, c)) //try and place a square in q[c] of c, if it is successfull
         move(q, c+1);  //then move to the next neighbour otherwise, we try the next square
}

//main function 
int main() 
{
   int q[8]; //we need 8 indexes in the array 
   move(q, 0); //call the move function with the array and the starting index which is 0
   return 0; //return when we done
}
// end of the code