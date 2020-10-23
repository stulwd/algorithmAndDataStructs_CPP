#include <iostream>
using namespace std;

/**
 *  第一行输入n，m，表示即将输入多少n个数，m条命令
 *  第二行输入n个数
 *  第3到2+m行输入m条命令，需要执行正确的操作。命令格式如下：
 *      删除最大：1
 *      修改第i个元素值：2 i 2 （将第i个元素值修改为2）
 *      插入：3 4 （在队列中插入4）
 * 
*/

// 上浮
int swim(int arr[], int brr[], int crr[], int index, int N){
    while(index > 1){
        if( arr[brr[index]] > arr[brr[index/2]] ){   //如果比父节点大，需要交换
            int tmp = brr[index];
            brr[index] = brr[index/2];
            brr[index/2] = tmp;
            crr[brr[index]] = index;
            crr[brr[index/2]] = index/2;
            index = index/2;
        }else{                              //如果比父节点小，直接break
            break;
        }
    }
}

// 下沉
int sink(int arr[], int brr[], int crr[], int index, int N){
    int Max;
    while( index*2 <= N && index >= 1 ){          //只要有子节点时
        if( (index*2 + 1) <= N ){   //当有右子节点时
            Max = arr[brr[index*2]] > arr[brr[index*2 + 1]] ? (index*2) : (index*2 + 1);
        }else{                      //只有左子节点
            Max = index*2;
        }
        if(arr[brr[index]] >= arr[brr[Max]]){    //比最大的子节点要大，不需要交换
            break;
        }else{                          //比最大的子节点小，需要交换
            int tmp = brr[index];
            brr[index] = brr[Max];
            brr[Max] = tmp;
            crr[brr[index]] = index;
            crr[brr[Max]] = Max;
            index = Max;
        }
    }
}

int string2num(string str){
    int res = 0;
    for(int i = 0; i < str.length(); i++){
        res *= 10;
        res += (int)(str[i] - '0');
    }
    return res;
}

int main(){
    int n, m;
    cout << "请输入元素个数n：" << endl;
    cin >> n;
    cout << "请输入命令数m：" << endl;
    cin >> m;
    int arr[100];
    int brr[100+1];
    int crr[100];
    // i个数
    cout << "输入" << n << "个数" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        brr[i+1] = i;
        crr[i] = i+1;
        // 上浮 
        swim(arr, brr, crr, i+1, n);
    }

    string input[3];
    // j条命令
    int N = n;
    for(int j = 0; j < m; j++){
        cout << "输入命令：" << endl;
        cin >> input[0];
        if("1" == input[0]){
            if(N == 0){
                cout << "none element to delete!" << endl;
                continue;
            }
            crr[brr[N]] = 1;
            crr[brr[1]] = -1;
            brr[1] = brr[N];
            N--;
            sink(arr, brr, crr, 1, N);
        }else if("2" == input[0]){
            cin >> input[1];
            cin >> input[2];
            int index = string2num(input[1]);
            int value = string2num(input[2]);
            cout << index << " " << value << endl;
            if(index > n-1){
                cout << "invalid element to modify" << endl;
                continue;
            }
            arr[index] = value;
            cout << "sink" << endl;
            sink(arr, brr, crr, crr[index], N);
            cout << "swim" << endl;
            swim(arr, brr, crr, crr[index], N);
        }else if("3" == input[0]){
            cin >> input[1];
            int value = string2num(input[1]);
            n++;
            N++;
            arr[n-1] = value;
            brr[N] = n-1;
            crr[n-1] = N;
            swim(arr, brr, crr, N, n);
        }else if("4" == input[0]){
            // show by order
            for(int i = 1; i <= N; i++){
                cout << arr[brr[i]] << " ";
            }
        }else if("5" == input[0]){
            // show by order
            for(int i = 0; i < n; i++){
                cout << arr[i] << " ";
            }
        }else if("6" == input[0]){
            // show by order
            for(int i = 1; i <= N; i++){
                cout << brr[i] << " ";
            }
        }else if("7" == input[0]){
            // show by order
            for(int i = 0; i < n; i++){
                cout << crr[i] << " ";
            }
        }else if("n=" == input[0]){
            // show by order
            cout << "n=" << n << endl;
        }else if("N=" == input[0]){
            // show by order
            cout << "N=" << N << endl;
        }
        else{
            cout << "invalid command!" << endl;
        }
    }
}
