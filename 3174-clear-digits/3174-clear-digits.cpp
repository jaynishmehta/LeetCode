class Solution {
public:
    string clearDigits(string s) {
        stack<char> charStack;
        for (char ch : s) {
            if (isdigit(ch)) {
                if (!charStack.empty()) {
                    charStack.pop();
                }
            } else {
                charStack.push(ch);
            }
        }
        string result;
        while (!charStack.empty()) {
            result = charStack.top() + result;
            charStack.pop();
        }

        return result;
        }
};