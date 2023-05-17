class Solution {
public:
 


    void solve(vector<int>& nums, int target,int index ,vector<int>&path,vector<vector<int>>& ans){
        int i=index;
        int j=nums.size()-1;
        while(i<j){
           
            if(nums[i]+nums[j]==target){
                if(nums[i]==nums[i-1] && (j<nums.size()-1 && nums[j]==nums[j+1])){
                    i++;
                    j--;
                    continue;
                }
                path.emplace_back(nums[i]);
                path.emplace_back(nums[j]);
                ans.emplace_back(path);
                path.pop_back();
                path.pop_back();
                i++;
                j--;
            }else if(nums[i]+nums[j]<target){
                i++;
            }else{
                j--;
            }
        }

        
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        if(n<3){
            return ans;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i-1]==nums[i]){
                continue;
            }
            if(nums[i]<=0){
                vector<int> path;
                path.emplace_back(nums[i]); 
                solve(nums,0-nums[i],i+1,path,ans);
            }
           
        }
        return ans;





    }
};