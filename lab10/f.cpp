#include <bits/stdc++.h>
using namespace std;
#define MAX 100001 

int n, m, c, d;
vector<int> g[MAX];
bool used[MAX];
vector<int> comp;
bool pass = true;
 
void dfs (int v,set<int> &cmp) {
	used[v] = true;
	cmp.insert (v);
	comp.push_back (v);
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (! used[to])
			dfs (to, cmp);
	}
}
 
void find_comps() {
	for (int i=0; i<n; ++i)
		used[i] = false;
	for (int i=0; i<n; ++i)
		if (! used[i]) {
            set<int> cmp;
			comp.clear();
			cmp.clear();
			dfs (i, cmp);
			int s = cmp.size();
			cmp.insert(c);
			cmp.insert(d);
			if(cmp.size() != s){
			    pass = false;
			}else{
			    pass = true;
			}
		}
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cin >> c >> d;
    find_comps();
    if(pass){
        cout << "YES";
    }else{
        cout << "NO";
    }
}