#include <bits/stdc++.h>
using namespace std;
#define MAX 100001 

vector<int> g[MAX], used(MAX), d(MAX);
int n, m, q;
int red = 0;
int bfs(int s, int n){
    queue<int> q;
    q.push (s);
    vector<bool> used (n);
    vector<int> ans (n), p (n);
    used[s] = true;
    ans[s] = 0;
    p[s] = -1;
    int cnt = 0;
    while (!q.empty()) {
    	int v = q.front();
    	q.pop();
    	if(d[v]){
    	    return ans[v];
    	}
    	for (size_t i=0; i<g[v].size(); ++i) {
    		int to = g[v][i];
    		if (!used[to]) {
    			used[to] = true;
    			q.push (to);
    			ans[to] = ans[v] + 1;
    			p[to] = v;
    		}
    	}
    }
    return -1;
}

int main(){
     cin >> n >> m >> q;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    while(q--){
        int a, v; cin >> a >> v;
        if(a == 1){
            d[v] = 1;
            red++;
        }else{
            if(!red) cout << -1 << endl;
            else cout << bfs(v, n) << endl;
        }
    }
}