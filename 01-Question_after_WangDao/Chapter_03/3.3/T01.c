bool bracketCheck(char str[]) {
    SqStack S;
    InitStack(S);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            Push(S, str[i]);
        }
        // 注意下面这一行不同， 因为是在表达式中，除了括号还有别的字符
        if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (StackEmpty(S))
                return false;
            char topElem;
            Pop(S, topElem);
            if (!isMatched(topElem, str[i])) {
                return false;
            }
        }
    }
    return StackEmpty(S);
}

bool isMatched(char left, char right) {
    bool flag = false;
    if (left == '(' && right == ')')
        flag = true;
    if (left == '[' && right == ']')
        flag = true;
    if (left == '{' && right == '}')
        flag = true;
    return flag;
}

