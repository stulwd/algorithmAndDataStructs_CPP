#include "MergeSort.h"

MergeSort::MergeSort(/* args */)
{
}

MergeSort::~MergeSort()
{
}

bool MergeSort::greater(Comparable* tar1, Comparable* tar2){
    return tar1->compare(tar2);
}

void MergeSort::sort(Comparable* arr[], int start, int end){
    if(end == start) return;
    int mid = (start + end)/2;
    sort(arr, start, mid);
    sort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

void MergeSort::merge(Comparable* arr[], int start, int mid, int end){
    int num = end - start + 1;
    Comparable* tmp[num];
    int p1 = start;
    int p2 = mid + 1;
    int i = 0;
    while(p1 <= mid && p2 <= end){
        if(greater(arr[p1], arr[p2])){
            tmp[i++] = arr[p2]; p2++;
        }else{
            tmp[i++] = arr[p1]; p1++;
        }
    }
    while(p1 <= mid){
        tmp[i++] = arr[p1]; p1++;
    }
    while(p2 <= end){
        tmp[i++] = arr[p2]; p2++;
    }

    for(int j = 0; j < end - start + 1; j++){
        arr[start + j] = tmp[j];
    }
}

void MergeSort::sort(Comparable* arr[], int length){
    sort(arr, 0, length-1);
}
