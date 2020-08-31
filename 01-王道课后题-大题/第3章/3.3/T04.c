Queue Q;  // 载渡队列
Queue Q1;  // 客车队列
Queue Q2;  // 货车队列

void manage() {
    int i = 0,  // 载渡客车数（指已上船的客车，每满4辆就重新计数，即i <= 4）
		j = 0;  // 载渡总车数
    int temp;
    while (j < 10) {
        if (!IsEmpty(Q1) && i < 4) {
            DeQueue(Q1, temp);
            EnQueue(Q, temp);
            i++;
            j++;
        } else if (i == 4 && !IsEmpty(Q2)) {
            DeQueue(Q2, temp);
            EnQueue(Q, temp);
            j++;
            i = 0;
        } else {  // 客车队列空或货车队列空
            while (j < 10 && i < 4 && !IsEmpty(Q2)) {
                DeQueue(Q2, temp);
                EnQueue(Q, temp);
                i++;
                j++;
            }
            i = 0;
        }
        if (IsEmpty(Q1) && IsEmpty(Q2)) {  // 客车和货车加起来不足10
            j = 11;
        }
    }
}

