#include <bits/stdc++.h>
using namespace std;

void merge(int * a, int l1, int r1, int l2, int r2){
    int n1 = r1 - l1 + 1;
    int L[n1];
    for(int i = 0; i < n1; ++i){
        L[i] = a[l1 + i];
    }

    int n2 = r2 - l2 + 1;
    int R[n2];
    for(int i = 0; i < n2; ++i){
        R[i] = a[l2 + i];
    }

    int i = l1;
    int i1 = 0;
    int i2 = 0;

    while(i1 < n1 && i2 < n2){
        if(L[i1] < R[i2]){
            a[i++] = L[i1++];
        }else {
            a[i++] = R[i2++];
        }
    }
    
    //copy rest of L
    while(i1 < n1){
        a[i++] = L[i1++];
    }

    //copy rest of R
    while(i2 < n2){
        a[i++] = R[i2++];
    }

}

void msort(int * a, int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;
        msort(a, l, m);
        msort(a, m + 1, r);
        merge(a, l, m , m + 1, r);
    }
}

int main(){
   int n,m; cin >>n>>m; int a[n], arr[m];
   for(int i=0; i<n;i++){
    cin >>a[i];
   }
    msort(a, 0, n-1);
   
   for(int i=0; i<m; i++){
    cin >> arr[i];
   }
    msort(arr, 0, m-1);
   if(n > m){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(arr[i] == a[j]){
                    a[j] = 0;
                    cout << arr[i] << " ";
                    break;
                }
            }
        }
    }
    else{
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i] == arr[j]){
                    arr[j] = 0;
                    cout << a[i] << " ";
                    break;
                }
            }
        }
    }
}