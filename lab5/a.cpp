#include <bits/stdc++.h>
using namespace std;
long long sum;
class Heap{
    long long size;
    long long a[100005];

public: 
    Heap(){
        size=0;
        a[0]=INT_MAX;
    }

    long long parent(long long i){
        return i/2;
    }

    int left(long long i){
        return i*2;
    }

    long long right(long long i){
        return i*2+1;
    }

    void insert(long long val){
        size++;
        a[size]=val;
        sift_up(size);
    }

    void sift_up(long long i){
        while(i>1 && a[parent(i)]>a[i]){
            swap(a[parent(i)], a[i]);
            i=parent(i);
        }
    }

    void sift_down(long long i){
        long long l=left(i);
        long long r=right(i);
        long long childMin = left(i);
        if(l>size) return;
        if(r<=size){
            if(a[r]<a[l]) childMin = r;
        }
        if(a[i]>a[childMin]){
            swap(a[i], a[childMin]);
            sift_down(childMin);
        }
    }
    long long ExtractMin(){
        long long  ans  = a[1];
        swap(a[1], a[size]);
        size--;
        sift_down(1);
        return ans; 
    }

    void print(){
        for(long long i=1; i<=size; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    long long sz(){

        return size;
    } 
};
int main(){
    Heap h;
    long long n;
    cin >> n;
    for(long long i=0; i<n; i++){
        long long x;
        cin >> x;
        h.insert(x);
    }
    
    while(h.sz()>1){
        long long min1, min2;
        min1 = h.ExtractMin();
        min2=h.ExtractMin();
        sum+=min2+min1;
        h.insert(min1+min2);
        // cout <<min1+min2<<endl;

    }
      cout <<sum<<endl;
    
    
    // cout << h.ExtractMin() << endl;
    // h.print();
}