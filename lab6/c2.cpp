#include <bits/stdc++.h>
using namespace std;

void print(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}


int partition(int a[], int low, int high){
    int pivot = a[high];
    int i = (low - 1);
    for(int j = low; j <= high - 1; j++){
        if(a[j] < pivot){
            i++;
            swap(a[i], a[j]);
            
        }
    }
    swap(a[i + 1], a[high]);
    return (i + 1);
}


void quickSort(int a[], int low, int high){
    if(low < high){
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}


int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }   
    //sort(a,a+n);

    quickSort(a, 0, n - 1);
    // print(a, n);
    int mind=INT_MAX;
    map <pair<int, int>,int> v;
    for (int i=1; i<n;i++){
        mind = min(mind,a[i] - a[i - 1]);
        //v(make_pair({a[i - 1], a[i]}),mind));
        v[{a[i - 1], a[i]}] = a[i] - a[i - 1];
        
    }
    for(auto i : v){
        if(i.second==mind) cout << i.first.first << " "<< i.first.second<<" ";
    }

} 