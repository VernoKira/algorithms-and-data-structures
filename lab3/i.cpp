#include <bits/stdc++.h> 
 
using namespace std; 
 
int main() { 
 
    int n; 
    cin >> n; 
    vector<int> nums(n); 
    for(int i = 0 ; i < n; i++) { 
        cin >> nums[i]; 
    } 
 
    int x; 
    cin >> x; 
    int l = 0, r = n; 
    while(l + 1 < r) { 
        int mid = (l+r)/2; 
        if(nums[mid] <= x) 
            l = mid; 
        else 
            r = mid; 
    } 
     if (nums[l] == x) cout << "Yes";
     else cout << "No"; 
    return 0; 
}