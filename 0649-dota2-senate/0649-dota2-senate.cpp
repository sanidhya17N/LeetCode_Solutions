class Solution {
public:
    string predictPartyVictory(string senate) {
      
        int n=senate.length();
        
        queue<int> R;
        queue<int> D;

        for(int i=0;i<n;i++){
            if(senate[i]=='R'){
                R.push(i);
            }else{
                D.push(i);
            }
        }
        int index=n;
        while(!R.empty() && !D.empty()){
            if(R.front()<D.front()){
                D.pop();
                R.push(index);
                R.pop();
                index++;
                
            }else{
                R.pop();
                D.push(index);
                D.pop();
                index++;
            }
        }

        if(R.empty()){
            return "Dire";
        }else{
            return "Radiant";
        }
        
        
    }
};