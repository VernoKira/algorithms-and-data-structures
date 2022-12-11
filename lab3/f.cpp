#include <bits/stdc++.h>
using namespace std;
int binS(int a[], int s,int power){
    int l=0; 
    int r= s-1;
    while(l<=r){
        int mid = l+((r-l)/2);
        if(a[mid]<=power) l = mid+1;
        else r = mid-1;
    }
    return l;

}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    int numR; 
    cin >> numR;
    while(numR--){
       int sum=0;
        int power;
        cin>> power;
        int cnt = binS(a,n,power);
        for(int i=0; i<cnt; i++){
            sum+=a[i];
        }
        cout << cnt <<" " << sum<<endl;
    }

}