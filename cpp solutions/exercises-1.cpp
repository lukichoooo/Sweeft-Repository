#include <iostream>
#include <ctime>

using namespace std;

// 1

string palindromeAfterLetterDeletion(string &s)
{

    if (s.length() <= 2)
        return "YES";

    int L = 0, R = s.length() - 1;

    bool canForgive = true;

    while (L < R)
    {
        if (s[L++] == s[R--])
        {
            continue;
        }
        else
        {
            if (canForgive)
            {
                canForgive = false;
                L--;
                R++;

                if (L + 1 >= R)
                    return "YES";

                if (s[L + 1] == s[R])
                    L++;
                else if (s[R - 1] == s[L])
                    R--;
                else
                    return "NO";
            }
            else
            {
                return "NO";
            }
        }
    }
    return "YES";
}

int main()
{
    // generate tests
    for (int n = 1; n < 32; ++n)
    {
        string s(n, '0');
        for (int i = 0; i < n; ++i)
        {
            s[i] = 'a' + (rand() % 26);
        }

        // make palindrome
        for (int i = 0; i < n / 2; ++i)
        {
            s[i] = s[n - 1 - i];
        }

        // if (palindromeAfterLetterDeletion(s) == "NO")
        //     cout << s << endl;

        // insert char at any position
        for (int i = 0; i < n; ++i)
        {
            string og = s;

            // s.insert(i, "0");
            // if (palindromeAfterLetterDeletion(s) == "NO")
            //     cout << s << endl;

            s = og;
        }

        // change char at two positions with two different values
        if (n > 2)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = i + 1; j < n; ++j)
                {
                    if (i == n - 1 - j)
                        continue;

                    char ogI = s[i];
                    char ogJ = s[j];
                    s[i] = '0';
                    s[j] = '1';
                    if (palindromeAfterLetterDeletion(s) == "YES") // only prints edge cases (one char ends up in the middle so its YES)
                        cout << s << endl;
                    s[i] = ogI;
                    s[j] = ogJ;
                }
            }
        }
    }
}