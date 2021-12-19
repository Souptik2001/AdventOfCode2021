#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include<unordered_map>
#include<map>
#include <chrono>

using namespace std;

vector<long> splitString(string s, char del){
  vector<long> o(9, 0);
  string temp;
  stringstream ss(s);
  while(getline(ss, temp, del)){
    if(temp=="") continue;
    long age = stoi(temp);
    o[age]++;
  }
  return o;
}

long solve(vector<long> ages){
  int len = ages.size();
  for(int i=0; i<256; i++){
    long transition_age = 0;
    for(int j=len-1; j>=0; j--){
      long temp = ages[j];
      ages[j] = transition_age;
      transition_age = temp;
    }
    ages[6] += transition_age;
    ages[8] += transition_age;
  }
  long ans = 0;
  for(int i=0; i<ages.size(); i++){
    ans += ages[i];
  }
  return ans;
}

int main() {
  auto start = chrono::high_resolution_clock::now();
  string inp_line;
  ifstream inp_s;
  bool board_start=false;
  inp_s.open("./Day6/inputfile");
  getline(inp_s, inp_line);
  vector<long> input = splitString(inp_line, ',');
  // input_dump(input);
  cout << solve(input) << endl; 

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(end-start);
  cout << "Time taken by the program : " << duration.count() << " microseconds." << endl;
} 