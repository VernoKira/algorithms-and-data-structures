#include <bits/stdc++.h>

using namespace std;

class Heap{
    int a[100005];
    int size;
    public:
        Heap(){
            a[0] = INT_MAX;
            size = 0;
        }
        
        int parent(int i){
            return i / 2;
        }
        
        int left(int i){
            return 2 * i;
        }
        
        int right(int i){
            return 2 * i + 1;
        }
        
        void insert(int val){
            size++;
            a[size] = val;
            shift_up(size);
        }
        
        int shift_up(int i){
            while(i > 1 && a[parent(i)] < a[i]){
                swap(a[i], a[parent(i)]);
                i = parent(i);
            }
            return i;
        }
        
        int compare(int i){
            int lx = left(i), rx = right(i), cnt = 0;
            while(lx < size){
                if(a[lx] < a[rx]) cnt++;
                i++;
                lx = left(i), rx = right(i);
            }
            return cnt;
        }
        
        
};

int main()
{
    Heap heap;
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        heap.insert(x);
    }
    cout << heap.compare(1);
    
}