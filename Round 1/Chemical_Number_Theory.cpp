#include <bits/stdc++.h>
using namespace std;
string S="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";



void fillMap(map<char,pair<int,int>> &mp){
	mp['0'] ={0,2};
	int x = 1;
	for(size_t i=1;i<S.length();i++){
		mp[S[i]] = {x,x+1};
		x++; 
	}
}


int main(){
	map<char,pair<int,int>> mp;
	fillMap(mp);
	// for(auto i : mp){
	// 	cout << i.first << " " << i.second.first << " " << i.second.second << endl;
	// }
	// cout << mp['H'].first << endl;
	vector<string> elements;
	string s;
	getline(cin,s);
	string str = "";
	for(auto i : s){
		if(i != ' '){
			str.push_back(i);
		}
		else{
			elements.push_back(str);
			str.clear();
		}
	}
	elements.push_back(str);
	 str.clear();
	map<string,int>reactivity;
	for(auto i : elements){
		int reac = 0;
		if(i.length() == (size_t) 1){
			// pair<int,int> p = mp[i];
			reac = mp[i[0]].first;
		}
		else{
			reac = mp[i[1]].first + mp[i[0]].first * mp[i[1]].second;
		}

		reactivity[i] = reac;
	}
	int n = mp.size();
	if(n == 1){
		cout << reactivity[elements[0]];
	}
	else{
		int max_gcd1 = 1;
		for(auto x : elements){
			for(auto y : elements){
				if(x != y){
					max_gcd1 = max(max_gcd1, __gcd(reactivity[x],reactivity[y]));
				}
			}
		}
		cout << max_gcd1 ;
	}


}
