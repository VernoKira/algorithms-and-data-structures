#include <bits/stdc++.h>
using namespace std;

int binS(int a[],int n, int h){
    int l=1;
    int r=a[n-1];
  
    while(l<r){
        int sum=0;
        int mid = l+((r-l)/2);
          for(int i=0; i<n; i++){
          sum += ceil(1.0 * a[i]/mid);   
        }
        
        if(sum > h) l = mid+1;
        else r = mid;
        
    }
    
    return l;
}

int main(){
    int n; cin >> n;
    int a[n];
    int h; cin >>h;

    for(int i=0; i<n;i++){
        cin >> a[i];
    }
    sort(a, a+n);

    cout << binS(a,n,h);


}