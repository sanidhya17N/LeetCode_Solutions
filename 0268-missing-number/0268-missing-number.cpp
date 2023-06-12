class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum=n*(n+1)/2;
        int tempsum=0;
        for(auto x : nums){
            tempsum+=x;
        }
        return sum-tempsum;
    }
};