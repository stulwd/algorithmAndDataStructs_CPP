#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "LinkList.h"
using namespace std;

//用已写好的链表实现栈

template<class T>
class queue
{
private:
    /* data */
public:
    int N;
    LinkList<T>* ll;
    queue(/* args */);
    // 重写拷贝构造
    queue(const queue<T>& o){   
        ll = new LinkList<T>();
        this->N = 0;
        this->operator=(o);
    }
    ~queue();
    void enqueue(T );
    T dequeue();
    int length();
    T get(int) const;
    // 重载operator=运算符，在对象赋值时，深拷贝
    queue<T>& operator=(const queue<T>& o){
        // 自赋值时，不要进行操作
        if(this != &o){
            this->N = o.N;
            delete ll;  // 释放掉原来的内存数据
            this->ll = new LinkList<T>( *(o.ll) );
        }
        return *this;
    }
};

template<class T>
T queue<T>::get(int index) const{
    return this->ll->get(index);
}

template<class T>
queue<T>::queue(/* args */)
{
    ll = new LinkList<T>();
    this->N = 0;
}

template<class T>
queue<T>::~queue()
{
    delete ll;
}


template<class T>
void queue<T>::enqueue(T t){
    this->ll->insert(t, 1);
    this->N++;
}
template<class T>
T queue<T>::dequeue(){
    if(0 == N){
        // 这里只是返回一个T类型的默认值，不能返回空，所以只能临时创建一个。
        T t;
        return t;
    }
    this->N--;
    return this->ll->remove(N+1);
}

template<class T>
int queue<T>::length(){
    return this->N;
}

#endif
