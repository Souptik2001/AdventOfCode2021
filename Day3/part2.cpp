#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solve(vector<string> input){
  if(input.size()==0){return 0;}
  int bin_length = input[0].length();
  vector<int> oxy(input.size(), 1);
  vector<int> carb(input.size(), 1);
  int o_c = input.size();
  int c_c = input.size();
  char prev_lower = '-';
  char prev_higher = '-';
  char prev_lower2 = '-';
  char prev_higher2 = '-';

  int last_bit = 0;
  int last_bit2 = 0;
  for(int i=0; i<bin_length; i++){
    int zero_count = 0;
    int one_count = 0;
    int zero_count2 = 0;
    int one_count2 = 0;
    for(int j=0; j<input.size(); j++){

      // Oxygen block
      if(oxy[j]==1 && o_c>1){
        last_bit = i;
        // Checking for prev elemination
        if(i>0 && prev_lower == input[j][i-1] ){
          // cout << i<< endl;
          oxy[j]=0;
        }

        if(oxy[j]==1){
          if(input[j][i]=='1'){
            one_count++;
          }else{
            zero_count++;
          }
        }
      }

      // Carbondioxide block
        if(carb[j]==1 && c_c>1){
        last_bit2 = i;
        // Checking for prev elemination
        if(i>0 && prev_higher2 == input[j][i-1] ){
          // cout << i<< endl;
          carb[j]=0;
        }

        if(carb[j]==1){
          if(input[j][i]=='1'){
            one_count2++;
          }else{
            zero_count2++;
          }
        }
      } 
      
    }

    // Oxygen block
    if(o_c>1){
      if(one_count<zero_count){
        prev_lower = '1';
        prev_higher = '0';
        o_c = zero_count;
      }else{
        prev_lower = '0';
        prev_higher = '1';
        o_c = one_count;
      }
    }

    // Co2 block
    if(c_c>1){
      if(one_count2<zero_count2){
        prev_lower2 = '1';
        prev_higher2 = '0';
        c_c = one_count2;
      }else{
        prev_lower2 = '0';
        prev_higher2 = '1';
        c_c = zero_count2;
      }
    }

    if(o_c==1 && c_c==1){
      break;
    }

  }
  string ans_o;
  string ans_c;

  for(int i=0; i<oxy.size(); i++){
    if(oxy[i]==1 && input[i][last_bit]!=prev_lower){
      ans_o = input[i];
      break;
    }
  }
  for(int i=0; i<carb.size(); i++){
    if(carb[i]==1 && input[i][last_bit2]!=prev_higher2){
      ans_c = input[i];
      break;
    }
  }

  int oxy_amount = 0;
  int carb_amount = 0;
  for(int i=0; i<ans_o.length(); i++){
    oxy_amount = oxy_amount << 1;
    carb_amount = carb_amount << 1;
    if(ans_o[i]=='1'){
      oxy_amount = oxy_amount | 1;
    }
    if(ans_c[i]=='1'){
      carb_amount = carb_amount | 1;
    }
  }

  return oxy_amount * carb_amount;

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