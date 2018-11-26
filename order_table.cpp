/**
 *  顺序表基本操作的实现
 */
#include "order_table.h"
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
        return 0;
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
 * 遍历输出顺序表的的数据域（基本数据类型）
 * @param L
 * @return
 */
int traverseList(OTList L)
{
    int i = 0;

    for(i=0;i<L.length;i++)
    {
        cout << L.data[i]<<",";
    }
    cout << endl;
    return 0;
}
/**
 * 下面是线性表中更复杂的操作 高级操作 如线性表的合并，拆分，元素排序等 在摸一个地方插入多个链表
 */




