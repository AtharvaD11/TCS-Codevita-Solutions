#include <bits/stdc++.h>
#define Fast1 ios_base::sync_with_stdio(false)
#define Fast2 cin.tie(NULL)
#define ll long long int
#define inf 1000000000000000000
using namespace std;
const int N = 10000007;
const ll mod = 1e9+7;
string S = "abcdefghijklmnopqrstuvwxyz";


class Edge {
public:
  int src;
  int nbr;

  Edge(int src, int nbr) {
    this->src = src;
    this->nbr = nbr;
  }
};

bool iscyclic(vector<vector<Edge>> &g, vector<bool>& vis, int s){
    queue<pair<int, int>> q;
  for(Edge e : g[s]){
    q.push({s,e.nbr});
  }
  while(q.size() > 0){
    pair<int,int> p = q.front();
    q.pop();
    if(vis[p.second] == true){
        return true;
    }
    vis[p.second] = true;
    for(Edge e : g[p.second]){
        if(e.nbr != p.first){
            q.push({p.second, e.nbr});
        }
    }
  }
  return false;
}

void getcomp(vector<vector<Edge>> &g, int src, vector<bool>& vis, vector<int>& comp){
    vis[src] = true;
    comp.push_back(src);
    for(Edge e : g[src]){
        if(vis[e.nbr] == false){
            getcomp(g, e.nbr, vis, comp);
        }
    }
}

void solve(){
	string s;
	cin >> s;
	vector<string> parts;
	string e_str = "";
	for(size_t i =0;i<s.length();i++){
		if(s[i] == ',' && s[i-1] == '}'){
			parts.push_back(e_str);
			e_str.clear();
		}
		else{
			e_str.push_back(s[i]);
		}
	}
	parts.push_back(e_str);
	vector<int> ids_of_g;
	int m = 0;
	for(auto i : parts){
		string id = "";
		for(size_t j = 0;j<i.length();j++){
			if(i[j] == '.'){
				ids_of_g.push_back(stoi(id));
				m = max(stoi(id), m);
				id.clear();
				break;
			}
			else{
				id.push_back(i[j]);
			}
		}
	}
	map<int,int> mp;
	for(auto i : ids_of_g){
		mp[i]++;
	}
	for(auto i : mp){
		if(i.second > 1){
			cout << "error\n";
			return;
		}
	}

	vector<vector<Edge>> graph(m+1,vector<Edge>());
	
	for(size_t i=0;i<parts.size();i++){
		int id = ids_of_g[i];
		for(size_t j = 0;j<parts[i].length();j++){
			if(parts[i][j] == '{' && parts[i][j+1] == '}'){
				break;
			}
			string vtces = "";
			if(parts[i][j] == '{'){
			    int k = j+1;
				while(parts[i][k] != '}'){
					if(parts[i][k] == ','){
						graph[stoi(vtces)].push_back(Edge(stoi(vtces), id));
						vtces.clear();
					}
					else{
						vtces.push_back(parts[i][k]);
					}
					k++;
				}
				j = k;
			}
			if(vtces.length() > 0) graph[stoi(vtces)].push_back(Edge(stoi(vtces),id));
		}
	}
	

  	vector<vector<int>> components;
    vector<bool> visited_again(m, false);
    for(int i=1;i<=m;i++){
        if(visited_again[i] == false){
            vector<int> v;
            getcomp(graph, i, visited_again, v);
            components.push_back(v);
        }
    }
    if(components.size() == 1){
    	 vector<bool> visited(m, false);
  		for(int i=1;i<=m;i++){
    		if(visited[i] == false){
        		if(iscyclic(graph, visited, i)){
            		cout << "error"; return ;
        		}
    		}
  		}
    }

    int ans = 0;
    for(auto i : components){
    	ans = max(ans, (int)i.size());
    }
    cout << ans << endl;
 

}

int main(){
    Fast1;
    Fast2;
    // Seive();
    // int t;
    // cin >> t;
    // while(t--){
    //     solve();
    // }
 
    // solve();
    return 0;
}
