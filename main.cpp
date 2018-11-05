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
 */
#include <iostream>
#include "order_table.h"
using namespace std;
/**
 * 声明函数
 * @return
 */
int orderTableTest();
void primerTest();

int main() {
//    orderTableTest();
    primerTest();
//    std::cout << "Hello, World!" << std::endl;
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
    int i;
    char * str = (char *)"abc";
    e.ch = str;
    InitList(L);
//    for(i=1;i < 30;i++)
//    {
//        ListInsert(L,i,e);
//    }
    cout<<L.elem<<endl;
  cout<<e.ch<<endl;
   return 0;
}
/**
 * 指针测试方法
 */
void primerTest()
{
    int donuts = 6;
    double cups = 4.5;
    cout << "donuts vlaue ="<<donuts;
    cout << " and donuts address = "<<&donuts;
}
