/**
 *  顺序表基本操作的实现
 */

#include "order_table.h"
#include "common.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
/**
 * 构造一个空的顺序表
 */
int InitList(OTList &L)
{
    L.length = 0;
    return 0;
}
/**
 * 顺序表可以销毁吗
 */
int DestroyList(OTList &L)
{
    return 1;
}


/**
 *  顺序表L已经存在 ，1<=i<=ListList.length;
 *  返回L中第i个数据元素的值
 */
int GetElem(OTList L,int i,ElemType &e)
{
    if(L.length<i|| i<1)
    {
        exit(LENGTH_OVER_ERROR);
    }
    e = L.data[i-1];
    return 1;
}

/**
 * 根据元素值查找该值在顺序表中的逻辑序号
 * @param L
 * @param e
 * @return
 */
int LocateElem(OTList L,ElemType e)
{
    int i;
    for(i=0;L.data[i]!=e;i++)
    {
        if(i >= L.length)
        {
            return 0;
        }
    }
    return i+1;
}

/**
 * 插入数据到顺序表中 插入i之后的元素向后移动
 * @param L
 * @param e
 * @param i 逻辑序号 从1开始
 * @return
 */
int ListInsert(OTList &L,ElemType e,int i)
{
    int j;// 物理序号
    if(i < 1||i > L.length+1 || L.length == LIST_INIT_SIZE)
    {
        return 0;
    }
    for(j = L.length;j >= i;j--)
    {
       L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;
    L.length++;

    return 1;
}
/**
 * 删除第i个元素,i之后的元素向左移动
 * @param L
 * @param i
 * @param e 删除返回的值
 * @return
 */
int ListDelete(OTList &L,int i,ElemType &e)
{
    int j;// 物理序号
   if(i < 1 || i > L.length+1 || L.length == 0)
   {
       return 0;
   }
   e = L.data[i-1];
  for(j = i;j < L.length;j++)
  {
     L.data[j-1] = L.data[j];
  }
  L.length--;
  return 1;
}
 /**
  *  线性表已经存在 ，若cur_e是L的数据元素，且不是第一个，则用
  *  pre_e返回它的操作前驱，否则操作失败，pre_e无定义
  */
int PriorElem(OTList L,char * cur_e,char * &pre_e)
{
    return 0;
}
/**
 * 线性表L已经存在 ，若cur_e是L的1数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，next_e无定义
 */
int NextElem(OTList L,char * cur_e,char * next_e)
{
    return 0;
}
/**
 * 线性表L已经存在 ，1<=i<=ListLength+1;
 * 在L中第i个位置之前插入新的数据元素e,L的长度加1
 */
int ListInsert(OTList &L,int i,ElemType e)
{
    // 空间不足时新的地址指针

   return 0;
}
/**
 *  线性表L已经存在且非空， 1<=i<=ListLength(L)
 *  删除L的第i个数据元素，并用e返回其值，L的长度减1
 */
int ListDelete(OTList &L,int i,char &e)
{
    return 0;
}
/**
 * 线性表L已经存在
 * 依次对L的每个数据元素调用函数visit()
 */
int ListTraverse(OTList L,char visit)
{
    return 0;
}

/**
 * 下面是线性表中更复杂的操作 高级操作 如线性表的合并，拆分，元素排序等 在摸一个地方插入多个链表
 */




