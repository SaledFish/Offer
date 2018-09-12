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
      *return a>b;
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
    - 有些集成化的调试工具可以对const常量进行调试，但是不能对宏常量进行调试。在C++程序中只使用const常量而不使用宏常量，即const常量完全取代宏常量。
- 常量的引进实在早期的C++版本中，当时标准C规范正在制订。那时，常量被看作一个好的思想而被包含在C中。但是，C中的const的意思是“一个不能被改变的普通常量”。在C中，它总是占用内存，而且它的名字是全局符。C编译器不能把const看成一个编译期间的常量。在C中，如果写：
```
const bufsize = 100;
char buf[bufsize];
```
尽管看起老好像做了一件合理的事情，但是这将得到一个错误的结果。因为bufsize占用内存的某个地方，所以C编译器不知道它在编译时的值。在C语言中可以选择这样书写：
```
const bufsize;
```
这样写在C++中是不对的，而C编译器则把它作为一个声明，这个声明指明在别的地方有内存分配。因为C默认const是外部连接的，C++默认const是内部连接的，这样，如果在C++从想完成与C中同样的事情，必须用extern把内部连接改为外部连接：
```
extern const bufsize; // declaration only
```
这种方法也可用在C语言中。在C语言中使用限定符const不是很有用，即使是在常数表达式里（必须在编译期间被求出）想使用一个已命名的值，使用const也不是很有用。C迫使程序员在预处理器里使用#define
- 有类如下：
```
class A
{
    void f() const {};
}
```
在上面这种情况下，如果要修改类的成员变量，应该怎么办？
在C++程序中，类里面的数据成员加上mutable后，修饰为const的成员变量，就可以修改它了。
```
class A
{
    public:
    ...
    int incr() const  // 注意这里的const
    {
      return ++m_Count;
    }
    
    private:
    mutable int m_Count;
}
```
- ***sizeof***
```
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct{
	short a1;
	short a2;
	short a3;
}A;

struct{
	long a1;
	short a2;
}B;

int main()
{
	char *ss1 = "0123456789";
	char ss2[] = "0123456789";
	char ss3[100] = "0123456789";
	int ss4[100];

	char q1[] = "abc";
	char q2[] = "a\n";
	char *q3 = "a\n";
	char *str1 = (char*)malloc(100);
	void *str2 = (void*)malloc(100);

	//输出以上各个变量的sizeofa()

	return 0;
}
```
ss1是一个字符指针，指针的大小是一个定值，就是4字节，所以sizeof（ss1）是4字节。  
ss2是一个字符数组，这个数组最初未定大小，由具体填充值来定。填充值是“0123456789”。1个字符所占空间是1字节，10个就是10字节，再加上隐含的“\0”，所以一共是11字节。  
ss3也是一个字符数组，这个数组开始预分配100，所以它的大小一共是100字节。  
ss4是一个整形数组，这个数组开始预分配100，但每个整型变量所占空间是4，所以它的大小一共是400字节。  
q1与ss2类似，4字节。  
q2里面有一个“\n”,"\n"算作一位，所以它的空间大小是3字节。  
q3是一个字符指针，指针的大小是一个定值，就是4。  
A和B是两个结构体。在默认情况下，为了方便对结构体内元素的访问和管理，当结构体内的元素的长度都小于处理器的位数的时候，便以结构体里面最长的数据元素为对齐单位，也就是说，结构体的长度一定是最长的数据元素的整数倍。如果结构体内存在长度大于处理器位数的元素，那么就以处理器的位数为对齐单位。但是结构体内类型相同的连续元素和数组一样，将在连续的空间内。
结构体A中有3和short类型变量，各自以2字节对齐，结构体对齐参数按默认的8字节对齐，则a1，a2，a3都取2字节对齐，sizeof(A)为6，其也是2的整数倍。B中a1位4字节对齐，a2位2字节对齐，结构体默认对齐参数为8，则a1取4字节对齐，a2取2字节对齐，结构体大小为6字节，6不是4的整数倍，补空字节，增加到8时，符合所有条件，则sizeof(B)=8。  
CPU的优化规则大致原则是这样的：对于n字节元素（n=2,4,8，...）,它的首地址能被n整除，才能获得最好的性能。设计编译器的时候可以遵循这个原则：对于每一个变量，可以从当前位置先后找到第一个满足这个条件的地址作为首地址。  
- 数据对齐，是指数据所在的内存地址必须是该数据长度的整数倍。***DWORD***数据的内存起始地址能被4除尽，***WORD***数据的内存其实地址能被2除尽。  
- 字节对齐是编译时决定的，一旦决定则不会在改变，因此即使有对齐的因素在，也不会出现一个结构在运行时尺寸发生变化的情况。  
- 静态变量存放在全局数据区，而sizeof计算栈中分配的大小，因此计算类的sizeof时，不计算其中的static成员变量。  
- **sizeof**和**strlen**之间的区别，由以下几个例子说明：
例子1：
```char *ss = "0123456789```
```sizeof(ss)```结果为4，ss是指向字符串常量的字符指针。
```sizeof(*ss)```结果为1，```*ss```是第一个字符。
例子2：
```char ss[] = "0123456789"```
```sizeof(ss)```结果为11，ss是数组，计算到"\0"位置，因此是（10+1）。
```sizeof(*ss)```结果为1，```*ss```是第一个字符。
例子3：
```char ss[100] = "0123456789"```
```sizeof(ss)```结果为100，ss表示在内存中预分配的大小，```100*1```
```strlen(ss)```结果为10，它的内部实现是用一个循环计算字符串的长度，直到"\0"为止。
例子4：
```int ss[100] = "0123456789"```
```sizeof(ss)```结果为400，ss表示在内存中的大小，```100*4```
```strlen(ss)```错误，strlen的参数只能是```char*```，且必须是以"\0"结尾的。
例子5：
```
class X{
int i;
int j;
char k;
};
X x;
```
```
cout<<sizeof(X)<<endl; // 结果为12，内存补齐
cout<<sizeof(x)<<endl; // 结果为12，理由同上
```
- 通过对sizeof与strlen的深入理解，得出两者区别如下：
  （1）sizeof操作符的结果类型是size_t，它在头文件中的typedef为unsigned int类型。该类型保证能容纳实现所建立的最大对象的字节大小。
  （2）sizeof是运算符，strlen是函数。
  （3）sizeof可以用类型做参数，strlen只能用```char*```做参数，且必须是以"\0"结尾的，。sizeof还可以用函数做参数，比如：
  ```short f();
     printf("%d\n",sizeof(f));
  ```
     输出的结果是sizeof（short），即2。
   （4）数组做sizeof的参数不退化，传递给strlen就退化为指针。
   （5）大部分编译程序在编译的时候就把sizeof计算过了，是类型或是变量的长度。这就是sizeof（x）可以用来定义数组维数的原因。
   （6）strlen的结果要在运行的时候才能计算出来，用来计算字符串的长度，而不是类型占用内存的大小。
   （7）sizeof后如果是类型必须加括号，如果是变量名可以不加括号，因为sizeof是个操作符而不是个函数。
   （8）当使用了一个结构类型或变量时，sizeof返回实际的大小。当使用一静态的空间数组时，sizeof返回全部数组的尺寸。sizeof操作符不能返回被动态分配的数组或外部的数组的尺寸。
   （9）数组作为参数传递给函数时传递的是指针而不是数组，传递的是数组的首地址，如```fun(char[8])```,```fun(char[])```,都等价于```fun(char*)```。在C++里穿肚数组永远都是穿肚指向数组首元素的指针，编译器不知道数组的大小。如果想在函数内知道数组的大小，需要这样做：进入函数后用memcpy将数组复制出来，长度由另一个形参传进去：
   ```
   fun(unsigned char *p1, int len)
   {
      unsigned char *buf = new unsigned char [len + 1];
      memcpy(buf, p1, len);
   }
   ```
   (10)使用sizeof时要考虑内存对齐的因素。
  （11）sizeof操作符不能用于函数类型、不完全类型或位字段。不完全类型指具有未知存储大小数据的数据类型，如未知储存大小的数组类型，未知内容的结构或联合类型，void类型等。
