#include <latch>

class waitgroup{
   public :
   waitgroup(int num):group(num){}

   void Done(){
        group.count_down();
   }

   void Wait(){
        group.wait();
   }


   private:
   std::latch group;
};