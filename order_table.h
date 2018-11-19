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
#endif //LINEAR_LIST_ORDER_TABLE_H
