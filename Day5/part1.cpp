#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include<unordered_map>
#include<map>
#include <chrono>

using namespace std;

vector<string> splitString(string s, char del){
  vector<string> o;
  string temp;
  stringstream ss(s);
  while(getline(ss, temp, del)){
    if(temp=="") continue;
    o.push_back(temp);
  }
  return o;
}

int horizontalLine(int x, int y1, int y2, map<pair<int, int>, int> &cells){
  int ans = 0;
  for(int y=min(y1, y2); y<=max(y1, y2); y++){
    int present_cell_val = cells[pair<int, int>(x,y)];
    if(present_cell_val!=-1){
      present_cell_val++;
      if(present_cell_val==2){
        present_cell_val = -1;
        ans++;
      }
      cells[pair<int,int>(x,y)] = present_cell_val;
    }
  }
  return ans;
}

int verticalLine(int y, int x1, int x2, map<pair<int, int>, int> &cells){
  int ans = 0;
  for(int x=min(x1, x2); x<=max(x1, x2); x++){
    int present_cell_val = cells[pair<int, int>(x,y)];
    if(present_cell_val!=-1){
      present_cell_val++;
      if(present_cell_val==2){
        present_cell_val = -1;
        ans++;
      }
      cells[pair<int,int>(x,y)] = present_cell_val;
    }
  }
  return ans;
}

int solve(vector<vector<int>> input){
  int ans = 0;
  map<pair<int, int>, int> cells;
  for(int i=0; i<input.size(); i++){
    if(input[i][0]==input[i][2]){
      ans += horizontalLine(input[i][0], input[i][1], input[i][3], cells);
    }else if(input[i][1]==input[i][3]){
      ans += verticalLine(input[i][1], input[i][0], input[i][2], cells);
    }
  }
return ans;
}

void input_dump(vector<vector<int>> input){
  for(int i=0; i<input.size(); i++){
    cout << "(" << input[i][0] << "," << input[i][1] << ")" << " -> (" << input[i][2] << "," << input[i][3] << ")" << endl;
  }
}

int main() {
  auto start = chrono::high_resolution_clock::now();
  string inp_line;
  vector<vector<int>> input;
  ifstream inp_s;
  bool board_start=false;
  inp_s.open("./Day5/inputfile");
  while(getline(inp_s, inp_line)){
    vector<string> cords = splitString(inp_line, ' ');
    vector<string> b_cords = splitString(cords[0], ',');
    vector<string> e_cords = splitString(cords[2], ',');
    vector<int> temp{stoi(b_cords[0]), stoi(b_cords[1]), stoi(e_cords[0]), stoi(e_cords[1])};
    input.push_back(temp);
  }
  // input_dump(input);
  cout << solve(input) << endl; 

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(end-start);
  cout << "Time taken by the program : " << duration.count() << " microseconds." << endl;
} 