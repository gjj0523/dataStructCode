#include<stdio.h>
#include<stdlib.h> 
#define MAXSIZE 1000

typedef struct Node {
    struct TreeNode* root;
    struct Node *next;
} Node, *NodePtr;

typedef struct Queue {
    NodePtr front;  // ͷ
    NodePtr rear;  // β
} QNode, *QueuePtr;

QueuePtr InitQueue() {
    QueuePtr q = (QueuePtr)malloc(sizeof(QNode));
    q->front = q->rear = (NodePtr)calloc(1, sizeof(Node));  // ���������ڵ�
    return q;
}

void EnQueue(QueuePtr q, struct TreeNode* node) {
    NodePtr p = (NodePtr)malloc(sizeof(Node));
    p->next = NULL;  // ��ֹԽ��
    p->root = node;
    q->rear->next = p;
    q->rear = p;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    // 1.����
    *returnSize = 0;
    if (!root) return NULL;
    // 2.���г�ʼ������Ϣ��ʼ��
    QueuePtr q = InitQueue();
    EnQueue(q, root);
    struct TreeNode *p = q->rear;  // ��Ϊ������ն��еĽ��
    int **res = (int **)malloc(sizeof(int*) * MAXSIZE);
    int *nums = (int *)malloc(sizeof(int) * (MAXSIZE * 3));  // �����������3000��
    *returnColumnSizes = (int *)malloc(sizeof(int) * MAXSIZE);
    int counter = 0, idx = 0;
    // 3.BFS����
    while (q->front != q->rear) {
        NodePtr rm = q->front->next;  // ��ɾ�����
        counter++;  // �˲����+1�����ֵ��*returnColumnSizes[level]
        nums[idx++] = rm->root->val;  // ����Ԫ�ط���nums����idx����+1
        if (rm->root->left) EnQueue(q, rm->root->left);  // 1.����ӽ���
        if (rm->root->right) EnQueue(q, rm->root->right);  // 2.�Ҷ��ӽ���
        if (rm == p) {  // 3.���ֶ�����ս���
            p = q->rear;  // ���½�β��
            res[(*returnSize)++] = nums + idx - counter;  // ����ַ
            returnColumnSizes[0][(*returnSize)-1] = counter;  // ���й�counter��Ԫ��
            counter = 0;  // ���������㣬׼�������²�Ԫ�ظ���
        }  // 4.�ͷŽ�㼴ɾ������
        q->front->next = rm->next;
        if (q->rear == rm) q->rear = q->front;  // ֻ��һ����ֹ�´�Ұָ��
        free(rm);
    }
    return res;
}


