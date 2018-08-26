# Offer
## 8/10：make_heap,pop_heap,push_heap,sort_heap
  STL中，有很多的排序函数模板供我们调用，省去我们自己编写一些排序过程的麻烦，本文是一篇关于STL中堆排序的一个介绍。  
  本文涉及的几个函数如下：make_heap(),push_heap(),pop_heap(),is_heap(),sort_heap()。其中make_heap()用于构建一个堆。  
  SGI STL中对make_heap()的声明如下：  
  ```
  template<class RandomAccessIterator> void make_heap(RandomAccessIterator first, RandomAccessIterator last);    
  template<class RandomAccessIterator, class StrictWeakOrdering> void make_heap(RandomAccessIterator first, RandomAccessIterator last, StrictWeakOrdering comp);
  ```  
  就是说make_heap()有两个重载版本，事实上都差不多，都是指定一个需要处理的区间，第二个版本只不过是自己定义一个比较准则而已，默认（第一种）是以operator<   来作为比较准则的。
    
  SGI STL中对push_heap()的声明如下：  
  ```
  template<class RandomAccessIterator> void push_heap(RandomAccessIterator first, RandomAccessIterator last);  
  template<class RandomAccessIterator, class StrictWeakOrdering> void push_heap(RandomAccessIterator first, RandomAccessIterator last, StrictWeakOrdering comp);   
  ```
  形式和make_heap()差不多，push_heap()用于将指定区间的最后一个元素加入堆中并使整个区间称为一个新的堆，注意前提是除最后一个元素外的所有元素已经构成一个堆。  
  SGI STL中堆pop_heap()的声明如下：
  ```
  template<class RandomAccessIterator> void pop_heap(RandomAccessIterator first, RandomAccessIterator last);
  template<class RandomAccessIterator, class StrictWeakOrdering> void pop_heap(RandomAccessIterator first, RandomAccessIterator last, StrictWeakOrdering comp);
  ```  
  和push_heap()相反，pop_heap()用于弹出堆中的第一个元素，并把它放到区间的最后一个位置，然后重新将前面的元素构成一个堆。  
  
  SGI STL中堆is_heap()的声明如下：  
  ```
  template<class RandomAccessIterator> bool is_heap(RandomAccessIterator first, RandomAccessIterator last);
  template<class RandomAccessIterator, class StrictWeakOrdering> bool is_heap(RandomAccessIterator first, RandomAccessIterator last, StrictWeakOrdering comp);
  ```  
  is_heap()用于判断一个区间是否是一个堆，这个函数在push_heap()之前用可以确保区间已经构成一个堆。  
  
  例子：  
  ```
  #include <cstdio>
  #include <algorithm>
  using namespace std;
  
  bool cmp(int a, int b)
  {
      return a>b;
  }
  
  int main()
  {
      int i,number[20] = {29,23,20,22,17,15,26,51,19,12,35,40};
      make_heap(number, number+12);
      //结果是：51 35 40 23 29 20 26 22 19 12 17 15
      for(i=0; i<12; ++i)
          printf("%d",num[i]);
      printf("\n");
      
      make_heap(&number[0],&number[12],cmp);
      //结果是：12 17 15 19 23 20 26 51 22 29 35 40
      
      //加入元素8
      number[12]=8;
      //加入后调整
      push_heap(number,number+12,cmp);
      //结果：8 17 12 19 23 15 26 51 22 35 40 20
      
      //弹出元素8
      pop_heap(&numebr[0],&number[12],cmp);
      //结果：12 17 15 19 23 20 26 51 22 29 35 40
      
      sort_heap(&number[0],&number[12],cmp);
      //结果不用说都知道是有序的
      
      return 0;
  }
  ```  
  
  ## 8/10 知识点整理  
  - 把整数右移一位和把整数除以2在数学上是等价的，但是除法的运算效率比位移运算要低得多，**在实际编程中应尽可能地用位移运算代替除法**  
  - 把一个整数减去1之后再和原来的整数做位与运算（&），得到的结果相当于把整数的**二进制表示中最右边的*1*变成*0***
  - 声明一个引用的同时，如果不是作为**函数的参数**或**返回值**，**必须进行初始化**，明确引用是哪个变量的别名，引用一旦成为某个变量的别名后，在程序运行过程中**不可改变**这种指代关系
  - 静态成员数据是属于类的，类的所有对象共享，可视作全局变量
  - 基类的私有成员在派生类中不可直接访问，只能通过基类的方法进行访问，或通过友元函数进行访问
  - 枚举类型中每个枚举常量的值都是一个整数
  - 只能使用成员函数重载的运算符有：=, (), [], ->, new ,delete
  - 数组名为一级指针
  - 通常情况下，变量的值是存于内存中，若使用CPU寄存器，将局部变量值直接放于寄存器中，其存取速度远远高于对内存的存取速度，因此使用寄存器可以提高执行效率  
  ```
  register int a[1000] 执行效率远大于 int a[1000]
  ```
  - 类中，变量的初始化顺序使其声明的顺序，跟初始化列表中的顺序无关
  - STL迭代器方法：
  ```
  advance(it,5); //将迭代器it移动次
  prev(it);      //将迭代器it递减一个单位长度
  ```
  
  ## 8/21 知识点整理
  - 内部类是定义在其他类内部的类。内部类作为其外部类的一个成员，与其他成员一样，可以直接访问其外部类的数据和方法。
  - double在内存中占8个字节，float占4字节，int占2字节，char占1字节
  - <<，左移运算，相当于乘2，>>，右移运算，相当于除以2
  - 字符串可以存放在字符数组中，文字常量区
  - C程序在编译前由预处理器对预处理命令进行操作
  - 静态绑定：静态绑定是指指针指向声明时的对象，指针声明为Base类，因此调用Base类的函数；动态绑定：动态绑定是指指针指向引用的对象，指针引用Derived对象，因此调用Derive的类的函数。非虚函数是静态绑定，虚函数是动态绑定。
  - 指针是基类，但指向的对象是子类，当方法前有关键字VIRTUAL时，根据指针指向的对象的类型选择方法，当没有关键字VIRTUAL时，根据指针的类型选择方法。
  - 在16位C语言编译系统上，C语言中结构体变量所占内存的大小是其所包含的各个成员所需内存大小之和。
  - 构造一个对象的时候，必须知道对象的实际类型，而虚函数行为是在运行期间确定实际类型的。而在构造一个对象时，由于对象还未构造成功，编译器无法知道对象的实际类型是该类本身，还是该类的一个派生类，或是更深层次的派生类，无法确定。
  - 虚函数的执行依赖于虚函数表，而虚函数表在构造三叔中进行初始化工作，即初始化vptr，让他指向正确的虚函数表，而在构造对象期间，虚函数表还没有被初始化，将无法进行，因此构造函数不能是虚函数。
  - 二维数组必须指定列的数量，行的数量可以不指定。数组初始化时可以省略一维的定义，但不能省略第二维的定义，即可以使用 int a[][3]
  - #pragma预处理命令
  ```
  #pragma comment // 将一个注释记录放置到对象文件或可执行文件中
  #pragma pack    // 用来改变编译器的字节对齐方式
  #pragma code_seg// 它能够设置程序中的函数在obj文件中所在的代码段，如果未指定参数，函数将放置在默认代码段.text中
  #pragma once    // 保证所在文件只会被包含一次，它是基于磁盘文件的，而#ifndef则是基于宏的
  ```
  - 函数指针的声明格式为：函数返回类型（指针）（参数列表），例如 
  ```
  int (A::*j)()
  ```
  - 有些信息在储存时，并不需要占用一个完整的字节，而只需要占用几个或一个二进制位，例如在存放一个开关变量时，只有0和1两种状态，用一位二进制即可，为了节省空间，并使处理简单，C语言体用了一种数据结构，称为“位域”或“位段”。所谓“位域”是把一个直接中的二进制位划分为一个不同的区域，并说明每个区域的位数。每个域有一个域名，允许在程序中按域名进行操作。这样就可以把几个不同的对象用一个字节的二进制位域来表示。
  ```
  struct s
  {
    int x:3;
    int y:4;
    int z:5;
    double a;
  }
```
x，y，z分别占用3,4,5位，int4个字节32位，相当于xyz占用4个字节，double占用8个字节，按照对齐原则，前面补4位，4+4+8=16。有一个条件是默认8字节对齐，如果前面加上一句“# pragma pack(4)”，设定为4字节对齐，结果就是12
- 指针和引用：
```
相同点：
都是地址的概念。指针指向一块内存，它的内容是所值内存的地址；引用是某块内存的别名。
区别：
1.指针是一个实体，而引用仅是个别名
2.引用使用时无需解引用（*），指针需要解引用
3.引用只能在定义时被初始化一次，之后不可改变；指针可变
4.引用没有const；指针有const
5.引用不能为空；指针可以为空
6.“sizeof 引用”得到的是所指向的变量（对象）的大小；而“sizeof 指针”得到的是指针本身（所指向的变量或对象的地址）的大小
7.指针和引用的自增（++）运算意义不一样
8.从内存分配上看：程序为指针变量分配内存区域，而引用不需要分配内存区域
```
- 局部变量存在于栈区；new出的变量存在于堆区；static变量和全局变量由操作系统释放
- C++在编译前由预处理器对预处理命令进行处理，编译时进行语法分析
- 字符串输入：
```
getchar //输入单个字符
gets //输入字符串
scanf //格式化输入
```
- 继承可以继承父类的属性和行为。封装是只提供接口并隐藏内部过程的行为。多态是指因继承产生的相关不同类。抽象是一种简化复杂现实问题的途径。
- 执行fopen函数时，如果文件打开成功，则返回该文件结构体的指针，如果打开失败（例如，读打开时文件不存在，写打开时文件不能创建），则返回NULL（即0）
- **C语言**程序中，若对函数类型未加显式说明，则函数的隐含类型为int
- 两个地址相加无意义，也可能越界，所以规定不允许指针相加
- 
## 8/23知识点整理
- char<short<int<float<double,不同类型运算结果类型向右靠齐

