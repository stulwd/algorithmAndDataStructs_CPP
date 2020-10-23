#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include "../02_linerStruct/queue.h"
using namespace std;

template<class T>
class g_node
{
private:
    /* data */
public:
    int _id;
    T _t;
    queue<int> adj;
    g_node(int id, T t){
        this->_id = id;
        this->_t = t;
    };
    ~g_node();
};

template<class T>
class Graph
{
private:
    /* data */
    // 图的N个节点
    int _N;
    int _E;
    g_node<T>* *nodeList;
public:
    int _capacity;
    Graph(int capacity){
        this->_N = 0;
        this->_E = 0;
        this->_capacity = capacity;
        nodeList = new g_node<T>*[capacity];
        for(int i = 0; i < capacity; i++){
            nodeList[i] = nullptr;
        }
    };
    // 向第i个位置添加节点
    void addNode(T t, int i){
        nodeList[i] = new g_node<T>(i, t);
        this->_N++;
    };
    // 连接第两个node
    void link(int i, int j){
        nodeList[i]->adj.enqueue(j);
        nodeList[j]->adj.enqueue(i);
        this->_E++;
    };
    // 获取顶点的所有邻接顶点
    const queue<int>& adj(int i){
        return nodeList[i]->adj;
    };
    // 获取顶点数量
    int nodeNum(){
        return this->_N;
    };
    // 获取边的数量
    int edgeNum(){
        return this->_E;
    };
    ~Graph(){
        for(int i = 0; i < this->_capacity; i++){
            if(nodeList[i] != nullptr){
                //delete nodeList[i];
            }
        }
        delete[] nodeList;
    };

};

#endif
