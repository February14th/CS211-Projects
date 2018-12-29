#include <iostream>
using namespace std;

void backtrack(int &c);
void print(int b[]);
bool check(int b[], int c);

int solution;

int main(){
  int n;
  n = 8; //told to test program with n = 8
  
  for (int i = 1; i <= n; i++){ //for loop because need to calculate every <= n queens before actual n queens too
    int *b = new int[i]; // was int b[8]
    b[0] = 0;
    int c = 1;
    
    solution = -1; //moved into for loop so its a new value every loop instead of piling onto the global variable
    
    bool reset = true;
    
    while(true){
      while(c < i){ //changed every 8 that appears to i instead
        if(reset == true) b[c] = -1;
			  reset = false;
			
			  while (b[c] < i){
				  b[c]++;
				
				  if(b[c] == i){
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
			  if (c == -1) break; //moved from backtrack function
      }
      solution++;
      backtrack(c);
		  reset = false;
		  if (c <= -1) break;
    }
    delete []b;
    cout << "There are " << solution << " solutions to the " << i << " queens problem." << endl;
  }
}

void backtrack(int &c){
	c--;
}

bool check(int b[], int c){
	for(int i = 0; i < c; i++){
		if((b[c] == b[i]) || ((c - i) == (b[c] - b[i])) || ((c - i) == (b[i] - b[c]))) return false;
	}
	return true;
}