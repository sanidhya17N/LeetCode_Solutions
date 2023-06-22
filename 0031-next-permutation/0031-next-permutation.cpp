class Solution {
public:
    void reverse(vector<int>& nums,int start){
        int n=nums.size();
        for(int i=start ; i<=(n+start)/2-1 ; i++){
            swap(nums[i],nums[n-(i-start)-1]);
        }
    }
    void nextPermutation(vector<int>& nums) { 
        int n=nums.size();
        int breakIndex=-1;
        for(int i=n-2 ;i>=0 ;i--){
            if(nums[i]<nums[i+1]){
                breakIndex=i;
                break;
            }
        }

        if(breakIndex!=-1){
            
            for(int i=n-1;i>=0;i--){
                if(nums[i]>nums[breakIndex]){
                    swap(nums[i],nums[breakIndex]);
                    break;
                }
            }
            reverse(nums,breakIndex+1);
        }else{
            reverse(nums,0);
        }



        
    }
};