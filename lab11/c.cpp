#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> graph[100000];
bool used[100000];


int main(){
    int n,m;
    cin >> n >> m;
    int big, small;
    cin >> big >> small;
    int t=min(big,small);
    
    for(int i=1; i<=m; i++){
        string type; cin >> type;
        int a, b, c;
        cin  >>a >> b >>c;
        int sum =0;
        if(type == "both"){
            sum=c*t;
        }
        else if(type == "big"){
            sum=c*big;

        }
        else if(type =="small"){
            sum=c*small;
        }
        graph[a].push_back({b,sum});
        graph[b].push_back({a,sum});
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