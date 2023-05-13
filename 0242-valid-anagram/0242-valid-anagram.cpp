class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.length();
        int m=t.length();
        
        if(n!=m)return false;
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }
        for(int i=0; i<n; i++){
            if(mp.find(t[i])!=mp.end()){
                
                mp[t[i]]--;
                if(mp[t[i]]==0)mp.erase(t[i]);
            }else{
                return false;
            }
                
        }
        return true;
    }
};