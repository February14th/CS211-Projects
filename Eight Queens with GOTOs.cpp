#include <iostream>
using namespace std;

int main(){
	int b[8][8] = {0}; //board
	int r = 0; //row, starting at first row
	int c = 0; //column, starting at first column
	b[0][0] = 1; //placing a queen at the first spot
	
	int solution = 1; //counting different solutions
	
	nc: c++; //next column
	if (c == 8) //if there are no more columns
		goto print; //print out the result
	
	r = -1; //ensure next row is the first row
	nr: r++; //next row
	if (r == 8) //if there are no more rows
		goto backtrack; //backtrack
	
	for (int i = 0; i < c; i++){ //checking for row
		if (b[r][i] == 1)
			goto nr;
	}
	
	for (int i = 0; (r - i) >= 0 && (c - i) >= 0; i++){ //checking for diagonal, left side up
		if (b[r - i][c - i] == 1)
			goto nr;
	}
	
	for (int i = 0; (r + i) < 8 && (c - i) >= 0; i++){ //checking for diagonal, left side down 
		if (b[r + i][c - i] == 1)
			goto nr;
	}
	
	b[r][c] = 1; //if passed the checks, place a queen
	
	goto nc; //go to the next column
	
	backtrack: c--; //backtrack, going back to the last column
	r = 0; //starting back at the top
	
	while (b[r][c] != 1) //while there isn't a queen
		r++; //go to the next row
		
	b[r][c] = 0; //placing 0 for spaces
	goto nr; //next row
	
	print: //printing out the board with all the queens
	cout << "Solution " << solution << ": " << endl;
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			cout << b[i][j];
		}
		cout << endl;
	}
	solution++; //done with a solution, going to the next one
	cout << endl;
	goto backtrack; //starting over for the next solution 
}