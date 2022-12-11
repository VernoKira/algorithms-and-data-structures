#include <bits/stdc++.h>
using namespace std;
char a[105][105];
int n, m ;
void bfs(int i, int j){
    if(i<0 || i==n || j<0 || j==m || a[i][j]=='0'){
        return;
    }

    a[i][j]='0';
    bfs(i-1,j);
    bfs(i+1,j);
    bfs(i,j-1);
    bfs(i,j+1);

}

 int main(){
    cin >>n >> m;
    
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin >> a[i][j];
        }
    }
    int cnt=0;
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            if(a[i][j]=='1'){
                cnt++;
                bfs(i, j);

            }
        }

    }
    cout << cnt;

    
    
}