#include "dblinklist.h"
#include <stdlib.h>
#include <stddef.h>

DLinkNode* CreateDLinkNode(DLinkType value)
{
    DLinkNode* new_node=(DLinkNode*)malloc(sizeof(DLinkNode));
    new_node->data=value;;
    new_node->prev=new_node;
    new_node->next=new_node;
    return new_node;
}

void DLinkListInit(DLinkNode** phead)
{
    if(phead == NULL)
    {
        //非法输入
        return ;
    }
    *phead=CreateDLinkNode(0);
}

void DLinkListPushBack(DLinkNode* head,DLinkType value)
{
    if(head == NULL)
    {
        //非法输入
        return ;
    }
    DLinkNode* new_node=CreateDLinkNode(value);
    DLinkNode* tail=head->prev;
    head->prev=new_node;
    new_node->next=head;
    tail->next=new_node;
    new_node->prev=tail;
    return ; 
}

void DestroyDLinkList(DLinkNode* phr)
{
    free(phr);
}

void DLinkListPopBack(DLinkNode* head)
{
    if(head == NULL)
    {
        //非法输入
        return ;
    }
    if(head->next == NULL)
    {
        //空链表
        return ;
    }
    DLinkNode* to_delete=head->prev;
    DLinkNode* tail=to_delete->prev;
    head->prev=tail;
    tail->next=head;
    DestroyDLinkList(to_delete);
    return ;
}

void DLinkListPushFront(DLinkNode* head,DLinkType value)
{
    if(head == NULL)
    {
        //非法输入
        return ;
    }
    DLinkNode* new_node=CreateDLinkNode(value);
    DLinkNode* new_node_next=head->next;
    head->next=new_node;
    new_node->prev=head;
    new_node->next=new_node_next;
    new_node_next->prev=new_node;
    return ;
}
void DLinkListPopFront(DLinkNode* head)
{
    if(head == NULL)
    {
        //非法输入
        return ;
    }
    if(head->next == NULL)
    {
        //空链表
        return ;
    }
    DLinkNode* to_delete=head->next;
    DLinkNode* head_next=to_delete->next;
    head->next=head_next;
    head_next->prev=head;
    DestroyDLinkList(to_delete);
    return ;

}

//给pos位置之前插入新节点
void DLinkListInsert(DLinkNode* head,DLinkNode* pos,DLinkType value)
{
    if(head == NULL || pos == NULL)
    {
        //非法输入
        return ;
    }
    DLinkNode* new_node=CreateDLinkNode(value);
    DLinkNode* pos_prev=pos->prev;
    new_node->next=pos;
    pos->prev=new_node;
    pos_prev->next=new_node;
    new_node->prev=pos_prev;
    return ;
}
//给pos位置之后插入新节点
void DLinkListInsertAfter(DLinkNode* head,DLinkNode* pos,DLinkType value)
{
    if(head == NULL || pos == NULL)
    {
        //非法输入
        return ;
    }
    DLinkNode* new_node=CreateDLinkNode(value);
    DLinkNode* new_node_next=pos->next;
    pos->next=new_node;
    new_node->prev=pos;
    new_node->next=new_node_next;
    new_node_next->prev=new_node;
    return ;
}
//查找元素，找到返回节点指针，找不到返回NULL
DLinkNode* DLinkListFind(DLinkNode* head,DLinkType to_find)
{
    if(head == NULL)
    {
        //非法输入
        return NULL;
    }
    if(head->next == NULL)
    {
        //空链表
        return NULL;
    }
    //遍历链表
    DLinkNode* cur=head->next;
    for(;cur!=head;cur=cur->next)
    {
        if(cur->data==to_find)
        {
            return cur;
        }
    }
    return NULL;
}
//删除pos位置的元素
void DLinkListErase(DLinkNode* head,DLinkNode* to_delete)
{
    if(head == NULL || to_delete == NULL)
    {
        //非法输入
        return ;
    }
    if(head->next == NULL)
    {
        //空链表
        return ;
    }
    DLinkNode* prev=to_delete->prev;
    DLinkNode* next=to_delete->next;
    prev->next=next;
    next->prev=prev;
    DestroyDLinkList(to_delete);
    return ;
}
//按值来删除元素
void DLinkListRemove(DLinkNode* head,DLinkType to_delete_value)
{
    if(head == NULL)
    {
        //非法输入
        return ;
    }
    DLinkNode* to_delete=DLinkListFind(head,to_delete_value);
    if(to_delete == NULL)
    {
        //没找到
        return ;
    }
    DLinkListErase(head,to_delete);
    return ;
}
//按值来删除所有元素
void DLinkListRemoveAll(DLinkNode* head,DLinkType to_delete_value)
{
    if(head == NULL)
    {
        //非法输入
        return ;
    }
    while(1)
    {
        DLinkNode* to_delete=DLinkListFind(head,to_delete_value);
        if(to_delete == NULL)
        {
            //没找到
            return ;
        }
        DLinkListErase(head,to_delete);
    }   
    return ;
}
//销毁链表
void DLinkListDestroy(DLinkNode** phead)
{
    if(phead == NULL)
    {
        //非法输入
        return ;
    }
    DLinkNode* cur=(*phead)->next;
    while(cur!=*phead)
    {
        DLinkNode* next=cur->next;
        DestroyDLinkList(cur);
    }
    DestroyDLinkList(*phead);
    *phead == NULL;
}
/************************
 *
 *
 *
 * 以下为测试代码
 *
 *
 ***************************/
