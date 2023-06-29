class Solution {
public:
    bool dfs(vector<int>& nums,int index,int sum,vector<vector<int>>& memo){
        if(index==nums.size())return false;
        if(sum==0)return true;
        if(memo[index][sum]!=-1)return memo[index][sum];
        if(nums[index]<=sum){
            return memo[index][sum]=dfs(nums,index+1,sum-nums[index],memo)||dfs(nums,index+1,sum,memo);
        }else{
            return memo[index][sum]=dfs(nums,index+1,sum,memo);
        }
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }else{
            sum=sum/2;
        }
        vector<vector<int>> memo(n,vector<int>(sum+1,-1));

       return dfs(nums,0,sum,memo);
    }
};