#include <iostream>
using namespace std;

int solution = 1; //counting solutions

void backtrack(int &c);
void print(int q[]);
bool ok(int q[], int col);

int main(){
	int q[3] = {0};
	int c = 1;
	
	bool reset = true;
	
	while(true){
		while(c < 3){
			if(reset == true) q[c] = -1;
			reset = false;
			while(q[c] < 3){
				q[c]++;
				if(q[c] == 3){
					reset = false;
					backtrack(c);
					break;
				}
				if(ok(q, c)){
					reset = true;
					c++;
					break;
				}
			}
		}
		print(q);
		reset = false;
		backtrack(c);
	}
}

bool ok(int q[], int col){
	int mp[3][3]={0,2,1, //given
					0,2,1,
					1,2,0};
    int wp[3][3]={2,1,0, //given
					0,1,2,
					2,0,1};
	int NewMan = col;
	int NewWoman = q[col];
	
	for(int i = 0; i < col; i++){
		int CurrentMan = i;
		int CurrentWoman = q[i];
		if (CurrentWoman == NewWoman) return false; //same woman
		if ((mp[CurrentMan][NewWoman] < mp[CurrentMan][CurrentWoman]) && (wp[NewWoman][CurrentMan] < wp[NewWoman][NewMan])) return false;
		//if man thinks new woman isn't as hot as current one and the new woman thinks her own man is better anyways, man's perspective
		if ((wp[CurrentWoman][NewMan] < wp[CurrentWoman][CurrentMan]) && (mp[NewMan][CurrentWoman] < mp[NewMan][NewWoman])) return false;
		//woman's perspective, opposite of above
	}
	return true;
}

void backtrack(int &c){
	c--;
	if(c == -1) exit(0);
}

void print(int q[]){
	cout << "Solution " << solution << ": " << endl;
	for(int i = 0; i < 3; i++){
		cout << q[i] << " ";
	}
	solution++;
	cout << endl;
}