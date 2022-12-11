#include <bits/stdc++.h>
using namespace std;
int BS(int x, int arr[], int n, bool left) {
    int l = 0, r = n - 1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(arr[mid] == x) return mid;
        else if(arr[mid] > x) r = mid - 1;
        else l = mid + 1;
    }
    if(left) return l;
    return r;
}

int main() {
    int n, q;
    cin >> n >> q;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);
    int l1, r1, l2, r2;

    while(q--) {
        cin >> l1 >> r1 >> l2 >> r2;
        bool inter= max(l1, l2) <= min(r1, r2);
        if(inter)
            cout << BS(max(r1, r2), arr, n, false) - BS(min(l1, l2), arr, n, true) + 1 << endl;
        else
            cout << BS(r1, arr, n, false) - BS(l1, arr, n, true) + BS(r2, arr, n, false) - BS(l2, arr, n, true) + 2 << endl;
         }
}