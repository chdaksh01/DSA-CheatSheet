//Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
//https://leetcode.com/problems/set-matrix-zeroes/description/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m= matrix.size();
        int n= matrix[0].size();
        unordered_map<int, int> mpi;
        unordered_map<int, int> mpj;
        for (int i=0; i<m; i++)
        {
            // if (mpi[i]) {continue;}
            for (int j=0; j<n; j++)
            {
                if (matrix[i][j]==0)
                {
                    mpi[i]++; mpj[j]++;
                    
                }
            }
        }

        for (int i=0; i<m; i++)
        {
            // if (mpi[i]) {continue;}
            for (int j=0; j<n; j++)
            {
                if (mpi[i] || mpj[j]) {matrix[i][j]=0;}
            }
        }
    }
};
