//
// Created by Administrator on 2018/11/22 0022.
//

#include "link_list_table_example.h"
#include "time.h"
#include <iostream>
using namespace std;
/**
 * 创建链表的两种方法
 * 1. 头插法
 * 2. 尾插法
 * @return
 */
int CreateLinkListTest()
{
   // 头插法创建的链表
   LinkList *L ;
   // 尾插法创建的链表
   LinkList *L2;
   ElemType dat[10];
   int i ;
   CreateDataList(dat);
   L = InitList();
   cout<<"链表插入前的序列:";
   for(i=0;i<10;i++)
   {
      cout<<dat[i]<<",";
   }
   cout<<endl;
  L = createLinkListFirst(dat);
  L2 = createLinkListTail(dat);
  cout<<"头插法插入后的值为:";
  traverseList(L);
  cout<<"尾插法插入后的值为:";
  traverseList(L2);
   return 0;
}
/**
 * 随机生成一个数组中的元素
 * @param dat
 * @param n
 * @return
 */
int CreateDataList( ElemType dat[])
{
   int i;
   int n;
   n = sizeof(dat)/sizeof(ElemType);
   srand((unsigned)time(NULL));
   for(i=0;i<n;i++)
   {
      dat[i] = rand()%1000;
   }
   return 0;
}