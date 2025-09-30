#include <iostream>
#include <vector>

using namespace std;

vector<int> addOne(vector<int> A)
{
    if (A.size() == 0)
        return {1};

    const int n = A.size();

    const int carry = 1;
    for (int i = n - 1; i >= 0; --i)
    {
        if (A[i] + carry <= 9)
        {
            A[i] += carry;
            return A;
        }
        else
        {
            A[i] = 0;
        }
    }
    A.insert(A.begin(), carry);
    return A;
}

int main()
{
    vector<int> arr = {9, 9, 9};

    vector<int> res = addOne(arr);
    for (int a : res)
        cout << a << " ";
    cout << endl;
}