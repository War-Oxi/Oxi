#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

std::mutex mtx; //mutual exclusion

using namespace std;
int main() {
//    const unsigned int num_pro = std::thread::hardware_concurrency();
//    cout << num_pro << endl;
//    cout << std::this_thread::get_id() << endl;
//
//    vector<std::thread> my_threads;
//    my_threads.resize(num_pro);
//
//    for (auto & e : my_threads)
//        e = std::thread([](){
//            cout << std::this_thread::get_id() << endl;
//            while(true){}
//        });

    auto work_func = [](const string & name)
    {
        for(int i=0; i<10; i++){
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            mtx.lock();
            cout << name << " " <<std::this_thread::get_id() << " is working " << i << endl;
            mtx.unlock();
        }
    };

    std::thread t1 = std::thread(work_func, "JackJack");
    std::thread t2 = std::thread(work_func, "Dash");

//    work_func("JackJack");
//    work_func("Dash");
    t1.join();
    t2.join();


//    std::thread t1 = std::thread([](){ //문제 발생 -> 새로 실행시킨 스레드가 끝나기전에 메인함수가 끝나버림.
//        cout << std::this_thread::get_id() << endl;
//        while(true)
//        {}
//    });

//    std::thread t2 = std::thread([](){ //문제 발생 -> 새로 실행시킨 스레드가 끝나기전에 메인함수가 끝나버림.
//        cout << std::this_thread::get_id() << endl;
//        while(true)
//        {}
//    });std::thread t3 = std::thread([](){ //문제 발생 -> 새로 실행시킨 스레드가 끝나기전에 메인함수가 끝나버림.
//        cout << std::this_thread::get_id() << endl;
//        while(true)
//        {}
//    });std::thread t4 = std::thread([](){ //문제 발생 -> 새로 실행시킨 스레드가 끝나기전에 메인함수가 끝나버림.
//        cout << std::this_thread::get_id() << endl;
//        while(true)
//        {}
//    });

//    t1.join(); //t1스레드가 끝날때 까지 기다림
//    t2.join();
//    t3.join();
//    t4.join();


    return 0;
}
