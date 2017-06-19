class Solution{
    public:
        vector<int> printMatrix(vector<vector<int> > matrix){
            vector<int> output;
            int row = matrix.size();
            int col = matrix[0].size();
            int circle = ((row>col?col:row)-1) / 2 + 1;
            for (int i=0;i<circle;i++)
            {
                for (int j=i;j<col-i;j++)
                {
                    output.push_back(matrix[i][j]);
                }
                for (int k=i+1;k<row-i;k++)
                {
                    output.push_back(matrix[k][col-i-1]);
                }
                for (int j=col-i-2;j>=i && (i+1!=row-i);j--)
                {
                    output.push_back(matrix[row-i-1][j]);
                }
                for (int j=row-i-2;j>i && (col-i-2!=i-1);j--)
                {
                    output.push_back(matrix[j][i]);
                }
            }
            return output;
        }

};
