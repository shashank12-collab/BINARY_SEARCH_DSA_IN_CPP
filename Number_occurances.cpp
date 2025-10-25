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

    int Count(vector<int>&arr , int target)
    {
        
        vector<int> ans = searchRange(arr , target);

        if(ans[0] == -1)
        {
            return 0;
        }
        return ans[1] - ans[0] + 1 ;

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

    int ans = Count(arr , 3);
    cout << "the  occurance is:" << ans;
    

    

    return 0 ;
}