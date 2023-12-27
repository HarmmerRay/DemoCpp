#include <gmpxx.h>

//
// Created by zy_ on 23-12-26.
// 想当初 制作的任务列表 写测试大报告、写网络课设、写算法这些任务超前完成的列表，一个也没有完成。回望过去满是遗憾与不甘。因为不可控的压抑、注意力的涣散、思想的躁动生出各种遗憾。
//快速排序：选择数组的最后一个元素arr[l]为基准元素，然后开始从数组的的一个数字开始遍历，比这个基准元素小的放在前面即,arr[j]小于基准,进行i+1,arr[i+1]与arr[j]swap，
//比这个大的就不动，最后比较到基准元素与i+1的那个元素相交换，进入到第二次的快速排序。前一个数组就用arr[i]后一个数组就是arr[l]
template<class T>
void quicksort(T data[],int first ,int last){
    int lower = first + 1,upper = last;
    swap(data[first],data[(first+last)/2]); //第一个与中间一个换位置
    T bound = data[first];
    while (lower <= upper){
        while (data[lower] < bound){
            lower++;
        }
        while (bound < data[upper]){
            upper--;
        }
        if (lower < upper){
            swap(data[lower++],data[upper--]);
        } else{
            lower++;
        }
        swap(data[upper],data[first]);
        if(first < upper - 1){
            quicksort(data,first,upper-1);
        }
        if(upper+1 < last){  //正确的工作学习状态 全方位地思考 逻辑 结构 细节 方法 ，边缘区的心流沉醉
            quicksort(data,upper+1,last);
        }
    }
}
template<class T>
void quicksort(T data[],int n){ //工科的东西简单而又有趣  动手的东西有什么难的
    if (n<2) return;
    for (int i = 1,max = 0;i <n ;i++){
        if(data[max] < data[i]){
            max = i;
        }
        swap(data[n-1],data[max]);
        quicksort(data,0,n-2);
    }
}



