- The first file does the following:
Write a program in C which computes "in parallel" the inner product of two vectors A and B (a1b1+a2b2+......+anbn) [using 'p' threads where each thread will compute the partial sum of 'n/p' terms (partial sums) - p, n, ai and bi should be given by the user or read from a file - also assume that 'n' is an integer multiple of 'p']. More specifically, each thread should (a) compute locally (in a local variable - e.g. local_sum) the subtotal that is assigned to it and (b) update at the end with its local sum a common variable (e.g. total_sum) that represents the final sum (inner product). This final sum should be printed on the screen at the end. 
Is there any "critical part" in your code that requires protection ? If so, additionally write the code to protect this critical section. 
Try running your program for large and very large 'n' (using for input corresponding vectors initialized with random numbers) and measure the execution times for one and more than one threads (e.g. 1, 2, 4 and 8 threads).

- The second file does the following:
Write a program in C, which will use the POSIX Threads library, and will result in the sequence being printed iteratively:
/What A Wonderful World! What A Wonderful World! What A Wonderful World! .../ 
To achieve the above you will need to start three (3) different threads in your program (one printing "What A ", one printing "Wonderful " and the third printing "World! "), and then properly synchronize them together using POSIX semaphores), and then synchronize them appropriately using POSIX semaphores.
Then try to provide (not necessarily required) an alternative version of your program using condition variables for the required synchronization
