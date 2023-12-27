//
// Created by zy_ on 23-12-26.
//
//定义解空间 及 给所有的物品按照单位价值从大到小排序
//创建解空间树：再按照每个物品选与不选分出左叉和右叉
//对解空间树进行dfs
//使用剪枝函数 及判断后面情况的树的价值是否有可能比当前选出来的高。  限界函数=已有价值+还可装入最大价值
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void sort(vector<int> weights,vector<int> values){

}

int main() {
    // 示例数据
    vector<int> weights = {1,2, 3, 4, 5};
    vector<int> values = {5,4,3,2,1};
    int capacity = 2;

    // 解决01背包问题
    solve01Knapsack(capacity, weights, values);

    return 0;
}
