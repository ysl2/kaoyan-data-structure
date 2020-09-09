// 目标：字符串里有S和H，把所有的S都调整到H之前
void Train_Arrange(char *train) {
    char *p = train, *q = train, c;
    Stack S;
    InitStack(S);
    while (*p != NULL) {
        if (*p == 'H') {
            Push(S, *p);  // 把H放入栈中
        } else {
            *(q++) = *p;  // 把S调到前部
        }
        p++;
    }
    while (!StackEmpty(S)) {
        Pop(S, c);
        *(q++) = c;  // 把H接在后部
    }
}

