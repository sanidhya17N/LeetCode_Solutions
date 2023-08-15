class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;
        int n=asteroids.size();
        for(int i=0;i<n;i++){
            if(asteroids[i]>0){
                st.push(asteroids[i]);
            }else{
                if(st.empty() || st.top()<0){
                    st.push(asteroids[i]);
                }else{
                    if(abs(asteroids[i])>st.top()){
                        while(!st.empty() && abs(asteroids[i])>st.top()){
                            if(st.top()<0){
                                st.push(asteroids[i]);
                                break;
                            }
                            st.pop();
                        }
                        if(st.empty()){
                            st.push(asteroids[i]);
                        }
                        if(!st.empty() && abs(asteroids[i])==st.top()){
                            st.pop();
                        }
                        
                        
                    }else if(abs(asteroids[i])==st.top()){
                        st.pop();
                    }
                }

            }

        }
       

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;    
    }
};