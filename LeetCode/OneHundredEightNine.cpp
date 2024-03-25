//
// Created by zy_ on 24-3-11.
//
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    static void rotate(std::vector<int> &nums, int k) {
        int size = static_cast<int>(nums.size());
        k %= size;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> vec(nums,nums+sizeof(nums)/sizeof(int));
    Solution::rotate(vec,2);
    for(int num:vec){
        std::cout <<num << "  "<< std::endl;
    }
    return 0;
}