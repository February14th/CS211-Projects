#include <iostream>
using namespace std;

int b[8][8] = {0}; //board
int r = 0;
int c = 0;
int solution = 1;

void print();
void backtrack();
void nc();
void nr();
void check();

int main(){
	b[0][0] = 1;
	nc();
}

void print(){
	cout << "Solution " << solution << ": " << endl;
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			cout << b[i][j];
			cout << " ";
		}
		cout << endl;
	}
	solution++;
	cout << endl;
	backtrack();
}

void backtrack(){
	c--;
	r = 0;
	while (b[r][c] != 1)
		r++;
	b[r][c] = 0;
	nr();
}

void nc(){
	c++;
	if (c == 8)
		print();
	r = -1;
	nr();
}

void nr(){
	r++;
	if (r == 8)
		backtrack();
	check();
}

void check(){
	for (int i = 0; i < c; i++){
		if (b[r][i] == 1)
			nr();
	}
	
	for (int i = 0; (r - i) >= 0 && (c - i) >= 0; i++){
		if (b[r - i][c - i] == 1)
			nr();
	}
	
	for (int i = 0; (r + i) < 8 && (c - i) >= 0; i++){
		if (b[r + i][c - i] == 1)
			nr();
	}
	b[r][c] = 1;
	nc();
}