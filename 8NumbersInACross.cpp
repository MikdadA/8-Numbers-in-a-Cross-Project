/** 
 * Project - Eight number in a cross
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
    for(int i=0; i<c; i++){ 
        if(q[i]==q[c]) 
        return false; 
    }
    
    //loop to go through the helperArray
    for(int i=0; helperArray[c][i]!=-1; i++){ 
        if(abs(q[c]-q[helperArray[c][i]])==1) return false; //if there's a error then it means they are squares with a consecutive number, therefore then the absolute value is 1
    }
    return true;
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

//backtrack and try again
void btrack(int &c){
    c--; // go back 
    if(c==-1) exit(1); // if it goes below 1 that means we have found all the solution and stop the program
};

int main(){
    // initialize 
    int q[8]={1}, c=0; // to fill out the q arrays with 1's
    bool from_btrack=false; 
    while(true){ // this will keep the loop running until the btrack functions is no longer true and halts the program
        while(c<8){ // it shouldn't go beyond 7 in the box
        if(!from_btrack) //if you did not backtrack
            q[c]=0; // then reset the number to 0 
            while(q[c]<9){ 
                q[c]++; //increment it to the next number 
                if(q[c]==9){ // if a solution is found then we backtrack (btrack)
                    btrack(c);
                    continue;
                } // if the number we place is okay then 
                if(adjacentCheck(q,c)) break; //if the adjacentCheck function says the number is fine in this spot
            }
            c++; // then move to the next index
            from_btrack=false;
        }
        printCross(q); //print the solution 
        btrack(c); // do btrack to get a another solution 
        from_btrack=true; //set btrack to true because you just backtracked 
    }
return 0;
}
// end of the code