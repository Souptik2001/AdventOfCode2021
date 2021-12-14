#include <bits/stdc++.h>
using namespace std;


int main() {
  int prev_one = INT16_MAX;
  int x = 0;
  int depth = 0;
  int aim = 0;
  string inp;
  while(getline(cin, inp)){
    if(inp==""){
      break;
    }
    stringstream ss(inp);
    string command;
    int mag;
    ss >> command;
    ss >> mag;
    if(command=="forward"){
      x += mag;
      depth += (aim * mag);
    }else if(command == "down"){
      aim += mag;
    }else if(command == "up"){
      aim -= mag;
    }
  }
  cout << x * depth << endl;
} 