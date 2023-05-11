class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> forwardPass(n,1);
        vector<int> productArr(n,1);
        vector<int> backwardPass(n,1);
      
        for(int i=1;i<n;i++){
            forwardPass[i]=nums[i-1]*forwardPass[i-1];
            backwardPass[n-i-1]=nums[n-i]*backwardPass[n-i];
        }
        for(int i=0;i<n;i++){
            productArr[i]=forwardPass[i]*backwardPass[i];
        }
        
        return productArr;
    }
};