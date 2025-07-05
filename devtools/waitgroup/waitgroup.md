# waitgroup

该工具旨在使用waitgroup类来同步并行计算部分，降低并行同步难度，这个是从线程层次上的阻塞

通用	现代 C++ 项目首选(c++20)

(Linux)		Linux需求,使用futex快速用户态阻塞和原子操作实现

## 文档

### 1. class类型

```cpp
 waitgroup(int num):group(num){}
```

创建该类型需要设置等待线程数量,小于等于零会解析为不需要同步。
如下：

```cpp
 waitgroup wp(5);
```

### 2. func功能

    void Done(void) 
    表示并行任务中的一个任务完成了

    void Wait(void)
    等待完成所有并行任务进行下一步。范围匹配：计数4如果释放了5次，第四次就会解锁。
```cpp

    //任务函数
    void test(int id,waitgroup &wg){
    cout<<"this is"<<id<<endl;
    wg.Done();
    }


    //创建线程
    std::thread threads[5];
    //创建waitgroup
    waitgroup a(5);
    //线程分配
    for (int i = 0; i < 5; i++)
    {
        threads[i]=thread ([i,&a]{
            test(i,a);
        });
    }
    //等待同步
    a.Wait();
    //回收线程
     for (int i=0;i<5;i++){
        threads[i].join();
    }
```

