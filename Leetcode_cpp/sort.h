#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include<iostream>
using namespace std;

class MySort{
public:
    void quick_sort(int a[],int s,int t){
        if(s<t){
            int k = Partition(a,s,t);
            quick_sort(a,s,k-1);
            quick_sort(a,k+1,t);
        }
    }


    int Partition(int a[],int s,int e){
        int temp = a[s];///store the a[s]
        while(s<e){
            while(s<e && a[e]>=temp) e--;
            a[s] = a[e];
            while(s<e && a[s]<=temp) s++;
            a[e] = a[s];
        }///while
        a[s] = temp;
        return s;
    }//Partition

    ///heap_sort algorithm
    void HeapSort(int a[],int n){///n is the index ,not the length
        for(int i = n/2;i>=0;i--){///build a big root heap
            Shift(a,i,n);
            for(int p = 0;p<=n;p++){
                cout<<a[p]<<" ";
            }cout<<endl;
        }

        for(int i = n;i>0;i--){
            int temp = a[0];
            a[0] = a[i];
            a[i] = temp;
            Shift(a,0,i-1);///build the a[0..(i-1)] as a big-root heap
        }
    }
    void Shift(int a[],int i,int m){///m is the index ,not the length
        ///这个算法假设a[i+1...m]中的各个元素满足堆的定义,本算法调整a[i]使得序列a[i..m]中的元素满足堆的性质
        ///要求不高,只是每次使大根堆的  元素数量多一个
        ///调堆的过程,每次只在一个子树中操作,调换;
        ///那么什么时候调换截止呢,就是说a[i]找到了要找的位置,就行了,我们这个函数的任务就结束了.
        int temp = a[i];///暂存a[i]到temp
        if(i==1){
            cout<<"start"<<endl;
        }
        for(int j = 2*i+1;j<=m;j=2*i+1){///a[i]的左右孩子的下标分别是[2i],[2i+1]
            if(j<m && a[j]<a[j+1]) j++;///若a[i]的右孩子存在,且关键字比较大,沿右孩子筛选
                                        ///找当前a[i]最大的孩子节点和a[i]相比较即可,
                                        ///大根堆的定义:只有节点和孩子节点的比较,没有孩子节点之间比较的意思
            if(temp<a[j]){///这个孩子的key比较大
                a[i] = a[j];///将这个孩子节点放到双亲的位置
                i = j;///修改当前被调整的节点
            }else{
                break;///调整完毕
            }
        }///for
        a[i] = temp;///将最初被调整节点放到正确位置
    }

    ///merger_sort algorithm
void mergeArray(int * arrs, int * tempArr, int left, int middle, int right){
    int i = left, j = middle ;
    int m = middle + 1, n = right;
    int k = 0;

    while(i <= j && m <= n){
        if(arrs[i] <= arrs[m])
            tempArr[k++] = arrs[i++];
        else
            tempArr[k++] = arrs[m++];
    }
    while(i <= j)
        tempArr[k++] = arrs[i++];
    while(m <= n)
        tempArr[k++] = arrs[m++];

    for(i=0; i < k; i++)
        arrs[left + i] = tempArr[i];
}

void mergeSort(int * arrs, int * tempArr, int left, int right){
    if(left < right){
        int middle = (left + right)/2;
        mergeSort(arrs, tempArr, left, middle);
        mergeSort(arrs, tempArr, middle + 1, right);
        mergeArray(arrs, tempArr, left, middle, right);
    }
}

};


#endif // SORT_H_INCLUDED


/**
#include <iostream>

using namespace std;
int arrs[] = { 23, 65, 12, 3, 8, 76, 345, 90, 21, 75, 34, 61 };
int arrLen = sizeof(arrs) / sizeof(arrs[0]);
int * tempArr = new int[arrLen];

void mergeArray(int * arrs, int * tempArr, int left, int middle, int right){
    int i = left, j = middle ;
    int m = middle + 1, n = right;
    int k = 0;

    while(i <= j && m <= n){
        if(arrs[i] <= arrs[m])
            tempArr[k++] = arrs[i++];
        else
            tempArr[k++] = arrs[m++];
    }
    while(i <= j)
        tempArr[k++] = arrs[i++];
    while(m <= n)
        tempArr[k++] = arrs[m++];

    for(i=0; i < k; i++)
        arrs[left + i] = tempArr[i];
}

void mergeSort(int * arrs, int * tempArr, int left, int right){
    if(left < right){
        int middle = (left + right)/2;
        mergeSort(arrs, tempArr, left, middle);
        mergeSort(arrs, tempArr, middle + 1, right);
        mergeArray(arrs, tempArr, left, middle, right);
    }
}

int main()
{
    mergeSort(arrs, tempArr, 0, arrLen-1);
    for (int i = 0; i < arrLen; i++)
        cout << arrs[i] << endl;
    return 0;
}
*/
