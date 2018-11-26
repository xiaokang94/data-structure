//
// Created by Administrator on 2018/11/21 0021.
//

#ifndef DATA_STRUCTURE_LINK_LIST_TABLE_H
#define DATA_STRUCTURE_LINK_LIST_TABLE_H
#include "common.h"
#include "stdlib.h"
// 尾插法创建单链表
LinkList * createLinkListTail(const ElemType dat[],int len);
// 头插法创建单链表
LinkList * createLinkListFirst(const ElemType dat[],int len);
// 初始化链表
LinkList * InitList();
// 遍历链表中的数据域 控制台输出 各个值用逗号隔开
int traverseList(LinkList *L);

#endif //DATA_STRUCTURE_LINK_LIST_TABLE_H
