#include <bits/stdc++.h>
using namespace std;
long long sum;
long long m;
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
        if(size<m){
            size++;
            a[size]=val;
            sift_up(size);
        }
        else if(a[1] <val){
                a[1] = val;
                sift_down(1);
            }
        
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

    // long long ExtractMax(){
    //     long long ans = a[1];
    //     swap(a[1], a[size]);
    //     size--;
    //     sift_down(size);
    //     return ans;
    // }

    long long ExtractMin(){
        long long  ans  = a[1];
        swap(a[1], a[size]);
        size--;
        sift_down(1);
        return ans; 
    }

    void print(){
        for(long long i=1; i<=size; i++){
            // cout << a[i] << " ";
            sum+=a[i];
        }
        cout << sum <<endl;
        sum=0;
    }
    long long sz(){

        return size;
    } 
};
int main(){
    Heap h;
    long long n;
    cin >> n>>m;
    for(long long i=0; i<n; i++){
        string s;
        cin >>s;
        if(s=="insert"){
            long long x;
            cin >> x;
            h.insert(x);
        }
        else if(s=="print"){
            if(h.sz()==0) cout << "0"<<endl;
            else h.print();
        }
        
    }
}