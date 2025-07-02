#include <atomic>
#include <linux/futex.h>
#include <sys/syscall.h>


class waitgroup
{
public:
    explicit waitgroup(int count) : _count(count),go(false) {
        //出现特殊情况说明不需要阻塞
        if (count<0) return ;
    }
    void Done() noexcept
    {
        // 原子减并检测
        if (_count.fetch_sub(1, std::memory_order_release) == 1)
        {

            go.exchange(true,std::memory_order_release);
            // 唤醒所有线程
            syscall(SYS_futex, &go, FUTEX_WAKE | FUTEX_PRIVATE_FLAG, INT_MAX);
        }
    }
    void Wait() noexcept
    {
        // 快速路径：无等待检查
        if (_count.load(std::memory_order_acquire) == 0)
        {
            return;
        }
        while(true){
            if (go.load(std::memory_order_acquire) == false)
            
                //阻塞当前线程
                syscall(SYS_futex, &go, FUTEX_WAIT | FUTEX_PRIVATE_FLAG,
                false, // 当前值
                nullptr, nullptr, 0);

            else return;       
        }
        
    }

private:
    //计数器
    std::atomic<int> _count;
    //标志位
    std::atomic_bool go;
};