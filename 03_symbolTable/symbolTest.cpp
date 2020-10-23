#include <iostream>
#include "symbolTable.h"

using namespace std;

class key
{
private:
    /* data */
    int _key;
public:
    key(int);
    key(){};
    ~key();
    bool compare(key);
    bool operator==(key );
};
key::key(int key):
_key(key)
{
}
key::~key()
{
}
bool key::compare(key other){
    return this->_key > other._key;
}
bool key::operator==(key k){
    return this->_key == k._key;
}








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











int main(){
    symbolTable<key, student> sb;
    sb.put(5, string("stu1"));
    sb.put(2, string("stu2"));
    sb.put(4, string("stu3"));
    sb.put(3, string("stu4"));
    sb.put(1, string("stu5"));
    sb.put(1, string("stu5"));
    if( 5 == sb.length() ){
        cout << "put()测试成功" << endl;
        cout << "length()测试成功" << endl;
    }
    key k;
    student stu;

    sb.getByOrder(3, &k, &stu);
    if( k==3 && stu==string("stu4") ){
        cout << "getByOrder()测试成功" << endl;
    }else{
        cout << "getByOrder()测试失败" << endl;
    }

    if( false == sb.getByKey(9, &stu) && 
        true == sb.getByKey(3, &stu) &&  
        stu == string("stu4") )
    {
        cout << "getByKey()测试成功" << endl;
    }else{
        cout << "getByKey()测试失败" << endl;
    }

    if( true == sb.removeByKey(1, &stu) && stu == string("stu5") && sb.length() == 4 ){
        if( false == sb.removeByKey(9, &stu) ){
            cout << "removeByKey()测试成功" << endl;
        }else{
            cout << "removeByKey()测试失败" << endl;
        }
    }else{
        cout << "removeByKey()测试失败" << endl;
    }

    sb.removeByOrder(1, &k, &stu);
    if( k == 2 && stu == string("stu2") && sb.length() == 3 ){
        cout << "removeByOrder()测试成功" << endl;
    }else{
        cout << "removeByOrder()测试失败" << endl;
    }

    sb.clear();
    if( sb.length() == 0){
        cout << "clear()测试成功" << endl;
        if( sb.isEmpty() ){
            cout << "isEmpty测试成功" << endl;
        }else{
            cout << "isEmpty测试失败" << endl;
        }
    }else{
        cout << "clear()测试失败" << endl;
    }
}
