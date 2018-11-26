//
// Created by Administrator on 2018/10/30 0030.
//

#ifndef LINEAR_LIST_ORDER_TABLE_H
#define LINEAR_LIST_ORDER_TABLE_H
#include "common.h"
/**
 * 声明方法 供外部调用
 *
 */
int InitList(OTList &L);// 初始化链表
int ListInsert(OTList &L,int i,ElemType e);// 链表里插入元素
int ListDelete(OTList &L,int i,ElemType &e);
// 依次输出数据域的数据（基本数据类型）
int traverseList(OTList L);
//
#endif //LINEAR_LIST_ORDER_TABLE_H
