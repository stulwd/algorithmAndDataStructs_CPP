#ifndef DFS_H
#define DFS_H

#include "Graph.h"

/**
 * 深度优先遍历
 * */

template<class T>
class dfs
{
private:
    /* data */
    bool* marked;
    int count;
public:
    //查找g
    dfs(Graph<T>* g, int v){
        int count = 0;
        marked = new bool[g->_capacity];
        for(int i = 0; i < g->_capacity; i++){
            marked[i] = false;
        }
        // 从顶点v开始遍历
        marked[v] = true;
        search(g, v);
    };
    void search(Graph<T>* g, int v){
        // queue的拷贝构造已经重写为深拷贝，所以内存重合不会发生。
        queue<int> q = g->adj(v);
        while(q.length() != 0){
            int i = q.dequeue();
            if(marked[i]){
                continue;
            }else{
                marked[i] = true;
                count++;
                search(g, i);
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
    ~dfs(){
        delete[] marked;
    };
};


#endif
