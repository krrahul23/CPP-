#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        int ans = INT_MIN;
        ans = helper(nums, 0, nums.size() - 2);
        ans = max(ans, helper(nums, 1, nums.size() - 1));

        return ans;
    }

private:
    int helper(vector<int> &nums, int start, int end)
    {
        if (start == end)
            return nums[start];
        vector<int> dp(nums.size());
        dp[start] = nums[start];
        dp[start + 1] = max(dp[start], nums[start + 1]);

        for (int i = start + 2; i <= end; i++)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[end];
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
    Solution a = Solution();
    vector<int> v = {2, 3, 2};
    int ans = a.rob(v);
    cout << ans << endl;
    return 0;
}