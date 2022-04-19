// #include <bits/stdc++.h>
// using namespace std;
// string S = "abcdcdabcdababcd";

// int main(){
// 	long long n;
// 	cin >> n;
// 	if(n == 1 || n ==2 || n==4 || n == 8 || n==14){
// 		cout << 'a';
// 	}
// 	else if(n == 3 || n ==5 || n==9 || n==15) cout << 'b';
// 	else if(n == 6 || n == 10 || n==12) cout << 'c';
// 	else if(n == 7 || n ==11 || n==13) cout << 'd';
// 	else{
// 		long long base = log2(n);
// 		long long len = pow(2,base);
// 		long long mod = n%len;
// 		mod = mod%16;
// 		cout << S[mod];
// 	}
// }

#include <bits/stdc++.h>
#define Fast1 ios_base::sync_with_stdio(false)
#define Fast2 cin.tie(NULL)
#define ll long long int
#define inf 1000000000000000000
using namespace std;
// const int N = 10000007;
// const ll mod = 1e9+7;
string S = "abcdefghijklmnopqrstuvwxyz";



void solve(){
	long long p;
	cin >> p;
	if(p == 1 || p ==2 || p==4 || p == 8 || p==14){
		cout << 'a';
	}
	else if(p == 3 || p ==5 || p==9 || p==15){ 
		cout << 'b';
	}
	else if(p == 6 || p == 10 || p==12) cout << 'c';
	else if(p == 7 || p ==11 || p==13) cout << 'd';
	else{
		long long b = log2(p);
		long long l = pow(2,b);
		long long mod = p%l;
		mod = mod%16;
		cout << S[mod];
	}
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
