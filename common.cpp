//
// Created by kangkang94 on 2018/11/20.
//

#include "common.h"
#include <time.h>
#include <stdlib.h>
/**
 * 生成字符串
 * cLen 表示要生成字符串的长度
 * cnt 生成的个数
 * new 分配的内存 对应的指针地址递增， 递增后的地址 会不会存有重要的数据？
 * @return
 */
char * createString(int cLen)
{
   // 单个字符串的长度
   char * ch = new char;
   // 字符串的初始地址
   char *tm ;
   tm = ch;
   int tmp = 0;
   // 设置种子数
   srand (time(NULL));
   for(tmp=0;tmp < cLen;tmp++)
   {
       *ch = 'A'+rand()%26;
       ch++;
   }
   *ch = '\0';
   ch  =tm;
   return  ch;
}