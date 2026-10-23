class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st(tokens.size() / 2 + 1);  // max numbers alive now
        int top = -1;

        for (const string& t : tokens) {
            if (t.size() == 1 && (t[0] == '+' || t[0] == '-' || t[0] == '*' || t[0] == '/')) {
                int first = st[top--];   // right operand
                int second = st[top];    // left operand, in place
                switch (t[0]) {
                    case '+': st[top] = second + first; break;
                    case '-': st[top] = second - first; break;
                    case '*': st[top] = second * first; break;
                    case '/': st[top] = second / first; break;
                }
            } else {
                st[++top] = stoi(t);
            }
        }
        return st[0];
    }
};