#include <bits/stdc++.h>
using namespace std;
#define MAX 50001

vector<int> g[MAX], used(MAX), d(MAX), p(MAX);
queue<int> q;
int cnt=0;
void bfs(int b){
    while (!q.empty()) {
	    int v = q.front(); q.pop();
	    for(int i = 0; i < g[v].size(); ++i) {
		    int to = g[v][i];
		    if (!used[to]) {
			    used[to] = true;
			    q.push(to);
			    d[to] = d[v] + 1;
			    p[to] = v;
		    }   
	    }
    }
    if (!used[b]){
	    cout << -1;
    }else{
	    for (int v = b; v !=-1; v = p[v]){
	        cnt++;
	    }
	    cout << cnt - 1;
    }
}

int main()
{
    int n; cin >> n;
    int adj[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> adj[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(adj[i][j] > 0){
                g[i + 1].push_back(j + 1);
                g[j + 1].push_back(i + 1);
            }
        }
    }
    int a, b; cin >> a >> b;
    q.push(a); used[a] = 1; p[a] = -1; d[a] = 0;
    bfs(b);
    
}