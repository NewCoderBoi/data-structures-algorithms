// Problem description : 

// An array is given, and a pivot element is given. We have to rearrange the array such that it has 3 sections, from left to right ->
// 1. All elements < pivot element.
// 2. All elements == pivot element.
// 3. All elements > pivot element.

// Note: This algorithm is the basis for problems like "Sort array with 0s 1s and 2s" or "Rearrange an array with 0s and 1s", etc.

// Solution description :

// We do two traversals of the array, forward and backward. For forward traversal, when we find an element == or > pivot, we 
// traverse the rest of the array till we find an element < pivot, REMEMBER THE INDEX where we found this less than pivot element,
// then swap the two elements and continue traversing. When we find the next element > or == pivot, we start traversing FROM THE INDEX
// where the previous < pivot element was found, and then find element < pivot and swap the two. Continue till the finding < pivot
// traversal reaches end of array. 
// Then we do backward traversal, where our goal is to make all elements > pivot come to the right side. If an element is == pivot, we 
// start backward traversal from that point, finding an element > pivot, REMEMBERING THAT INDEX, and swapping. We continue the same process
// as forward traversal till we find an element < pivot. This is when we stop, because our forward traversal made sure that all elements 
// from this point on is < pivot. This completes the algorithm. The capitalized parts are important because those are what ensures 
// the algorithm is O(n) and not O(n^2).

// Time Complexity - O(n). Space Complexity - O(1).

#include<iostream>
using namespace std;

int main(){
    // Input values. Should ideally be user inputs.
    int n = 9;
    int arr[n] = {0,1,2,1,2,1,1,1,2};
    int pivot_index = 3;

    // Finding pivot element from given pivot index.
    int pivot_element = arr[pivot_index];

    // Forward traversal
    int current_index = 0;
    for(int i=0;i<n;i++){
        if(arr[i]>=pivot_element){          // We will have to swap this element with the next smaller than pivot element.

        // Finding next element smaller than pivot element.
            int j;
            for(j=current_index+1;j<n;j++){
                if(arr[j]<pivot_element){
                    break;
                }
            }
            current_index=j;
            if(current_index==n) break;         // This happens when there is no element to right that is smaller than pivot.
            swap(arr[i],arr[current_index]);
        }
        else {
            if(current_index<=i) current_index++;
        }
    }

    // Backward traversal
    current_index=n-1;
    for(int i=n-1;i>=0;i--){
        if(arr[i]<pivot_element) break;     // This signals we have entered region that has been handled by forward traversal. We can end backward traversal here.
        else if(arr[i]==pivot_element){     // We have to swap this element with previous greater than pivot element.
        // Finding previous greater than pivot element.
            bool no_change=false;
            int j;
            for(j=current_index-1;j>=0;j--){
                if(arr[j]>pivot_element){
                    break;
                }
                else if(arr[j]<pivot_element){
                    no_change=true;
                    break;
                }
            }
            current_index=j;
            if(!no_change) swap(arr[i],arr[current_index]);
            else break; // When no change is true, we have reached end of required part of array and not found an element > pivot. We can end backward traversal. 
        }
        else{
            if(current_index>=i) current_index--;
        }
    }

    // Printing new array orientation
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
}

 