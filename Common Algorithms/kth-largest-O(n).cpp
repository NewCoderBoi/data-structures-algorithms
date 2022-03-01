#include<iostream>
using namespace std;

int partitioning(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i=l-1;
    int j = l;

    for(;j<r;j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}

int kthlargest(int arr[], int n, int k)
{
    int l=0, r=n-1;
    while(l<=r){
        int pivot_index = partitioning(arr,l,r);
        if(pivot_index == n-k) return arr[pivot_index];
        else if(pivot_index < n-k){
            l = pivot_index + 1;
        }
        else if(pivot_index > n-k){
            r = pivot_index - 1;
        }
    }
}

int main()
{
    int arr[] = {6,5,8,2,3,5,9};
    int n=7,k=3;
    cout<<kthlargest(arr,n,k)<<'\n';
}
