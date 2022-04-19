#include <bits/stdc++.h>
#define Fast1 ios_base::sync_with_stdio(false)
#define Fast2 cin.tie(NULL)
#define ll long long int
#define inf 1000000000000000000
using namespace std;
// const int N = 10000007;
// const ll mod = 1e9+7;
string S = "abcdefghijklmnopqrstuvwxyz";


// Driver function to get the
// modular addition.
int add(long long a, long long b)
{
    int mod = 1e9 + 7;
    return ((a % mod) + (b % mod)) % mod;
}

// Driver function to get the
// modular multiplication.
int mul(long long a, long long b)
{
    int mod = 1e9 + 7;
    return ((a % mod) * 1LL * (b % mod)) % mod;
}

// Driver function to get the
// modular binary exponentiation.
int bin_pow(long long a, long long b)
{
    int mod = 1e9 + 7;
    a %= mod;
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * 1LL * a % mod;
        }
        a = a * 1LL * a % mod;
        b >>= 1;
    }
    return res;
}

// Driver function to get the
// modular division.
int reverse(long long x)
{
    int mod = 1e9 + 7;
    return bin_pow(x, mod - 2);
}

int numberOfPermutations(long long n, long long k)
{

    // Updating 'k' with 'n - k'.
    k = n - k;

    // Initializing the 'ans' by 1.
    int ans = 1;

    // Condition when 'k' is 1.
    if (k == 0 or k == 1) {
        return ans;
    }

    // Adding derangement for 'k' = 2.
    ans += mul(mul(n, n - 1), reverse(2));

    // Condition when 'k' is 2.
    if (k == 2) {
        return ans;
    }

    // Adding derangement for 'k' = 3.
    ans += mul(mul(n, mul(n - 1, n - 2)),
            reverse(3));

    // Condition when 'k' is 3.
    if (k == 3) {
        return ans;
    }

    // Adding derangement for 'k' = 4.
    int u = mul(n, mul(n - 1, mul(n - 2,
                                n - 3)));
    ans = add(ans, mul(u, reverse(8)));
    ans = add(ans, mul(u, reverse(4)));

    return ans;
}

// Driver Code
int main()
{
    long long n;
    cin >> n;
    long long K = 1;

    cout << numberOfPermutations(n, K);
    return 0;
}


// int main(){
//     Fast1;
//     Fast2;
//     // Seive();
//     // size_tt;
//     // cin >> t;
//     // while(t--){
//     //     solve();
//     // }
 
//     solve();
//     return 0;
// }
