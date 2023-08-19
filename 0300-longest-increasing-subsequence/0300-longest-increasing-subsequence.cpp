class Solution {
public:
    int solve(vector<int>& nums,int index,int prev,vector<vector<int>>& dp){
        int n=nums.size();
        if(index==n)return 0;
        if(dp[index][prev+1]!=-1)return dp[index][prev+1];
        int notTake=0;
        int take=0;
        if(prev>=0 && nums[index]<=nums[prev]){
            notTake=solve(nums,index+1,prev,dp);   
        }else{
            take=1+solve(nums,index+1,index,dp);
            notTake=solve(nums,index+1,prev,dp);
        }

        return dp[index][prev+1]=max(take,notTake);


    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(nums,0,-1,dp);
    }
};