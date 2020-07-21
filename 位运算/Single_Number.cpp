在一个数组中除了一个数字只出现一次之外，其他数字都出现了三次。
请找出那个只出现一次的数字。
你可以假设满足条件的数字一定存在。

思考题：
如果要求只使用 O(n) 的时间和额外 O(1) 的空间，该怎么做呢？

样例
输入：[1,1,1,2,2,2,3,4,4,4]

输出：3



class Solution {
public:
    int findNumberAppearingOnce(vector<int>& nums) {
        int count = 0;
        for(int k = 0 ; k < 32 ; k++){
            int ans = 0;
            for(int i = 0 ; i < (int)nums.size() ; i++){
                ans += (nums[i] >> k) & 1;
            }
            count += (ans % 3) << k;
        }
        return count;
    }
};