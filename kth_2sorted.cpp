#include<bits/stdc++.h>
using namespace std;

int kthelementofarr(vector<int>& arr1 , vector<int>& arr2, int k)
{
    int n1 = arr1.size();
    int n2 = arr2.size();

    if(n1 > n2) return kthelementofarr(arr2 , arr1 , k);

    int low = max(0 , k - n2);
    int high = min(k , n1);
    int left = k;

    while(low <= high) 
    {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;

        int l1 = INT_MIN;
        int l2 = INT_MIN;
        int r1 = INT_MAX;
        int r2 = INT_MAX;

        if(mid1 < n1) r1= arr1[mid1];
        if(mid2 < n2) r2 = arr2[mid2];

        if(mid1 - 1 >= 0) l1 = arr1[mid1 -1];
        if(mid2 - 1 >= 0) l2 = arr2[mid2 -1];

        if(l1 <= r2 && l2 <= r1)
        {
            return max(l1 , l2);
        }
        else if(l1 > r2) high = mid1 -1;
        else low = mid1 + 1;

    }
    return -1;
}

int main()
{
    int n ;
    int m;
    vector<int> arr1;
    vector<int> arr2;
    int index;

    cout<< " Enter the number of element in arr1: ";
    cin >> n;

    cout <<" the element of arr 1 is: ";
    arr1.resize(n);
    for(int i = 0 ; i < n ;i++)
    {
        cin >> arr1[i]; 
    }

    cout<< " Enter the number of element in arr2: ";
    cin >> m;

    cout <<" the element of arr2 is: ";
    arr2.resize(m);
    for(int i = 0 ; i < m ;i++)
    {
        cin >> arr2[i]; 
    }

    cout << "enter the index at which element you want: ";
    cin >> index;

    int ans = kthelementofarr(arr1 , arr2 , index);
    cout  << " the value at " << index << " is " << ans;

    return 0;
}