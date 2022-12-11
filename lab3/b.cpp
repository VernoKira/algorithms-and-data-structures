#include <bits/stdc++.h>
using namespace std;
bool Split(int arr[], long long mid,int n, int x){
    long long subarr = 0;
    long long curSum = 0;
    for (int i = 0; i < n; i++){
        curSum+=arr[i];
        if (curSum > mid){
            subarr++;
            curSum = arr[i];
        }
    }
    return subarr + 1 <= x;
    
}
int main(){
    int n,m;
    cin >> n >> m;
    int arr[1000001];
    long long l,r;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(arr[i] > l) l = arr[i];
        r+=arr[i];
    }
    long long res = r;
    while (l <= r){
       long long mid = l + (r-l) / 2;
       if (Split(arr,mid,n,m)){
        res = mid;
        r = mid - 1;
       }
       else l = mid + 1;
       
    }

    cout << res;
}     