#include <iostream>
#include "OrientedGraph.h"
#include "detectCircle.h"
using namespace std;

int main(){
    OrientedGraph<string> og(100);
    og.addNode("", 0);
    og.addNode("", 1);
    og.addNode("", 2);
    og.addNode("", 3);
    og.addNode("", 4);
    og.addNode("", 5);

    og.link(0, 1);
    og.link(0, 2);
    og.link(2, 3);
    og.link(2, 4);
    og.link(4, 5);
    // og.link(5, 1);

    detectCircle<string> dc(&og);
    cout << "has circle ?" << dc.hasCircle << endl;


}
