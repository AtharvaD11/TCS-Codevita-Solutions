#include <bits/stdc++.h>
using namespace std;

int main(){
  map<int,int> mp;
  vector<vector<string>> board;
  for(int i=0;i<10;i++){
    vector<string>temp;
    string s;
    getline(cin,s);
    string str;
    for(size_t j=0;j<s.length();j++){
      if(s[j] !=' '){
        str.push_back(s[j]);
      }
      else{
        if(str == "End"){
          temp.push_back("100");
        }
        else if(str == "Start"){
          temp.push_back("1");
        }
        else{
          temp.push_back(str);
        }
        str.clear();
      }
    }
    temp.push_back(str);
    str.clear();
    board.push_back(temp);
  }
  string moves;
  getline(cin, moves);
  vector<int> m;
  string lol;
  for(size_t i=0;i<moves.length();i++){
    if(moves[i] != ' ') lol.push_back(moves[i]);
    else{
      m.push_back(stoi(lol));
      lol.clear();
    }
  }
  m.push_back(stoi(lol));

  for(size_t i=0;i<10;i++){
    for(size_t j=0;j<10;j++){
      if(board[i][j][0] == 'S' || board[i][j][0] == 'L'){
        if(j == 0){
          if(i%2 == 0){
            int num = stoi(board[i][j+1]) + 1;
            string to_go;
            int k= 2;
            while(board[i][j][k] != ')'){
              to_go.push_back(board[i][j][k]);
              k++;
            }
            if(to_go == "Start"){
              mp[num] = 1;
            }
            else if(to_go == "End") mp[num] = 100;
            else mp[num] = stoi(to_go);;
          }
          else{
            int num = stoi(board[i][j+1]) - 1;
            string to_go;
            int k= 2;
            while(board[i][j][k] != ')'){
              to_go.push_back(board[i][j][k]);
              k++;
            }
            if(to_go == "Start"){
              mp[num] = 1;
            }
            else if(to_go == "End") mp[num] = 100;
            else mp[num] = stoi(to_go);;

          }
        }
        else if(j == 9){
          if(i%2 == 0){
            int num = stoi(board[i][j-1]) -1;
            string to_go;
            int k= 2;
            while(board[i][j][k] != ')'){
              to_go.push_back(board[i][j][k]);
              k++;
            }
            if(to_go == "Start"){
              mp[num] = 1;
            }
            else if(to_go == "End") mp[num] = 100;
            else mp[num] = stoi(to_go);;
          }
          else{
            int num = stoi(board[i][j-1]) + 1;
             string to_go;
            int k= 2;
            while(board[i][j][k] != ')'){
              to_go.push_back(board[i][j][k]);
              k++;
            }
            if(to_go == "Start"){
              mp[num] = 1;
            }
            else if(to_go == "End") mp[num] = 100;
            else mp[num] = stoi(to_go);;
          }
        }
        else{
          if(i%2 == 0){
            int num = stoi(board[i][j-1]) - 1;
            string to_go;
            int k= 2;
            while(board[i][j][k] != ')'){
              to_go.push_back(board[i][j][k]);
              k++;
            }
            if(to_go == "Start"){
              mp[num] = 1;
            }
            else if(to_go == "End") mp[num] = 100;
            else mp[num] = stoi(to_go);;
          }
          else{
            int num = stoi(board[i][j-1]) + 1;
            string to_go;
            int k= 2;
            while(board[i][j][k] != ')'){
              to_go.push_back(board[i][j][k]);
              k++;
            }
            if(to_go == "Start"){
              mp[num] = 1;
            }
            else if(to_go == "End") mp[num] = 100;
            else mp[num] = stoi(to_go);;
          }
        }
      }
    }
  }
  // for(auto i : mp){
  //   cout << i.first << " " << i.second << endl;

  // }
  int p = 0;
  int s = 0;
  int l = 0;
  for(auto i : m){
    if(mp.find(p+i) != mp.end()){
      if(p > mp[i+p]){
        s++;
      }
      else if(p < mp[i+p]){
        l++;
      }
      p = mp[p+i];
    }
    else{
      p = p+ i;
    }
  }
  if(p == 100){
    cout << "Possible " << s << " " << l;
  }
  else {
    cout << "Not possible " << s << " " << l << " " << p;
  }
  
}
