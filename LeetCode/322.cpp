#include <bits/stdc++.h>
using namespace std;
/* 
top - down approach


vector<int> change(amount+1,1e5);
change[0] = 0;

for(int i=1;i<=amount;i++) {
    for(auto j:coins) {
        if(i-j>=0)
        change[i] = min(change[i], change[i-j]+1);
    }
    if(change[amount]== 1e5)return -1;
    else return change[amount];
}
*/
class Solutin
{
public:
    vector<int> change;
    int coinChange(vector<int> &coins, int amount)
    {
        change.resize(amount + 1, 1e5);
        change[0] = 0;

        return util(amount, coins);
    }

private:
    int util(int amount, vector<int> &coins)
    {
        if (change[amount] != 1e5)
            return change[amount];
        else
        {
            int result = 1e6;

            for (auto i : coins)
            {
                if (amount - i >= 0)
                {
                    result = min(result, util(amount - i, coins) + 1);
                }
            }
            return change[amount] = result;
        }
    }
};

int main()
{
    return 0;
}