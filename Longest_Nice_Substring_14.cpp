#include <iostream>
using namespace std;

bool hasBothCases(string s, char ch) {
    bool lower = false, upper = false;
    for (char c : s) {
        if (c == tolower(ch)) lower = true;
        if (c == toupper(ch)) upper = true;
    }
    return lower && upper;
}

string longestNice(string s) {
    if (s.length() < 2) return "";

    for (int i = 0; i < s.length(); i++) {
        if (!hasBothCases(s, s[i])) {
            string left = longestNice(s.substr(0, i));
            string right = longestNice(s.substr(i + 1));
            return (left.length() >= right.length()) ? left : right;
        }
    }

    return s;
}

int main() {
    string input = "YazaAay";
    cout << longestNice(input);
    return 0;
}
