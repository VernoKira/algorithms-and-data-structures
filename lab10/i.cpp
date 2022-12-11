#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
vector<int> g[MAX], path;
bool imposs = false;
int used[MAX];
int n, m;
void dfs(int v){
	used[v] = 1;
	for (vector<int>::iterator i=g[v].begin(); i!=g[v].end(); ++i){
	    if (used[*i] == 0) {
            dfs (*i);
        }
		if (used[*i] == 1){
           imposs = true; 
        } 
	}
	used[v] = 2;
    path.push_back(v);
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
    }

    for(int i = 1; i <= n; i++){
        if(used[i] == 0){
           dfs(i); 
        }
    }

    if(imposs){
        cout << "Impossible" << '\n';
    }else{
        cout << "Possible" << '\n';
        reverse(path.begin(), path.end());
        for(int i = 0; i < path.size(); i++){
            cout << path[i] << ' ';
        }
    }
}