#include <stdio.h>
#include <string.h>

//树结点结构体
struct Node {
    Node *lchild; //左儿子指针
    Node *rchild; //右儿子指针
    char c; //结点字符信息
} Tree[50]; //静态内存分配数组

int loc; //静态数组中已经分配的结点个数

//申请一个结点空间，返回指向其的指针
Node *creat() {
    Tree[loc].lchild = Tree[loc].rchild = NULL; //初始化左右儿子为空
    return &Tree[loc++]; //返回指针，且loc累加
}

char str1[30], str2[30]; //保存前序和中序遍历结果字符串
//后序遍历
void postOrder(Node *T) {
    if (T->lchild != NULL) {
        postOrder(T->lchild); //若左子树不为空，递归遍历其左子树
    }
    if (T->rchild != NULL) {
        postOrder(T->rchild); //若右子树不为空，递归遍历其右子树
    }
    printf("%c", T->c); //遍历该结点，输出其字符信息
}
//由字符串的前序遍历和中序遍历还原树，并返回其根节点
//其中前序遍历结果为由str[s1]到str[e1]
//中序遍历结果为str[s2]到str[e2]
Node *build(int s1, int e1, int s2, int e2) {
    Node* ret = creat(); //为该树根节点申请空间
    ret->c = str1[s1]; //该结点字符为前序遍历中第一个字符
    int rootldx;
    for (int i = s2; i <= e2; i++) {
        if (str2[i] == str1[s1]) {
            rootldx = i; //查找该根节点在中序遍历中的位置
            break;
        }
    }
    if (rootldx != s2)
        ret->lchild = build(s1 + 1, s1 + (rootldx - s2), s2, rootldx - 1); //若左子树不为空，递归还原其左子树
    if (rootldx != e2)
        ret->rchild = build(s1 + (rootldx - s2) + 1, e1, rootldx + 1, e2); //若右子树不为空，递归还原其右子树
    return ret; //返回根节点指针
}

int main() {
    while (scanf("%s", str1) != EOF) {
        scanf("%s", str2);
        loc = 0; //初始化静态内存空间中已经使用结点个数为0
        //计算两个字符串长度
        int L1 = strlen(str1);
        int L2 = strlen(str2);
        Node *T = build(0, L1 - 1, 0, L2 - 1); //还原整棵树，其根结点指针保存在T中
        postOrder(T); //后序遍历
        printf("\n");
    }
    return 0;
}
