class Solution {
public:
    /* Logic is that if a Positive number is missing it would be in between from 1 to n or the ans will be n+1 .
       So we will be taking elements from 1 to n to their respective postion . For eg:
       arr={-1,-2,0,1,4,5,3}
       we will change it to 
       index 0   1  2  3  4   5  6
       arr={`1 ,-2 ,3 ,4 ,5 ,-1 ,0}
       so we index+1 element exists we put it in position index
       Traverse again ans the index which is missing gives us answer as i+1
            
    */
    
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int element=nums[i];
            if(element>0 && element<=n){
                int chair=element-1; // chair is element's postion we want 
                if(nums[chair]!=element){
                    swap(nums[chair],nums[i]);
                    i--; // i-- because swap can put another element at a unwanted postion 
                }
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
    }
};
