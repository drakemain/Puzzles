// https://leetcode.com/submissions/detail/89150794/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

class Solution {
public:

    // this is the member function the leetcode solution expects
    int singleNumber(std::vector<int>& nums) {
        return this->xorSolution(nums);
    }

    int mapSolution(std::vector<int>& nums) {
        std::unordered_map<int, int> valueCount;
        
        for (int value : nums) {
            ++valueCount[value];
        }
        
        for(std::pair<int, int> value : valueCount) {
            if (value.second == 1) {
                return value.first;
            }
        }
        
        return 0;
    }
    
    int xorSolution(std::vector<int>& nums) {
        int result = 0;
        for (int value : nums)
        {
            result ^=value;
        }
        return result;
    }
};

int main() {
    Solution findSingleNumber;

    std::vector<int> set0{1, 1, 2, 2, 3, 4, 4, 5, 5}; // 3
    std::vector<int> set1{3, 1, 6, 3, 7, 8, 7, 1, 6}; // 8
    std::vector<int> set2{10, 13, 5, 13, 5}; // 10
    std::vector<int> set3{1}; //1

    assert(findSingleNumber.mapSolution(set0) == 3);
    assert(findSingleNumber.xorSolution(set0) == 3);

    assert(findSingleNumber.mapSolution(set1) == 8);
    assert(findSingleNumber.xorSolution(set1) == 8);

    assert(findSingleNumber.mapSolution(set2) == 10);
    assert(findSingleNumber.xorSolution(set2) == 10);

    assert(findSingleNumber.mapSolution(set3) == 1);
    assert(findSingleNumber.xorSolution(set3) == 1);

    std::cout << "All 'Single List' tests passed." << std::endl;
}