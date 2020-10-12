#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <iostream>
#include "Comparable.h"

class QuickSort
{
private:
    /* data */
    static void exch(Comparable* [], int, int);
    static void sort(Comparable* [], int, int);
    static int division(Comparable *[], int, int);
    static bool greater(Comparable*, Comparable*);
public:
    QuickSort(/* args */);
    ~QuickSort();
    static void sort(Comparable* [], int );
};



#endif
