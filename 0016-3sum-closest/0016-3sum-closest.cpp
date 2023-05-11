class Solution {
public:
    int twoSumClosest(vector<int>&nums,int target,int i){
       /* this function will traverse the array in two pointer manner , if target - (nums[i] + nums[j] )< minGap , we will store the ans . 
          if our sum < target i++ else j-- . Logic being array is sorted so it to get closer it is understood that i++ will be required at lesser sum and 
          j-- at the reverse condition
       */
        
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
         int minGap=INT_MAX;
         int sum=0;
         int n=nums.size();
         // Sorting will help in twoSumClosest Function
         sort(nums.begin(),nums.end());
         for(int i=0;i<n-2;i++){
             // twoSumClosest returns two numbers with closet sum to (target - nums[i])  
             int temp=twoSumClosest(nums,target-nums[i],i+1);
             if(abs(target-(temp+nums[i]))<minGap){
                 minGap=abs(target-(temp+nums[i])); //updating minGap is a closer ans is achieved
                 sum=temp+nums[i];
             }
         }
         return sum;
    }

};
