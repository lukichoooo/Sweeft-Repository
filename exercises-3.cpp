#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

vector<int> merge(const vector<int> &A, const vector<int> &B)
{
    const int n = A.size(), m = B.size();
    vector<int> C(n + m);
    int a = 0, b = 0, k = 0;
    while (a < n && b < m)
        C[k++] = (A[a] < B[b] ? A[a++] : B[b++]);
    while (a < n)
        C[k++] = A[a++];
    while (b < m)
        C[k++] = B[b++];
    return C;
}

int main()
{
    vector<int> list1 = {1, 2, 4};
    vector<int> list2 = {1, 3, 4};

    vector<int> res = merge(list1, list2);
    for (int a : res)
        cout << a << " ";
    cout << endl;
}