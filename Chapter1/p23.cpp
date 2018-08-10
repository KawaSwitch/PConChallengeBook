#include <iostream>
using namespace std;

const int LMAX = 10e6;
int L;
int n;
int x[LMAX];

int Ma(int a, int b)
{
    return (a > b) ? a : b;
}

int mi(int a, int b)
{
    return (a < b) ? a : b;
}

int main()
{
    cout << "L:"; cin >> L;
    cout << "n:"; cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cout << "x[" << i << "]:";
        cin >> x[i];
    }

    int min = 0, max = 0;

    // calc min
    for (int i = 0; i < n; ++i)
    {
        min = Ma(min, mi(x[i], L - x[i]));

        // L = oddのときに対応できてない
    //     int temp = x[i] - (L / 2);
    //     temp = (temp > 0) ? temp : -temp;

    //     temp = (L / 2) - temp;
    //     temp = (temp > 0) ? temp : -temp;

    //     if (min < temp)
    //         min = temp;
    }

    // calc for max
    for (int i = 0; i < n; ++i)
    {
        max = Ma(max, Ma(x[i], L - x[i]));
    }


    cout << "min: " << min << endl;
    cout << "max: " << max << endl;

    return 0;
}