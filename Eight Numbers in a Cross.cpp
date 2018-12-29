#include <iostream>
using namespace std;

int b[8] = {0};
int c = 0;
int solution = 1;

int x[8][5] = { //array for determining adjacent squares
	{-1, -1, -1, -1, -1}, //0
	{0, -1, -1, -1, -1}, //1
	{0, 1, -1, -1, -1}, //2
	{0, 2, -1, -1, -1}, //3
	{1, 2, -1, -1, -1}, //4
	{1, 2, 3, 4, -1}, //5
	{2, 3, 5, -1, -1}, //6
	{4, 5, 6, -1, -1}}; //7
	

void backtrack();
void print();
bool check(int y);
void NextInteger(); //next integer
void StartOver();


int main(){
	while (c < 8){
		NextInteger();
		for (int i = 0; i < 5; i++){
			if (x[c][i] == -1){
				c++;
				if (c == 8) print();
				break; //break out of loop early if it's already at -1
			}
			if (check(x[c][i]) == false) break;
			}
	}
}

void NextInteger(){
	b[c]++;
	if (b[c] > 8) StartOver();
}

void StartOver(){
	b[c] = 0;
	backtrack();
	NextInteger();
}

void print(){
	cout << "Solution " << solution << ": " << endl;
	cout << " " << " " << b[1] << " " << b[4] << " " << " " << endl;
	cout << b[0] << " " << b[2] << " " << b[5] << " " << b[7] << endl;
	cout << " " << " " << b[3] << " " << b[6] << " " << " " << endl;
	solution++;
	cout << endl;
	backtrack();
}

void backtrack(){
	c--;
	if (c == -1) exit(0);
}

bool check(int y){
	for (int i = 0; i < c; i++){
		if ((b[i] == b[c]) || ((b[c] - b[y]) == 1) || ((b[c] - b[y]) == -1)) return false;
	}
	return true;
}