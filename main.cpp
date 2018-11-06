/**
 * 指针名表示的是地址， * 运算符被称为间接值或解除引用运算符，将其应用于指针
 * 如 manly是一个指针，则manly表示的是一个地址,而*manly表示的是存储在该地址出的值
 *  *manly 与常规int变量等效
 *  声明和初始化指针
 *  int *p;
 *  解释 *p的类型是int,由于*运算被用于指针，因此p变量本身必须是指针，p指向int类型
 *  p的类型是指向int的指针，p是地址（指针） ，而*p是int，不是指针
 *  int *p1,p2 表示声明创建一个指针（p1)和一个int变量(p2)
 *  c++中 int* 是一种复合类型， 是指向int的指针
 *  可以在声明语句中初始化指针，被初始化的是指针，而不是它指向的值，
 *  如 int higgens = 5;
 *  int *pt = &higgens;
 *  指针的危险
 *   在c++中创建指针时，计算机将分配用来存储地址的内存，但不会分配用来存储指针所指向的数据的内存
 *
 *   为数据提供孔家是一个独立的步骤，忽略这一步无意识自找麻烦
 *    如
 *    long * f;
 *    *f = 2222;
 *    没有为数据提供分配空间
 *
 *    非常注意的事项 ： 一定要在对指针应用解除引用运算符（*）之前，将指针初始化一个确定的、适当的地址，这是关于使用
 *    指针的金科玉律
 *
 *    指针不是整型，指针与整数是可以执行加、减、除等运算，而指针描述的是位置，将两个地址相乘
 *    是没有任何意义的 所以不能简单的将整数赋值给指针
 *
 *    变量在编译时分配的有名称的内存，而指针只是为可以通过名称直接访问内存提供了一个别名。指针真正的用
 *    武之地在于，可以使用库函数malloc()来分配内存；在c++中仍然可以使用 但c++有更好的方法
 *
 *    new 运算符
 *    在运行阶段为一个int值分配未命名的内存，并使用指针来访问这个值
 *    告诉new 需要为哪种数据类型分配内存； new找到一个长度正确的内存块，并返回该内存块的地址，
 *    int *p  = new int;
 *     *p = 100;
 *    typeName *p = new typeName;
 *    new 分配内存时在程序运行时进行的，
 *     地址本身只指出了对象存储地址的开始，没有指出其类型（使用的字节数）
 *     new 分配的内存块通常与常规变量声明分配的内存块不同，常规的变量分配内存被存储在栈的内存区域
 *     中，而new 是在堆或者自由存储区的内存区域分配内存的
 *     使用delete释放内存
 *
 *     int *p = new int ;
 *     delete p;
 *     这将释放p指向的内存，但不会删除指针p本身
 *     new 和delete 必须配对的使用，否则会发生内存泄漏，如果内存泄漏严重，程序将
 *     由于不断寻找更多内存而终止
 *
 *     只能使用 delete 来释放使用new 分配的内存，然而，对空指针使用delete是安全的
 *     在编译时给数组分配内存被称为静态联编，意味着是在编译时加入到程序中的，但使用new时
 *     如果在运行阶段需要数组，则创建它，如果不需要则不创建他，还可以在程序运行时选择数组的长度，这被称为动态联编，
 *     意味着数组是在程序运行时创建的，这种数组叫动态数组，使用静态联编时，必须写在程序时
 *     指定数组的长度，使用动态联编时，程序将在运行时确定数组的长度
 *
 *     1. 使用new 常见动态数组
 *
 *     int *p = new int [10];
 *     new 运算符返回第一个元素的地址，这个地址被赋给指针p
 *     对于new创建出来的数组，使用
 *     delete [] p;来释放
 *
 *     使用new和delete
 *
 *     字符指针如何输出地址
 *     cout默认将字符指针当作字符串来处理，要想输出地址需要使用强类型转换 如 char * p
 *
 *     输出时 cout<<(void *)p<<endl;
 *
 *     问题：
 *     1. 返回类型为字符指针的函数 内部使用new动态分配了内存，应该在何处释放内存？
 *         ans: 应该在调用该函数结束时 使用delete回收内存
 *     2. 使用new动态分配内存后 没用delete释放内存 程序结束后操作系统会释放它
 *
 *     3.比如使用new为一个字符指针动态分配内存，是分配字符的存储内存的空间吗？ 存储字符的地址递增后 会不会指向到一个新的
 *     地址那边重要的数据 ，如何判断新的地址是可用的而不是指向重要数据的地址不可用的
 *
 *      4. 其中L.elem 为L中的一个元素
    L.elem = (ElemNode *)malloc(LIST_INIT_SIZE* sizeof(ElemNode));
 *
 *
 */
#include <iostream>
// 随机数函数
#include <stdlib.h>
#include <time.h>

#include "order_table.h"
using namespace std;
/**
 * 声明函数
 * @return
 */
int orderTableTest();
void primerTest();
// 创建个随机字符串
char * createString(int cLen);

int main() {
    orderTableTest();
    return 0;
}
/**
 * 顺序表测试
 * @return
 */
int orderTableTest()
{
    SqList L;
    ElemNode e;
   // 链表的第1个位置插入数据
   int i = 1;
   char *strList  ;
   char *ch ;
    InitList(L);// 初始化链表
    for(i=1;i < 30;i++)
    {
        // 一个10位数的字符串
        e.ch =  createString(10);
        ListInsert(L,i,e);
    }
    for(i=1;i<30;i++)
    {
        cout<<(L.elem+i-1)->ch<<endl;
    }
   return 0;
}
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

