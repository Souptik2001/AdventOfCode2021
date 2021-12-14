#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solve(vector<string> input){
  if(input.size()==0){return 0;}
  vector<int> a;
  vector<int> b;
  string first = input[0];
  int length = 0;
  for(int i=0; i<first.length(); i++){
    if(first[i]=='0'){
      a.push_back(1);
      b.push_back(0);
    }else{
      a.push_back(0);
      b.push_back(1);
    }
    length++;
  }
  for(int i=1; i<input.size(); i++){
    string present = input[i];
    for(int j=0; j<present.length(); j++){
      if(present[j]=='0'){
        a[j]++;
      }else{
        b[j]++;
      }
    }
  }
  int gammaRate = 0;
  int epsilonRate = 0;
  for(int i=0; i<length; i++){
    gammaRate = gammaRate << 1;  
    epsilonRate = epsilonRate << 1;
    if(a[i]<b[i]){
      gammaRate = gammaRate | 1;
    }else{
      epsilonRate = epsilonRate | 1;
    }
  }
  return gammaRate * epsilonRate;
}


int main() {
  string num_string;
  vector<string> inp;
  while(getline(cin, num_string)){
    if(num_string==""){
      break;
    }
    inp.push_back(num_string);
  }
  int ans = solve(inp);
  cout << ans << endl;
} 