#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <iostream>
#include "Comparable.h"

class BubbleSort
{
private:
    /* data */
    static bool greater(Comparable*, Comparable*);
    static void exch(Comparable* [], int, int);
public:
    BubbleSort(/* args */);
    ~BubbleSort();

    static void sort(Comparable* [], int);
};





#endif
