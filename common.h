//
// Created by kangkang94 on 2018/11/20.
/**
 * datetime: 2018/11/20 00:00:00;
 * author: kangkang94
 *
 * 本文件主要是通用的自定义函数的声明、自定义的常量、结构体
 *
 */

#ifndef DATA_STRUCTURE_COMMON_H
#define DATA_STRUCTURE_COMMON_H
/**
 * 常量定义
 */
#define LIST_INIT_SIZE 100  // 线性表存储空间的初始分配量
#define LISTINCREMENT 10 // 线性表存储空间的分配增量


/**
 * 定义的错误编码
 */
#define  OVERFLOW -100 // 内存空间分配失败
#define LENGTH_OVER_ERROR -99 // 长度超出现在

/**
 * 结构体
 */
#define ElemType int
// 顺序表
typedef struct
{
   ElemType data[LIST_INIT_SIZE];
   int length;
}OTList;


/**
 * 自定义函数声明
 */
// 创建一个长度为cLen的随机字符串序列
char * createString(int cLen);
#endif //DATA_STRUCTURE_COMMON_H
