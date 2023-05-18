class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int n=prices.size();
        int i=0;
        for(int k=1;k<n;k++){
            ans=max(ans,prices[k]-prices[i]);
            if(prices[k]<prices[i]){
                i=k;
            }
        }
        return ans;
    }
};