class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int maxLen=1;
        vector<vector<int>> table(n,vector<int>(n,0));
        for(int i=0; i<n ;i++){
            table[i][i]=1;
        }
        int start=0;
        for(int i=0; i<n-1;i++){
            if(s[i]==s[i+1]){
                table[i][i+1]=1;
                start=i;
                maxLen=2;
            }
        }
      
        for(int k=3;k<=n;k++){
            for(int i=0;i<n-k+1;i++){
                int j=i+k-1;
                if(table[i+1][j-1] && s[i]==s[j]){
                    table[i][j]=1;
                    maxLen=k;
                    start=i;

                }
            }
        }

        return s.substr(start,maxLen);
    }
};