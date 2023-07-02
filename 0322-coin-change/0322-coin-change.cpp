class Solution {
public:
    int solver(vector<int>& coins, int amount , int index,vector<vector<int>>& memo){
        if(amount==0){
            return 0;
        }
        if(index==0){
            if(amount%coins[index]==0){
                return amount/coins[index];
            }else{
                return INT_MAX;
            }
        }


        if(memo[index][amount]!=-1)return memo[index][amount];

                        // not take
        int nottake=solver(coins,amount,index-1,memo);
        int take=INT_MAX;
        if(amount>=coins[index]){
            take=solver(coins,amount-coins[index],index,memo);
            if(take!=INT_MAX)take++;
        }
                        // take
        
        
        return memo[index][amount]=min(nottake,take);

        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(),coins.end());
        vector<vector<int>> memo(n,vector<int>(amount+1,-1));
        int ans=solver(coins,amount,n-1,memo);
        if(ans==INT_MAX)ans=-1;
        return ans;
    }
};