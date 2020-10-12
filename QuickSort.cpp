#include "QuickSort.h"

void QuickSort::exch(Comparable* arr[], int i, int j){
    Comparable* tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void QuickSort::sort(Comparable* arr[], int start, int end){
    if(start >= end) return;
    int mid = division(arr, start, end);
    sort(arr, start, mid-1);
    sort(arr, mid+1, end);
}

int QuickSort::division(Comparable* arr[], int start, int end){
    int p1 = start + 1;
    int p2 = end;
    while(true){
        while(!greater(arr[p1], arr[start])){
            p1++;
            if(p1 > end){
                break;
            }
        }
        while(greater(arr[p2], arr[start])){
            p2--;
            if(p2 < start + 1){
                break;
            }
        }
        if(p1 > p2) break;
        exch(arr, p1, p2);
    }
    exch(arr, start, p2);
    return p2;
}

bool QuickSort::greater(Comparable* tar1, Comparable* tar2){
    return tar1->compare(tar2);
}

void QuickSort::sort(Comparable* arr[], int length){
    sort(arr, 0, length-1);
}


QuickSort::QuickSort(/* args */)
{
}

QuickSort::~QuickSort()
{
}
