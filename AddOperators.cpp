#include <iostream>
#include <string>
using namespace std;

int toInt(string str) {
    int num = 0;
    for (int i = 0; i < str.length(); i++) {
        num = num * 10 + (str[i] - '0');
    }
    return num;
}

bool isDigitOnly(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

int apply(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    return 0;
}

// We're returning a dynamic array with size reference
int solve(string expr, int results[], int &count) {
    count = 0;

    if (isDigitOnly(expr)) {
        results[0] = toInt(expr);
        count = 1;
        return 1;
    }

    int temp[100], tempCount;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];
        if (ch == '+' || ch == '-' || ch == '*') {
            string left = expr.substr(0, i);
            string right = expr.substr(i + 1);

            int leftRes[100], rightRes[100];
            int leftCount, rightCount;

            solve(left, leftRes, leftCount);
            solve(right, rightRes, rightCount);

            for (int j = 0; j < leftCount; j++) {
                for (int k = 0; k < rightCount; k++) {
                    results[count++] = apply(leftRes[j], rightRes[k], ch);
                }
            }
        }
    }

    return count;
}

int main() {
    string expr = "2-1-1";
    int res[100], resCount;

    solve(expr, res, resCount);

    cout << "Results: ";
    for (int i = 0; i < resCount; i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
