#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include "../02_linerStruct/SeqenceList.h"         // 为前序中序后序遍历提供支持
#include "../02_linerStruct/queue.h"               // 为层序遍历提供支持
using namespace std;

/** 节点类 */
template<class K, class T>
class b_node
{
private:
    /* data */
public:
    K _k;
    T _t;
    b_node<K, T>* _left;
    b_node<K, T>* _right;
    // 构造
    b_node(K k, T t, b_node* left, b_node* right):
    _k(k),
    _t(t),
    _left(left),
    _right(right)
    {
    
    }
    ~b_node(){};
};



/** 二叉树类 */
template<class K, class T>
class binaryTree
{
private:
    /* data */
    b_node<K, T>* root;
    int N;
     // put到子树
    b_node<K, T>* put(K k, T t, b_node<K, T>* tree){
        if( tree == nullptr ){
            this->N++;
            return new b_node<K, T>(k, t, nullptr, nullptr);
        }

        if( k > tree->_k ){ //当t的key比当前节点大
            tree->_right = put(k, t, tree->_right);
        }else if( k < tree->_k ){   //当t的key比当前节点小
            tree->_left = put(k, t, tree->_left);
        }else{  //当t的key等于当前节点，修改当前节点,不继续向下递归
            tree->_t = t;
        }
        return tree;
    }
    // 查找子树
    const T* find(K k, b_node<K, T>* tree){
        if(tree == nullptr){
            return nullptr;
        }

        if(tree->_k == k){
            return &(tree->_t);
        }else if(tree->_k > k){
            return find(k, tree->_left);
        }else if(tree->_k < k){
            return find(k, tree->_right);
        }
    }
    // 删除子树节点
    b_node<K, T>* del(K k, b_node<K, T>* tree){
        if( k < tree->_k ){
            tree->_left = del(k, tree->_left);
        }else if( k > tree->_k ){
            tree->_right = del(k, tree->_right);
        }else{  //删除的就是这个节点
            if(tree->_left != nullptr){     //被删节点的左节点不空时
                // 查找左子树中最大节点的父节点
                if(tree->_left->_right == nullptr){
                    b_node<K, T>* oldTree = tree;
                    tree = tree->_left;
                    tree->_right = oldTree->_right;
                }else{       
                    b_node<K, T>* delFather = tree->_left;
                    while(delFather->_right->_right != nullptr){
                        delFather = delFather->_right;
                    }
                    // 将左子树的最大节点赋值给要删除的节点处
                    b_node<K, T>* oldTree = tree;
                    tree = delFather->_right;
                    // 将左子树的最大节点的父节点指向最大节点的左节点
                    delFather->_right = delFather->_right->_left;
                    tree->_left = oldTree->_left;
                    tree->_right = oldTree->_right;
                }
            }else if(tree->_right != nullptr){      //被删节点的左节点空，右节点不空
                tree = tree->_right;
            }else{                      // 被删节点是叶子节点
                tree = nullptr;
            }
        }
        return tree;
    }
    // 中序遍历子树
    void midErgodic(SeqenceList<K>* sl, b_node<K, T>* tree){
        if(tree == nullptr) return;
        midErgodic(sl, tree->_left);
        sl->insert(tree->_k);
        midErgodic(sl, tree->_right);
    }
    // 前序遍历
    void preErgodic(SeqenceList<K>* sl, b_node<K, T>* tree){
        if(tree == nullptr) return;
        sl->insert(tree->_k);
        preErgodic(sl, tree->_left);
        preErgodic(sl, tree->_right);
    }
    // 后序遍历
    void afterErgodic(SeqenceList<K>* sl, b_node<K, T>* tree){
        if(tree == nullptr) return;
        afterErgodic(sl, tree->_left);
        afterErgodic(sl, tree->_right);
        sl->insert(tree->_k);
    }
    // 子树深度
    int depth(b_node<K, T>* tree){
        if(tree == nullptr) return 0;
        int ldepth = depth(tree->_left);
        int rdepth = depth(tree->_right);
        if( ldepth >= rdepth ){
            return 1 + ldepth;
        }
        else{
            return 1 + rdepth;
        }
    }

public:
    binaryTree(){
        // 这里一定要把root设为空指针，要是不设置，有可能是野指针，程序崩坏
        this->root = nullptr;
        this->N = 0;
    };
    ~binaryTree(){};
    // put
    void put(K k, T t){
        this->root = put(k, t, root);
    }
    // 查找
    const T* find(K k){
        return find(k, root);
    }
    // size()
    int size(){
        return this->N;
    }
    // 删除
    void del(K k){
        this->root = del(k, root);
    }
    // 中序遍历
    void midErgodic(SeqenceList<K>* sl){
        midErgodic(sl, root);
    }
    // 前序遍历
    void preErgodic(SeqenceList<K>* sl){
        preErgodic(sl, root);
    }
    // 后序遍历
    void afterErgodic(SeqenceList<K>* sl){
        afterErgodic(sl, root);
    }
    // 层序遍历
    void layerErgodic(SeqenceList<K>* sl){
        queue< b_node<K, T>* >* ql = new queue< b_node<K, T>* >();
        ql->enqueue(root);
        b_node<K, T>* cur;
        while(0 != ql->length()){
            cur = ql->dequeue();
            sl->insert(cur->_k);
            if(cur->_left != nullptr){
                ql->enqueue(cur->_left);
            }
            if(cur->_right != nullptr){
                ql->enqueue(cur->_right);
            }
        }
    }

    // 树的最大深度
    int depth(){
        return depth(this->root);
    }

    // 最小值
    const T* min(){
        b_node<K, T>* cur = this->root;
        if(cur == nullptr) return nullptr;
        while(cur->_left != nullptr){
            cur = cur->_left;
        }
        return &cur->_t;
    }
    // 最大值
    const T* max(){
        b_node<K, T>* cur = this->root;
        if(cur == nullptr) return nullptr;
        while(cur->_right != nullptr){
            cur = cur->_right;
        }
        return &cur->_t;
    }
};




#endif