- sizeof操作符的使用场合：
  （1）sizeof操作符的一个主要用途是与储存分配和I/O系统那样的例程进行通信：例如
  ```
  void *malloc(size_t size);
  size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
  ```
  （2）用它可以看看某种类型的对象在内存中所占的单元字节
  ```
  void *memset(void *s, int c, sizeof(s));
  ```
  （3）在动态分配一对象时，可以让系统知道要分配多少内存。
  （4）便于一些类型的扩充。在Windows中有很多结构类型就有一个专用的字节段用来存放该类型的字节大小。
  （5）由于操作数的字节数在实现时可能出现变化，建议在设计操作数字节大小时用sizeof代替常量计算。
  （6）如果操作数是函数中的猪猪形参或函数类型的形参，sizeof给出其指针的大小。
- 
- sizeof不是函数，也不是一元运算符，它是个类似宏定义的特殊关键字，sizeof（）。括号内的内容在编译过程中是不被编译的，而是被类型替代。
- unsigned影响的只是最高位bit的意义（正、负），数据长度是不会被改变的，所以
```
sizeof(unsigned int) == sizoef(int);
```
- 自定义类型的sizeof取值等同于它的类型原型
```
typedef short WORD;
sizeof(short) == sizeof(WORD);
```
- 对函数使用sizeof，在编译阶段会被函数返回值的类型取代
- 只要是指针，大小就是4
- 数组的大小是各维数的乘积，再乘上数组元素的大小
- 字符串常量保存在只读的数据段，而不是像全局变量那样保存在普通数据段（静态储存区）。
```
char *c = "hello world";
*c = 't'; //false,因为*c指向的是只读数据段

char c[] = "hello world";
c[0] = 't'; // ok
```
- 请问下面代码的输出结果是多少？
```
#include <cstdio>
class A
{
public:
	A(){ m_a = 1; m_b = 2;}
	~A() {};
	void fun() { printf("%d%d", m_a, m_b); }
private:
	int m_a;
	int m_b;
};

class B
{
public:
	B() { m_c = 3; }
	~B();
	void fun() { printf("%d", m_c); }
private:
	int m_c;
};

void main()
{
	A a;
	B *pb = (B*)(&a);
	pb->fun();
}
```
首先可以肯定的是上面这段代码是非常糟糕的，无论是可读性还是安全性都很差。这道题考察队内存偏移的理解：
```B* pb = (B*)(&a);```
这是一个野蛮的转化，强制把a地址内容看成是一个B类对象，pb指向的是a类的内存空间：
```pb->fun();```
正常情况下，B类自由一个元素是int m_c，但是A类的内存空间中存放第一个元素的位置是m_a，pb指向的是对象的内存首地址，比如0x22ff58，当pb->fun()调用B::fun()来打印m_c时，编译器对m_c的认识就是m_c距离对象的偏移量为0，于是打印了对象a首地址的编译量0x22ff58+0变量值。所以打印的是m_a的值1。
- 函数指针和二级指针
 ```
 float(**def)[10]; // deff是一个二级指针，它指向的是一个一维数组的指针，数组的元素都是float
 double*(*gh)[10]; // gh是一个指针，它指向一个一维数组，数组元素都是double*
 double(*f[10])(); // f是一个数组，f有10个元素，元素都是函数的指针，指向的函数类型是没有参数且返回double的函数
 int*((*b)[10]); // 就跟"int*(*b)[10]"一样，是一维数组的指针
 long(*fun)(int); // 函数指针
 int(*(*f)(int,int))(int); // f是一个函数的指针，指向的函数的类型是有两个int参数并且返回一个函数指针的函数，返回的函数指针指向有一个int参数且返回int的函数
 ```
 - 写出如下程序片段的输出：
 ```
 int a[] = {1, 2, 3, 4 ,5};
 int *ptr = (int*)(&a + 1);
 printf("%d, %d",*(a + 1), *(ptr - 1));
 //结果为2， 5
 ```
 第一个好理解，是正常的指针运算。但是第二个却有点难以理解。第二个的确是5.首先a表示一个1行5列数组，在内存中表示为一个5个元素的序列。```int *ptr = (int*)(&a + 1);```的意思是，指向a数组的第6个元素（尽管这个元素不存在）。那么显然（ptr-1）所指向的数据就是a数组的第5个元素5。
 如果存在这样的数组：
 ```int b[2][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};```
 那么显然：
 ```int *p = (int*)(&a + 1) = b[1];```
 实际上，b的数据分布还是按照1,2,3,4,5,6,7,8,9,10分布的，所谓b[0]和b[1]实际上只是指向其中一个元素的指针。
 时刻牢记这样的观点：数组名本身就是指针，再加个&，就变成了双指针，这里的双指针就是指二维数组，加1，就是数组整体加一行，ptr指向a的第6个元素。
 - C++中有了malloc/free，为什么还需要new/delete：
 malloc与free是C++/C语言的标准库函数，new/delete是C++的运算符。它们都可英语申请动态内存和释放内存。
 对于非内部数据类型的对象而言，只用malloc/free无法满足动态对象的要求。对象在创建的同时要自动执行构造函数，对象在消亡之前要自动执行析构函数。由于malloc/free是库函数而不是运算符，不在编译器控制权限之内，不能够吧执行构造函数和析构函数的任务强加于malloc/free。
 因此C++语言需要一个能完成动态内存分配和初始化工作的运算符new，以及一个能完成清理与释放内存工作的运算符delete。new/delete不是库函数，而是运算符。
 - 指针和句柄：句柄和指针是两个截然不同的概念。Windows系统用句柄标记系统资源，隐藏系统的信息，你只要知道有这个东西，然后去调用就行了。它是个32bit的uint。自身则标记某个物理内存地址，两者是不同的概念。
 - this指针易混的几个问题如下：
 （1）this指针本质是一个函数参数，只是编译器隐藏起形式的，语法层面上的参数。this只能在成员函数中使用，全局函数，静态函数都不能使用this，实际上，成员函数默认第一个参数为```T* const this```。
 ```
 如：
 class A{
 public:
 int func(int p){};
 };
 其中，func的原型在编译器看来应该是：
 int func(A* const this, int p);
 ```
 (2)this在成员函数的开始前构造，在成员的结束后清除。这个生命周期同任何一个函数的参数是一样的，没有任何区别，当调用一个类的成员函数时，编译器将类的指针作为函数的this参数传递进去。

