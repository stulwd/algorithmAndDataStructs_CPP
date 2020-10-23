#include <iostream>
#include "binaryTree.h"

using namespace std;



int main(){
    binaryTree<float, string> bt;
    bt.put(5, "q");
    bt.put(2, "w");
    bt.put(8, "e");
    bt.put(1, "r");
    bt.put(4, "t");
    bt.put(6, "y");
    bt.put(9, "u");
    bt.put(0, "i");
    bt.put(1.5, "o");
    bt.put(1.6, "p");
    bt.put(1.55, "a");
    bt.put(1.54, "s");
    bt.put(1.56, "d");

    bt.del(2);
    SeqenceList<float> sl(100); 
    // // 前序遍历
    // bt.preErgodic(&sl);
    // // 后序遍历
    // bt.afterErgodic(&sl);
    // // 中序遍历（排序）
    // bt.midErgodic(&sl);   
    // // 层序遍历
    bt.layerErgodic(&sl);
    for(int i = 0; i < sl.length(); i++){
        cout << sl.get(i) << endl;
    }
    // 树最大深度
    cout << "树的最大深度为：" << bt.depth() << endl; 
    bt.del(1.54);
    cout << "树的最大深度为：" << bt.depth() << endl; 
    bt.del(1.56);
    cout << "树的最大深度为：" << bt.depth() << endl; 
    cout << "树的最小K处值" << *(bt.min()) << endl; 
    cout << "树的最大K处值" << *(bt.max()) << endl;
    // bt.midErgodic(&sl);
    // for(int i = 0; i < sl.length(); i++){
    //     cout << sl.get(i) << endl;
    // }
    // cout << *(bt.find(1)) << endl;
    // cout << bt.size() << endl;
    // bt.put(7, "hello");
    // cout << *(bt.find(7)) << endl;


}
