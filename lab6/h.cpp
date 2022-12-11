#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; 
    cin >> n;
    char arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    char a; cin >> a;
    for(int i = 0; i < n ; i++){
        if(arr[i] > a){
            cout << arr[i];
            return 0;
        }
       
    }
     cout << arr[0];
}