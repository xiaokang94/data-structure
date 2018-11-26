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
   int len;
   len =sizeof(dat)/sizeof(ElemType);
   CreateDataList(dat,len);
   L = InitList();
   cout<<"链表插入前的序列:";
   for(i=0;i<10;i++)
   {
      cout<<dat[i]<<",";
   }
   cout<<endl;
  L = createLinkListFirst(dat,len);
  L2 = createLinkListTail(dat,len);
  cout<<"头插法插入后的值为:";
  traverseList(L);
  cout<<"尾插法插入后的值为:";
  traverseList(L2);
   return 0;
}
/**
 * 随机生成一个数组中的元素
 * @param dat 数据
 * @param len 长度
 * @return
 */
int CreateDataList( ElemType dat[],int len)
{
   int i;
   srand((unsigned)time(NULL));
   for(i=0;i<len;i++)
   {
      dat[i] = rand()%1000;
   }
   return 0;
}