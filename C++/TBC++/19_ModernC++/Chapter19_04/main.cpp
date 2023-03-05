#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <chrono>

using namespace std;

int shard_memory(0);
//atomic<int> shard_memory(0);
std::mutex mtx;

int main() {
    auto count_func = []() {
        for (int i=0; i<100000; i++){
//            mtx.lock();
//            this_thread::sleep_for(chrono::milliseconds(10));
//            mtx.unlock();

//            std::lock_guard lock(mtx);
//            std::scoped_lock lock(mtx); //lock_guard보다 진보된 형태. 사용 권장
            shard_memory++;
//            shard_memory.fetch_add(1);
        }
    };

    thread t1 = thread(count_func);
    thread t2 = thread(count_func);

    t1.join();
    t2.join();

    cout << "After" << endl;
    cout << shard_memory << endl;

    return 0;
}