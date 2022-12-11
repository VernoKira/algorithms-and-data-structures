#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> graph[100000];
bool used[100000];


int main(){
    int n;
    cin >> n;
    int a[10000];
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    
    sort(a+1, a+n+1);
    for(int i = 1; i <= n; i++){
        graph[1].push_back({i, a[i]+a[1]});
        graph[i].push_back({1, a[i]+a[1]});
    }
    int weight = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    
    q.push({0, 1});
    while(!q.empty()){
        pair<int, int> c = q.top();
        q.pop();

        int mst = c.first;
        int v = c.second;

        if(used[v]){
            continue;
        }
        used[v] = true;
        weight += mst;

        for(pair<int, int> e: graph[v]){
            int u = e.first; //вершина
            int length = e.second; // цена
            if(!used[u]){
                q.push({length, u});
            }
        }
    }

    cout << weight << endl;
}