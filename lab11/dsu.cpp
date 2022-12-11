#include <bits/stdc++.h>
using namespace std;

int p[1000000];
int r[1000000];

void init_dsu(){
    for(int i=0; i<=1000000; i++){
        p[i]=i;
    }
}
int find(int v){
    if(p[v]==v) return v;
    else {
        return p[v] = find(p[v]);
    }
}
bool merge(int a, int b){
    int root_a = find(a);
    int root_b = find(b);
    if(root_a==root_b){
        return true;
    }
    else{
        if(r[root_a]<r[root_b]){
            p[root_a]= root_b;
        }
        else if(r[root_a]>r[root_b]){
            p[root_b]=root_a;
        }
        else{
            p[root_a]=root_b;
            r[root_b]++;
        }
        return false;
    }
}

int main(){
    init_dsu();
    merge(1,5);

    

}