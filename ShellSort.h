#ifndef SHELL_SORT_H
#define SHELL_SORT_H

#include <iostream>
#include "Comparable.h"

class ShellSort
{
private:
    /* data */
    static bool greater(Comparable*, Comparable*);
    static void exch(Comparable* [], int, int);
public:
    ShellSort(/* args */);
    ~ShellSort();

    static void sort(Comparable* [], int);
};




#endif
