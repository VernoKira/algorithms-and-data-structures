#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> graph[100000];
bool used[100000];


int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
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