// merge sort algorithm

#include <iostream>

using namespace std;

void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);


void mergeSort(int arr[], int low, int high){
	if(low < high){
		int mid = (low + high) / 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}
void merge(int arr[], int low, int mid, int high){

	int leftIndex, rightIndex, arrIndex;

	int leftSize = mid - low + 1;
	int rightSize = high - mid;

	int leftArray[leftSize];
	int rightArray[rightSize];

	for(leftIndex = 0; leftIndex < leftSize; leftIndex++){
		leftArray[leftIndex] = arr[low + leftIndex];
	}

	for(rightIndex = 0; rightIndex < rightSize; rightIndex++){
		rightArray[rightIndex] = arr[mid + 1 + rightIndex];
	}

	leftIndex = 0;
	rightIndex = 0;

	arrIndex = low;

	while(leftIndex < leftSize && rightIndex < rightSize){
		if(leftArray[leftIndex] <= rightArray[rightIndex]){
			arr[arrIndex] = leftArray[leftIndex];
			leftIndex++;
		}

		else{
			arr[arrIndex] = rightArray[rightIndex];
			rightIndex++;
		}

		arrIndex++;
	}

	while(leftIndex < leftSize){
		arr[arrIndex] = leftArray[leftIndex];
		leftIndex++;
		arrIndex++;
	}

	while(rightIndex < rightSize){
		arr[arrIndex] = rightArray[rightIndex];
		rightIndex++;
		arrIndex++;
	}

}

int main(){
	int foo[] = {31, -10, 2, 0, -90, 202};
    mergeSort(foo, 0, 5);

    for(int i = 0; i < 6; i++){
        cout << foo[i] << endl;
    }
	return 0;
}
