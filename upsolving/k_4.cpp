#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q; cin>>n;
    deque<int> d;
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>q;
        if(q==1){
            int x; cin>>x;
            if(cnt%2==0) d.push_back(x);
            else d.push_front(x);
        }
        if(q==2) cnt++;
    }
    if(cnt%2==1){
        while(!d.empty()){
            cout<<d.back()<<" ";
            d.pop_back();
        }
    }
    else{
        while(!d.empty()){
            cout<<d.front()<<" ";
            d.pop_front();
        }
    }
}