#include <iostream>
#include "MaxpriorityQueue.h"

using namespace std;

int main(){
    /** 最大优先队列测试 */
    MaxpriorityQueue<string> maxq(20);
    maxq.enqueue("plwd");
    maxq.enqueue("tlwd");
    maxq.enqueue("jlwd");
    maxq.enqueue("qxlwd");
    maxq.enqueue("alwd");

    while(!maxq.isEmpty()){
        cout << maxq.dequeue() << " ";
    }
    
}
