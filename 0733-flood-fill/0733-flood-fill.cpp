class Solution {
public:
    void dfs(int r,int c,int color,int target,vector<vector<int>>& image,vector<vector<int>>& visited){
        int n=image.size();
        int m=image[0].size();
        
        if(image[r][c]!=target)return;
        image[r][c]=color;
        visited[r][c]=1;
        int dr[4]={0,-1,0,1};
        int dc[4]={1,0,-1,0};
        for(int i=0;i<4;i++){
     
            if(r+dr[i]<0 || r+dr[i]>n-1 || c+dc[i]<0 || c+dc[i]>m-1)continue;
            if(visited[r+dr[i]][c+dc[i]]==1)continue;
            r+=dr[i];
            c+=dc[i];
            dfs(r,c,color,target,image,visited);
            r-=dr[i];
            c-=dc[i];
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         int n=image.size();
        int m=image[0].size();
        int oldColor=image[sr][sc];
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        while(!q.empty()){
            int row=q.front().first, col=q.front().second;
            q.pop();
            vis[row][col]=1;
            image[row][col]=color;
            if(row-1>=0 && image[row-1][col]==oldColor && !vis[row-1][col]){
                q.push({row-1,col});
            }
            if(row+1<n && image[row+1][col]==oldColor && !vis[row+1][col]){
                q.push({row+1,col});
            }
            if(col-1>=0 && image[row][col-1]==oldColor && !vis[row][col-1]){
                q.push({row,col-1});
            }
            if(col+1<m && image[row][col+1]==oldColor && !vis[row][col+1]){
                q.push({row,col+1});
            }
            
        }
        
        return image;      
    }
};