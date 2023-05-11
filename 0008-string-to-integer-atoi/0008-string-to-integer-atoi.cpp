class Solution {
public:
    int myAtoi(string s) {
        map<int,int>mp={{48,0},{49,1},{50,2},{51,3},{52,4},{53,5},{54,6},{55,7},{56,8},{57,9}};
        long long int ans=0;
        int sign=1;
        bool num=false;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]==32 || s[i]==43 || s[i]==45){
                if(num==true){
                    break;
                }
                if(s[i]==32){
                    continue;
                }
                if(s[i]==43){
                    sign=1;
                    num=true;
                }else if(s[i]==45){
                    sign=-1;
                    num=true;
                }
              
            }else if(s[i]>=48 && s[i]<=57){
                num=true;
                long long int temp=ans*10+mp[s[i]];
                if(temp>INT_MAX && sign==1){
                    ans=INT_MAX;
                    return ans;
                }else if(temp*(-1)<INT_MIN && sign==-1){
                    ans=INT_MIN;
                    return ans;
                }
                else{ans=ans*10+mp[s[i]];}
                
            }else{
                if(num==false){
                    return 0;
                }else{
                    break;
                }
                continue;
            }
            
        }
        if(sign==-1){
            return ans=ans*(-1);
        }
        return ans;
        
    }
};