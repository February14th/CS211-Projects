#include <iostream>
using namespace std;

int b[3][3] = {0};
int r = 0;
int c = 0;
int moves = 0;

void print();
void place(int x, int y, int player);
void p1();
void p2();

int main(){
	while (moves < 9){
		p1();
		p2();
	}
	return 0;
}

void print(){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (b[i][j] == 0) cout << "\u263A";
			if (b[i][j] == 1) cout << "X";
			if (b[i][j] == 2) cout << "O";
			cout << " ";
		}
		cout << endl;
	}
}

void place(int x, int y, int player){
  if (b[x][y] == 0){
    if (player == 1){
      b[x][y] = 1;
    }
    if (player == 2){
      b[x][y] = 2;
    }
    print();
    moves++;
  }
  else if (player == 1) {
	  cout << "This spot is already occupied." << endl;
	  p1();
  }
  else if (player == 2) {
	  cout << "This spot is already occupied." << endl;
	  p2();
  }
}

void p1(){
	cout << "Player 1, please enter a move: " << endl;
	cout << "Please enter row: " << endl;
	cin >> r;
	while ((r < 0) || (r > 2)){
		cout << "Out of bound" << endl;
		cout << "Please enter row: " << endl;
		cin >> r;
	}
	cout << "Please enter column: " << endl;
	cin >> c;
	while ((c < 0) || (c > 2)){
		cout << "Out of bound" << endl;
		cout << "Please enter column: " << endl;
		cin >> c;
	}
	place(r, c, 1);
}

void p2(){
	cout << "Player 2, please enter a move: " << endl;
	cout << "Please enter row: " << endl;
	cin >> r;
	while ((r < 0) || (r > 2)){
		cout << "Out of bound" << endl;
		cout << "Please enter row: " << endl;
		cin >> r;
	}
	cout << "Please enter column: " << endl;
	cin >> c;
	while ((c < 0) || (c > 2)){
		cout << "Out of bound" << endl;
		cout << "Please enter column: " << endl;
		cin >> c;
	}
	place(r, c, 2);
}