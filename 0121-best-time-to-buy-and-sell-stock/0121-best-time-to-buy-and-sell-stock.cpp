class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int n=prices.size();
        int j=0;
        int buyPrice=INT_MAX;
        while(j<n){
            if(prices[j]<buyPrice){
                buyPrice=prices[j];
                
            }

            ans=max(ans, prices[j]-buyPrice);
            j++;
        }
        return ans;
    }
};