## 8/27知识点整理
- 递归：递归是程序设计中的一种算法。一个过程或函数直接调用自己本身或通过其他的过程或函数调用语句间接地调用自己的过程或函数，称为递归过程或函数。
- 解释一下什么是泛型编程，泛型编程和C++以及STL的关系是什么？并且，你是怎么在C++环境里进行泛型编程的？
泛型编程是一种基于发现高效算法的最抽象表示的编程方法。也就是说，以算法为起点并寻找能使其工作且有效率工作的最一般的必要条件集。令人惊讶的是，很多不同的算法都需要相同的必要条件集，并且这些必要条件有多重不同的实现方式。类似的事实在数学里也可以看到。大多数不同的定力都依赖于同一套公理，并且对于同样的公理存在多重不同的模型。泛型编程假定有某些基本的法则在支配软件组件的行为，并且基于这些法则有可能涉及可互操作的模块，甚至有可以使用此法则去知道我们的软件设计。STL就是一个泛型编程的例子。C++是我可以实现令人信服的例子的语言。
- 
## 8/28知识点整理
- 面向对象设计的三原则：封装，继承，多态。里氏代换原则是继承复用的基石：子类型必须能够替换它们的基类型。开闭原则是面向对象设计的重要特征之一：软件 对扩展应该是开放的，对修改应该是关闭的。通俗点说，已经设计好的代码应该是不做修改的（闭），如果需求改变，就另外自己扩展一块去（开），别破坏原来的代码。
- C++中对于一个空类，编译器默认产生4个成员函数：默认构造函数、析构函数、复制构造函数和赋值函数。
- class中**变量默认是private**，struct中**变量默认是public**。struct可以有构造函数、析构函数，之间也可以继承，等等。C++中strcut其实和class意义一样，唯一不同的就是struct里面默认的访问控制是public，class中默认的访问控制是private。C++中存在struct关键字的唯一意义就是为了让C程序员有个归属感，是为了让C++编译器兼容以前用C开发的项目。
- 哪一种成员变量可以在一个类的实例之间共享？
必须使用静态成员变量在一个类的所有实例间共享数据。如果想限制对静态成员变量的访问，则必须把它们声明为保护型或私有型。不允许静态成员变量去存放某一个对象的数据。静态成员数据是在这个类的所有对象间共享的。
- 如果把静态成员数据设为私有，可以通过公有静态成员函数访问。
- 类中，常量必须在构造函数的初始化列表里面初始化或者将其设置成static
```
class A
{
  const int size = 0;
}; // 错误

class A
{
  A()
  {const int size = 0;}
}; //正确

class A
{
  static const int size = 0;
}; // 正确
```
- 构造函数：先调用基类的构造函数，再调用派生类的构造函数；
- 析构函数：先调用派生类的析构函数，再调用基类的析构函数；
- 无论析构函数是不是虚函数，派生类对象被撤销时，肯定会依次上调其基类的析构函数。
- 析构函数可以为virtual型，构造函数则不能。虚函数采用一种虚调用的办法。虚调用是一种可以在只有部分信息的情况下工作的机制，特别允许我们调用一个只知道接口而不知道其准确对象类型的函数。但是如果要创建一个对象，你势必要知道对象的准确类型，因此构造函数不能为虚。
- 如果虚函数是非常有效的，是否可以把每个函数都声明为虚函数？不可以，这是因为虚函数是有代价的：由于每个虚函数的对象都必须维护一个虚函数表，因此在使用虚函数的时候都会产生一个系统开销。如果仅是一个很小的类，且不想派生其他类，那么根本没必要使用虚函数。
- ***析构函数可以是内联函数***
- 
```
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class B
{
private:
	int data;
public:
	B()
	{
		cout << "default constructor" << endl;
	}

	~B()
	{
		cout << "destrcuted" << endl;
	}

	B(int i) :data(i)
	{
		cout << "constrcuted by parameter" << data << endl;
	}
};

B Play(B b)
{
	return b;
}

int main(int argc, char argv[])
{
	B temp = Play(5);
	return 0;
}
```
1.程序的输出结果是什么：
B temp=Play（5），理论上该有两次复制构造函数，编译器把这两次合为一次，提高效率。所以把此句改为Paly（5），会发现结果一样。都是两次析构，区别在于：Paly（5）的第一次析构是在函数退出时，对形参的副本进行析构。第二次析构是在函数返回类对象时，再次调用复制构造函数来创建返回类对象的副本。所以还需要一次析构函数来析构这个副本。而B temp=Play（5）中的第二次析构是析构B temp。
所以输出结果应该有两个“destructed”输出。
2.Play（5），形参类型是类，而5是个常量，这样写合法吗？为什么？
合法。**单个参数的构造函数**如果不添加***explicit***关键字，会定义一个隐含的类型转换（从参数的类型转换到自己）；添加***explicit***关键字会消除这种隐含转换。
- 虚函数：派生类中虚函数的声明必须与基类中定义方式完全匹配，但是有一个例外，返回对基类型的引用或指针的虚函数，派生类中的虚函数可以返回基类函数所返回类型的派生类的引用或指针。
- 多态：按字面的意思就是“多种形态”。多态性是允许你将父对象设置成为和它的一个或更多的子对象相等的技术，赋值之后，父对象就可以根据当前赋值给它的子对象的特性以不同的方式运作。简单地说就是一句话，***允许将子类类型的指针赋值给父类类型的指针***，多态性在C++中都是通过虚函数实现的。
- 重载和覆盖有什么不同？虚函数总是在派生类中被改写，这种改写被称为“override”(覆盖)。override是指派生类重写基类的虚函数。重写的函数必须有一致的参数表和返回值（C++标准允许返回值不同的情况，但是很少有编译器支持这个特性）。
overload约定成俗的被翻译为“重载”，是指编写一个与已有函数同名但是参数表不同的函数。例如一个函数既可以接受整型数作为参数，也可以接受浮点数作为参数。重载不是一种面向对象的编程，而只是一种语法规则，重载与多态没有什么直接关系。
- 宏，内联函数，模板都可以在编译的时候解析，唯独虚函数不行，它必须在运行时才能确定。
- 友元是一种定义在类外部的普通函数，但它需要在类体内进行说明，为了与该类的成员函数加以区别，在说明时前面加以关键字friend。友元不是成员函数，但是它可以访问类中的私有成员。友元的作用至于提高程序的运行效率，但是，它破坏了类的封装性和隐藏性，使得非成员函数可以访问类的私有成员。
- 友元可以是一个函数，该函数被称为友元函数；友元也可以是一个类，该类被称为友元类。
- 构造函数中遇到异常是不会调用析构函数的，一个对象的父对象的沟槽函数执行完毕，不能称之为构造完成，对象构造是不可分割的，要么完全成功，要么完全失败，C++保证这一点。
- C++中通知对象构造失败的唯一方法，就是在构造函数中抛出异常；对象的部分构造是很常见的，异常的发生点也完全是随机的，程序员要谨慎处理这种情况；当对象发生部分构造时，已经构造完毕的子对象将不会被构造了（即异常发生点后面的对象），当然它也就没有析构过程了；还有正在构建的子对象和对象自己本身将停止继续构建（即出现异常的对象），并且它的析构是不会被执行的。
- EffectiveC++建议，析构函数尽可能的不要抛出异常。设想如果对象出了异常，现在异常处理模块为了维护系统对象数据的一致性，避免资源泄露，有责任释放这个对象的资源，调用对象的析构函数，可现在假如析构过程又在出现异常，那么请问由谁来保证这个对象的资源释放呢？
- 派生类可以操作基类的所有数据成员，包括受保护型的
- 构造函数从最开始的基类开始构造，个各类的同名变量没有形成覆盖，都是单独的变量。

