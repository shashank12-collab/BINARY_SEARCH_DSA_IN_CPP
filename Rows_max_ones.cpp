#include<bits/stdc++.h>
using namespace std;

int lowerbound(vector<int> & arr , int target)
{
    int n = arr.size();
    int low = 0 ;
    int high = n - 1;
    int ans = n;
    
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(arr[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int rowWithMaxOne(vector<vector<int>>& a )
{
    int cnt_max = -1 ;
    int index = -1;
    int n = a.size();
    int m = a[0].size();

    for(int i = 0 ; i < n ; i++)
    {
        int cnt_ones  = m - lowerbound(a[i] , 1);
        if(cnt_ones > cnt_max)
        {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}

int main()
{
    int n;
    cout<<"Enter the number of rows: ";
    cin >> n;

    int m; 
    cout<<"enter the number of col: ";
    cin>>m;

    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0 ; i < n ; i++)
    {
        cout<<endl;
        for(int j = 0 ; j < m ; j++)
      {
        cin >> a[i][j];
      }
    }

    int answer = rowWithMaxOne(a);
    cout << "The row with max ones: " << answer;
    return 0;
}