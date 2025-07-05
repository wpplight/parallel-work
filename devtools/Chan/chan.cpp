#include "devtools/Chan/chan.h"

template<typename chan_T>
chan<chan_T>::chan(int size):size_(size),data_(size_){

}