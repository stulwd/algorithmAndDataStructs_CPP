#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <iostream>
#include "Comparable.h"

using namespace std;

class MergeSort
{
private:
    /* data */
    static bool greater(Comparable* , Comparable* );
    static void sort(Comparable* [], int, int );
    static void merge(Comparable *[], int, int, int);
public:
    MergeSort(/* args */);
    ~MergeSort();
    static void sort(Comparable* [], int );
};


#endif
