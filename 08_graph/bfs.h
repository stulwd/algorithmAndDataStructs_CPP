#ifndef BFS_H
#define BFS_H

#include <iostream>
#include "Graph.h"

/**
 * 广度优先遍历
 * */

template<class T>
class bfs
{
private:
    /* data */
    bool* marked;
    queue<int> wait;
    int count;
public:
    // 从顶点V开始bfs
    bfs(Graph<T>* g, int v){
        marked = new bool[g->_capacity];
        for(int i = 0; i < g->_capacity; i++){
            marked[i] = false;
        }
        wait.enqueue(v);
        search(g, v);
    };
    // bfs顶点v
    void search(Graph<T>* g, int v){
        marked[v] = true;
        while(wait.length() != 0){
            int e = wait.dequeue();
            count++;
            queue<int> q = g->adj(e);
            while(q.length() != 0){
                v = q.dequeue();
                if(marked[v]){
                    continue;
                }else{
                    wait.enqueue(v);
                    marked[v] = true;
                }                
            }
        }
    }    
    // 检测和顶点i是否联通
    bool isLinked(int i){
        return marked[i];
    }
    // 联通的节点数量
    int linkedNodeNum(){
        return count;
    }
    ~bfs(){
        delete[] marked;
    };
};

#endif
