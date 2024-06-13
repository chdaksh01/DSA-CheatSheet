// Easy - Using pairs is essential!
// Just need to traverse the graph

// https://leetcode.com/problems/number-of-islands/

// T.C. = O(N^2) + O(5N^2) = O(N^2)
// -> TC analysis is important


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        int vis[n][m];
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                vis[i][j]=0;
            }
        }
        int isl=0;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (grid[i][j]=='1' && !vis[i][j])
                {
                    isl++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while(!q.empty())
                    {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        if (x-1>=0 && grid[x-1][y]=='1' && !vis[x-1][y])
                        {
                            vis[x-1][y]=1;
                            q.push({x-1, y});
                        }
                        if (y+1<m && grid[x][y+1]=='1' && !vis[x][y+1])
                        {
                            vis[x][y+1]=1;
                            q.push({x, y+1});
                        }
                        if (x+1<n && grid[x+1][y]=='1' && !vis[x+1][y])
                        {
                            vis[x+1][y]=1;
                            q.push({x+1, y});
                        }
                        if (y-1>=0 && grid[x][y-1]=='1' && !vis[x][y-1])
                        {
                            vis[x][y-1]=1;
                            q.push({x, y-1});
                        }

                    }
                } 
            }
        }
        return isl;
    }
};
