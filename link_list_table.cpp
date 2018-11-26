/**
 *  datetime: 20181121
 *  author: kangkang94
 *  本文件主要是链表操作的基本文件 包含链表的创建（头插法和尾插法创建链表）,链表添加节点，删除节点
 */
#include "link_list_table.h"
#include <iostream>
using namespace std;
// 创建一个包含头节点的链表,
/**
 *  创建一个包含头节点的链表
 * @return
 */
LinkList * InitList()
{
    LinkList *L;
    L = (LinkList *)malloc(sizeof(LinkList));
    L->next =NULL;
    return L;
}
/**
 *  采用头插法创建一个单链表,一直在头部后面添加节点
 *  特点： 头插法创建的链表和数据插入时的顺序逆序
 * @param dat 插入时的数据数组
 * @param len 数组的长度
 * @return
 */
LinkList * createLinkListFirst(const ElemType dat[],int len)
{
   LinkList *L;
   // 插入时的节点
   LinkList *node;
   // 数组的长度
   int i;
   L = InitList();
   for(i=0;i<len;i++)
   {
       // 为插入时的节点分配存储空间
       node = (LinkList *)malloc(sizeof(LinkList));
       node->next = L->next;
       L->next = node;
       node->data = dat[i];
   }
   return L;
}

/**
 * 采用尾插法创建链表 一直在尾部添加节点
 * 特点：创建的链表顺序和 数组参数时传入的顺序相同
 * @param dat
 * @param len 数组的长度
 * @return
 */
LinkList * createLinkListTail(const ElemType dat[],int len)
{
   LinkList *L;
   // 插入的节点的信息
   LinkList *node;
   // 尾部节点的值
   LinkList *tail;
   int i;
   //   初始化L链表
   L = InitList();
   tail = L;
   for(i = 0;i < len;i++)
   {
       node = (LinkList *)malloc(sizeof(LinkList));
       node->data = dat[i];
       tail->next = node;
       node->next = NULL;
       tail = node;
   }
   return L;
}
/**
 * 遍历链表中的数据域 数据域尾基本数据类型
 * 遍历的是带头结点的数据
 * @param L
 * @return
 */
int traverseList(LinkList *L)
{
    LinkList *p;
    p = L->next;
    while(p!=NULL)
    {
        cout<<p->data<<",";
        p = p->next;
    }
    cout<<endl;
   return 0;
}
