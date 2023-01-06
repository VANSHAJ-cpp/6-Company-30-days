/* 
  Q 2344. Minimum Deletions to Make Array Divisible ( https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/description/ )
*/
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(), nums.end());
        int gcd = numsDivide[0];
        for (int i = 1; i < numsDivide.size(); i++) {
            gcd = __gcd(gcd, numsDivide[i]);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (__gcd(gcd, nums[i]) == nums[i]) {
                return i;
            }
        }
        return -1;
    }
};
                                                   
