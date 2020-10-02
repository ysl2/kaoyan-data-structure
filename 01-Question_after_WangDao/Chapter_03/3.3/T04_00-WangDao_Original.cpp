#include <queue>
using namespace std;

// 同类车先到先上船：采用队列结构
queue<int> q;  //载渡队列
queue<int> q1;  // 客车队列
queue<int> q2;  // 货车队列

void manager() {
    // i表示客车数，j表示渡船上的总车辆数
    int i = 0, j = 0;
    while (j < 10) {
        if (!q1.empty() && i < 4) {
            // 客车队列不空，且客车未上足4辆
            // 从客车队列出队，然后压入载渡队列
            int temp = q1.front();
            q1.pop();
            q.push(temp);
            i++;  // 客车数 + 1
            j++;  // 总车数 + 1

        } else if (i == 4 && !q2.empty()) {
            // 客车已上足4辆
            // 从货车队列出队，然后压入载渡队列
            int temp = q2.front();
            q2.pop();
            q.push(temp);
            j++;  // 总车数 + 1
            i = 0;  // 每上一辆货车，i重新计数
        } else {
            // 其他情况：若等待客车不足4辆，则以货车代替
            while (j < 10 && i < 4 && !q2.empty()) {
                // 只要还有货车并且i < 4（即客车不足4辆）
                // 从货车队列出队，然后压入载渡队列
                int temp = q2.front();
                q2.pop();
                q.push(temp);
                i++;  // 客车数 + 1。当i == 4时，退出这个循环
                j++;  // 总车数 + 1
            }
            i = 0;  // 已经满足i == 4，因此i重新计数
        }
        if (q1.empty() && q2.empty())
            j = 11;  // 如果货车和客车加起来不足10辆，就直接开船
    }
}

//--------------------------------------------------------------------------
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

