// KMP substring search algorithm from GeeksforGeeks.
// KMP is an O(n+m) algorithm that finds all occurence of a substring from a main string.

#include <bits/stdc++.h>
using namespace std;

vector<int> si; // substring_index: starting index of all the substrings. 
                // si.size() will give how many times the substring occurs in the main string.

// Fills lps[] for given pattern pat[0..M-1]
void computeLPSArray(char* pat, int M, int* lps)
{
    int len = 0;
    lps[0] = 0; // lps[0] is always 0
 
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
 
void KMPSearch(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int lps[M];
 
    computeLPSArray(pat, M, lps);
 
    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
 
        if (j == M) {
            si.push_back(i - j);
            j = lps[j - 1];
        }
 
        else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}
 

 
// Driver code
int main()
{
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    KMPSearch(pat, txt);
    return 0;
}
