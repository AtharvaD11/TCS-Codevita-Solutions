#include <bits/stdc++.h>
using namespace std;
string S="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

void rearrangeArray(int* arr , int n){
	map<int,int> mp, vis;
	for(int i=0;i< n;i++){
		mp[arr[i]]++;
	}
	priority_queue<pair<int,int>> pq;
	for(int i=0;i<n;i++){
		int val = arr[i];
		if(mp[val] > 0 && vis[val] != 1){
			pq.push({mp[val],val});
		}
		vis[val] = 1;
	}
	vector<int> res(n);
	pair<int, int>prev = { -1, -1 };
    int l = 0;
    while (pq.size() != 0){
        pair<int,int>k = pq.top();
        pq.pop();
        res[l] = k.second;
        if (prev.first > 0){
            pq.push(prev);
        }
        k.first--;
        prev = k;
        l++;
    }
    int num = 0;
    for(int i=0;i<n;i++){
    	if(res[i] != arr[i]) num++;
    }
    cout << num/2;

}



int main(){
	string s;
	cin >> s;
	int arr[s.length()];
	for(size_t i=0;i<s.length();i++){
		if(s[i] == 'G') arr[i] = 1;
		else arr[i] = 2;
	}	
	rearrangeArray(arr, s.length());
}
