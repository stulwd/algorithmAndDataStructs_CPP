#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "LinkList.h"
using namespace std;

//用已写好的链表实现栈

template<class T>
class stack
{
private:
    /* data */
    LinkList<T>* ll;
    int N;
public:
    stack(/* args */);
    ~stack();   
    // 重写拷贝构造
    stack(const stack<T>& o){   
        ll = new LinkList<T>();
        this->N = 0;
        this->operator=(o);
    }
    void push(T );
    T pop();
    int length();
    stack<T>& operator=(const stack<T>& o){
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
stack<T>::stack(/* args */)
{
    ll = new LinkList<T>();
    this->N = 0;
}

template<class T>
stack<T>::~stack()
{
    delete ll;
}


template<class T>
void stack<T>::push(T t){
    this->ll->insert(t, 1);
    this->N++;
}
template<class T>
T stack<T>::pop(){
    if(0 == N){
        // 这里只是返回一个T类型的默认值，不能返回空，所以只能临时创建一个。
        T t;
        return t;
    }
    this->N--;
    return this->ll->remove(1);
}

template<class T>
int stack<T>::length(){
    return this->N;
}

#endif
