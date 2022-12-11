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
    int n,m; cin >> n>>m;
    int a[n];
    int b[m];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    quickSort(a, 0, n - 1);

    for(int j=0;j<m;j++){
        cin >> b[j];
    }
    quickSort(b,0,m-1);
    vector<int> v(n+m);
    vector<int> :: iterator it,s;
    it = set_intersection(a,a+n,b,b+m,v.begin());
    for(s = v.begin(); s!=it; s++){
        cout << *s<<" ";
    }
    
    // print(a, n);
} 