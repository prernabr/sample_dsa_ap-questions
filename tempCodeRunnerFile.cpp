#include <iostream>
#include <cstring>

using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int n = s.length();
    int last[256];
    memset(last, -1, sizeof(last)); // initialize last to -1 for all characters

    int ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
        if (last[s[i]] != -1) {
            j = max(j, last[s[i]] + 1);
        }
        last[s[i]] = i;
        ans = max(ans, i - j + 1);
    }
    cout << "Length of longest substring without repeating characters: " << ans << endl;

    return 0;
}
