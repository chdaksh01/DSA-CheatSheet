// Easy - Just need to traverse the graph with pair and queue applications

// https://leetcode.com/problems/flood-fill/


class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int n=image.size(), m = image[0].size();
        int vis[n][m];
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                vis[i][j]=0;
            }
        }
        vis[sr][sc]=1;
        int col=image[sr][sc];
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            image[x][y]=color;
            if (x-1>=0 && image[x-1][y]==col && !vis[x-1][y])
            {
                q.push({x-1, y});
                vis[x-1][y]=1;
            }
            if (x+1<n && image[x+1][y]==col && !vis[x+1][y])
            {
                q.push({x+1, y});
                vis[x+1][y]=1;
            }
            if (y+1<m && image[x][y+1]==col && !vis[x][y+1])
            {
                q.push({x, y+1});
                vis[x][y+1]=1;
            }
            if (y-1>=0 && image[x][y-1]==col && !vis[x][y-1])
            {
                q.push({x, y-1});
                vis[x][y-1]=1;
            }

        }
        return image;

    }
};
