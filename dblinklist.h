#pragma once
typedef char DLinkType;
typedef struct DLinkNode
{
    DLinkType data;
    struct DLinkNode* prev;
    struct DLinkNode* next;
}DLinkNode;

//链表初始化
void DLinkListInit(DLinkNode** phead);

//尾插法
void DLinkListPushBack(DLinkNode* head,DLinkType value);

//尾删法
void DLinkListPopBack(DLinkNode* head);

//头插法
void DLinkListPushFront(DLinkNode* head,DLinkType value);

//头删法
void DLinkListPopFront(DLinkNode* head);

//给pos位置之前插入新的节点
void DLinkListInsert(DLinkNode* head,DLinkNode* pos,DLinkType value);

//给pos位置之后插入新的节点
void DLinkListInsertAfter(DLinkNode* head,DLinkNode* pos,DLinkType value);

//查找元素
DLinkNode* DLinkListFind(DLinkNode* head,DLinkType to_find);

//删除pos位置对元素
void DLinkListErase(DLinkNode* head,DLinkNode* to_delete);

//按值来删除元素
void DLinkListRemove(DLinkNode* head,DLinkType to_delete_value);

//按值来删除所有元素
void DLinkListRemoveAll(DLinkNode* head,DLinkType to_delete_value);

//销毁链表
void DLinkListDestroy(DLinkNode** phead);

