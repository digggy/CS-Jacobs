
#include <bits/stdc++.h>
using namespace std;
#define var 256

void strsearch(string pat, string txt, int q)
{
    //The length of the pattern and the string
    int patLength = pat.length();
    int txtLength = txt.length();

    int p = 0, t = 0;
    int h = 1;
    int j;

    for (int i = 0; i < patLength - 1; i++)
    {
        h = (h * var) % q;
    }
    for (int i = 0; i < patLength; i++)
    {
        // Hash functions for the pattern and the string's elements
        p = (var * p + pat[i]) % q;
        t = (var * t + txt[i]) % q;
    }

    // Checking if the hash matches and increasing index so as to check if it matches
    for (int i = 0; i <= txtLength - patLength; i++)
    {
        if (p == t)
        {
            for (j = 0; j < patLength; j++)
            {
                if (txt[i + j] != pat[j])
                    break;
            }
            if (j == patLength)
            {
                // If the pattern matches completely
                cout << "The pattern's starting index is : " << i << endl;
            }
        }

        if (i < txtLength - patLength)
        {
            t = (var * (t - txt[i] * h) + txt[i + patLength]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
}

// The main function
int main(int argc, char **argv)
{
    string input, pattern;
    input = "Hello my name is Jack";
    pattern = "Jack";

    strsearch(pattern, input, 1011);
    return 0;
}

// References :
// Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (n.d.). Introduction to algorithms.
// https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
