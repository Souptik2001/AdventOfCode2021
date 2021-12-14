#include <bits/stdc++.h>
using namespace std;


int main() {
  int prev_one = INT16_MAX;
  int x = 0;
  int y = 0;
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
    }else if(command == "down"){
      y += mag;
    }else if(command == "up"){
      y -= mag;
    }
  }
  cout << x * y << endl;
} 