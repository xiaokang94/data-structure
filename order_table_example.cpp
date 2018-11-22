//
// Created by kangkang94 on 2018/11/20.
//

#include "order_table_example.h"
#include "common.h"
#include "order_table.h"
#include "stdlib.h"
#include "time.h"
#include <iostream>

using namespace std;

/**
 * 归并算法测试 包含随机生成顺序表，顺序表排序，顺序表归并
 */
OTList MergeTest()
{
   OTList L1;
   OTList L2;
   OTList L3;
  L1 = createOrderTable();
  L2 = createOrderTable();
  BubbleSort(L1);
  BubbleSort(L2);
  Merge(L1,L2,L3);
  return L3;
}
/**
 * 有序顺序表中插入一个数据 使之插入之后的顺序表依然有序
 * @return
 */
OTList InsertOrderTest()
{
   OTList L;
   ElemType e;
   // 生成种子文件
   srand((unsigned)time(NULL));
   e = rand()%123;
   L = createOrderTable();
   BubbleSort(L);
    insert(L,e);
    return L;
}
/**
 *  删除节点测试
 * @return
 */
OTList DeleteElemTest()
{
    OTList L;
    ElemType e;
    int i;
    srand((unsigned)time(NULL));
    //    i 生成1到49的随机数、
    i = rand()%49;
    i= i+1;
    L = createOrderTable();
    // 删除第i个节点 将删除的数据返回到e中
    ListDelete(L,i,e);
    return L;
}
/**
 * 将顺序表逆置操作
 *
 * @return
 */
OTList reverseTest()
{
    OTList L;
    L = createOrderTable();
   reverse(L);
   return L;
}
/**
 * 创建一个顺序表 表的长度为 LIST_INIT_SIZE/2
 * 数据元素随机
 * @return
 */
OTList createOrderTable()
{
    ElemType e;
    OTList L;
    int i;
    InitList(L);
    srand((unsigned)time(NULL));
    for(i = 1;i <= LIST_INIT_SIZE/2;i++)
    {
        e = rand()%123;
        ListInsert(L,e,i);
    }
   return L;
}


/**
 * 冒泡排序
 * 通过无序区中相邻元素关键字间的比较和位置交换，使关键字最小的元素如气泡一般逐渐往上漂浮直至水面
 * 当初始数据序列正序时，执行效率最高，此时的时间复杂度为O(n)(执行i=0 这一趟后边退出算法),当初始数据序列反序时，执行效率最低，此时的时间
 * 复杂度为O(n2),所以当初始数据越接近正序，冒泡排序的算法性能越好
 *
 * 冒泡排序算法中所产生的有序区一定是全局有序的，也就是说，有序区中的所有元素的关键字一定大于或者小于无序区中所有元素的关键字，这样每一趟排序
 * 都会将一元素放置到最终的位置上（即归位一个元素）
 * @param L
 */
int BubbleSort(OTList &L)
{
    int len;
    int i;
    int j;
    int exchange;// 是否需要交换
    ElemType tmp;
    len = L.length;
    for(i=0;i<len-1;i++)
    {
        exchange = 0;
        for(j=len-1;i<j;j--)
        {
           if(L.data[j] < L.data[j-1])
           {
               tmp = L.data[j];
               L.data[j] = L.data[j-1];
               L.data[j-1] = tmp;
           }
           exchange = 1;
        }
        // 当本趟没有存在交换时直接退出循环
        if(exchange==0)
        {
            break;
        }
    }
    return 0;
}

// 有序表的归并算法
/**
 * 有序表的归并算法
 * 条件： L1与L2归并到L3中 L1与L2 有序 且都是具有相同的次序
 * 思想： 两个下标pos1和pos2 分别遍历L1,L2,然后将较小的存入L3中，最后将较长的那个表数据添加到L3后面
 * 时间复杂度为O(m+n),其中n,m分别为顺序表L1,L2的长度。其空间复杂度为O(1)
 * @param L1
 * @param L2
 * @param L3
 * @return
 */
int Merge(OTList L1,OTList L2,OTList &L3)
{
   int pos1 = 0;
   int pos2 = 0;
   int pos3 = 0;

   while(pos1 < L1.length && pos2< L2.length)
   {
        if(L1.data[pos1] < L2.data[pos2])
        {
            L3.data[pos3] = L1.data[pos1];
            pos1++;
            pos3++;

        }else {
            L3.data[pos3] = L2.data[pos2];
            pos2++;
            pos3++;
        }
   }

   // 遍历L1剩下的元素
   while(pos1<L1.length)
   {
       L3.data[pos3] = L1.data[pos1];
       pos1++;
       pos3++;
   }

   // 遍历L2剩下的元素
   while(pos2 < L2.length)
   {
       L3.data[pos3] = L2.data[pos2];
       pos2++;
       pos3++;
   }
   L3.length =pos3;
   return 0;
}
/**
 * 已知一个顺序表，其中的元素递增有序排列，插入元素e后，该顺序表依旧有序
 * 思想：先找到元素插入的位置，然后再移动插入
 * @param L
 * @param e
 */
void insert(OTList &L,ElemType e)
{
    int i;
    // 元素的逻辑位置
    int pos;
    for(i=0;i<L.length;i++)
    {
        if(L.data[i]<e)
        {
            i++;
        }else{
            // i为下标 逻辑位置应该加1
            pos =i+1;
            break;
        }
    }
    if(pos == 0)
    {
        pos++;
    }

    ListInsert(L,e,pos);

}
/**
 * 将顺序表所有的元素逆置，算法空间复杂度为O(1)
 * 思想：将顺序表的前半部分和后半部分对应的元素 L.data[L.length-i-1]进行交换，0<=i<L.length/2
 * @param L
 * @return
 */
int reverse(OTList &L)
{
   int i;
   int maxPos;
   ElemType e;
   maxPos = L.length/2;
   for(i = 0;i < maxPos;i++)
   {
      e = L.data[i];
      L.data[i] = L.data[L.length-i-1] ;
      L.data[L.length-i-1] =e;
   }
   return 0;
}