-
```
#include <iostream>
using namespace std;

class A
{
public:
	void virtual f(){
		cout << "A" << endl;
	}
};

class B :public A
{
public:
	void virtual f(){
		cout << "B" << endl;
	}
};

int main()
{
	A *pa = new A();
	pa->f();
	B *pb = (B*)pa;
	pb->f();

	delete pa, pb;
	pa = new B();
	pa->f();
	pb = (B*)pa;
	pb->f();
}
```
这是一个虚函数覆盖虚函数的问题。A类里的f函数是一个虚函数，***虚函数是被子类同名函数覆盖的***。而B类里的f函数也是一个虚函数，它覆盖A类f函数的同时，也会被它的子类覆盖。但是在```B *pb=(B*)pa;```里面，该语句的意思是*转化pa为B类型并新建一个指针pb，将pa复制到pb*。但这里有一点请注意，就是pa的指针始终没有发生变化，所以pb也指向pa的f函数，这里并不存在覆盖的问题。
```delete pa,pb;```删除了pa和pb所指向的地址，但pa，pb指针并没有删除，也就是我们通常所说的悬浮指针。现在重新给pa指向新地址，所指向的位置是B类的，而pa指针类型是A类的，所以就产生了一个覆盖。```pa-f();```的值是B。
```pb=(B*)pa;```转化pa为B类指针给pb赋值，但pa所指向的f函数是B类的f函数，所以pb所指向的f函数是B类的f函数，```pb->f();```的值是B。
- 公有继承和私有继承的区别：*私有继承使对象不能被派生类的子类访问。*
- *一个私有的或保护的派生类不是子类，因为非公有的派生类不蹦做基类能做的所有的事*
- 派生类的3种继承方式如下：
公有继承（public）、私有继承（private）和保护继承（protacted）是常用的3种继承方式。
1、*公有继承方式*
基类成员对其对象的可见性与一般类及其对象的可见性相同，公有成员可见，其他成员不可见。这里***保护成员与私有成员相同***。
基类成员对派生类的可见性对派生类来说，基类的公有成员和保护成员可见，基类的公有成员和保护成员作为派生类的成员时，它们都保持原有的状态；基类的私有成员不可见，基类的私有成员仍然是私有的，派生类不可访问基类中的私有成员。
基类成员对派生类对象的可见性对派生类对象来说，基类的公有成员是可见的，其他成员是不可见的。
所以，在公有继承时，派生类的***对象***可以访问基类中的***公有成员***，派生类的***成员函数***可以访问基类中的***公有成员和保护成员***。
2.私有继承方式
基类成员对其对象的可见性与一般类及其对象的可见性相同，公有成员可见，其他成员不可见。
接力成员对派生类的可见性对派生类来说，基类的公有成员和保护成员是可见的，接力的公有成员和保护成员都作为派生类的***私有成员***，并且不能被这个派生类的子类所访问；基类的私有成员是不可见的，派生类不可访问基类中的私有成员。
基类成员对派生类对象的可见性对派生类***对象***来说，基类的***所有成员都是不可见的***。所有，在私有继承时，基类的成员只能由直接派生类访问，而无法再往下继承。
3.保护继承方式
这种继承方式与私有继承方式的情况相同。二者的区别仅在于对派生类的***成员***而言，基类成员对其对象的可见性与一般类及其对象的可见性相同，公有成员可见，其他成员不可见。
基类成员对派生类的可见性对派生类来说，基类的公有成员和保护成员是可见的，基类的公有成员和保护成员都作为派生类的保护成员，并且不能被这个派生类的子类的***对象***访问，但是可以被派生类的***子类***所访问；基类的私有成员是不可见的，派生类不可访问基类中的私有成员。
基类成员对派生类对象的可见性对派生类对象来说，基类的所有成员都是不可见的。
C++支持多重击沉个，从而大大增强了面向对象程序设计的能力。多重继承是一个类从多个基类派生而来的能力。派生类实际上获取了所有基类的特性。当一个类是两个或多个基类的派生类时，必须在在派生类名和冒号之后，列出所有基类的类名，基类间用逗号隔开。派生类的构造函数必须激活所有基类的构造函数，并把响应的参数传递给它们。派生类可以死另一个类的基类，这样，相当于形成了一个继承链。当排上类的构造函数被激活时，它的所有基类的构造函数也都会被激活。在面向对象的程序设计中，继承和多重继承一般指共有继承。在无继承的类中，protected和private控制符是没有差别的。在继承中，基类的private对所有的外界都屏蔽（包括自己的派生类），基类的protected控制符对应用程序是屏蔽的，但对其派生类时可访问的。
保护继承和私有继承只是在技术上讨论时有其一席之地。
- 每个对象里有虚表指针，指向虚表，虚表里存放了虚函数的地址。虚函数表是顺序存放虚函数地址的，不需要用到链表。
- 
## 9/4 知识点整理
- 虚函数与纯虚函数：在它们的子类中都可以被重写，它们的区别是：纯虚函数只有定义，没有实现；而虚函数既有定义，也有实现的代码，纯虚函数一般没有代码实现部分。虚函数之所以“虚”是因为调用的虚函数不是在静态编译（静态编联）时确定的，而是在运行时通过动态编联确定的。多态核心理念即是通过基类访问派生的子类，通常情况是借助基类的指针来访问派生类的对象。
纯虚函数是一种特殊的函数，通常定义在基类中，纯虚函数在基类中定义方法是在函数声明末尾加“=0”，如```virtual func(int ,int) = 0```,纯虚函数的“纯”体现为基类不需要实现它，其主要作用是为派生类定义函数接口框架，由派生类完成纯虚函数的实现。
***虚函数最主要的缺点是执行效率低***
- 虚函数引入的原因：
1.为了方便使用多态性，我们常常需要在基类中定义虚函数。
2.在很多情况下，基类本身生成对象是不合情理的，例如，动物作为一个基类可以派生出老虎、孔雀等子类，但动物本身生成对象明显不合常理。
- 多态性：指相同对象收到不同消息或不同对象收到相同消息时产生不同的实现动作。（由虚函数实现的动态多态性就是：同一类族中不同的派生类对象，对同一函数调用做出不同的响应）
- 多态分为两种：
一种是静态多态，是指编译时候的多态，通过函数重载或者运算符重载实现。
一种是动态多态，是指运行时候的多态，通过虚函数与基类指针共同作用实现。
- 多态的作用：
1.可以将基类指针指向派生类对象，通过基类指针调用派生类的成员函数来执行不同的操作。
2.多态是为了接口重用，也就是说，不论传递过来的酒精是哪个类的对象，函数都能通过一个接口调用到适应各自对象的实现方法。
- 虚函数的工作原理：
每一个含有虚函数的对象都有一个虚表指针，虚表指针指向对应的虚表，当一个对象调用了虚函数，实际的被调用函数通过下面的步骤确定：找到对象的vptr指向的vtbl，然后在vtbl中寻找合适的函数指针。
- 为什么基类的析构函数是虚函数，而构造函数不能为虚：
在实现多态时，当基类操作派生类时，在析构时为防止只析构基类而不析构派生类的情况发生，所以基类析构函数是虚函数。构造函数的构造过程是两步：首先，分配一块内存；其次调用构造函数。虚函数需要通过vtable来调用，而vtable是在构造函数中初始化的，所以构造函数不能为虚函数。
- TCP如何保证传输可靠：
TCP协议传输的特点主要就是面向字节流、传输可靠、面向连接。
1.确认和重传：接受方收到报文就会确认，发送方发送一段时间后没有收到确认就会重传。
2.数据校验。
3.数据合理分片和排序：
  UDP：IP数据报大于1500字节，大于MTU，这个时候发送方IP层就需要分片，把数据报分成若干片，使每一片都小于MTU。而接受方IP层则需要进行数据报的重组，这样就会多做许多事情，而更严重的是，由于UDP的特性，当某一片数据传送中丢失时，接受方便无法重组数据报，导致丢弃整个UDP数据报。
  TCP：TCP会按MTU合理分片，接受方会缓存未按序到达的数据，重新排序后再交给应用层。
