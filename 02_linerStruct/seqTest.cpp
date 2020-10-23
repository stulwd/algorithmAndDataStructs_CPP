#include <iostream>
#include "SeqenceList.h"
#include "string"
#include "LinkList.h"
#include "stack.h"
#include "queue.h"
using namespace std;

class student
{
private:
    /* data */
    string m_name;
public:
    student(){};
    student(string );
    ~student();
    string getName() const;
    bool operator==(const student&);
    friend ostream& operator<<(ostream& , const student&);
};

string student::getName() const{
    return this->m_name;
}

bool student::operator==(const student& stu){
    return this->m_name == stu.getName();
}

ostream& operator<<(ostream& out, const student& stu){
    out << stu.m_name;
    return out;
}

student::student(string name):
m_name(name)
{
}

student::~student()
{
}




template<typename T>
void traverse(LinkList<T>* );

int str2int(string );
string int2str(int );

int main(){
    
    /** 顺序表测试 */
    // SeqenceList<student* > sl(10);
    // sl.insert(new student("yaoming"));
    // sl.insert(new student("kobe"));
    // sl.insert(new student("maidi"));
    // student* james = new student("james");
    // sl.insert(james);

    // student* res = sl.get(1);
    // cout << "sl[1] = " << *res << endl;
    // student* rmv = sl.remove(0);
    // cout << "delete : " << *rmv << endl;
    // //sl.clear();
    // cout << "length: " << sl.length() << endl;
    // cout << "indexOf james" << sl.indexOf(james);

    /** LinkList测试 */
    cout << "start" << endl;
    LinkList<student> ll;
    ll.insert(student("n1"));
    ll.insert(student("n2"));
    ll.insert(student("n3"));
    ll.insert(student("n4"));
    ll.insert(student("n5"));
    cout << "length:" << ll.length() << endl;
    cout << "isEmpty?" << ll.isEmpty() << endl;
    cout << "ele3:" << (ll.get(3)) << endl;
    // 查找测试
    student* lisa = new student("Lisa");
    ll.insert(*lisa);
    cout << "pos of Lisa" << ll.indexOf(*lisa) << endl;
    cout << "pos of m3" << ll.indexOf(student("m3")) << endl;
    // 插入测试
    ll.insert(student("headMaster"), 1);
    traverse(&ll);
    // 反转列表测试
    ll.reverse();
    traverse(&ll);
    // remove测试
    ll.remove(4);
    traverse(&ll);
    // 清空测试
    ll.clear();
    cout << "length:" << ll.length() << endl;
    traverse(&ll);
    // 链表快慢指针测试
    cout << "fast and slow ptr application:" << endl;
    LinkList<int> li;
    li.insert(1);
    li.insert(2);
    li.insert(3);
    li.insert(4);
    li.insert(5);
    li.insert(6);
    li.insert(7);
    cout << "中间值是：" << li.getMid() << endl;
    // 生成环1 - 2 - 3 - 4
    //          |       | 
    //          7 - 6 - 5       
    node<int>& res = li.getNode(7);
    res._next = &(li.getNode(2));
    if(true == li.hasCircle()){
        cout << "有环," << "环的入口是：" << li.getEntrance()._t << endl; 
    }else{
        cout << "没有环！" << endl;
    }
    

    /* 栈测试--基于LinkList实现 */
    stack<student> st;
    st.push(student("001"));
    st.push(student("002"));
    st.push(student("003"));
    st.push(student("004"));
    st.push(student("005"));
    cout << "stack length:" << st.length() << endl;
    cout << "pop:" << st.pop() << endl;
    cout << "pop:" << st.pop() << endl;
    cout << "pop:" << st.pop() << endl;
    cout << "stack length:" << st.length() << endl;
    /* 栈测试：逆波兰表达式求值*/
    cout << "请输入逆波兰表达式" << endl;
    string npl[9] = {"3", "17", "15", "-", "*", "18", "6", "/", "+"};
    stack<string> nplStack;
    for(int i = 0; i < 9; i++){
        
        if(npl[i] == "+"){
            int op2 = str2int( nplStack.pop() );
            int op1 = str2int( nplStack.pop() );
            nplStack.push( int2str(op1+op2) );
            continue;
        }else if(npl[i] == "-"){
            int op2 = str2int( nplStack.pop() );
            int op1 = str2int( nplStack.pop() );
            nplStack.push( int2str(op1-op2) );
            continue;
        }else if(npl[i] == "*"){
            int op2 = str2int( nplStack.pop() );
            int op1 = str2int( nplStack.pop() );
            nplStack.push( int2str(op1*op2) );
            continue;
        }else if(npl[i] == "/"){
            int op2 = str2int( nplStack.pop() );
            int op1 = str2int( nplStack.pop() );
            nplStack.push( int2str(op1/op2) );
            continue;
        }
        nplStack.push(npl[i]);
    }
    cout << "npl exp res:" << nplStack.pop() << endl;

    /* 队列测试--基于LinkList实现 */
    queue<student> ql;
    ql.enqueue(student("no.1"));
    ql.enqueue(student("no.2"));
    ql.enqueue(student("no.3"));
    ql.enqueue(student("no.4"));
    ql.enqueue(student("no.5"));
    cout << "queue length:" << ql.length() << endl;
    cout << "dequeue:" << ql.dequeue() << endl;
    cout << "dequeue:" << ql.dequeue() << endl;
    cout << "dequeue:" << ql.dequeue() << endl;
    cout << "queue length:" << ql.length() << endl;
}




int str2int(string str){
    int res = 0;
    for(int i = 0; i < str.length(); i++){
        res *= 10;
        res = res + (int)(str[i] - '0');
    }
    return res;
}
string int2str(int num){
    string res;
    while(num){
        res = string(1, ((num % 10) + '0')) + res;
        num /= 10;
    }
    return res;
}

template<typename T>
void traverse(LinkList<T> *lp){
    /**
     * 经典bug案例
     *     新的对象ll虽然是lp所指定对象的副本，但是两个对象内保存着其他的公共对象，这些公共对象还是唯一的，没有随ll的创建而创建。
     * 所以子函数退出时，ll会析构，导致把公共对象也析构了，影响原对象。
     * */
    //LinkList<T> ll = *lp;
    // 下面两行和上面一行调用的函数不一样，上面调用的拷贝构造函数，下面先调用默认构造，然后调用operator=重载函数
    LinkList<T> ll;
    ll = *lp;
    int N = ll.length();
    for(int i = 1; i <= N; i++){
        cout << ll.get(i);
    }
    cout << endl;

    /**
     * 解决办法：
     *      1.不要再次用原始对象的数据创建新对象，使用原始对象操作。
     *      2.重载LinkList的=号运算符，为析构时会被delete的成员，重新开辟空间。
     * */
    // int N = (*lp).length();
    // for(int i = 1; i <= N; i++){
    //     cout << ((*lp).get(i)) << " ";
    // }
    // cout << endl;
}
