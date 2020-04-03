// binary search algorithm

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(vector<int> v, int target){
    if(v.size() == 0){
        return -1;
    }

    int high = v.size() - 1;
    int low = 0;

    while(low <= high){
        // get mid index, then compare the values
        int mid = low + ((high - low) / 2);

        if(v[mid] < target){
            low = mid + 1;

        } else if(v[mid] > target){
            high = mid - 1;

        } else{
            return mid;

        }
    }

    return -1;

}

int main(){
    vector<int> vec;
    vec.push_back(-1);
    vec.push_back(0);
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(32);

    int find = binary_search(vec, 20);
    cout << find << endl;

}
