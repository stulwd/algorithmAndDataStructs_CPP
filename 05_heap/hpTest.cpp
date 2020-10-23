#include <iostream>
#include <stdlib.h>
#include <ctime>

#include "heap.h"
#include "MaxpriorityQueue.h"

using namespace std;

class cpu
{
private:
    /* data */
    int _core;
    int _coreNum;    
public:
    cpu():_core(0){};
    cpu(int core):_core(core){};
    ~cpu(){};
    const int& getCore() const{
        return this->_core;
    }
    bool operator>=(const cpu& other){
        return this->_core >= other._core;
    }
    bool operator>(cpu other){
        return this->_core > other._core;
    }
    friend ostream& operator<<(ostream& out, const cpu& c){
        out << c._core;
        return out;
    }
};


int main(){
    // 当元素为对象时，最好是存指针
    heap<cpu> hp(300);
    hp.insert(cpu(5250));
    hp.insert(cpu(4220));
    hp.insert(cpu(9750));
    hp.insert(cpu(8750));
    hp.insert(cpu(9770));
    hp.insert(cpu(9880));
    hp.insert(cpu(6770));
    hp.insert(cpu(6700));
    while(!hp.isEmpty()){
        cout << (hp.delMax()) << endl;
    }

    /** 堆排序和归并排序测试 */
    int num = 10000;
    cpu cpuList[num];
    cpu* clPtr[num];
    clock_t star, end;
    // cout << "排序前：" << endl;
    // for(int i = 0; i < num; i++){
    //     cout << arr[i] << " ";
    // }
    for(int i = 0; i < num; i++){
        cpuList[i] = cpu(rand()%1000);
    }
    cout << endl; 
    star = clock();
    heap<cpu>::sort(cpuList, num);
    end = clock();
    cout << "oriData heapSort running time: " << (double)(end-star) / CLOCKS_PER_SEC << "s" << endl;
    

    for(int i = 0; i < num; i++){
        cpuList[i] = cpu(rand()%1000);
    }   
    cout << endl; 
    star = clock();
    mergeSort<cpu>::oriData_Sort(cpuList, num);
    end = clock();
    cout << "oriData mergeSort running time: " << (double)(end-star) / CLOCKS_PER_SEC << "s" << endl;


    for(int i = 0; i < num; i++){
        cpuList[i] = cpu(rand()%1000);
        clPtr[i] = &cpuList[1];
    }      
    cout << endl; 
    star = clock();
    mergeSort<cpu>::ptr_sort(clPtr, num);
    end = clock();
    cout << "ptr mergeSort running time: " << (double)(end-star) / CLOCKS_PER_SEC << "s" << endl;
    
    // cout << "排序后：" << endl;
    // for(int i = 0; i < num; i++){
    //     cout << cpuList2[i] << " ";
    // }
    // cout << endl;
}
