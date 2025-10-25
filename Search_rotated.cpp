#include<bits/stdc++.h>
using namespace std;

vector<int> reversearr(vector<int> & arr , int k)
{
    int n = arr.size(); 
    k = k % n; 
    reverse(arr.begin(), arr.begin() + (n - k));
    reverse(arr.begin() + (n - k), arr.end());
    reverse(arr.begin(), arr.end());

    return arr;
}

int rotate(vector<int> & arr , int target)
{
    int n = arr.size();
    int low = 0 ;
    int high = n - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(arr[mid] == target)
        {
            return mid;
        }

        //now check which part is sorted left or right
        //left sortrd
        if(arr[low] <= arr[mid])
        {
            if(arr[low] <= target && target <= arr[mid])
            {
                high = mid -1;
            }
            else
            {
                low = mid +1 ;
            }
        }

        else
        {
            if(arr[mid] <= target && target <= arr[high])
            {
                low = mid +1;
            }
            else
            {
                high = mid -1;
            }
        }

    }
    return -1;
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

    vector<int> ans = reversearr(arr , 5);
    cout<<"the reversed arr is:";
    for( int i = 0 ; i < arr.size() ; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;

    int ns = rotate(arr , 5);
    cout << "The target is at index no:" << ns;

    

    return 0 ;
}