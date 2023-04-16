#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n){
    int temp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i] < arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void printArray(int arr[], int n){
    for(int i = 0 ;  i < n; i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[5] = {42, 26, 69, 32, 48};
    bubbleSort(arr, 5);
    printArray(arr, 5);
    return 0;
}