## 8/26 知识点整理
- 关于const修饰指针的情况，一般分为如下4种情况：
```
int b = 500;
const int* a = &b;       // case 1
int const *a = &b;       // case 2
int* const a = &b;       // case 3
const int* const a = &b; // case 4
```
区别：
  1）先看情况1。如果const位于星号的左侧，则const就是用来修饰指针所指向的变量，即指针指向为常量；如果const位于星号的右侧，const就是修饰指针本身，即指针本身是常量。因此，1和2的情况相同，都是指针所指向的内容为常量（与const放在变量声明符中的位置无关），这种情况下不允许对内容进行更改操作。
  换句话说，如果a是一名仓库管理员的话，他所进入的仓库，里面的货物```(*a)```是他没有权限允许动的，仓库里面的东西原来是什么就是什么；所以
  ```
  int b = 500;
  const int* a = &b;
  *a = 600; // 错误
  ```
  但是也有别的办法去改变```*a```的值，一个是通过改变b的值：
  ```
  int b = 500;
  const int* a = &b;
  b = 600;
  cout<<*a<<endl; // 得到600
  ```
  还有一种办法就是a指向别处（管理员换个仓库）：
  ```
  int b = 500, c = 600;
  const int* a = &b;
  a = &c;
  cout<<*a<<endl; // 得到600
  ```
  对于情况1，可以先不进行初始化，因为虽然指针内容是常量，但指针本身不是常量。
  ```
  const int* a; // 正确
  ```
  2)情况2与情况1相同。
  3)情况3位指针本身是常量，这种情况下不能对指针本身进行更改操作，而指针所指向的内容不是常量。
  举例来说：如果a是一名仓库管理员的话，他只能进入指定的某仓库，而不能去别的仓库（所以a++是错误的）；但这个仓库里面的货物```(*a)```是可以随便动的；
  此外，对于情况3：定义时必须同时初始化。
  ```
  int b = 500, c = 600;
  int* const a; // 错误，没有初始化
  int* const a = &b; // 正确，必须初始化
  *a = 600; // 正确，允许改值
  cout << a++ << endl; // 错误
  ```
  4)对于情况4为指针本身和指向的内容均为常量。那么这个仓库管理员只能去特定的仓库，并且仓库里面所有的货物他都没有权限去改变。