4.流量控制：当接收方来不及处理发送方的数据，能提示发送方降低发送的速率，方式包丢失。
5.拥塞控制：当网络拥塞时，减少数据的发送。
- HTTP和TCP：http是要基于TCP连接基础上的，简单的说，TCP就是单纯的建立连接，不涉及任何我们需要请求的实际数据，简单的传输。http是用来收发数据的，即实际应用上来的。
TCP是底层通讯协议，定义的是数据传输和连接方式的规范。
HTTP是应用层协议，定义的是传输数据的内容的规范。
HTTP协议中的数据利用TCP协议传输，所以支持HTTP也一定支持TCP。
- STL容器
C++标准模板库主要是定义了标准模板的定义与声明，我们使用了STL就不用自己来创建模板了，只需要学会怎么使用这些类模板来定义一个具体的类，然后能够使用类提供的各种方法来处理数据。
STL容器分为三类：
1.顺序容器类：vector（向量容器），deque（双向队列），list（链表，插入块，查询慢）
2.关联容器类：与顺序容器最大的区别是：容器里的东西与加入顺序无关，在插入时就会排序。set（集合，元素不重复），multiset（多重集合，元素可重复），map（映射，元素不可重复），multimap（多重映射，元素可重复）
3.容器适配器：stack（栈），queue（队列）

