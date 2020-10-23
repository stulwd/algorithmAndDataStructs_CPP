#ifndef DETECT_CIRCLE_H
#define DETECT_CIRCLE_H

#include <iostream>
#include "OrientedGraph.h"

template<class T>
class detectCircle
{
private:
    /* data */
    bool* marked;
    bool detect(OrientedGraph<T>* g, int v){
        marked[v] = true;
        queue<int> q = g->adj(v);
        while(q.length() != 0){
            v = q.dequeue();
            if(marked[v] == false){
                bool has = detect(g, v);
                if(has){
                    return true;
                }
            }else{
                this->hasCircle = true;
                return true;
            }
        }
        return false;
    };
public:
    detectCircle(OrientedGraph<T>* g){
        this->hasCircle = false;
        marked = new bool[g->_capacity];
        for(int i = 0; i < g->_capacity; i++){
            marked[i] = false;
        }
        detect(g, g->getfirstAddedNode());
    };
    bool hasCircle;
    ~detectCircle(){};
};

#endif
