#include <bits/stdc++.h>
using namespace std;
void print(vector<char> &v, int n){
    for(int i = 0; i < n; i++){
        cout << v[i];
    }
}

int partition(vector<char> & v, int low, int high){
    char pivot = v[high];
    int i = (low - 1);
    for(int j = low; j <= high - 1; j++){
        if(v[j] < pivot){
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[high]);
    return (i + 1);
}


void quickSort(vector<char> & v, int low, int high){
    if(low < high){
        int pi = partition(v, low, high);
        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
    }
}


int main(){
    int n; cin >> n;
    string s; cin >> s;
    vector<char> vowels;
    vector<char> cons;
    for(int i = 0; i < n; i++){
        if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u'){
            vowels.push_back(s[i]);
        }
        else{
            cons.push_back(s[i]);
        }

    }
    quickSort(vowels, 0, vowels.size() - 1);
    quickSort(cons, 0, cons.size() - 1);
    print(vowels, vowels.size());
    print(cons, cons.size());
}