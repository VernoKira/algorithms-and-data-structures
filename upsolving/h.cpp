#include <bits/stdc++.h>
using namespace std;
class Heap{
    int size;
    int a[1000000];
    public:
        Heap(){
            size = 0;
            a[0]=INT_MAX;
        }
        int parent(int i){
            return i/2;
        }
        int left(int i){
            return 2*i;
        }
        int right(int i){
            return 2*i+1;
        }

        void insert(int val){
            size++;
            a[size] = val;
            sift_up(size);
        }
        void sift_up(int i){
            while(i>1 && a[parent(i)]<a[i]){
                swap(a[i], a[parent(i)]);
                i = parent(i);
            }
        }
        
        void comparison(int i){
            int l = left(i);
            int r = right(i);
            int cnt = 0;
            while(l<size){
                if(a[l]<a[r]){
                    cnt++;
                }
                i++;
                l = left(i);
                r= right(i);
            }
            cout <<cnt;
        }

};

int main(){
    Heap h;
    int n; 
    cin >>n;
    for(int i=0; i<n;i++){
        int x; cin >>x;
        h.insert(x);
    }   
    h.comparison(1);
}
