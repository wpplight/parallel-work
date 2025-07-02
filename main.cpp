#include <iostream>
#include "devtools/waitgroup/waitgroup.h"
#include <thread>
using namespace std;

void test(int id,waitgroup &wg){
    cout<<"this is"<<id<<endl;
    wg.Done();
}

int main()
{
    waitgroup a(5);
    std::thread threads[5];
    for (int i = 0; i < 5; i++)
    {
        threads[i]=thread ([i,&a]{
            test(i,a);
        });
    }
    for (int i=0;i<5;i++){
        threads[i].join();
    }
    a.Wait();
    cout<<"done"<<endl;
}
