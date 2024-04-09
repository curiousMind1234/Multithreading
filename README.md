1. Mutex are used for mutual exclusion i.e to safe gaurd the critical sections of a code.
2. Semaphone/condition_variable are used for thread synchronisation(which is what we want to achieve here).
3. Mutex have ownership assigned with them, that is to say, the thread that locks a mutex must only unlock it. Also, we must not unlock a mutex that has not been locked (This 
   is what most programs have got wrong).
4. If the mutex is not used as said above, the behavior is undefined, which however in our case produces the required result.
