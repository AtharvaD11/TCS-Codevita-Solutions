#include <bits/stdc++.h>
using namespace std;
const int N = 25;
const int M = 25;
int vis[N][M];
int mat[N][M];

int mini = INT_MAX;

void solve(int sum, int x, int y, int m, int n){
	if(vis[x][y]) return;
	if(x == 0 || y == 0 || x == m-1 || y == n-1){
		mini = min(mini, sum);
		return;
	}
	vis[x][y]= 1;
	if(sum + mat[x-1][y] < mini) solve(sum + mat[x-1][y], x-1, y, m,n);
	if(sum + mat[x-1][y+1] < mini)solve(sum + mat[x-1][y+1], x-1, y+1, m,n);
	if(sum + mat[x][y+1] < mini)solve(sum + mat[x][y+1], x, y+1, m,n);
	if(sum + mat[x+1][y+1] < mini)solve(sum + mat[x+1][y+1], x+1, y+1, m,n);
	if(sum + mat[x+1][y] < mini)solve(sum + mat[x+1][y], x+1, y, m,n);
	if(sum + mat[x+1][y-1] < mini)solve(sum + mat[x+1][y-1], x+1, y-1, m,n);
	if(sum + mat[x][y-1] < mini)solve(sum + mat[x][y-1], x, y-1, m,n);
	if(sum + mat[x-1][y-1] < mini)solve(sum + mat[x-1][y-1], x-1, y-1, m,n);
	vis[x][y] = 0;
}

int main(){
	int m,n;
	cin >> m >> n;
	int x = -1, y = -1;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin >> mat[i][j];
			if(mat[i][j] == 0){
				x = i,y=j;
			}
		}
	}
	// cout << x << " " << y << endl;
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		cout << mat[i][j];
	// 	}
	// 	cout << endl;
	// }
	solve(0,x,y,m,n);
	cout << mini << endl;


}
