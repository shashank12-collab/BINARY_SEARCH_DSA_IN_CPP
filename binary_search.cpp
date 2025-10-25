#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr , int target)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1 ;
    while(low <= high)
    {
        int mid = (low + high ) / 2;

        if(arr[mid] == target)
        {
            return mid;
        }

        else if(arr[mid] < target)
        {
            low = mid+1;
        }
        else
        {
            high = mid -1 ;
        }
    }
    return -1 ;
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

    int ans = binarySearch(arr , 4);
    cout << ans;
    return 0 ;
}