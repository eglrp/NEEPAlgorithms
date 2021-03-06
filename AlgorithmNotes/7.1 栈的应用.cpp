/**
* stack：后进先出的数据结构
**/

int TOP; //栈顶指针

//清空（clear）
void clear() {
    TOP = -1;
}

//获取栈内元素个数（size）
int size() {
    return TOP + 1;
}

//判空（empty）
bool empty() {
    if (TOP == -1)
        return true;
    else
        return false;
}

//进栈（push）
void push(int x) {
    st[++TOP] = x;
}

//出栈（pop）
void pop() {
    TOP--;
}

//取栈顶元素（top）
int top() {
    return st[TOP];
}

//注意：使用pop()函数和top()函数之前需使用empty()判空

//STL中没有栈的清空，可用while循环实现
while (!st.empty()) {
    st.pop();
}
