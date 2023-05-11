class Solution {
public:
    int twoSumClosest(vector<int>&nums,int target,int i){
        int ans=0;
        int j=nums.size()-1;
        int minGap=INT_MAX;
        while(i<j){
            if(abs(target-(nums[i]+nums[j]))<minGap){
                ans=nums[i]+nums[j];
                minGap=abs(target-(nums[i]+nums[j]));
            }
            if((nums[i]+nums[j])<target){
                i++;
            }else{
                j--;
            }
        }
        return ans;
        
    }
    int threeSumClosest(vector<int>& nums, int target) {
         int ans=INT_MAX;
         int sum=0;
         int n=nums.size();
         sort(nums.begin(),nums.end());
         for(int i=0;i<n-2;i++){
             int temp=twoSumClosest(nums,target-nums[i],i+1);
             if(abs(target-(temp+nums[i]))<ans){
                 ans=abs(target-(temp+nums[i]));
                 sum=temp+nums[i];
             }
         }
         return sum;
    }

};