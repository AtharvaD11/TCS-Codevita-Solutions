#include <bits/stdc++.h>
#define Fast1 ios_base::sync_with_stdio(false)
#define Fast2 cin.tie(NULL)
#define ll long long int
#define inf 1000000000000000000
using namespace std;
const int N = 1000007;
const ll mod = 1e9+7;
string S = "abcdefghijklmnopqrstuvwxyz";


vector<long> primes;
void Sieve()
{
    // Create a boolean array
    // "prime[0..n]" and initialize
    // all entries it as true.
    // A value in prime[i] will
    // finally be false if i is
    // Not a prime, else true.
    bool prime[N + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= N; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }
 
    // Print all prime numbers
    for(int p=2;p<=N;p++){
    	if(prime[p]) primes.push_back(p);
    }
}


void solve(){
    // freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    int f,p1,p2;
    cin >> f >> p1 >> p2;
    double maximum_force = 0;
    for(int i=p1;i<=p2;i++){
    	for(int j=1;j+i<= p2;j++){
    		int x1 = i;
    		int x2 = j+i;
    		if(binary_search(primes.begin(),primes.end(),x1) || binary_search(primes.begin(),primes.end(),x2)){
    			continue;
    		}
    		else{
    			double force = (1.0 * x1 * x2)/ ((x2 - x1)*(x2-x1));
    			maximum_force = max(maximum_force, force);
    			if(maximum_force >=f){
    				cout << x1 << " " << x2 << endl;
    				return;
    			}
    		}
    	}
    }
    cout << "None" << endl;
}   



int main(){
    Fast1;
    Fast2;
    Sieve();
    // int t;
    // cin >> t;
    // while(t--){
    //     solve();
    // }
 
    solve();
    return 0;
}
