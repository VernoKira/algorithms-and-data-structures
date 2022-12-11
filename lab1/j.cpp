#include <bits/stdc++.h>
using namespace std;
int main(){
int n ; 
string a;
deque <int> q;

while(true){
    cin >> a;
    if (a=="!") break;
    if (a=="+"){
        cin >> n;
        q.push_front(n);
    }
    if (a=="-"){
        cin >> n;
        q.push_back(n);
    }
    if(a=="*"){
        if(q.empty()) cout << "error" << endl;
        else {
            cout << q.front()+q.back() << endl;
            if(!q.empty()) q.pop_back();
            if(!q.empty()) q.pop_front();

    }

    }
}

}