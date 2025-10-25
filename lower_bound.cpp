#include<bits/stdc++.h>
using namespace std;

int lowerbound(vector<int> & arr  ,int target)
{
    int n = arr.size();
    int ans = -1;
    int low = 0 ;
    int high = n -1 ;

    while(low <= high)
    {
        int mid = (low + high) / 2 ;

        if(arr[mid] >= target)
        {
            ans = mid;
            high = mid -1;
        }
        else 
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{

    int n;
    cout << " Enter the number of element in array:" ;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the element of the array: " ; 
    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i];
    }

    int ns = lowerbound(arr , 6);
    cout << "The lower bound is at index:" << ns ;
    return 0 ;
}