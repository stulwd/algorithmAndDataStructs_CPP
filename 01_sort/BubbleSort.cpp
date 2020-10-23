#include "BubbleSort.h"

BubbleSort::BubbleSort(/* args */)
{
}

BubbleSort::~BubbleSort()
{
}

bool BubbleSort::greater(Comparable* tar1, Comparable* tar2){
    return tar1->compare(tar2);
}

void BubbleSort::exch(Comparable* (arr[]), int i, int j){
    Comparable* tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void BubbleSort::sort(Comparable* (arr[]), int length){
    for(int i = length-1; i >= 1; i--){
        for(int j = 0; j <= i-1; j++){
            if(BubbleSort::greater(arr[j], arr[i])){
                exch(arr, i, j);
            }
        }
    }
}
