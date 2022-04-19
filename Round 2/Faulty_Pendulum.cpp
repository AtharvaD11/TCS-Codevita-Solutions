#include <bits/stdc++.h>
#define Fast1 ios_base::sync_with_stdio(false)
#define Fast2 cin.tie(NULL)
#define ll long long int
#define inf 1000000000000000000
using namespace std;
const int N = 10000007;
const ll mod = 1e9+7;
string S = "abcdefghijklmnopqrstuvwxyz";


void solve(){
	int n;
	cin >> n;
	int magnitude;
	string dir;
	cin >> magnitude >> dir; 
	int arr[n];
	for(int i=0;i<n;i++){ cin >> arr[i];}
	for(int i=0;i<n;i++){
		if(magnitude - arr[i] == 0){ cout << "Possible";return ;}
		else if(magnitude - arr[i] > 0){ magnitude -= arr[i];}
		else{ magnitude += arr[i];}
	}
	if(magnitude != 0){cout << "Not Possible"; }
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
