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
