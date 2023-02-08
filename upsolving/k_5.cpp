#include <bits/stdc++.h>>
using namespace std;
int main(){
    int n,m;
    cin >>n;
    int cnt=0;
    deque <int> d;
    while(n--){
        cin >>m;
        if(m==1){
            int x; cin >>x;
            if(cnt%2==0) {
                d.push_back(x);
            }
            else {
                d.push_front(x);
            }
        }
        if(m==2) {
            cnt++;
        }
    }
    if(cnt%2==1){
        while(!d.empty()){
            cout << d.back() <<" "<<endl;
            d.pop_back();
        }
    }
    else {
        while(!d.empty()){
            cout << d.front() << " " <<endl;
            d.pop_front();
        }
    }

}