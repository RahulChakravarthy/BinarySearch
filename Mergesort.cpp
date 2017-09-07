#include <iostream>
#include <Math.h>
#include "Mergesort.h"
//Practicing the Mergesort algorithm to use it in the Binary Search
//WARNING THIS IS JUST THE SOURCECODE FOR THE LIBRARY IT DOES NOT CONTAIN A MAIN METHOD
using namespace std;

/*
Understanding MergeSort:

The mergesort algorithm is the divide and conquer strategy. While BubbleSort and other linear sorting algorithms have a sort time of O(n^2) at worst case, MergeSort has a speed of O(nlogn) at worst case
Mergesort starts by partitioning the unsorted array into 2 parts (Left, Right), and it recursivly does this until there are just arrays of size 1. Since an array of size 1 is already sorted you then begin the merging sorted
arrays algorithm.

Merging sorted arrays is a 2 step process:
1) Use the upper parent level array as the array which will be overwrited with the merging of the 2 child sorted arrays
2) Replace each element in the parent level array from left to right with the corresponding value from the left element of both child arrays. That is to say, compare the value of the child arrays with eachother and select the one that is
appropriate. Once that value has been selected, iterate to the next element in the child array which had its element chosen and compare it with the same index of the otherchild array


*/

// Update 1.0: this version is only compatible with integers, update it using templates to increase its usability

//Creates merged array sorted in ascending order
int* MergeSortedAscending(int* UnsortedArray_A, int size_A, int* UnsortedArray_B, int size_B, int* concatArray, int concatArraySize){
	//create iterators for both child array A and B
	int A_iterator = 0;
	int B_iterator = 0;

	for (int i = 0; i < concatArraySize; i++){
		//Check to see if the iterators are at the max size of the respective child array
		if (A_iterator >= size_A){
			concatArray[i] = UnsortedArray_B[B_iterator];
			B_iterator++;
		}
		else if (B_iterator >= size_B){
			concatArray[i] = UnsortedArray_A[A_iterator];
			A_iterator++;
		}

		//if the element in B is less than A then element i in concat array = element in B
		else if (UnsortedArray_A[A_iterator] > UnsortedArray_B[B_iterator]){
			concatArray[i] = UnsortedArray_B[B_iterator];
			B_iterator++;
		}
		//else element in A is less than B so place that element in i'th position in concat array
		else {
			concatArray[i] = UnsortedArray_A[A_iterator];
			A_iterator++;
		}
	}
	print(UnsortedArray_A,size_A);
	print(UnsortedArray_B,size_B);
	print(concatArray, concatArraySize);
	return concatArray;
}

//Mergesort Method
int* Mergesort(int* UnsortedArray, double size){
	print(UnsortedArray,size);
	if (size == 1){
		return UnsortedArray;
	}

	//pass the first half of the array into the first argument of the MergeSorted and the 2nd half to the second argument
	return MergeSortedAscending(Mergesort(UnsortedArray, (int) size-floor(size/2)), (int) size-floor(size/2),Mergesort(UnsortedArray + (int) ceil(size/2), (int) size-ceil(size/2)), (int) size-ceil(size/2), UnsortedArray, size);
}

//Print method for debugging
void print(int* array, double size){
	for (int i = 0; i < (int)size; i++){
		cout << array[i] << " ";
	}
	cout << endl;
}
