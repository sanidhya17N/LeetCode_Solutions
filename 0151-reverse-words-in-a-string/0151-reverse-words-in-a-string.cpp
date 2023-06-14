class Solution {
public:
    string reverseWords(string s) {
        string temp="";
        string ans="";
        
        int n=s.length();
        for(int i=n-1 ;i>=0;i--){

            if(s[i]==32 && temp=="") continue;
            if(s[i]==32){
                ans+=temp+" ";
                temp="";
            }else{
                temp=s[i]+temp;
            }

            
        }

        if(s[0]!=32)ans+=temp;
        else ans.erase(ans.length()-1,ans.length());
        return ans;
    }
};