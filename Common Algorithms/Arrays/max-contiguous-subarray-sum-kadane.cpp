#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int arr[] = {50,-2,-3,7,2,-5,3,6,-8};
    int n = 9;

    //Logic starts here
    for(int i=1;i<n;i++){
        arr[i] = max(arr[i],(arr[i-1]+arr[i]));
    }
    int max_sum = INT_MIN;
    for(int i=0;i<n;i++){
        max_sum = max(max_sum,arr[i]);
    }

    cout<<max_sum<<'\n';
}
