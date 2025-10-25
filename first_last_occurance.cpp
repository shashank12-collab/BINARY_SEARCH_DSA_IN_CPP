#include<bits/stdc++.h>
using namespace std;

int first_occurance(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0 ;
    int high = n - 1 ;
    int first = -1;

    while(low <= high)
    {
        int mid = (low + high ) / 2;

        if(arr[mid] == target)
        {
            first = mid;
            high = mid -1 ;
        }

        else if(arr[mid] < target)
        {
            low= mid +1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return first;
}

int last_occurance(vector<int> &arr , int target)
{
    int n = arr.size();
    int low = 0 ;
    int high = n - 1 ;
    int last = -1;

    while(low <= high)
    {
        int mid = (low + high ) / 2;

        if(arr[mid] == target)
        {
            last = mid;
            low = mid +1 ;
        }

        else if(arr[mid] < target)
        {
            low= mid +1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return last;
}

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = first_occurance(nums  , target);
        if(first == -1) return { -1 , -1};
        int last = last_occurance(nums  , target);
        return {first , last};
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

    vector<int> ans = searchRange(arr , 3);
    cout << "the first and last occurance is:";
    for(int  i = 0 ; i < ans.size() ; i++)
    {
        cout << ans[i] << " ";
    }

    

    return 0 ;
}