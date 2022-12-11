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
        while(i>1 && a[parent(i)]<a[i]){
            swap(a[parent(i)], a[i]);
            i=parent(i);
        }
    }

    void sift_down(long long i){
        long long l=left(i);
        long long r=right(i);
        long long childMax = left(i);
        if(l>size) return;
        if(r<=size){
            if(a[r]>a[l]) childMax = r;
        }
        if(a[i]<a[childMax]){
            swap(a[i], a[childMax]);
            sift_down(childMax);
        }
    }

    long long ExtractMax(){
        long long ans = a[1];
        swap(a[1], a[size]);
        size--;
        sift_down(1);
        return ans;
    }

    // long long ExtractMin(){
    //     long long  ans  = a[1];
    //     swap(a[1], a[size]);
    //     size--;
    //     sift_down(1);
    //     return ans; 
    // }

    void print(){
        for(long long i=1; i<=size; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    long long sz(){

        return size;
    } 
    long long head(){
        return a[1];
    }
};
int main(){
    Heap h;
    long long n,m;
    cin >> n>>m;
    for(long long i=0; i<n; i++){
        long long x;
        cin >> x;
        h.insert(x);
    }
    
    while(m>0){
        long long max1;
        max1 = h.ExtractMax();
        // max2=h.ExtractMax();
        sum+=max1;
        h.insert(max1-1);
        // cout <<max1-max2<<endl;
        // cout <<sum<<endl;
        m--;

    }
      cout <<sum<<endl;
//    if(h.sz()==1) cout <<h.head();
    
    
    // cout << h.ExtractMax() << endl;
    // h.print();
}