stack，deque和queue这三个C++的STL数据结构很相似但又各有不同。
stack是堆栈，没有迭代器，特点是先进后出，用push（）将元素压入栈，top（）返回栈顶元素，pop（）移除栈顶元素
deque是双向队列，支持迭代器，使用push_back（）在队尾添加元素，pop_back()移除队尾元素，这些跟vector差不多，不同的地方在于deque还可以在队首添加和移除元素，使用push_front()和pop_front()
queue是队列，不支持迭代器，特点是先进先出，使用push（）将添加元素，front（）返回队首元素，pop（）移除队首元素

- vector：
底层数据结构为数组，支持快速随机访问，***拥有一段连续的储存空间***，并且起始地址不变，因此能够非常好的支持随机存取，即 [] 操作符，但是由于它的内存空间是连续的，所以在头部和中间进行插入和删除操作会造成内存块的拷贝，另外，当该数组的内存空间不够时，需要重新申请一块足够大的内存并且进行内存拷贝，这些都大大影响了vector的效率，***对任何元素的访问时间都是O(1)，所以常用来保存需要经常进行随机访问的内容，并且不需要经常对中间元素进行添加和删除造作***，对最后的元素操作最快（在后面添加删除元素最快），此时一般不需要移动内存，只有保留内存不够时才需要

