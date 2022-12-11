#include <bits/stdc++.h>
using namespace std;

int p[200005];
int r[200005];


void init_dsu(){
    for(int i = 0; i <= 200005; i++){
        p[i] = i;
        r[i] = i;
    }
}

int find(int v){
    if(p[v] == v) return v;
    else {
       return p[v] = find(p[v]);
    }
}


bool merge(int a, int b){
    int root_a = find(a);
    int root_b = find(b);
    if(root_a == root_b) return true;
    else{
        if(r[root_a] < r[root_b]){
            p[root_a] = root_b;
        }
        else if(r[root_b] < r[root_a]){
            p[root_b] = root_a;
        }
        else{
            p[root_a] = root_b;
            r[root_b]++;
        }
        return false;
    }
}


vector<int> g[200005];
vector<int> answer;
int cnt;

int main(){
    int n, m;
    cnt = 0;
    init_dsu();
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i = n; i > 1; i--){
        cnt++;
        for(int j = 0; j < g[i].size(); j++){
            if(g[i][j] > i && find(i) != find(g[i][j])){
                cnt--;
                merge(i, g[i][j]);
            }
        }
        answer.push_back(cnt);
    }

    reverse(answer.begin(), answer.end());
    for(auto i: answer){
        cout << i << endl;
    }
    cout << 0 << endl;
}