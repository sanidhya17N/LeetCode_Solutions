class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        while(i<j){
            if(nums[i]==0){
                i++;
            }else if(nums[j]==1 || nums[j]==2){
                j--;
            }
            else{
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
        }
        i=0,j=n-1;
        while(i<j){
            if(nums[i]==0){
                i++;
            }else if(nums[j]==2){
                j--;

            }else if(nums[i]==1){
                i++;
            }else{
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
            
        }
    
    }


};