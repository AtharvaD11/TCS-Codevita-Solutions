#include <bits/stdc++.h>
#define Fast1 ios_base::sync_with_stdio(false)
#define Fast2 cin.tie(NULL)
#define ll long long int
#define inf 1000000000000000000
using namespace std;
const int N = 10000007;
const ll mod = 1e9+7;
string S = "abcdefghijklmnopqrstuvwxyz";
int mat[50][50];
int time_mat[50][50];
double rat_mat[50][50];

void solve(){
    int n,m;
    cin >> n >> m;
    int x,y;
    cin >> x >> y;
    int t;
    cin >> t;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int diff = abs(x-i) + abs(y-j);
            time_mat[i][j] = 2*diff + 1;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            rat_mat[i][j] = (1.0*mat[i][j]/time_mat[i][j]);
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         // rat_mat[i][j] = (1.0*mat[i][j]/time_mat[i][j]);
    //         cout << rat_mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    map<double, pair<int,int>, greater<double>> mp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mp[rat_mat[i][j]] = {mat[i][j], time_mat[i][j]};
        }
    }
    // for(auto i : mp){
    //     cout << i.first << " " << i.second.first << " " << i.second.second << endl;
    // }


    int sum = 0;
    for(auto i : mp){
        if(t == 0) break;
        if( t - i.second.second >= 0){
            t -= i.second.second;
            sum += i.second.first;
        }
    }
    cout << sum;

}


int main(){
    Fast1;
    Fast2;
    // Seive();
    // size_tt;
    // cin >> t;
    // while(t--){
    //     solve();
    // }
 
    solve();
    return 0;
}
