#include <iostream>
#include "devtools/waitgroup/waitgroup.h"
#include <thread>
using namespace std;

void test(int id,waitgroup &wg){
    sleep(1);
    cout<<"this is"<<id<<endl;
    wg.Done();
}

int main()
{
    waitgroup a(10);
    std::thread threads[10];
    for (int i = 0; i < 10; i++)
    {
        threads[i]=thread ([i,&a]{
            test(i,a);
        });
    }
     a.Wait();
    cout<<"done"<<endl;
    for (int i=0;i<10;i++){
        threads[i].join();
    }
   
}