- stack：
底层一般用list或dqueue实现，封闭头部即可，不用vector的原因应该是容量大小限制，扩容耗时，stack是堆栈，没有迭代器，不允许遍历行为，特点是先进后出，用push（）将元素压入栈中，top（）返回栈顶元素，pop（）移除栈顶元素。

- 重载与重写与隐藏
重载 overload：是函数名相同，参数列表不同，重载只是在类的内部存在，但是不能靠返回类型来判断
重写 override：也叫作覆盖，子类重新定义父类中有相同名称和参数的虚函数，函数返回类型也要相同（C++标准允许返回值不同的情况，但是很少编译器支持这个feature），但是具体实现不同，主要是在继承关系中出现
隐藏：是指派生类的函数屏蔽了与其同名的基类函数，注意只要是同名函数，不管参数列表是否相同，基类函数都会被隐藏

- 静态编译与动态编译的区别
动态编译的可执行文件需要附带一个动态链接库，在执行时，需要调用对应动态链接库中的命令，所以其优点：一方面缩小了执行文件本身的体积，另一方面是加快了编译速度，节省了系统资源。缺点：一是哪怕是很简单的程序，只要用到了链接库中的一两条命令，也需要附带一个相对庞大的链接库，二是如果其他计算机上没有安装对应的运行库，则用动态编译的可执行文件就不能运行。
静态编译就是编译器在编译可执行文件的时候，将可执行文件需要调用的对应动态链接库中的部分提取出来，连接到可执行文件中去，使可执行文件在运行的时候不依赖与动态链接库，所以其优缺点与动态编译的可执行文件正好互补

-联编：联编是指一个程序自身彼此关联的过程，按照联编所进行的阶段不同，可分为静态联编和动态联编
静态联编：又称为静态绑定，指在调用同名函数（即重载函数）

## 9/5知识点整理
- 类与类之间的关系
在设计模式中类与类之间的关系主要有6种：**依赖、关联、聚合、组合、继承、实现**，它们之间的耦合度依次增加。  
1.**依赖**  
依赖关系定义为：对于两个相对独立的对象，当一个对象依赖另一个对象的服务时，这两个对象之间主要体现为依赖关系，一般是A中某个方法把B的对象作为参数使用或者在A中的某个方法作为局部变量使用  
2.**关联**  
对于两个相对独立的对象，当一个对象与另一个对象有某种对应关系，这连个对象之间为关联关系，关联分为单向关联，双向关联和自身关联，实现方法一般是A中包含B的某个指针或者引用  
3.**聚合**  
聚合是关联关系的一种，耦合度比关联关系强，它们的代码表现是相同的，仅仅是在语义上有所区别：关联关系的对象间是平等关系，而聚合关系的对象之间存在着包容关系，它们之间是“整体-个体”的相互关系，比如：张三和李四是关联，张三和张三的被子是聚合  
4.**组合**  
组合是耦合度比聚合还强的一种关系，类和类之间的关系是“整体-部分”的关系，整体和部分具有相同的生命周期，部分不能脱离整体而独立存在，代码实现为A中包含B的成员变量  
5.**继承**  
类和类之间存在父子关系，子类继承父类的属性和方法  
6.**实现**  
表示一个类实现一个或多个接口的方法，接口定义好操作的集合，由实现类去完成接口的具体操作  

