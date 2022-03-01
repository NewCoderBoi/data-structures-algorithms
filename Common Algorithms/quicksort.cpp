#include<iostream>
using namespace std;

int partitioning(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l-1;
    int j = l;

    for(;j<r;j++){
        if(arr[j]<pivot){
            i++; //Doubt
            /*arr[i] = arr[i]+arr[j];
            arr[j] = arr[i]-arr[j];
            arr[i] = arr[i]-arr[j];*/
            swap(arr[i],arr[j]);

        }
    }
    /*arr[i+1] = arr[i+1]+arr[r];
    arr[r] = arr[i+1] - arr[r];
    arr[i+1] = arr[i+1] - arr[r];*/

    swap(arr[i+1],arr[r]);
    return i+1;
}

void quicksort(int arr[], int l, int r)
{
    if(l<r){
        int pivot_index = partitioning(arr, l, r);
        quicksort(arr,l,pivot_index-1);
        quicksort(arr,pivot_index+1,r);
    }
}

int main()
{
    int arr[] = {4,8,3,7,7,5,9};
    quicksort(arr,0,6);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<' ';
    }
}
