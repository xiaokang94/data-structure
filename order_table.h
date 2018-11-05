//
// Created by Administrator on 2018/10/30 0030.
//

#ifndef LINEAR_LIST_ORDER_TABLE_H
#define LINEAR_LIST_ORDER_TABLE_H

#define LIST_INIT_SIZE 100  // 线性表存储空间的初始分配量
#define LISTINCREMENT 10 // 线性表存储空间的分配增量
// 定义错误编码
#define  OVERFLOW -100 // 内存空间分配失败
#define LENGTH_OVER_ERROR -99 // 长度超出现在
/**
 * 顺序表定义
 */
// 元素节点
 typedef struct{
     char * ch;
 }ElemNode;

typedef struct
{
   ElemNode *elem;// 存储空间的基址
   int length;// 当前线性表长度
   int listSize;// 当前分配的存储容量（以sizeof(ElemType)）为单位
}SqList;
/**
 * 声明方法 供外部调用
 *
 */
 int InitList(SqList &L);// 初始化链表
int ListInsert(SqList &L,int i,ElemNode e);// 链表里插入元素
#endif //LINEAR_LIST_ORDER_TABLE_H
