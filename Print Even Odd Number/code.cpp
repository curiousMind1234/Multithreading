/* Online C++ Compiler and Editor */
#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
using namespace std;
std::mutex m;
std::condition_variable cv;
int i=1;
void PrintEven(int n){
    while(i<=n){
        std::unique_lock<std::mutex> lock(m);
        cv.wait(lock, [](){return (i%2 == 0);});
        cout << "Even : " << i << endl;
        i++;
        cv.notify_all();
    }
}
void PrintOdd(int n){
    while(i<=n){
        std::unique_lock<std::mutex> lock(m);
        cv.wait(lock, [](){return (i%2 == 1);});
        cout << "Odd : " << i << endl;
        i++;
        cv.notify_all();
    }
}
int main()
{
   cout << "created the thread" << endl;
   thread t1(PrintEven, 50);
   cout <<"started 2nd thread" << endl;
  
   thread t2(PrintOdd, 50);
   
  t1.join();
  t2.join();
   
   cout <<"exiting from main" << endl;
   return 0;
}