- cosnt成员函数：
我们定义的类的成员函数中，常常有一些成员函数不改变类的数据成员，也就是说，这些函数是“只读”函数，而有一些函数要修改类数据成员的值。如果把不改变数据成员的函数都加上const关键字进行标识，显然，可以提高程序的可读性。其实，它还能提高程序的可靠性，已定义成const的成员函数，一旦企图修改数据成员的值，则编译器按错误处理。
下面是定义const成员函数的一个实例：
```
class Point
{
  int xVal,yVal;
  public:
  int GetY() const;
 };
 // 关键字const必须用同样的方式重复出现在函数实现里，否则编译器会把它看成一个不同的函数；
 int Point::GetY() const
 {
    return yVal;
 }
 ```
 - const与#define相比有什么不同：
 C++语言可以用const定义常量，也可以用#define定义常量，但是前者比后者有更多的优点：
    - cosnt常量有数据类型，而宏常量没有数据类型。编译器可以对前者进行类型安全检查，而对后者只进行字符替换，没有类型安全检查，并且在字符替换中可能会       产生意料不到的错误（边际效应）。
    - 有些集成化的调试工具可以对const常量进行调试，但是不能对宏常量进行调试。在C++程序中只使用const常量而不使用宏常量，即宠上天常量完全取代宏常量。
- 
