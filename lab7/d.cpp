#include <bits/stdc++.h>
using namespace std;

void merge(vector<pair<double, string>> &a, int l1, int r1, int l2, int r2){
    int n1 = r1 - l1 + 1;
    vector<pair<double, string>> L(n1);
    for(int i = 0; i < n1; ++i){
        L[i] = a[l1 + i];
    }

    int n2 = r2 - l2 + 1;
    vector<pair<double, string>> R(n2);
    for(int i = 0; i < n2; ++i){
        R[i] = a[l2 + i];
    }

    int i = l1;
    int i1 = 0;
    int i2 = 0;

    while(i1 < n1 && i2 < n2){
        if(L[i1].first < R[i2].first){
            a[i++] = L[i1++];
        }
        else if(L[i1].first == R[i2].first) {
            if(L[i1].second < R[i2].second){
                a[i++] = L[i1++];
            }
            else{
                a[i++] = R[i2++];
            }
        }
        else{
            a[i++] = R[i2++];
        }
            
    }
    
    //copy rest of L
    while(i1 < n1){
        a[i++] = L[i1++];
    }

    //copy rest of R
    while(i2 < n2){
        a[i++] = R[i2++];
    }

}

void msort(vector<pair<double, string>> &a, int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;
        msort(a, l, m);
        msort(a, m + 1, r);
        merge(a, l, m , m + 1, r);
    }
}

int main(){
   int n; cin >> n;
   string first, last;
   string mark; int ects;
   vector<pair<double, string>> v;
   map<string, double> m; 
   m["A+"]=4.00;
   m["A"]=3.75; m["B+"]=3.50; m["B"]=3.00; m["C+"]=2.50; m["C"]=2.00;
   m["D+"]=1.50; m["D"]=1.00; m["F"]=0;
   while(n--){
    cin >> last >> first;
    string full = last + " " + first;
    int x; cin >>x;
    double gpa=0,p=0;
     int sum=0;

    while(x--){
        cin >> mark >> ects;
        sum+= ects;
        p +=m[mark]*ects;
    }
    gpa = p/sum;
    v.push_back(make_pair(gpa, full));
   }
    msort(v, 0, v.size()-1);

   for(auto i :v){
    cout << i.second <<" "<< fixed<<setprecision(3)<< i.first<<'\n';
   }

}