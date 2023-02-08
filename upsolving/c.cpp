#include <bits/stdc++.h>
using namespace std;
struct MaxHeap{
    vector<int> vec;
    int parent(int i){
        return (i - 1) / 2;
    }
    int left(int i){
        return 2 * i + 1;
    }
    int right(int i){
        return 2 * i + 2;
    }
    void insert(int x){
        vec.push_back(x);
        int i = vec.size() - 1;
        sift_up(i);
    }


    void sift_up(int i){
        while(i != 0 && vec[parent(i)] < vec[i]){
            swap(vec[parent(i)], vec[i]);
            i = parent(i);
        }
    }

    void print(){
        for(int i = 0; i < vec.size(); i++){
            cout << vec[i] << ' ';
        }
        cout << endl;
    }
    void Increase(int index, int b){
        for(int i = 0; i < vec.size(); i++){
            if(i == index){
                vec[index] += b;
            }
        }
        if(vec[index] > vec[parent(index)]){
            sift(index);
        }
        else{
            cout << index + 1 << endl;
        }
    }

    void sift(int i){
        while(i != 0 && vec[parent(i)] < vec[i]){
            swap(vec[parent(i)], vec[i]);
            i = parent(i);
        }
        cout << i + 1 << endl;
    }

};


int main(){
    MaxHeap H;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        H.insert(x);
    }
    int m; cin >> m;
    for(int i = 0; i < m; i++){
        int index; cin >> index;
        int b; cin >> b;
        H.Increase(index - 1, b);
    }
    H.print();
}