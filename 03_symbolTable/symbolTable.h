#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <iostream>

/** 符号表的节点类 */
template<class key, class value>
class s_node
{
private:
    /* data */
public:
    key _key;
    value _value;
    s_node* _next;
    s_node(key, value, s_node*);
    ~s_node();
};

template<class key, class value>
s_node<key, value>::s_node(key k, value v, s_node* next):
_key(k),
_value(v),
_next(next)
{
}
template<class key, class value>
s_node<key, value>::~s_node()
{
}




/** 符号表类 */
template<class typeKey, class typeVal>
class symbolTable
{
private:
    /* data */
    int N;
    s_node<typeKey, typeVal>* _head;
public:
    symbolTable();
    ~symbolTable();
    void put(typeKey, typeVal);
    void getByOrder(int, typeKey*, typeVal*);
    bool getByKey(typeKey, typeVal*);
    void removeByOrder(int, typeKey*, typeVal*);
    bool removeByKey(typeKey, typeVal*);
    int length();
    void clear();
    bool isEmpty();
};

template<class typeKey, class typeVal>
symbolTable<typeKey, typeVal>::symbolTable()
{
    this->N = 0;
    typeKey key;
    typeVal val;
    this->_head = new s_node<typeKey, typeVal>(key, val, nullptr);
}

template<class typeKey, class typeVal>
symbolTable<typeKey, typeVal>::~symbolTable()
{
}


template<class typeKey, class typeVal>
void symbolTable<typeKey, typeVal>::put(typeKey key, typeVal val){
    /* 找到插入的位置 */
    s_node<typeKey, typeVal>* cur = this->_head->_next;
    s_node<typeKey, typeVal>* pre = this->_head;  
    for(int i = 1; i <= N; i++){
        if(cur == _head->_next){
            // 如果是第一个节点，不需要比较前节点
            if( key == cur->_key ){ cur->_value = val; return;}
            if( !key.compare(cur->_key) ){
                break;
            }
        }else{
            if( key == cur->_key ){ cur->_value = val; return;}
            if( key.compare(pre->_key) && !key.compare(cur->_key)){
                break;
            }
        }
        pre = cur;
        cur = cur->_next;
    }
    s_node<typeKey, typeVal>* newNode = new s_node<typeKey, typeVal>(key, val, cur);
    pre->_next = newNode;
    this->N++;
}

template<class typeKey, class typeVal>
void symbolTable<typeKey, typeVal>::getByOrder(int index, typeKey* p_key, typeVal* p_val){
    if( index > this->N ) {
        return;
    }
    s_node<typeKey, typeVal>* cur = this->_head;
    for(int i = 1; i <= index; i++){
        cur = cur->_next;
    }
    *p_key = cur->_key;
    *p_val = cur->_value;
    return;
}


template<class typeKey, class typeVal>
bool symbolTable<typeKey, typeVal>::getByKey(typeKey key, typeVal* p_val){
    s_node<typeKey, typeVal>* cur = this->_head->_next;
    for(int i = 1; i <= this->N; i++){
        if(key == cur->_key){
            *p_val = cur->_value;
            return true;
        }
        cur = cur->_next;
    }
    return false;
}

template<class typeKey, class typeVal>
void symbolTable<typeKey, typeVal>::removeByOrder(int index, typeKey* p_key, typeVal* p_val){
    if( index > this->N ){
        return;
    }
    s_node<typeKey, typeVal>* cur = this->_head;
    for(int i = 0; i < index - 1; i++){
        cur = cur->_next;        
    }
    // 记录要删除的元素
    s_node<typeKey, typeVal>* rmv = cur->_next;
    //改变指针指向
    cur->_next = cur->_next->_next;
    //赋值
    *p_key = rmv->_key;
    *p_val = rmv->_value;
    //删除
    delete rmv;
    this->N--;
}

template<class typeKey, class typeVal>
bool symbolTable<typeKey, typeVal>::removeByKey(typeKey key, typeVal* p_val){
    s_node<typeKey, typeVal>* cur = this->_head;
    for(int i = 0; i < N; i++){
        if(key == cur->_next->_key){
            // 记录要删除的元素
            s_node<typeKey, typeVal>* rmv = cur->_next;
            //改变指针指向
            cur->_next = cur->_next->_next;
            //删除
            *p_val = rmv->_value;
            delete rmv;
            this->N--;
            return true;            
        }
        cur = cur->_next;        
    }
    return false;
}

template<class typeKey, class typeVal>
int symbolTable<typeKey, typeVal>::length(){
    return this->N;
}
template<class typeKey, class typeVal>
void symbolTable<typeKey, typeVal>::clear(){
    s_node<typeKey, typeVal>* cur = this->_head->_next;
    for(int i = 0; i < N; i++){
        s_node<typeKey, typeVal>* next = cur->_next;    
        delete cur;
        cur = next;
    }
    this->N = 0;
    return;
}

template<class typeKey, class typeVal>
bool symbolTable<typeKey, typeVal>::isEmpty(){
    return 0 == this->N;
}

#endif
