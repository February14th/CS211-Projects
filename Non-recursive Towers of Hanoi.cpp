#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> t[3]; //three towers A, B, C
  
  int n;
  int candidate;
  int to;
  int from;
  int move = 0; //move counts the count number
  
  cout << "Please enter an odd number of rings to move: ";
  cin >> n;
  cout << endl;
  
  //initialize the 3 towers
  for(int i = n + 1; i >= 1; i--){
    t[0].push_back(i);
  }
  t[1].push_back(n + 1);
  t[2].push_back(n + 1);
  
  //initialize towers and candidate
  from = 0;
  if((n % 2) != 0) to = 1; //moving to different towers depending on odd or even
  if((n % 2) == 0) to = 2;
  candidate = 1;
  
  while(t[1].size() < n + 1){ //there are still rings to transfer to tower B = t[1]
    t[to].push_back(t[from].back()); //move the top ring from "from" tower to "to" tower
    t[from].pop_back(); //remove the ring from the "from" tower to complete the move
    cout << "Move number " << ++move << ": Transfer ring " << candidate << " from tower " << char(from + 65) << " to tower " << char(to + 65) << endl;
    
    if((n % 2) != 0){
      //get next "from tower"
      if(t[(to + 1) % 3].back() < t[(to + 2) % 3].back())
        from = (to + 1) % 3;
      else
        from = (to + 2) % 3; //finding the tower with the smaller ring to move from
      //get next "to tower"
      if(t[from].back() < t[(from + 1) % 3].back())
        to = (from + 1) % 3;
      else
        to = (from + 2) % 3; //finding the tower with the bigger ring to move to
      //get next candidate
      candidate = (t[from].back()); // it’s on the top of the current “from tower”
    }
    
    if((n % 2) == 0){
      //get next "from tower"
      if(t[(to + 1) % 3].back() < t[(to + 2) % 3].back())
        from = (to + 1) % 3;
      else
        from = (to + 2) % 3; //finding the tower with the smaller ring to move from
      //get next "to tower"
      if(t[from].back() < t[(from + 2) % 3].back())
        to = (from + 2) % 3;
      else
        to = (from + 1) % 3; //finding the tower with the bigger ring to move to
      //get next candidate
      candidate = (t[from].back()); // it’s on the top of the current “from tower”
    }
  }
}