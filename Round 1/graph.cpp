#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> p1, pair<int,int> p2){
	return p1.second > p2.second ;
}

size_tmain(){
	size_tn;
	cin >> n;
	map<int,int> freq;
	size_tm;
	cin >> m;
	vector<pair<int,int>> edges;
	for(size_ti=0;i<m;i++){
		size_tn1,n2;
		cin>> n1 >> n2;
		freq[n1]++;
		freq[n2]++;
		edges.push_back({n1,n2});
	}
	size_tweights[n];
	for(size_ti=0;i<n;i++){
		cin >> weights[i];
	}
	sort(weights,weights+n,greater<int>());
	vector<pair<int,int>> node_freq;
	for(auto i : freq){
		node_freq.push_back({i.first, i.second});
	}
	sort(node_freq.begin(), node_freq.end(),cmp);
	
	map<int,int> node_wt;
	for(size_ti=0;i<n;i++){
		node_wt[node_freq[i].first] = weights[i];
	}
	// for(auto i : node_wt ){
	// 	cout << i.first << " " << i.second << endl;
	// }

	size_tsum = 0;
	for(auto i : edges){
		sum += (node_wt[i.first] + node_wt[i.second]);
	}
	cout << sum ;


}
