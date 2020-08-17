#include<iostream>
#include<vector>

using namespace std;

// Transposes a square matrix with respect to the main diagonal
vector<vector<int>> transposeLeadingDiagonal(const vector<vector<int>> & matrix, int n) {
    
    vector<vector<int>> transpose_matrix(n,vector<int>(n,0));
    
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
            transpose_matrix[j][i]= matrix[i][j];
        }
    }

    return transpose_matrix;
}

// Transposes a square matrix with respect to the secondary diagonal
vector<vector<int>> transposeOtherDiagonal(const vector<vector<int>> &matrix, int n) {

    vector<vector<int>> transpose_matrix = matrix;

    for(int i=0;i<(n-1);++i) {
        for(int j=0; j<(n-1)-i;++j)
        {
         int temp = transpose_matrix[i][j];
         transpose_matrix[i][j] = transpose_matrix[(n - 1) - j][(n - 1) - i];
         transpose_matrix[(n - 1) - j][(n - 1) - i] = temp;
        }
    }

    return transpose_matrix;
}

void printMatrix(const vector<vector<int>> &matrix) {
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout<<matrix[i][j]<<'\t';
        }
        cout<<"\n";
    }
}

int main(int argc, char **argv)
{
    vector<vector<int>> a{{1,2,3},{4,5,6},{7,8,9}};
    printMatrix(a);

    cout<<"Transpose by leading diagonal\n";

    printMatrix(transposeLeadingDiagonal(a, 3));
    
    cout<<"Transpose by secondary diagonal\n";
    printMatrix(transposeOtherDiagonal(a, 3));

    return 0;
}