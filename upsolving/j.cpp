#include <bits/stdc++.h>
using namespace std;
void BS(int arr[], int x, int size){
    for(int i=0; i<size; i++){
        int val = x - arr[i];

        int l=0;
        int r = size -1;

        while(l<=r){
            int mid = l+(r-l)/2;
            if(arr[mid]==val){
                if(arr[i]< val) cout <<arr[i] << " " <<val;
                else cout << val<< " " <<arr[i];
                return;
            }
            if(arr[mid] < val) l = mid+1;
            else r=mid-1;

        }
    }

}


int main(){
    int x, n;
    cin >> x >>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    BS(arr, x, n);
    
}