#ifndef LINK_LIST_H
#define LINK_LIST_H

#include <iostream>

/**
 * 链表的节点类
 * */
template<class T>
class node
{
private:
    /* data */
public:
    T _t;
    node* _next;
    node(T, node*);
    ~node();
};
template<class T>
node<T>::node(T t, node* next)
{
    this->_t = t;
    this->_next = next;
}
template<class T>
node<T>::~node()
{
}






/**
 * 链表类
 * */
template<class T>
class LinkList
{
private:
    /* data */
    // 头节点指针
    node<T>* _head;
    int N;
    // 链表反转的public方法递归所用到的重载方法
    node<T>* reverse(node<T>*);

public:
    LinkList();
    // 重载拷贝构造函数，在构造时深拷贝
    LinkList(const LinkList<T>& lo):LinkList() {
        this->operator=(lo);
    };
    ~LinkList();
    // 清空链表
    void clear();
    // 返回长度
    int length();
    // 链表是否空
    bool isEmpty();
    // 获取i索引处
    const T& get(int);
    // 查找所处的位置
    int indexOf(T);
    // 尾插
    void insert(T);
    // 插入
    void insert(T, int);
    // 移除
    T remove(int );

    // 链表反转
    void reverse();
    // 快慢指针应用
    // 找中间值
    const T& getMid();
    // 是否有环
    bool hasCircle();
    // 返回环的入口节点
    const node<T>& getEntrance();
    // getNode方法，为生成一个环使用
    node<T>& getNode(int i){
        // 让指针指向头节点
        node<T>* cur = this->_head;
        while(i--){
            cur = cur->_next;
        }
        return *cur;        
    }
    // 重载=运算符，在拷贝对象时，深度拷贝。
    LinkList<T>& operator=(const LinkList& lo){
        // 防止自复制
        if(this != &lo){
            // 先删除掉this的数据
            this->clear();
            delete this->_head;
            // 再复制
            this->N = lo.N;
            this->_head = new node<T>( *(lo._head) );
            node<T>* cur = this->_head;
            node<T>* lo_p = lo._head;
            while(lo_p->_next != nullptr){
                cur->_next = new node<T>( *(lo_p->_next) );
                lo_p = lo_p->_next;
                cur = cur->_next;
            }
        }
        return *this;

    };
};

template<class T>
LinkList<T>::LinkList()
{
    //头节点什么也不存储
    T t;
    this->_head = new node<T>(t, nullptr);
    this->N = 0;
}

template<class T>
LinkList<T>::~LinkList()
{
    // 析构链表时，要释放栈中内存
    node<T>* cur = this->_head;
    // 每次delete当前节点时，要记录下个节点指针
    for(int i = 0; i <= N; i++){
        node<T>* next = cur->_next;
        delete cur;
        cur = next;
    }
}


template<class T>
void LinkList<T>::clear(){
    // 清空链表，保留头节点
    node<T>* cur = this->_head->_next;
    for(int i = 0; i < N; i++){
        node<T>* next = cur->_next;
        delete cur;
        cur = next;
    }
    this->_head->_next = nullptr;
    this->N = 0;
}

template<class T>
int LinkList<T>::length(){
    return this->N;
}

template<class T>
bool LinkList<T>::isEmpty(){
    return N==0;
}

template<class T>
const T& LinkList<T>::get(int i){
    // 让指针指向头节点
    node<T>* cur = this->_head;
    while(i--){
        cur = cur->_next;
    }
    return cur->_t;
}

template<class T>
int LinkList<T>::indexOf(T t){
    node<T>* cur = this->_head->_next;
    for(int i = 1; i <= N; i++){
        if(t == cur->_t){
            return i;
        }
        cur = cur->_next;
    }
    return -1;
}

template<class T>
void LinkList<T>::insert(T t){
    node<T>* cur = this->_head;
    int i = N;
    while(i--){
        cur = cur->_next;
    }
    cur->_next = new node<T>(t, nullptr);
    this->N++;
}

template<class T>
void LinkList<T>::insert(T t, int i){
    node<T>* cur = this->_head;
    int j = 0;
    while(j+1 < i){         //当j的下一个位置不是i时
        cur = cur->_next;
        j++;
    }
    node<T>* oldNext = cur->_next;
    cur->_next = new node<T>(t, oldNext);
    this->N++;    
}

template<class T>
T LinkList<T>::remove(int i){
    node<T>* cur = this->_head;
    int j = 0;
    while(j+1 < i){         //当j的下一个位置不是i时
        cur = cur->_next;
        j++;
    }
    node<T>* dNode = cur->_next;
    cur->_next = dNode->_next;
    this->N--;
    // C++中手动删堆中数据
    T dT = dNode->_t;
    delete dNode;    
    return dT;
}

template<class T>
void LinkList<T>::reverse(){
    this->reverse(this->_head->_next);
}

template<class T>
node<T>* LinkList<T>::reverse(node<T>* t){
    if(t == nullptr) return this->_head;
    node<T>* res = reverse(t->_next);
    res->_next = t;
    t->_next = nullptr;
    return t;
}

// 找中间值
template<class T>
const T& LinkList<T>::getMid(){
    node<T>* fast = this->_head->_next;
    node<T>* slow = this->_head->_next;
    while(fast != nullptr && fast->_next != nullptr && fast->_next->_next != nullptr){
        slow = slow->_next;
        fast = fast->_next->_next;
    }
    return slow->_t;
}
// 是否有环
template<class T>
bool LinkList<T>::hasCircle(){
    node<T>* fast = this->_head->_next;
    node<T>* slow = this->_head->_next;
    while(true){
        if(fast == nullptr && fast->_next == nullptr && fast->_next->_next == nullptr){
            return false;
        }
        slow = slow->_next;
        fast = fast->_next->_next;
        if(fast == slow){
            return true;
        }
    }
}
// 返回环的入口节点
template<class T>
const node<T>& LinkList<T>::getEntrance(){
    node<T>* fast = this->_head->_next;
    node<T>* slow = this->_head->_next;
    node<T>* wait = this->_head->_next;
    while(true){
        if(fast == nullptr && fast->_next == nullptr && fast->_next->_next == nullptr){
            // 没有环，返回头节点
            return *(this->_head);
        }
        slow = slow->_next;
        fast = fast->_next->_next;
        if(fast == slow){
            break;
        }
    }
    while(wait != slow){
        wait = wait->_next;
        slow = slow->_next;
    }
    return *wait;
}
#endif
