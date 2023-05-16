class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
          s.insert(nums[i]);
        }

        for (int i=0;i<n;i++){
            if(s.find(nums[i]-1)!=s.end()){
                continue;
            }else{
                int j=nums[i];
                while(s.find(j+1)!=s.end()){
                    j++;
                }
                ans=max(ans,j-nums[i]+1);
            }

            
        }
        return ans;
    }
};