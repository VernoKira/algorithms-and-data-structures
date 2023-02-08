#include <bits/stdc++.h>
using namespace std;
vector <int> v;
void rev(int n){
    string s; int x;
     while (n--)
    {
       cin >>s;
       if(s=="1"){
        cin >> x;
        v.push_back(x);
       }
       if(s=="2"){
        vector<int> v2 (v.rbegin(),v.rend());

	    v.swap(v2);
        
        }
    }
    vector <int> :: iterator it;
    for(it = v.begin(); it!=v.end(); ++it){
        cout <<*it << " ";
    }
}

int main(){
    int n; cin >>n;
    rev(n);

}