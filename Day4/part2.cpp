#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include<unordered_map>
#include <chrono>

using namespace std;

vector<int> splitString(string s, char del){
  vector<int> o;
  string temp;
  stringstream ss(s);
  while(getline(ss, temp, del)){
    if(temp=="") continue;
    o.push_back(stoi(temp));
  }
  return o;
}

void print_board(vector<unordered_map<int, int>> boards, int index){
  cout << "Number of boards : " << boards.size() << endl;
  if(boards.size()<=index) return;
  unordered_map<int, int> board = boards[index];
  for(auto it = board.begin(); it!=board.end(); ++it){
    cout << it->first << " : " << it->second << endl;
  }
}


int solve(vector<int> moves, vector<unordered_map<int, int>> b1, vector<vector<int>> b2, vector<bool> board_won){
  if(moves.size()==0) return 0;
  int last_num = moves[0];
  int num_boards = board_won.size();
  for(int i=0; i<moves.size(); i++){
    last_num = moves[i];
    for(int j=0; j<b1.size(); j++){
      if( board_won[j]==false && b1[j].find(moves[i]) != b1[j].end() && b1[j][moves[i]] != -1 ){
        int index = b1[j][moves[i]];
        b1[j][moves[i]] = -1;
        int col = index % 5;
        int row = index / 5;
        b2[j][col] -= 1;
        b2[j][row+5] -=1;
        if(b2[j][col]==0 || b2[j][row+5]==0){
          // This board wins
          num_boards--;
          if(num_boards<=0) break;
          board_won[j] = true;
        }
      }
    }
    if(num_boards<=0) break;
  }
  cout << num_boards << endl;
  for(int i=0; i<board_won.size(); i++){
    if(board_won[i]==false){
      // This is the last one
      cout << i+1 << " number board is the last one to win when " << last_num << " is called" << endl;
      int unmarked_sum = 0;
      for(auto it=b1[i].begin(); it!=b1[i].end(); ++it){
        if(it->second==-1) continue;
        unmarked_sum += it->first;
      }
      return unmarked_sum * last_num;
    }
  }
  return 0; // All won - Unreachable condition
}


int main() {
  auto start = chrono::high_resolution_clock::now();
  string inp_line;
  vector<int> moves;
  // Board
  vector<bool> board_won;
  vector<unordered_map<int, int>> board1;
  vector<vector<int>> board2;
  unordered_map<int, int> temp_unit;
  vector<int> temp_count;
  int board_index = 0;
  // Board
  ifstream inp_s;
  bool board_start=false;
  inp_s.open("./Day4/inputfile");
  while(getline(inp_s, inp_line)){
    if(inp_line==""){
      if(board_start){
        board_index = 0;
        board1.push_back(temp_unit);
        board2.push_back(temp_count);
        board_won.push_back(false);
        temp_unit.clear();
        temp_count.clear();
      }
      board_start = true;
    }

    if(board_start==false){
      moves = splitString(inp_line, ',');
    }else{
      // Each row
      vector<int> vals = splitString(inp_line, ' ');
      for(int i=0; i<vals.size(); i++){
        temp_unit[vals[i]] = board_index;
        board_index++;
      }
      temp_count.push_back(5);
      temp_count.push_back(5);
    }
  }
  if(temp_unit.size()>0){
    board1.push_back(temp_unit);
    board2.push_back(temp_count);
    board_won.push_back(false);
    temp_unit.clear();
    temp_count.clear();
  }
  cout << solve(moves, board1, board2, board_won) << endl;
  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(end-start);
  cout << "Time taken by the program : " << duration.count() << " microseconds." << endl;
} 