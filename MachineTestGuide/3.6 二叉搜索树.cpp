#include <stdio.h>
#include <string.h>

struct Node {
    Node *lchild;
    Node *rchild;
    int c;
} Tree[110];
int loc;
Node *creat() {
    Tree[loc].lchild = Tree[loc].rchild = NULL;
    return &Tree[loc++];
}

char str1[25], str2[25]; //保存二叉排序树的遍历结果
int size1, size2; //保存在字符数组中的遍历得到字符个数
char *str; //当前正在保存字符串
int *size; //当前正在保存字符串中字符个数

//前序遍历
void postOrder(Node *T) {
    if (T->lchild != NULL)
        postOrder(T->lchild);
    if (T->rchild != NULL)
        postOrder(T->rchild);
    str[(*size)++] = T->c + '0'; //将结点中的字符放入正在保存的字符串中
}
//中序遍历
void inOrder(Node *T) {
    if (T->lchild != NULL)
        inOrder(T->lchild);
    str[(*size)++] = T->c + '0';
    if (T->rchild != NULL)
        inOrder(T->rchild);
}

//将数字插入二叉树
Node *Insert(Node *T, int x) {
    if (T == NULL) {
        T = creat();
        T->c = x;
        return T;
    } else if (x < T->c)
        T->lchild = Insert(T->lchild, x);
    else if (x > T->c)
        T->rchild = Insert(T->rchild, x);
    return T;
}

int main() {
    int n;
    char tmp[12];
    while (scanf("%d", &n) != EOF && n != 0) {
        loc = 0; //初始化静态空间为未使用
        Node *T = NULL;
        scanf("%s", tmp); //输入字符串
        for (int i = 0; tmp[i] != 0; i++)
            T = Insert(T, tmp[i] - '0'); //按顺序将数字插入二叉排序树
        size1 = 0; //保存在第一个字符串中的字符初始化为0
        str = str1; //将正在保存字符串设定为第一个字符串
        size = &size1; //将正在保存字符串中的字符个数指针指向size1
        postOrder(T);
        inOrder(T);
        str1[size1] = 0; //向第一个字符串的最后一个字符添加空字符，方便使用字符串函数
        while (n-- != 0) {
            scanf("%s", tmp);
            Node *T2 = NULL;
            for (int i = 0; tmp[i] != 0; i++)
                T2 = Insert(T2, tmp[i] - '0');
            size2 = 0; //第二个字符串保存字符初始化为0
            str = str2; //将正在保存字符串设定为第二个字符串
            size = &size2; //正在保存字符串中字符数量指针指向size2
            postOrder(T2);
            inOrder(T2);
            str2[size2] = 0; //字符串最后添加空字符
            puts(strcmp(str1, str2) == 0 ? "YES" : "NO"); //比较两个遍历字符串，若相同输出YES，否则输出NO
        }
    }
    return 0;
}