- **UML类间图**  
UML（Unified Modeling Language）是统一建模语言，是用来对软件密集系统进行可视化建模的一种语言。UML为面向对象开发系统的产品进行说明、可视化、和编制文档的一种标准语言。  
在UML中，依赖关系用带箭头的虚线表示，由依赖的一方指向被依赖的一方  
在UML类图中，用实线连接有关联的对象所对应的类  
在UML中，聚合关系用带空心菱形的直线表示  
在UML中，组合关系用带实心菱形的直线表示  
在UML中，类与接口之间的实现关系用带空心三角形的虚线来表示  

- **面向对象设计的原则**  
1.开-闭原则（OCP）：一个软件实体应当对扩展开放，对修改关闭  
2.单一职责原则（SRP）：一个类只负责一项职责，其逻辑肯定要比负责多项职责简单的多；提高类的可读性，提高系统的可维护性  
3.里氏替换原则（LSP）：子类可以替换父类并且出现在父类能够出现的任何地方，该原则主要应用在继承关系上，在实现继承时，子类必须能够替换掉他们的基类  
4.依赖倒置原则（DIP）：高层模板不应该依赖底层模板，两者应该依赖于抽象，而抽象不依赖与细节。在模块编程中要依赖抽象编程，不要依赖具体的细节编程，即针对接口的编程，不要针对具体的实现编程  
5.接口隔离原则（ISP）：不要强迫客户依赖于它们不需要的方法，应该使用接口将两者隔离。在具体的编程过程中，一个类对另一个类的依赖性应该是建立在最小的接口上，如果客户端只需要某一些方法的话，那么就应该向客户端提供这些需要的方法，而不是提供不需要的方法  

- **用过哪些设计模式，详细讲一下观察者模式**  
1.*单例模式*  
简单点说，就是一个应用程序中，某个类的实例对象只有一个，你没有办法去new，因为构造器是被private修饰的，一般通过getInstance（）的方法来获取它们的实例，getInstance（）的返回值是一个对象的引用，并不是一个新的实例，所以不要错误的理解成多个对象  
2.*观察者模式*  
对象间一对多的依赖关系，当一个对象的状态发生改变时，所有依赖于它的对象都得到通知并被自动更新  
3.*装饰者模式*  
对已有的业务逻辑进一步的封装，使其增加额外的功能  
4.*适配器模式*  
将两种完全不同的事物联系到一起，就像现实生活中的变压器  
5.*工厂模式*  
简单工厂模式：一个抽象的接口，多个抽象接口的实现类，一个工厂类，用来实例化抽象的接口  
6.*代理模式（proxy）*  

- **进程的状态**  
1.创建状态：进程在创建时需要申请一个空白PCB，向其中填写控制和管理进程的信息，完成资源分配。如果创建工作无法完成，比如资源无法满足，就无法被调度运行，把此时进程所处状态称为创建状态  
2.就绪状态：进程已经准备好，已分配到所需资源，只要分配到CPU就能够立即运行  
3.执行状态：进程处于就绪转态被调度后，进程进入执行状态  
4.阻塞状态：正在执行的进程由于某些事件（I/O请求，申请缓存区失败）而暂时无法运行，进程收到阻塞，在满足请求时进入就绪状态等待系统调用  
5.终止状态：进程结束，或出现错误，或被系统终止，进入终止状态，无法再执行  

- 死锁的四个必要条件  
1.互斥条件：一个资源每次只能被一个进程使用  
2.请求与保持条件：一个进程因请求资源而阻塞时，已获得资源保持不放  
3.不剥夺条件：进程已获得资源，在未使用完之前，不能强行剥夺  
4.循环等待条件：若干线程之间形成一种收尾相连接的循环等待资源关系  

- **智能指针**
C++程序设计中使用堆内存是非常频繁的操作，堆内存的申请和释放都有程序员自己管理，程序员自己管理堆内存可以**提高程序的效率**，但是整体来说堆内存的管理是麻烦的，C++11中引入了**智能指针**的概念，**方便管理内存**。**使用普通指针，容易造成内存泄露（忘记释放），二次释放，程序发生异常时内存泄露等问题**，使用智能指针能更好的**管理堆内存**。  
理解智能指针需要下面三个层次：  
1.从较浅的层面看，智能指针是利用了一种叫做RAII（资源获取即初始化）的技术对普通的指针进行封装，这使得智能指针**实质是一个对象**，行为表现的**却想一个指针**。  
2.智能指针的作用是**防止忘记调用delete释放内存和程序异常的进入catch块忘记释放内存。另外指针的释放时机也是非常有考究的，多次释放同一指针会造成程序崩溃，这些都可以通过智能指针来解决**。  
3.智能指针还有一个作用是把**值语义转换成引用语义**，C++和Java有一处最大的区别在于语义不同，在Java里面下列代码：
```
Animal a = new Animal();
Animal b = a;
```
你当然知道，这里其实只生成了一个对象，a和b仅仅是把持对象的引用而已，**但在C++中不是这样**
```
Animal a;
Animal b = a;
```
这里却是就是生成了两个对象。  

-- 智能指针的使用，智能指针在C++11版本之后提供，包含在头文件```<memory>```中，shared_ptr，unique_ptr，weak_ptr。
















