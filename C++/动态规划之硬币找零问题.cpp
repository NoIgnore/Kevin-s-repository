// 给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

// 示例 1:

// 输入: coins = [1, 2, 5], amount = 11
// 输出: 3 
// 解释: 11 = 5 + 5 + 1

// 示例 2:

// 输入: coins = [2], amount = 3
// 输出: -1

// 说明:
// 你可以认为每种硬币的数量是无限的。
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);//vector<int> list5(7,3);指定值初始化，list5被初始化为包含7个值为3的int
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) //for(int a:b) 从数组b依次取出元素赋值给整形变量a，循环执行for中语句 
            if (coin <= i)
                dp[i] = min(dp[i], dp[i - coin] + 1);
    }
    return dp[amount] > amount ? -1 : dp[amount];
}