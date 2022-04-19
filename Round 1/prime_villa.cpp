#include <bits/stdc++.h>
#define Fast1 ios_base::sync_with_stdio(false)
#define Fast2 cin.tie(NULL)
#define ll long long int
#define inf 1000000000000000000
using namespace std;
const int N = 1000005;
const ll mod = 1e9+7;
string S = "abcdefghijklmnopqrstuvwxyz";

bool isLeap(int y)
{
    if (y%100 != 0 && y%4 == 0 || y %400 == 0)
        return true;
 
    return false;
}

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


void revoffsetDays(int offset, int y, int *d, int *m)
{
    int month[13] = { 0, 31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31 };
 
    if (isLeap(y))
        month[2] = 29;
 
    int i;
    for (i = 1; i <= 12; i++)
    {
        if (offset <= month[i])
            break;
        offset = offset - month[i];
    }
 
    *d = offset;
    *m = i;
}

int offsetDays(int d, int m, int y)
{
    int offset = d;
 
    switch (m - 1)
    {
    case 11:
        offset += 30;
    case 10:
        offset += 31;
    case 9:
        offset += 30;
    case 8:
        offset += 31;
    case 7:
        offset += 31;
    case 6:
        offset += 30;
    case 5:
        offset += 31;
    case 4:
        offset += 30;
    case 3:
        offset += 31;
    case 2:
        offset += 28;
    case 1:
        offset += 31;
    }
 
    if (isLeap(y) && m > 2)
        offset += 1;
 
    return offset;
}


string addDays(int d1, int m1, int y1, int x)
{
    int offset1 = offsetDays(d1, m1, y1);
    int remDays = isLeap(y1)?(366-offset1):(365-offset1);
 
    // y2 is going to store result year and
    // offset2 is going to store offset days
    // in result year.
    int y2, offset2;
    if (x <= remDays)
    {
        y2 = y1;
        offset2 = offset1 + x;
    }
 
    else
    {
        // x may store thousands of days.
        // We find correct year and offset
        // in the year.
        x -= remDays;
        y2 = y1 + 1;
        int y2days = isLeap(y2)?366:365;
        while (x >= y2days)
        {
            x -= y2days;
            y2++;
            y2days = isLeap(y2)?366:365;
        }
        offset2 = x;
    }
 
    // Find values of day and month from
    // offset of result year.
    int m2, d2;
    revoffsetDays(offset2, y2, &d2, &m2);
 	string ret = "";
 	string y = to_string(y2);
 	string m = to_string(m2);
 	string d = to_string(d2);
 	// cout << y << " " << m << " " << d << endl;
 	if(y.length() < 4){
 		for(int i=0;i<4-y.length();i++){
 			ret.push_back('0');
 		}
 	}
 	ret += y;
 	if(m.length() < 2){
 		ret.push_back('0');
 	}
 	ret += m;
 	if(d.length() < 2){
 		ret.push_back('0');
 	}
 	ret += d;
 	return ret;
    // cout << "d2 = " << d2 << ", m2 = " << m2
         // << ", y2 = " << y2;
}





string weekdayday[7] = {"Sat","Sun","Mon","Tue", "Wed","Thu","Fri"};
string zellersAlgorithm(string date){
	int year = stoi(date.substr(0,4));
    int month = stoi(date.substr(4,2));
    int day = stoi(date.substr(6,2));
   int mon;
   if(month > 2)
      mon = month; //for march to december month code is same as month
   else{
      mon = (12+month); //for Jan and Feb, month code will be 13 and 14
      year--; //decrease year for month Jan and Feb
   }
   int y = year % 100; //last two digit
   int c = year / 100; //first two digit
   int w = (day + floor((13*(mon+1))/5) + y + floor(y/4) + floor(c/4) + (5*c));
   w = w % 7;
   return weekdayday[w];
}


bool isValid(string date, string wd){
	int m = stoi(date.substr(4,2));
	// cout << m << endl;
	if((m == 2 || m == 3 || m==5 || m== 7 || m==11)&& wd == zellersAlgorithm(date)){
		return true;
	}
	return false;
}


void solve(){
    // freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    string date, weekday;
    ll n;
    cin >> date >> weekday >> n;
    string todays_day = zellersAlgorithm(date);
    if(todays_day == weekday){
    	cout << "No " << 0 << endl;
    	return;
    }
    int year = stoi(date.substr(0,4));
    int month = stoi(date.substr(4,2));
    int day = stoi(date.substr(6,2));
    string date1 = addDays(day,month,year,37) ;
    // cout << addDays(day,month,year,37)  << endl;
    // cout << isValid(date1,weekday) << endl;
    // for(auto i : primes){
    // 	cout << i <<  " ";
    // }
    // cout << endl;

    for(int i=0;i<primes.size();i++){
    	string date1 = addDays(day, month, year, primes[i]);
    	if(isValid(date1,weekday)){
    		if(primes[i] <= n){
    			cout<< "Yes " << primes[i] << endl;
    			return;
    		}
    		else{
    			cout<< "No " << primes[i] << endl;
    			return;
    		}
    	}
    }
    cout << "No " << 0 << endl;

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
