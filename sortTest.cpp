#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include "BubbleSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
using namespace std;

class student : public Comparable
{
private:
    /* data */
    string m_name;
    int m_score;
public:
    student(string, int);
    ~student();

    bool compare(Comparable* ) override;
    const string& getName();
    int getScore();
};

student::student(string name, int score):
m_name(name),
m_score(score)
{
}

student::~student()
{
}

bool student::compare(Comparable* tar){
    return this->getScore() > ((student* )tar)->getScore();
}
const string& student::getName(){
    return m_name;
}
int student::getScore(){
    return m_score;
}



int main(){
    int num = 100000;
    srand(time(0));
    student* stuArr[num];
    clock_t star, end;
    char ch1 = 'A', ch2 = 'A';
    for(int i = 0; i < num; i++){
        char str[3] = {ch1, ch2, '\0'};
        stuArr[i] = new student(string("stu_").append(str), rand()%100);
        ch2++;
        if(ch2 > 'Z'){
            ch2 = 'A';
            ch1++;
        }
    }

    // for(int i = 0; i < num; i++){
    //     cout << stuArr[i]->getName() << ":" << stuArr[i]->getScore() << " ";
    // }
    star = clock();
    // 冒泡排序
    //BubbleSort::sort((Comparable **)stuArr, num);     //当数据量是十万条时，冒泡排序耗时一分钟
    // 希尔排序
    //ShellSort::sort((Comparable **)stuArr, num);        //当数据量是十万条时，希尔排序耗时0.157s
    // 归并排序
    //MergeSort::sort((Comparable **)stuArr, num);        //当数据量是十万条时，归并排序耗时0.072s
    // 快速排序
    //QuickSort::sort((Comparable **)stuArr, num);        //当数据量是十万条时，快速排序耗时1.034s
    end = clock();

    cout << "\n\n";
    // for(int i = 0; i < num; i++){
    //     cout << stuArr[i]->getName() << ":" << stuArr[i]->getScore() << " ";
    // }
    cout << endl;

    cout << "running time: " << (double)(end-star) / CLOCKS_PER_SEC << "s" << endl;
}
