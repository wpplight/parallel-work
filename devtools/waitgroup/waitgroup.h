#pragma once

#include <latch>
#include <optional>

class waitgroup{
   public :
   explicit waitgroup(int num):valid_(num>0){
     //负数情况下直接非阻塞
     if (num>0) group.emplace(num);
   }

   void Done(){
     if (valid_)
        group->count_down();
   }

   void Wait(){
     if (valid_)
        group->wait();
   }


   private:
   bool valid_;
   std::optional<std::latch> group;
};