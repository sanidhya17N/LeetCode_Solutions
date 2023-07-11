class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j=i+1;j<n;j++){
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int k=j+1,m=n-1;
                while(k<m){
                    long long sum=nums[i]+nums[j];
                    if(sum+nums[k]+nums[m]==target){
                        vector<int> temp={nums[i],nums[j],nums[k],nums[m]};
                        ans.push_back(temp);
                        k++,m--;

                        while(k<m && nums[k]==nums[k-1])k++;
                        while(k<m && nums[m]==nums[m+1])m--;
                    }
                    else if(sum+nums[k]+nums[m]>target){
                        m--;
                    }else{
                        k++;
                    }
                }

            }
        }
        
        return ans;

        
    }
};