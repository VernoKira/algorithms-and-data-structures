#include <bits/stdc++.h>
using namespace std;

int binaryS(int a[], int l, int r, int t, int cnt){
    int ans = 0;
    while(l <= r){
        int m = l + (r - l) / 2;
        if(a[m] == t){
            ans = m;
            break;
        } else if(a[m] > t){
            r = m - 1;
            if(cnt == 0) ans = m;
        } else {
            l = m + 1;
            if(cnt != 0) ans = m;
        }
    }
    return ans;
}

int main(){
    int n, k; cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        a[i] = t;
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if (a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
            }
        }
    }
    for(int i = 0; i < k; i++){
        int l1, r1, l2, r2, l, r; 
        cin >> l1 >> r1 >> l2 >> r2;
        int cnt = 0;
        if(r1 > r2 && r2 >= l1 - 1 || r1 < r2 && r1 >= l2 - 1){
            l = min(l1, l2);
            r = max(r1, r2);
            cnt = binaryS(a, 0, n - 1, r, 1) - binaryS(a, 0, n - 1, l, 0) + 1;
        } else {
            if(l1 < a[n - 1] && r1 > a[0]){
             cnt = binaryS(a, 0, n - 1, r1, 1) -binaryS(a, 0, n - 1, l1, 0) + 1;
            }
            if(l2 < a[n - 1] && r2 > a[0]){
             cnt += binaryS(a, 0, n - 1, r2, 1) - binaryS(a, 0, n - 1, l2, 0) + 1;
            }
        }

        
        cout << cnt << endl;
    }

    return 0;
}