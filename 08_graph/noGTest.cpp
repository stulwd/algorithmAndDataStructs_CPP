#include <iostream>
#include "Graph.h"
#include "dfs.h"
#include "bfs.h"
#include "dfp.h"
using namespace std;

/**
 * 无向图测试，包含Graph.h dfs.h bfs.h dfp.h
 * */

int main(){
    Graph<string> g(100);
    g.addNode("a", 0);
    g.addNode("b", 1);
    g.addNode("c", 2);
    g.addNode("d", 3);
    g.addNode("e", 4);
    g.addNode("f", 5);
    g.addNode("g", 6);
    g.addNode("h", 7);
    g.addNode("i", 8);
    g.addNode("j", 9);

    g.link(0, 1);
    g.link(0, 7);
    g.link(0, 8);
    //g.link(0, 9);
    //g.link(1, 2);
    g.link(2, 3);
    //g.link(2, 7);
    g.link(2, 9);
    g.link(3, 4);
    g.link(4, 5);
    //g.link(4, 6);
    //g.link(4, 7);
    //g.link(5, 6);
    g.link(5, 9);
    g.link(6, 7);
    g.link(6, 8);
    //g.link(8, 9);
    cout << g.edgeNum() << endl;
    cout << g.nodeNum() << endl;
    /** 
     * 经典错误分析：
     *      每一个queue对象在析构时，都会delete它的成员ll，因此ll所指向的链表区域会被回收
     * 所以我们最好不要复制一个queue对象的副本，因为这个副本和原对象ll的值相同，在析构时会删除掉同一份ll链表对象
     * wrong code：const queue<int> q = g.adj(9);
    */
    const queue<int>* q = &(g.adj(9));
    for(int i = 1; i <= q->N; i++){
        cout << q->get(i) << " ";
    }
    cout << endl;

    bfs<string> s(&g, 2);
    cout << s.isLinked(4) << endl;
    cout << s.isLinked(9) << endl;
    cout << s.isLinked(6) << endl;
    cout << "linkedNodeNum:" << s.linkedNodeNum() << endl;

    /**
     * 畅通工程测试
     * */
    int cityNum = 20;
    int roads = 7;
    int linkTable[7][2] = {{0, 1}, {6, 9}, {3, 8}, {5, 11}, {2, 12}, {6, 10}, {4, 8}};
    // build cities
    Graph<string> gc(100);
    for(int i = 0; i < cityNum; i++){
        gc.addNode("", i);
    }
    // build roads
    for(int i = 0; i < roads; i++){
        gc.link(linkTable[i][0], linkTable[i][1]);
    }
    dfs<string> rs(&gc, 9); 
    cout << "is linked to 10? " << (rs.isLinked(10)? "true" : "false") << endl;
    cout << "is linked to 8? " << (rs.isLinked(8)? "true" : "false") << endl;

    /** 
     * 深度优先路径测试
     * */
    dfp<string> fp(&g, 5);
    stack<int> st1 = fp.pathTo(9);
    cout << "path from 5 to 9: ";
    while(st1.length() != 0){
        cout << "->" << st1.pop();
    }
}