#if 1
#include <stdio.h>
#define TEST_HEAD printf("\n===========%s================\n",__FUNCTION__);
void DLinkListPrintChar(DLinkNode*head,const char* msg)
{
    printf("[%s]\n",msg);
    DLinkNode* cur=head->next;
    for(;cur!=head;cur=cur->next)
    {
        printf("[%c|%p]",cur->data,cur);
    }
    printf("\n");
    for(cur=head->prev;cur!=head;cur=cur->prev)
    {

        printf("[%c|%p]",cur->data,cur);
    }
    printf("\n");
}
void TestInit()
{
    TEST_HEAD;
    DLinkNode* head;
    DLinkListInit(&head);
    printf("head expected not NULL,actual %p\n",head);
    printf("data expected 0,actual %d\n",(int)head->data);
}
void TestPushBack()
{
    TEST_HEAD;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushBack(head,'a');
    DLinkListPushBack(head,'b');
    DLinkListPushBack(head,'c');
    DLinkListPushBack(head,'d');
    DLinkListPrintChar(head,"尾部插入四个节点");

}

void TestPopBack()
{
    TEST_HEAD;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushBack(head,'a');
    DLinkListPushBack(head,'b');
    DLinkListPushBack(head,'c');
    DLinkListPushBack(head,'d');
    DLinkListPrintChar(head,"尾部插入四个节点");
    DLinkListPopBack(head);
    DLinkListPopBack(head);
    DLinkListPrintChar(head,"尾部删除两个节点");
    DLinkListPopBack(head);
    DLinkListPopBack(head);
    DLinkListPrintChar(head,"再对尾部删除两个节点");
    DLinkListPopBack(head);
    DLinkListPrintChar(head,"尝试对空链表进行删除");
}

void TestPushFront()
{

    TEST_HEAD;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushFront(head,'a');
    DLinkListPushFront(head,'b');
    DLinkListPushFront(head,'c');
    DLinkListPushFront(head,'d');
    DLinkListPrintChar(head,"头部插入四个节点");
}

