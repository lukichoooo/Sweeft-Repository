#include <iostream>
#include <vector>

using namespace std;

int maxContainer(vector<int> heights) // O(n)
{
    const int n = heights.size();

    int maxContainer = 0;

    int L = 0, R = n - 1;
    while (L < R)
    {
        const int len = R - L;
        const int height = min(heights[L], heights[R]);
        maxContainer = max(maxContainer, height * len);

        heights[L] < heights[R] ? L++ : R--;
    }

    return maxContainer;
}

int slowMaxContainer(vector<int> heights) // O(n^2)
{
    const int n = heights.size();

    int maxContainer = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            const int len = j - i;
            const int height = min(heights[i], heights[j]);
            maxContainer = max(maxContainer, height * len);
        }
    }

    return maxContainer;
}

int main()
{
    // vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    // int ans = slowMaxContainer(heights);
    // int res = maxContainer(heights);
    // cout << "real answer = " << ans << endl;
    // cout << "result = " << res << endl;
    // cout << "your result is " << (res == ans ? "CORRECT" : "WRONG!!!!!!!!!!!!!!") << endl;

    for (int n = 0; n < 500; ++n)
    {
        vector<int> vec(n);

        for (int i = 0; i < n; ++i)
            vec[i] = (rand() % 10000);

        if (slowMaxContainer(vec) != maxContainer(vec))
            cout << "WRONG!!!!!!!" << endl;
    }
}