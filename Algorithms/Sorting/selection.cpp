// selection sort algorithm
// compile using g++ -o selection selection.cpp
// run using ./selection

#include <iostream>
#include <vector>

using namespace std;

void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

void selection_sort(vector<int> &v){
    for(int i = 0; i < v.size() - 1; i++){
        for(int j = i + 1; j < v.size(); j++){
            if(v[i] > v[j]){
                swap(v[i], v[j]);

            }
        }
    }

}

int main(){
    vector<int> vec;
    vec.push_back(-1);
    vec.push_back(-20);
    vec.push_back(0);
    vec.push_back(100);
    vec.push_back(5);
    vec.push_back(26);
    vec.push_back(-100);

    for(int i = 0; i < vec.size(); i++){
        cout << "unsorted: " << vec[i] << endl;;
    }

    selection_sort(vec);
    cout << endl << endl << endl;
    
    for(int i = 0; i < vec.size(); i++){
        cout << "sorted: " << vec[i] << endl;
    }

}
