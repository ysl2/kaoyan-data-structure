void createCSTree_Degree(CSTNode *&T, int data[], int degree[], int n){
// data[]是层序序列，degree[]是每个结点的度，n是树结点个数
	CSTNode **temp = (CSTNode **) malloc(sizeof(CSTNode) * n); // 创建临时数组
	for(int i = 0; i < n; i++){  // 把每一个节点放进临时数组
		temp[i] = (CSTNode *) malloc(sizeof(CSTNode));
		temp[i]->data = data[i];
		temp[i]->lchild = temp[i]->rbro = NULL; // 初始化兄弟与孩子结点
	}
	// 构造完临时数组之后我们得到了先序序列的结点数组
	// 接下来我们根据结点的度来确定每一个结点的儿子与儿子的兄弟结点
	int index = 0; // 指向数组还未操作的结点
	int d;// d表示当前结点的度数;
	for(int i = 0; i < n; i++){
		d = degree[i];   // 获取当前结点的度数

		// 接下来找他的儿子与儿子兄弟

		// 首先要知道叶子结点的是没有兄弟和孩子的所以先进行一个判断  
		// 注:叶子结点的度数为0

		if(d != 0) {  // 若不是叶子结点 开始找儿子 
            index++;
			temp[i]->lchild = temp[index];  // 首先找到第一个儿子结点
			
			// 然后给第一个儿子结点找兄弟结点
			// 注意 j=2 表示的是 从第二个孩子开始 一共有 d孩子 d是度数
			for(int j = 2; j <= d; j++){
				index++;
				temp[index - 1]->rbro = temp[index];
				// index -1 为上一个孩子结点
				// 也就是父节点的第一个孩子/
				// 或者是上一个孩子的兄弟 
				// 剩下的孩子结点依次是上一个孩子的右兄弟
			}
		}

	}
	// 找完所有孩子结点与孩子的兄弟结点后就返回头指针
	T = *temp; // 注意这里是函数参数返回的
}



