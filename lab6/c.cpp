#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > minAbsDiffPairs(vector<int>& arr){
    vector<vector<int> > ans;
    int n = arr.size();
 
    // Sort the array
    sort(arr.begin(), arr.end());
 
    // Stores the minimal absolute difference
    int minDiff = INT_MAX;
 
    for (int i = 0; i < n - 1; i++)
        minDiff = min(minDiff, abs(arr[i] - arr[i + 1]));
 
    for (int i = 0; i < n - 1; i++) {
        vector<int> pair;
        if (abs(arr[i] - arr[i + 1]) == minDiff) {
            pair.push_back(min(arr[i], arr[i + 1]));
            pair.push_back(max(arr[i], arr[i + 1]));
            ans.push_back(pair);
        }
    }
 
    return ans;
}

int main()
{
    vector<int> arr;
    int n; cin >>n;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        arr.push_back(x);
    }
    // int N = (sizeof arr) / (sizeof arr[0]);
    vector<vector<int> > pairs = minAbsDiffPairs(arr);

    for (auto v : pairs)
        cout << v[0] << " " << v[1]<<" ";
    return 0;
}