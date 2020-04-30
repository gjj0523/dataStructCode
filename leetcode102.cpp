#include<stdio.h>
#include<stdlib.h> 
#define MAXSIZE 1000

typedef struct Node {
    struct TreeNode* root;
    struct Node *next;
} Node, *NodePtr;

typedef struct Queue {
    NodePtr front;  // 头
    NodePtr rear;  // 尾
} QNode, *QueuePtr;

QueuePtr InitQueue() {
    QueuePtr q = (QueuePtr)malloc(sizeof(QNode));
    q->front = q->rear = (NodePtr)calloc(1, sizeof(Node));  // 辅助操作节点
    return q;
}

void EnQueue(QueuePtr q, struct TreeNode* node) {
    NodePtr p = (NodePtr)malloc(sizeof(Node));
    p->next = NULL;  // 防止越界
    p->root = node;
    q->rear->next = p;
    q->rear = p;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    // 1.特判
    *returnSize = 0;
    if (!root) return NULL;
    // 2.队列初始化与信息初始化
    QueuePtr q = InitQueue();
    EnQueue(q, root);
    struct TreeNode *p = q->rear;  // 作为单词清空队列的结点
    int **res = (int **)malloc(sizeof(int*) * MAXSIZE);
    int *nums = (int *)malloc(sizeof(int) * (MAXSIZE * 3));  // 这个填充结果最大3000个
    *returnColumnSizes = (int *)malloc(sizeof(int) * MAXSIZE);
    int counter = 0, idx = 0;
    // 3.BFS搜索
    while (q->front != q->rear) {
        NodePtr rm = q->front->next;  // 待删除结点
        counter++;  // 此层个数+1，最后赋值到*returnColumnSizes[level]
        nums[idx++] = rm->root->val;  // 出列元素放在nums中且idx计数+1
        if (rm->root->left) EnQueue(q, rm->root->left);  // 1.左儿子进列
        if (rm->root->right) EnQueue(q, rm->root->right);  // 2.右儿子进列
        if (rm == p) {  // 3.此轮队列清空结束
            p = q->rear;  // 更新结尾点
            res[(*returnSize)++] = nums + idx - counter;  // 赋地址
            returnColumnSizes[0][(*returnSize)-1] = counter;  // 此行共counter个元素
            counter = 0;  // 计数器归零，准备计数下层元素个数
        }  // 4.释放结点即删除链表
        q->front->next = rm->next;
        if (q->rear == rm) q->rear = q->front;  // 只有一个防止下次野指针
        free(rm);
    }
    return res;
}


