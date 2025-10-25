#include<bits/stdc++.h>
using namespace std;

pair<int , int> Search_in_2D_matrix(vector<vector<int>> & matrix , int x)
{
    int low = 0;
    int n = matrix.size();
    int m = matrix[0].size();
    int high = (n*m-1);
    int ans = -1;

    while(low <= high)
    {
        int mid = (low + high) /2;
        int row = mid / m;
        int col = mid % m ;

        if(matrix[row][col] == x)
        {
            return {row , col};
        }
        else if(matrix[row][col] < x)
        {
            low = mid +1;
        }
        else
        {
            high = mid - 1 ;
        }
    }
    return {-1 , -1};
}

int main() {
    int n, m;
    cout << "Enter number of rows: ";
    cin >> n;
    cout << "Enter number of columns: ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter the elements row-wise (each row sorted):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    pair<int,int>answer = Search_in_2D_matrix(matrix , 5);
    if (answer.first == -1)
        cout << "Element not found"<<endl;
    else
        cout << "Element found at row " << answer.first << " and column " << answer.second ;
    return 0;
}