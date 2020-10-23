#include "ShellSort.h"

ShellSort::ShellSort(/* args */)
{
}

ShellSort::~ShellSort()
{
}


bool ShellSort::greater(Comparable* tar1, Comparable* tar2){
    return tar1->compare(tar2);
}

void ShellSort::exch(Comparable* arr[], int i, int j){
    Comparable* tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void ShellSort::sort(Comparable* arr[], int length){
    int h = 1;
    while( h < length/2 ){
        h = 2*h + 1;
    }
    while(h >= 1){
        for(int i = 0; i < length; i++){
            for( int j = i; j-h >= 0; j -= h ){
                if(greater(arr[j-h], arr[j])){
                    exch(arr, j-h, j);
                }else{
                    break;
                }
            }
        }
        h /= 2;
    }
}
