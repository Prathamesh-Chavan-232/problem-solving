#include <bits/stdc++.h>
using namespace std;

class solution {
   public:
    void brute() {
        int n, q;
        cin >> n >> q;
        string str;
        cin >> str;
        while (q--) {
            int l, r;
            cin >> l >> r;
            int hsh[26] = {0};

            // l & r are in 1-based index, make them 0-based index
            l--;
            r--;

            for (int i = l; i <= r; ++i) {
                hsh[str[i] - 'a']++;
                // storing numbers of occurrences of the letters
                // in the hash array
            }

            int oddCt = 0;
            for (int i = 0; i < 26; ++i) {
                if (hsh[i] % 2 != 0)
                    oddCt++;
            }

            if (oddCt > 1)
                cout << "No\n";
            else
                cout << "Yes\n";
        }
    }
    void optimal() {
        int n, q;
        cin >> n >> q;
        int hash[n + 1][26];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < 26; j++) {
                hash[i][j] = 0;
            }
        }
        string str;
        cin >> str;
        for (int i = 0; i < n; ++i) {
            hash[i + 1][str[i] - 'a']++;
        }
        for (int i = 0; i < 26; ++i) {
            for (int j = 1; j <= n; ++j) {
                hash[j][i] += hash[j - 1][i];
            }
        }
        while (q--) {
            int l, r;
            cin >> l >> r;
            int flag = 1;
            int oddCount = 0;
            for (int i = 0; i < 26; i++) {
                int charCt = hash[r][i] - hash[l - 1][i];
                if (charCt % 2) {
                    oddCount++;
                    if (oddCount > 1) {
                        flag = 0;
                        break;
                    }
                }
            }
            if (flag) {
                cout << "YES\n";
            } else {
                cout << "N0\n";
            }
        }
    }
};

/*
    Link -
    Problem -
    Difficulty -
    contest -
    Status -
    Date -
*/
/*
Approach -

    Brute force approach -
        Calculate the number of occurrences of every alphabet in the substring for every test case
        Then if more than 1 letter that occur odd number of times
                Palindrome isnt possible
            else
                Palindrome is possible
            i.e. when all letters ocurr even times or only 1 letter occurs odd times

    Brute force Time complexity - O(n + q*(26 + n + 26))
        ~ O(n*q) -> ~O(n^2) = 1e10 (i.e. > 1 sec)


    Optimal Approach -



    Optimal Time complexity - O()


*/
int main() {
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:/Prathamesh/Programming/input.txt", "r", stdin);
    freopen("C:/Prathamesh/Programming/output.txt", "w", stdout);
    freopen("C:/Prathamesh/Programming/err.txt", "w", stderr);
#endif
    solution s;
    int t;
    scanf("%d", &t);
    while (t--) {
        s.optimal();
    }

    return 0;
}