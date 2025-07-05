#pragma once

#include <vector>
#include <queue>

template <typename chan_T>
class chan{
    public:
    explicit chan(int size);


    private:

    const int size_;
    std::vector<chan_T> data_;
    
};
