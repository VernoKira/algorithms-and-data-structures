#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
int used[MAX], d[MAX];
int n, m; 
int main(){
    int cnt = 0; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        d[b] = a;
        used[a]++;
    }
    for(int i = 0; i < n; i++){
        if(used[d[i + 1]] == 0){
            cnt++;
        }else if(used[d[i + 1]] < used[i + 1]){
            cnt++;
        }
    }
    cout << cnt;
}