#include <iostream>
#include <string>
using namespace std;


int main() {
  int prev_one = INT16_MAX;
  int ans=0;
  string num_string;
  while(getline(cin, num_string)){
    if(num_string==""){
      break;
    }
    int i = stoi(num_string);
    if(i>prev_one){ans++;}
    prev_one = i;
  }
  cout << ans << endl;
} 