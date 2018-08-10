#include <iostream>
#include <algorithm>
using namespace std;

int n;
int m;
int k[(int)10e5];

bool binary(int* A, int s, int min, int max)
{
    int mid;

    while (min < max)
    {
        //cout << "min:" << min << " max:" << max << " mid:" << mid << endl;
        mid = (min + max) / 2;

        if (A[mid] == s)
            return true;
        else if (A[mid] < s)
            max = mid;
        else
            min = mid + 1;
    }

    return false;
}

// bool binary(int s, int min, int max)
// {
//     int mid;

//     while (min < max)
//     {
//         //cout << "min:" << min << " max:" << max << " mid:" << mid << endl;
//         mid = (min + max) / 2;

//         if (k[mid] == s)
//             return true;
//         else if (k[mid] < s)
//             max = mid;
//         else
//             min = mid + 1;
//     }

//     return false;
// }

int main()
{
    cout << "n:"; cin >> n;
    cout << "m:"; cin >> m;

    for (int i = 0; i < n; ++i)
    {
        cout << "k[" << i << "]:";
        cin >> k[i];
    }

    sort(k, k + n, less<int>());
    bool found = false;

    // O(n^2 * logN)
    {
        // 2つの配列の要素をそれぞれ足し合わせて作った配列
        int kk[(int)10e5*2];
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                kk[i * n + j] = k[i] + k[j];
            }
        }

        sort(kk, kk + n * n);
        for (int i = 0; i < n * n; ++i)
            cout << kk[i] << " ";
        cout << endl;

        for (int a = 0; a < n; ++a)
        {
            for (int b = 0; b < n; ++b)
            {
                if (binary(kk, m - (k[a] + k[b]), 0, n*n - 1))
                {
                    found = true;
                    break;
                }
            }
        }
    }


    // // O(n^3 * logN)
    // for (int a = 0; a < n; ++a)
    // {
    //     for (int b = 0; b < n; ++b)
    //     {
    //         for (int c = 0; c < n; ++c)
    //         {
    //             if (binary(m-(k[a]+k[b]+k[c]), 0, n-1))
    //                 {
    //                     found = true;
    //                     break;
    //                 }
    //         }
    //     }
    // }

    // O(n^4)
    // for (int a = 0; a < n; ++a)
    // {
    //     for (int b = 0; b < n; ++b)
    //     {
    //         for (int c = 0; c < n; ++c)
    //         {
    //             for (int d = 0; d < n; ++d)
    //             {
    //                 if (k[a] + k[b] + k[c] + k[d] == m)
    //                 {
    //                     found = true;
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    // }


    if (found)
        cout << "found" << endl;
    else
        cout << "not found" << endl;

    return 0;
}