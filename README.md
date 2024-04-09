1. Mutex are used for mutual exclusion i.e to safe gaurd the critical sections of a code.
2. Semaphone/condition_variable are used for thread synchronisation(which is what we want to achieve here).
3. Mutex have ownership assigned with them, that is to say, the thread that locks a mutex must only unlock it. Also, we must not unlock a mutex that has not been locked (This 
   is what most programs have got wrong).
4. If the mutex is not used as said above, the behavior is undefined, which however in our case produces the required result.

# wait() function:
In C++, the wait() function associated with condition variables is used to atomically release the mutex and suspend the execution of the thread until it is notified by another thread or until a specified timeout expires. When the thread is awakened, it re-acquires the mutex before returning control to the caller.

Here's a brief overview of how wait() works with condition variables:

The thread calls wait() on the condition variable while holding the associated mutex.
The mutex is atomically released, and the thread is put to sleep.
While the thread is asleep, the associated mutex is made available for other threads to acquire.
When another thread calls notify_one() or notify_all() on the condition variable, one or all of the waiting threads are awakened.
The awakened thread(s) compete to re-acquire the mutex. Once acquired, the thread(s) continue execution from where they left off.
This mechanism allows threads to synchronize their execution based on certain conditions and to avoid busy waiting, where a thread repeatedly checks a condition in a loop.

# Diffrence between mutex and condition variable

Mutex and condition variables are both synchronization primitives used in concurrent programming, but they serve different purposes:

Mutex:

A mutex (short for mutual exclusion) is used to protect shared resources by allowing only one thread at a time to access them.
It provides mutual exclusion, meaning that only one thread can acquire the mutex at a time. Other threads attempting to acquire the mutex while it's locked will be blocked until it's released by the owning thread.
Mutexes are typically used to prevent race conditions and ensure thread-safe access to shared data.
Condition Variable:

A condition variable is used for inter-thread communication and synchronization based on certain conditions.
It allows threads to wait until a certain condition is satisfied before proceeding with execution.
Condition variables are often used in conjunction with mutexes to coordinate the actions of multiple threads. They are associated with a mutex, and typically, the mutex is locked before waiting on a condition variable and unlocked while waiting.
When a condition variable is signaled or notified by another thread, the waiting thread(s) are awakened and recheck the condition. If the condition is met, they proceed; otherwise, they may wait again.
In summary, mutexes are used for mutual exclusion and protecting shared resources, while condition variables are used for signaling and waiting based on conditions in a multi-threaded environment. They often work together to coordinate access to shared resources and synchronize the actions of multiple threads.






