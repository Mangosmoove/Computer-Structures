Questions:

1.How much time (in miliseconds) does it take for each thread to complete its task? 
For the first thread, it took 113 ms. For the second thread, it took 185 ms. For the main thread, it took 3629669 ms. 

2.In the multi-threaded version does main thread time == thread 1 time + thread 2 time?
No, it does not. The sum of the two threads is: 298 ms.

3.Which method (single-thread or multi-thread) results in a faster execution time? Explain why the given version is faster than the other.
The multi-threaded version is much faster. This makes sense because a single thread runs sequentially, which is slower than the threads running concurrently.

4.In the Step 4 - Execution section above, why are there two possible outputs for the same code?
There's no order for the threads to execute. It's dependent on your computer and one thread can finish before the other thread.
