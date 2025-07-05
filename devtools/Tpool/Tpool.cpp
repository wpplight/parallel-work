#include "devtools/Tpool/Tpool.h"

Tpool::Tpool(int num):_len(num),_activity_threads(0){
    _pool.reserve(num);
    
}

void Tpool::thread_run(){



}

void Tpool::init_pool(){
    for(int i=0;i<_len;i++){

    }
}