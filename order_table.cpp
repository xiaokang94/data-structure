/**
 *  顺序表基本操作的实现
 */

#include "order_table.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
/**
 * 构造一个空的线性表 判断L是否为空
 */
int InitList(SqList &L)
{
    // 分配多个地址空间存放 每个ElemNode元素
    L.elem = (ElemNode *)malloc(LIST_INIT_SIZE* sizeof(ElemNode));
    if(!L.elem)
    {
        exit(OVERFLOW);
    }
    L.length = 0;// 初始化长度
    L.listSize = LIST_INIT_SIZE;// 表的最大长度
    return 0;
}
/**
 * 线性表已经存在，销毁线性表
 */
int DestroyList(SqList &L)
{
    free(L.elem);
    L.elem = NULL;
    L.length = 0;
    L.listSize = 0;
    return 1;
}
/**
 *  将L重置为空表
 */
int ClearList(SqList &L)
{
    L.length = 0;
    L.listSize = LIST_INIT_SIZE;

    return 1;
}
/**
 *  线性表L已经存在 ，若L为空表 ，则返回TRUE 否则返回FALSE
 */

bool ListEmpty(SqList L)
{
    if(L.length == 0)
    {
        return true;
    }else {
        return false;
    }
}
/**
 * 返回线性表的长度
 * @return
 */
int ListLength(SqList L)
{
    return L.length;
}
/**
 *  线性表L已经存在 ，1<=i<=ListList.length;
 *  e返回L中第i个数据元素的值
 */
int GetElem(SqList L,int i,ElemNode &e)
{
    if(L.length<i|| i<1)
    {
        exit(LENGTH_OVER_ERROR );
    }
    e = L.elem[i-1];
    return 1;
}

/**
 * 线性表L已经存在，comePare()是数据元素的判定函数
 * 返回L中第一个与e满足关系comepare()的数据元素的位序，若不存在，则返回
 * 0
 */
 int LocateElem(SqList L,char e,char *compare)
 {
    return 0;
 }

 /**
  *  线性表已经存在 ，若cur_e是L的数据元素，且不是第一个，则用
  *  pre_e返回它的操作前驱，否则操作失败，pre_e无定义
  */
int PriorElem(SqList L,char * cur_e,char * &pre_e)
{
    return 0;
}
/**
 * 线性表L已经存在 ，若cur_e是L的1数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，next_e无定义
 */
int NextElem(SqList L,char * cur_e,char * next_e)
{
    return 0;
}
/**
 * 线性表L已经存在 ，1<=i<=ListLength+1;
 * 在L中第i个位置之前插入新的数据元素e,L的长度加1
 */
int ListInsert(SqList &L,int i,ElemNode e)
{
    // 空间不足时新的地址指针
    ElemNode *newBase;
    ElemNode *q;
    ElemNode *p;
    int j;
    // 循环变量
   // 先判断插入的地方是否合法
   // 再判断链表是否已经满了 ，满了的话要额外分配内存
   // 再插入数据 到链表中去
   if( i < 0 || i > L.length + 1 )
   {
       exit(LENGTH_OVER_ERROR);
   }
   // 额外分配空间
   if( L.length == L.listSize )
   {
      newBase = (ElemNode *)realloc(L.elem,(L.listSize+LISTINCREMENT)* sizeof(ElemNode));// 分配新的存储空间
      L.elem = newBase;
      // 增加新的存储容量
      L.listSize += LISTINCREMENT;
   }
    // 插入数据的地方
    q = p = L.elem;
   if(i>0)
   {
       p = p + i - 1;
   }
   // 插入数据后最后一位数据
   j = L.length+1;
   q = q + j;
    // 从最后一位开始 依次向右移动一位
   for(j ;j > i;q--,j--)
   {
        *q = *(q - 1);
   }
   *p = e;
   L.length++;
   return 0;
}
/**
 *  线性表L已经存在且非空， 1<=i<=ListLength(L)
 *  删除L的第i个数据元素，并用e返回其值，L的长度减1
 */
int ListDelete(SqList &L,int i,char &e)
{
    return 0;
}
/**
 * 线性表L已经存在
 * 依次对L的每个数据元素调用函数visit()
 */
int ListTraverse(SqList L,char visit)
{
    return 0;
}

/**
 * 下面是线性表中更复杂的操作 高级操作 如线性表的合并，拆分，元素排序等 在摸一个地方插入多个链表
 */




