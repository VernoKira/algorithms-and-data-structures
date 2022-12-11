#include <bits/stdc++.h>
using namespace std;
int n, m; 
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int mario(vector<vector<int>>& table) {
        queue<pair<int,int>> pos;
        int totalMushRoms=0,current=0,minute=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(table[i][j]!=0) totalMushRoms++;
                if(table[i][j]==2) pos.push({i,j});
            }
        }
        
        while(!pos.empty()){
            int sz=pos.size();
            current+=sz;
            while(sz--){
                int x=pos.front().first;
                int y=pos.front().second;
                pos.pop();
                for(int i=0;i<4;i++){
                    int dpos_x=x+dx[i];
                    int pos_y=y+dy[i];
                    if(pos_y<0 || dpos_x<0 || dpos_x>=m || pos_y>=n || table[dpos_x][pos_y]==0 || table[dpos_x][pos_y]==2) continue;
                    table[dpos_x][pos_y]=2;
                    pos.push({dpos_x,pos_y});
                }
            }
            if(!pos.empty()) minute++;
        }
        if(current==totalMushRoms){
            return minute;
        }
        else return -1;
    }

int main(){
    cin >> m >> n;
    vector<vector<int> > table(m, vector<int>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> table[i][j];
        }
    }
    cout << mario(table);
}