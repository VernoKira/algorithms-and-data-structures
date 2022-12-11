#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string b;
    cin >> n;
    cin >> b;

    queue <int> k;
    queue <int> s;
    for(int i=0; i<n;i++){
        if(b[i]=='K') k.push(i);
        else s.push(i);

    }

    while (true){
        if(s.front() > k.front ()){
            s.pop();
            k.push(k.front()+n);
            k.pop();

        }
        if(k.front() > s.front()){
            k.pop();
            s.push(s.front()+n);
            s.pop();

        }
         if(k.empty()) {
        cout << "SAKAYANAGI";
        break;
    }
    if(s.empty()){
        cout << "KATSURAGI";
        break;
    }
    }
    // if(k.empty()) {
    //     cout << "SAKAYANAGI";
    // }
    // if(s.empty()){
    //     cout << "KATSURAGI";
    // }
}
