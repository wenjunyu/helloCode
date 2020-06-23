//基于动态数组实现的栈 与 基于链表实现的栈的区别
// 动态数组的栈可以随机访问数组下标，比链表实现要快但更复杂

// push/pop操作都会改变链表的第一个元素，调用函数的栈指针必须进行修改，通过指向栈指针的指针来解决这个问题
// 因为它只更新了头元素指针的本地副本
// void push(Element **stack, void *data);
// void *pop(Element **stack);



bool insert(NodeLink* head, int data) {
    
    NodeLink* new = (NodeLink*)malloc(sizeof(NodeLink));

    if (!new) { return false; }

    new->data = data;
    new->next = head;

    head = new; //错误，只更新了head的本地副本    

    return true;

} 


bool insert(NodeLink** head, int data) {
    
    NodeLink* new = (NodeLink*)malloc(sizeof(NodeLink));

    if (!new) { return false; }

    new->data = data;
    new->next = *head;

    *head = new; //正确    

    return true;

}
    