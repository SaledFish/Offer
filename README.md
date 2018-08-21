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
