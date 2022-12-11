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
    vector<int> v;
    int index=0;
    int arr[n];
    for(int i=0; i<n; i++){
        string s; cin >>s;
        int day= (s[0]-'0')*10+ s[1]-'0';
        int month = (s[3]-'0')*10 +s[4]-'0';
        int year = (s[6]-'0')*1000+(s[7]-'0')*100+(s[8]-'0')*10+s[9]-'0';
        int date = 0;
        date+=year*1000+month*70+day;
        arr[i]=date;
        // v.push_back(date);
        // cout << day <<" "<<month<<" "<< year<<'\n';
    }
    quickSort(arr, 0,n-1);

    for(int i=0; i<n;i++){
        int year=arr[i]/1000;
        arr[i]= arr[i]-year*1000;
        int month = arr[i]/70;
        arr[i]=arr[i]-month*70;
        if(arr[i] <10) cout <<0;
        cout << arr[i]<<"-";
        if(month <10) cout <<0;
        cout <<month<<"-";
        cout << year<<'\n';
        // cout << arr[i] <<" "<<month <<" "<< year<<'\n';
    }

} 