#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct NodeLink
{
    struct NodeLink *next;
    int data;
} NodeLink;

NodeLink *insert(NodeLink *node, int NodeData)
{

    while (node->next != NULL)
    {
        node = node->next;
    }

    if (node->next == NULL)
    {

        NodeLink *new = (NodeLink *)malloc(sizeof(NodeLink));
        new->data = NodeData;
        new->next = NULL;

        node->next = new;
        node = new;
    }

    return node;
}

// 打印链表
void printNode(NodeLink *a)
{
    while (a != NULL)
    {
        a = a->next;
    }
    return;
}

void InitLinkHead(NodeLink *node)
{
    node->data = 0;
    node->next = NULL;
    return;
}

//构建链表
void insertNode(NodeLink *pNode, int baseValue)
{
    for (int i = baseValue; i < baseValue + 10; i++)
    {
        insert(pNode, i);
    }

    return;
}

// 将两个单链表进行混合
NodeLink *fixMax(NodeLink *pa, NodeLink *pb)
{
    NodeLink *p = NULL;
    while (pa != NULL)
    {
        p = pb->next;
        pb->next = pa->next;
        pa->next = pb;

        pa = pa->next->next;
        pb = p;
    }

    return pa;
}

//从单链表的尾部开始找倒数第index结点
int findNodeFormTail(NodeLink *pHead, int index)
{

// 当前方法是遍历两次，第一次获取到长度，然后再遍历到l-m的长度
    NodeLink *pTail = NULL;
    NodeLink *pTemp = NULL;
    int linkLen = 0;

    pTail = pHead;
    pTemp = pHead;
/*
    while (pHead) {  
        pHead = pHead->next;      
        if (pHead->next == NULL) {
            break;
        } else {
            linkLen++;
        }
    }

    for (int i = 0; i <= linkLen; i++) {
        pTemp = pTemp->next;
        if (i == linkLen - index + 1) { 
            printf("find :index %d, tatil : %d\n", i, pTemp->data);
        }
        printf("index %d, tatil : %d\n", i, pTemp->data);        
    }
*/
// 当前方法是遍历一次，两个间隔index长度的指针
    int i = 0;
    while (pHead) {
        pHead = pHead->next; 
        i++;
        if ( i >= index) {
            pTail = pHead;
            pTemp = pTemp->next;
        }

        if (pHead->next == NULL) {
            break;
        }
    }

    printf("pTemp : %d\n", pTemp->data);
    return 0;
}


//判断链表是否是循环链表
bool hasNullPtr(NodeLink* pHead)
{
    NodeLink* pFast = NULL;
    NodeLink* pLow = NULL;

    pFast = pHead;
    pLow = pHead;

    printf("hasNullPtr !\n");

    if (pFast->next == NULL || pFast->next->next == NULL) {
        printf("I am  have NULL ptr!\n");
        return false;
    }

    //构建循环链表
    while (pFast->next != NULL ) {
        pFast = pFast->next;
        if (pFast->next->next == NULL) {
            pFast->next->next = pFast;
            break;
        }
    }

    while (pLow->next != NULL && pFast->next->next != NULL) {        
        pLow = pLow->next;
        pFast = pFast->next->next;

        if (pFast->data == pLow->data) {
            return true;
        } 
    }    

    return false;
}


int main()
{
    NodeLink a, b;
    bool hasTail = false;

    InitLinkHead(&a);
    InitLinkHead(&b);

    NodeLink *pa = &a;
    NodeLink *pb = &b;

    insertNode(&a, 10);
    insertNode(&b, 20);

    fixMax(&a, &b);

    printNode(pa);

    findNodeFormTail(pa,5);

    hasTail = hasNullPtr(pa);
    if (!hasTail) {
        printf("I am  have tail!\n");
    } else {
        printf("I am  not have tail!\n");
    }

    return 0;
}
