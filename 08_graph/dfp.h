#ifndef DFP_H
#define DFP_H

#include <iostream>
#include "Graph.h"
#include "../02_linerStruct/stack.h"
#include "../02_linerStruct/queue.h"
using namespace std;
/**
 * 图的深度优先路径: Depth First Path
 * */

template<class T>
class dfp
{
private:
    /* data */
    int* preNode;
    bool* marked;
    search(Graph<T>* g, int v){
        marked[v] = true;
        queue<int> q = g->adj(v);
        while(q.length() != 0){
            int vs = q.dequeue();
            if(marked[vs]){
                continue;
            }else{
                preNode[vs] = v;
                search(g, vs);
            }
        }
    };
public:
    dfp(Graph<T>* g, int v){
        preNode = new int[g->_capacity];
        marked = new bool[g->_capacity];
        for(int i = 0; i < g->_capacity; i++){
            preNode[i] = -1;
            marked[i] = false;
        }
        search(g, v);
    };
    stack<int> pathTo(int v){
        stack<int> st;
        while(preNode[v] != -1){
            st.push(v);
            v = preNode[v];
        }
        st.push(v);
        return st;
    }
    ~dfp(){};
};

#endif
