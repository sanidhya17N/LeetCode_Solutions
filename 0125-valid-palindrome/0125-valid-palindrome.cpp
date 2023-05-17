class Solution {
public:
                                                                                           bool isPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<=j){
            s[i]=tolower(s[i]);
            s[j]=tolower(s[j]);
            bool change=false;
            if((!(s[i]>='a') || !(s[i]<='z')) && (!(s[i]>='0') || !(s[i]<='9'))){
                i++;
                change=true;
            }
            if((!(s[j]>='a') || !(s[j]<='z')) && (!(s[j]>='0') || !(s[j]<='9'))){
                j--;
                change=true;
            }
            if(change)continue;
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
            
        }
        return true;
    }
};