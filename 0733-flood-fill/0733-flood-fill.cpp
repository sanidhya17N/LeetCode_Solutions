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
        int target=image[sr][sc];
         int n=image.size();
        int m=image[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        dfs(sr,sc,color,target,image,visited);
        return image;       
    }
};