void TestPopFront()
{

    TEST_HEAD;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushBack(head,'a');
    DLinkListPushBack(head,'b');
    DLinkListPushBack(head,'c');
    DLinkListPushBack(head,'d');
    DLinkListPrintChar(head,"尾部插入四个节点");
    DLinkListPopFront(head);
    DLinkListPopFront(head);
    DLinkListPrintChar(head,"头部删除两个节点");
    DLinkListPopFront(head);
    DLinkListPopFront(head);
    DLinkListPrintChar(head,"再对头部删除两个节点");
    DLinkListPopFront(head);
    DLinkListPrintChar(head,"尝试对空链表进行删除");
}

void TestInsert()
{

    TEST_HEAD;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushBack(head,'a');
    DLinkListPushBack(head,'b');
    DLinkListPushBack(head,'c');
    DLinkListPushBack(head,'d');
    DLinkListPrintChar(head,"尾部插入四个节点");
    DLinkNode* pos_b=DLinkListFind(head,'b');
    DLinkListInsert(head,pos_b,'x');
    DLinkListPrintChar(head,"在b之前插入元素x");
}

void TestInsertAfter()
{
    TEST_HEAD;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushBack(head,'a');
    DLinkListPushBack(head,'b');
    DLinkListPushBack(head,'c');
    DLinkListPushBack(head,'d');
    DLinkListPrintChar(head,"尾部插入四个节点");
    DLinkNode* pos_b=DLinkListFind(head,'b');
    DLinkListInsertAfter(head,pos_b,'x');
    DLinkListPrintChar(head,"在b之后插入元素x");
}

void TestFind()
{
    TEST_HEAD;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushBack(head,'a');
    DLinkListPushBack(head,'b');
    DLinkListPushBack(head,'c');
    DLinkListPushBack(head,'d');
    DLinkNode* result_x=DLinkListFind(head,'x');
    DLinkListPrintChar(head,"查找未知元素x");
    printf("result expected NULL,actual %p\n",result_x);
    DLinkNode* result_b=DLinkListFind(head,'b');
    DLinkListPrintChar(head,"查找元素b的位置");
    printf("result expected %p,actual %p\n",head->next->next,result_b);
}

void TestErase()
{
    
    TEST_HEAD;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushBack(head,'a');
    DLinkListPushBack(head,'b');
    DLinkListPushBack(head,'c');
    DLinkListPushBack(head,'d');
    DLinkListPrintChar(head,"删除之前链表为");
    DLinkListErase(head,head->next->next);
    DLinkListPrintChar(head,"删除元素b");
}

void TestRemove()
{
    TEST_HEAD;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushBack(head,'a');
    DLinkListPushBack(head,'b');
    DLinkListPushBack(head,'c');
    DLinkListPushBack(head,'d');
    DLinkListPrintChar(head,"删除之前链表为");
    DLinkListRemove(head,'b');
    DLinkListPrintChar(head,"删除元素b");
}

void TestRemoveAll()
{
    TEST_HEAD;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushBack(head,'b');
    DLinkListPushBack(head,'a');
    DLinkListPushBack(head,'b');
    DLinkListPushBack(head,'c');
    DLinkListPushBack(head,'d');
    DLinkListPushBack(head,'b');
    DLinkListPrintChar(head,"删除之前链表为");
    DLinkListRemoveAll(head,'b');
    DLinkListPrintChar(head,"删除元素b");
}

void TestDestroy()
{
    
    TEST_HEAD;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushBack(head,'b');
    DLinkListPushBack(head,'a');
    DLinkListPushBack(head,'b');
    DLinkListPushBack(head,'c');
    DLinkListPushBack(head,'d');
    DLinkListPushBack(head,'b');
    DLinkListPrintChar(head,"删除之前链表为");
    DLinkListDestroy(&head);
    printf("head expect NULL,actual %p",head);
}

int main()
{
    TestInit();
    TestPushBack();
    TestPopBack();
    TestPushFront();
    TestPopFront();
    TestInsert();
    TestInsertAfter();
    TestFind();
    TestErase();
    TestRemove();
    TestRemoveAll();
    //TestDestroy();
    return 0;

}
#endif
