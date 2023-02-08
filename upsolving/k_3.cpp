#include <bits/stdc++.h>
using namespace std;
deque <int> d;
void solve (int x){
    d.push_back(x);
}
void rev(){
    reverse(d.begin(), d.end());
}

int main(){
    int n; cin >> n;
    string s; int x;
    while (n--){
        cin >> s;
        if(s=="1"){
            cin >>x;
            solve(x);
        }
        if(s=="2") rev();
    }
     for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
}