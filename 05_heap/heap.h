#ifndef HEAP_H
#define HEAP_H

template<class T>
class heap
{
private:
    /* data */
    // 堆数组的头指针
    T* head;
    int N;
    // 堆中两个索引处的比较
    bool less(int i, int j){
        return head[i] < head[j];
    }
    // 交换
    void exch(int i, int j){
        T tmp = head[i];
        head[i] = head[j];
        head[j] = tmp;
    }
    // 下沉
    void sink(int index){
        int Max;
        while( index*2 <= N ){          //只要有子节点时
            if( (index*2 + 1) <= N ){   //当有右子节点时
                Max = head[index*2] > head[index*2 + 1] ? (index*2) : (index*2 + 1);
            }else{                      //只有左子节点
                Max = index*2;
            }
            if(head[index] >= head[Max]){    //比最大的子节点要大，不需要交换
                break;
            }else{                          //比最大的子节点小，需要交换
                exch(index, Max);
                index = Max;
            }
        }
    }
    // 上浮
    void swim(int index){
        while(index > 1){
            if( head[index] > head[index/2] ){   //如果比父节点大，需要交换
                exch(index, index/2);
                index = index/2;
            }else{                              //如果比父节点小，直接break
                break;
            }
        }
    }
public:
    // 构造堆数组
    heap(int capacity){
        this->head = new T[capacity];
        this->N = 0;
    };
    // 析构后，释放掉内存
    ~heap(){
        delete [] head;
    };
    // 删除最大元素（此堆为大根堆）
    T delMax(){
        exch(1, N);
        this->N--;
        sink(1);
        return head[N+1];
    }
    // 插入
    void insert(T t){
        this->N++;
        head[N] = t;
        swim(N);
    }
    // 是否空
    bool isEmpty(){
        return this->N == 0;
    }

    /**
     * 堆排序静态方法
     * @param tl：排序前的数组头指针
     * @param length：数组长度
     * */
    static void sort(T* tl, int length){
        /** 堆有序化 */
        // 创建一个新堆，把数据整体赋值到新的堆中，这里可以用内存拷贝
        heap<T> hp(length+1);
        for(int i = 0; i < length; i++){
            hp.head[i+1] = tl[i];
        }
        hp.N = length;
        // 从N/2处向前下浮到第一个元素，使得堆有序
        int cur = hp.N/2;
        while(cur >= 1){
            hp.sink(cur);
            cur--;
        }
        // 删除最大元素到tl中
        for(int i = 0; i < length; i++){
            tl[i] = hp.delMax();
        }
    }

};




/* 归并模板实现 */
template<class T>
class mergeSort
{
private:
    static bool greater(T t_a, T t_b){
        return t_a > t_b;
    }
    
    /* 指针排序 */
    static void ptr_sort(T* arr[], int start, int end){
        if(end == start) return;
        int mid = (start + end)/2;
        ptr_sort(arr, start, mid);
        ptr_sort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
    static void merge(T* arr[], int start, int mid, int end){
        int num = end - start + 1;
        T* tmp[num];
        int p1 = start;
        int p2 = mid + 1;
        int i = 0;
        while(p1 <= mid && p2 <= end){
            if(greater(*arr[p1], *arr[p2])){
                tmp[i++] = arr[p2]; p2++;
            }else{
                tmp[i++] = arr[p1]; p1++;
            }
        }
        while(p1 <= mid){
            tmp[i++] = arr[p1]; p1++;
        }
        while(p2 <= end){
            tmp[i++] = arr[p2]; p2++;
        }

        for(int j = 0; j < end - start + 1; j++){
            arr[start + j] = tmp[j];
        }
    }
    
    /* 源数据排序 */
    static void oriData_Sort(T arr[], int start, int end){
        if(end == start) return;
        int mid = (start + end)/2;
        oriData_Sort(arr, start, mid);
        oriData_Sort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
    static void merge(T arr[], int start, int mid, int end){
        int num = end - start + 1;
        T tmp[num];
        int p1 = start;
        int p2 = mid + 1;
        int i = 0;
        while(p1 <= mid && p2 <= end){
            if(greater(arr[p1], arr[p2])){
                tmp[i++] = arr[p2]; p2++;
            }else{
                tmp[i++] = arr[p1]; p1++;
            }
        }
        while(p1 <= mid){
            tmp[i++] = arr[p1]; p1++;
        }
        while(p2 <= end){
            tmp[i++] = arr[p2]; p2++;
        }

        for(int j = 0; j < end - start + 1; j++){
            arr[start + j] = tmp[j];
        }
    }
public:
    mergeSort(/* args */){};
    ~mergeSort(){};

    // 原对象排序
    static void oriData_Sort(T arr[], int length){
        oriData_Sort(arr, 0, length-1);
    }

    // 指针排序
    static void ptr_sort(T* arr[], int length){
        ptr_sort(arr, 0, length-1);
    }
 
};

#endif
