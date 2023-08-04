//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    bool isvalid(int i,int j,int row,int col,int oldcolor,vector<vector<int>>&vis,vector<vector<int>>&image){
        if(i>=0 && i<row && j>=0 && j<col && (!vis[i][j]) && image[i][j]==oldcolor){
            return true;
        }
        return false;
    }
    void bfs(int r,int c,int newcolor,int oldcolor,vector<vector<int>>&vis,vector<vector<int>>&image){
        queue<pair<int,int>>q;
        q.push({r,c});
        int n=image.size();
        int m=image[0].size();
        vis[r][c]=1;
        image[r][c]=newcolor;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second; 
            q.pop();
            // cout<<row<<" "<<col<<endl;
            if(isvalid(row-1,col,n,m,oldcolor,vis,image)){
                q.push({row-1,col});
                vis[row-1][col]=1;
                image[row-1][col]=newcolor;
            }
            if(isvalid(row+1,col,n,m,oldcolor,vis,image)){
                q.push({row+1,col});
                vis[row+1][col]=1;
                image[row+1][col]=newcolor;
            }
            if(isvalid(row,col-1,n,m,oldcolor,vis,image)){
                q.push({row,col-1});
                vis[row][col-1]=1;
                image[row][col-1]=newcolor;
            }
            if(isvalid(row,col+1,n,m,oldcolor,vis,image)){
                q.push({row,col+1});
                vis[row][col+1]=1;
                image[row][col+1]=newcolor;
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int oldcolor=image[sr][sc];
        bfs(sr,sc,newColor,oldcolor,vis,image);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends