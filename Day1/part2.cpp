#include <iostream>
#include <string>
#include<vector>
using namespace std;


int solve(vector<int> inputs, int w_s){
  int ans = 0;
  int w_sum = 0;
  for(int i=0; i<w_s; i++){
    if(i>=inputs.size()){
      return ans;
    }
    w_sum += inputs[i];
  }
  int i = w_s;
  while(i<inputs.size()){
    int temp = w_sum;
    w_sum -= inputs[i-w_s];
    w_sum += inputs[i];
    if(w_sum > temp){
      ans++;
    }
    i++;
  }
  return ans;
}

int main() {
  vector<int> inputs;
  string num_string;
  while(getline(cin, num_string)){
    if(num_string==""){
      break;
    }
    int i = stoi(num_string);
    inputs.push_back(i);
  }
  int ans = solve(inputs, 3);
  cout << ans << endl;
} 