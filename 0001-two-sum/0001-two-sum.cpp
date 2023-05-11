class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for (int i=0;i<nums.size();i++){

            //checking if map contains target-nums[i]
            if(mp.find(target-nums[i])!=mp.end()){
                ans.emplace_back(i);
                ans.emplace_back(mp[target-nums[i]]);
                return ans;
            }

            // checking if nums[i] is already in the map  
            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]]=i;
            }
        }  

        
        return ans;
    }
};

            