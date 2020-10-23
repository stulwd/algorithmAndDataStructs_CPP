#ifndef SEQENCE_LIST_H
#define SEQENCE_LIST_H

#include <iostream>
#include <string>


template <class T>
class SeqenceList
{
private:
    /* data */
    T* elems;
    int N;
public:
    SeqenceList(int );
    void clear();
    bool isEmpty();
    int length();
    const T& get(int );
    void insert(const T&);
    void insert(const T&, int);
    T remove(int i);
    int indexOf(T);
    ~SeqenceList();
};



template <class T>
SeqenceList<T>::SeqenceList(int capacity)
{
    // 开辟capacity个T类型的内存
    elems = new T[capacity];
    this->N = 0;
}

template <class T>
void SeqenceList<T>::clear(){
    N = 0;
}

template <class T>
bool SeqenceList<T>::isEmpty(){
    return N == 0;
}

template <class T>
int SeqenceList<T>::length(){
    return N;
}

template <class T>
const T& SeqenceList<T>::get(int i){
    return elems[i];
}

template <class T>
void SeqenceList<T>::insert(const T& t){
    elems[N++] = t;
}

template <class T>
void SeqenceList<T>::insert(const T& t, int i){
    for(int index = N; index >= i+1; index--){
        elems[index] = elems[index-1];
    }
    elems[i] = t;
    N++;
}

template <class T>
T SeqenceList<T>::remove(int i){
    T current = elems[i];
    N--;
    for(int index = i; index <= N-1; index++){
        elems[i] = elems[i+1];
    }
    return current;
}

template <class T>
int SeqenceList<T>::indexOf(T t){
    for(int i = 0; i < N; i++){
        if(elems[i] == t){
            return i;
        }
    }
    return -1;
}


template <class T>
SeqenceList<T>::~SeqenceList()
{
}



#endif
