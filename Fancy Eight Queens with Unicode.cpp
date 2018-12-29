#include <iostream>
using namespace std;

void backtrack(int &c);
void print(int b[]);
bool check(int b[], int c);

int solution = 1;

int main(){
	int b[8];
	b[0] = 0;
	int c = 1;
	
	bool reset = true;
	
	while(true){
		while(c < 8){
			if(reset == true) b[c] = -1;
			reset = false;
			
			while (b[c] < 8){
				b[c]++;
				
				if(b[c] == 8){
					reset = false;
					backtrack(c);
					break;
				}
				
				if(check(b, c) == true){
					reset = true;
					c++;
					break;
				}
			}
		}
		print(b);
		reset = false;
		backtrack(c);
	}
}

void backtrack(int &c){
	c--;
	if(c == -1) exit (0);
}

void print(int b[]){
	cout << "Solution " << solution << ": " << endl;
	int i,j,k,l;
	typedef string box[5][7];
	box bb,wb,*board[8][8];
	string z = "\u2588";
	box wq = {
	  " ", " ", " ", " ", " ", " ", " ",
	  " ", " ", " ", z, " ", " ", " ",
	  " ", " ", z, z, z, " ", " ",
	  " ", z, z, z, z, z, " ",
	  " ", " ", " ", " ", " ", " ", " ",
	};
	box bq = {
	  z, z, z, z, z, z, z,
	  z, z, z, " ", z, z, z,
	  z, z, " ", " ", " ", z, z,
	  z, " ", " ", " ", " ", " ", z,
	  z, z, z, z, z, z, z,
	};
	
	for(i=0;i<5;i++)
	for( j=0;j<7;j++){
	  wb[i][j]=" ";
	  bb[i][j]="\u2588";
	}
	
	for(i=0;i<8;i++)
	for(j=0;j<8;j++)
	if((i+j)%2==0){
	  if(b[i]==j){
	    board[i][j]=&wq;
	  }
	  else{
	    board[i][j]=&wb;
	  }
	}
	else{
	  if(b[i]==j){
	    board[i][j]=&bq;
	  }
	  else{
	    board[i][j]=&bb;
	  }
	}

	cout<<" ";
	for(i=0;i<7*8;i++)
	cout<<"_";
	cout<<endl;
	
	for(i=0;i<8;i++)
	for(k=0;k<5;k++){
	  cout<<" "<<"\u2502";
	  for(j=0;j<8;j++)
	  for(l=0;l<7;l++)
	  cout<<(*board[i][j])[k][l];
	  cout<<"\u2502"<<endl;
	}
	
	cout<<" ";
	for(i=0;i<7*8;i++)
	cout<<"\u2500";
	cout<<endl;

	solution++;
}

bool check(int b[], int c){
	for(int i = 0; i < c; i++){
		if((b[c] == b[i]) || ((c - i) == (b[c] - b[i])) || ((c - i) == (b[i] - b[c]))) return false;
	}
	return true;
}