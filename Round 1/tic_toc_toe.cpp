#include <bits/stdc++.h>
#define Fast1 ios_base::sync_with_stdio(false)
#define Fast2 cin.tie(NULL)
#define ll long long int
#define inf 1000000000000000000
using namespace std;
const int N = 100;
const ll mod = 1e9+7;
string S = "abcdefghijklmnopqrstuvwxyz";


int win__play[8][3] = {
    {0, 1, 2},
    {3, 4, 5}, 
    {6, 7, 8}, 
    {0, 3, 6}, 
    {1, 4, 7}, 
    {2, 5, 8}, 
    {0, 4, 8}, 
    {2, 4, 6}
}; 


bool is_Winner(char *board, char c){
    for (int i=0; i<8; i++)
        if (board[win__play[i][0]] == c &&
            board[win__play[i][1]] == c &&
            board[win__play[i][2]] == c )
            return true;
    return false;
}
 

bool isValid(char board[9]){
    
    int x_cnt=0, o_cnt=0;
    for (int i=0; i<9; i++)
    {
    if (board[i]=='X') x_cnt++;
    if (board[i]=='O') o_cnt++;
    }
 
  
    if (x_cnt==o_cnt || x_cnt==o_cnt+1)
    {
       
        if (is_Winner(board, 'O'))
        {
           
            if (is_Winner(board, 'X'))
                return false;
 
      
            return (x_cnt == o_cnt);
        }
 
        if (is_Winner(board, 'X') && x_cnt != o_cnt + 1)
        return false;
 
        return true;
    }
    return false;
}



void solve(){
    // freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    std::vector<string> v;
    for(int i=0;i<3;i++){
        string s;
        cin >> s;
        v.push_back(s);
    }
    // cout << v.size() << endl;
    char board[9];
    int cnt = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[cnt] = v[i][j];
            cnt++;
        }
    }
    if(isValid(board)){
        cout << "YES\n";
    }
    else cout << "NO\n";
}  

int main(){
    Fast1;
    Fast2;
    // Sieve();
    // int t;
    // cin >> t;
    // while(t--){
    //     solve();
    // }
 
    solve();
    return 0;
}
