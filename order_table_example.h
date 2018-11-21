/**
 * datetime：2018/11/20 00:3556
 * author:kangkang94
 *  顺序表的基本测试用例
 *
 */

#ifndef DATA_STRUCTURE_ORDER_TABLE_EXAMPLE_H
#define DATA_STRUCTURE_ORDER_TABLE_EXAMPLE_H
#include "common.h"
// 创建一个随机满数据的有序表
OTList createOrderTable();
// 冒泡排序
int BubbleSort(OTList &L);
// 顺序表合并
int Merge(OTList L1,OTList L2,OTList &L3);
// 顺序表逆置操作
int reverse(OTList &L);
// 顺序表二路归并测试
OTList MergeTest();
// 顺序表L 有序，插入元素e之后依然有序
void insert(OTList &L,ElemType e);
// 顺序表L 有序、插入元素e之后依然有序测试方法
OTList InsertOrderTest();
// 顺序表中删除某一节点测试
OTList DeleteElemTest();
// 顺序表逆置测试
OTList reverseTest();

#endif //DATA_STRUCTURE_ORDER_TABLE_EXAMPLE_H
