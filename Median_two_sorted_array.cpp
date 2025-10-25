#include <bits/stdc++.h>
using namespace std;

double median(vector<int> &arr1, vector<int> &arr2)
{
    int a = arr1.size();
    int b = arr2.size();

    if (a > b)
        return median(arr2, arr1);
    int left = (a + b + 1) / 2;
    int high = a;
    int low = 0;
    int n = a + b;

    while (low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;

        int L1 = INT_MIN;
        int L2 = INT_MIN;
        int R1 = INT_MAX;
        int R2 = INT_MAX;

        if (mid1 < a)
            R1 = arr1[mid1];
        if (mid2 < b)
            R2 = arr2[mid2];

        if (mid1 - 1 >= 0)
            L1 = arr1[mid1 - 1];
        if (mid2 - 1 >= 0)
            L2 = arr2[mid2 - 1];

        if (L1 <= R2 && L2 <= R1)
        {
            if (n % 2 == 0)
            {
                return (max(L1, L2) + min(R1, R2)) / 2.0;
            }
            else
            {
                return max(L1, L2);
            }
        }
        else if (L1 > R2)
        {
            high = mid1 - 1;
        }
        else
        {
            low = mid1 + 1;
        }
    }
    return -1;
}

int main()
{
    int n1;
    cout << "Enter the number of element in n1:";
    cin >> n1;

    int n2;
    cout << "Enter the number of in n2:";
    cin >> n2;

    vector<int> arr1(n1);
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }

    vector<int> arr2(n2);
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }

    float ans = median(arr1 , arr2);
    cout << "The median of two sorted array is: " <<ans ;

    return 0;
}