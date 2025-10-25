#include<bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &row, int target) {
    int low = 0, high = row.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (row[mid] <= target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low; 
}

int countSmall(vector<vector<int>> & matrix , int x)
{
    int cnt = 0;
    for(int i = 0 ; i < matrix.size() ; i++)
    {
        cnt += upperBound(matrix[i] , x);
    }
    return cnt;
}

int median(vector<vector<int>> & matrix )
{
    int low = INT_MAX;
    int high = INT_MIN;
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i = 0 ; i < n ; i++)
    {
        low = min(low , matrix[i][0]);
        high = max(high , matrix[i][m-1]);
    }

    int req = (n * m) / 2;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        int smallEqual = countSmall(matrix , mid);
        if(smallEqual <= req) low = mid +1;
        else high=mid - 1;
    }
    return low;

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

    cout << "The median is: " << median(matrix) << endl;
    return 0;
}