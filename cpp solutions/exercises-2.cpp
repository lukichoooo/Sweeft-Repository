#include <iostream>
#include <queue>
#include <ctime>
#include <functional>

using namespace std;

// in every prefix  '(' >= ')'
// number of '(' == ')' == n

class Path
{
public:
    int idx;
    string s;
    int bal = 0; // how much more is '(' in nuber than ')'
    // if bal < 0 path is NOT VALID
    Path(int idx, string s, int bal) : idx(idx), s(s), bal(bal) {}
    Path(int idx, string s) : idx(idx), s(s) {}
};

void printAllValidParanthesisBFS(int n)
{
    queue<Path> q;
    q.push(Path(0, "", 0));
    const int end = 2 * n;

    while (!q.empty())
    {
        Path curr = q.front();
        q.pop();

        if (curr.idx == end)
        {
            if (curr.bal == 0) // number of opening brackets = number of closing brackets = 'n'
            {
                cout << curr.s << endl;
            }
            continue;
        }

        if (curr.bal < 0)
            continue;

        curr.idx++;

        // pick '('
        Path opening = curr;
        opening.s += '(';
        opening.bal++;
        if (opening.bal <= end - opening.idx) // we should be able to make bal = 0 at the end
        {
            q.push(opening);
        }

        // pick ')'
        Path closing = curr;
        closing.s += ')';
        closing.bal--;
        if (closing.bal >= 0)
        {
            q.push(closing);
        }
    }
}

void printAllValidParanthesisDFS(int n)
{
    const int end = 2 * n;
    string s(end, '(');

    function<void(int, int)> dfs = [&](int idx, int bal)
    {
        if (idx == end)
        {
            if (bal == 0)
                cout << s << endl;
            return;
        }

        if (bal < 0 || bal > end - idx)
            return;

        s[idx] = '(';
        dfs(idx + 1, bal + 1);
        s[idx] = ')';
        dfs(idx + 1, bal - 1);
    };

    dfs(0, 0);
}

int main()
{
    printAllValidParanthesisDFS(20);

    // should print (2n choose n)/(n+1) expressions
}