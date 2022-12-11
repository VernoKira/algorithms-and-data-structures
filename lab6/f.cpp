#include <bits/stdc++.h>
using namespace std;

double findGPA(){
    map<string, double> m; 
    m["A+"]=4.00;
    m["A"]=3.75; m["B+"]=3.50; m["B"]=3.00; m["C+"]=2.50; m["C"]=2.00;
    m["D+"]=1.50; m["D"]=1.00; m["F"]=0;
        int x; cin >>x;
        double gpa=0,p=0;
        int sum=0;
        string mark; int ects;
        while(x--){
            cin >> mark >> ects;
            sum+= ects;
            p += m[mark]*ects;
        }
       return gpa = p/sum;    
    }

void print(pair<pair<string, string>, double> stud[], int n){
    for(int i = 0; i < n; i++){
        cout << stud[i].first.first << " " << stud[i].first.second << " " <<  fixed << setprecision(3) << stud[i].second <<endl;
    }
}


int partition(pair<pair<string, string>, double> stud[], int low, int high){
    pair<pair<string, string>, double> pivot = stud[high];
    int i = (low - 1);
    for(int j = low; j <= high - 1; j++){
        if(stud[j].second < pivot.second){
            i++;
            swap(stud[i], stud[j]);
        }
        else if(stud[j].second == pivot.second){
            if(stud[j].first.first < pivot.first.first){
                i++;
                swap(stud[i], stud[j]);
            }
            else if(stud[j].first.first == pivot.first.first){
                if(stud[j].first.second < pivot.first.second){
                    i++;
                    swap(stud[i], stud[j]);  
                }
            }
        }
    }
    swap(stud[i + 1], stud[high]);
    return (i + 1);
}


void quickSort(pair<pair<string, string>, double> stud[], int low, int high){
    if(low < high){
        int pi = partition(stud, low, high);
        quickSort(stud, low, pi - 1);
        quickSort(stud, pi + 1, high);
    }
}


int main(){
    int n; cin >> n;
    pair<pair<string, string>, double> stud[n];
    for(int i = 0; i < n; i++){
        cin >> stud[i].first.first;
        cin >> stud[i].first.second;

        stud[i].second = findGPA();
    }
    quickSort(stud, 0, n - 1);
    print(stud, n);
}