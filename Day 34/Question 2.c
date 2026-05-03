int calculate(char* s) {
    long curr = 0, last = 0, result = 0;
    char op = '+';
    for (int i = 0; s[i]; i++) {
        if (isdigit(s[i])) {
            curr = curr * 10 + (s[i] - '0');
        }
        if ((!isdigit(s[i]) && s[i] != ' ') || s[i+1] == '\0') {
            if (op == '+') { result += last; last = curr; }
            else if (op == '-') { result += last; last = -curr; }
            else if (op == '*') { last = last * curr; }
            else if (op == '/') { last = last / curr; }
            op = s[i];
            curr = 0;
        }
    }
    return result + last;
}
