# homework2
Qiyu Xiao(qx344)


bug_solved2: The variable 'total' is shared in the parallel region. Changing it to reduction or private can solve the problem.

bug_solved3: 'Section' directive makes function 'print_results' only run by one thread, thus the 'Barrier' directive at the end of 'print_results' function will never be able to synchronize all the threads. Delete this 'Barrier' directive and add the 'print' statement to the critical section.

bug_solved4: Fixed size array may cause stack size exceed error. Allocate the array inside the parrallel  region dynamically can solve this problem.

bug_solved5: Nested locks cause deadlock. Instead, using locks to let addition happens in one array first, then assign the result to the other array to eliminate conflicts. 

bug_solved6: 'sum' is shared before entering 'drop()' but then tries to become private. Declare 'sum' to be private before entering the function drop() to insure consistency.




| Array Length(N) / Max Iter  | jacobi2D | jacobi2D-omp | gs2D | gs2D-omp | Last Residual |
| --- | --- | --- | --- | --- | --- | 
| 10/1000 | 0.000895 | 0.001664 | 0.000615 | 0.001497 | <10^(-5) |  
| 100/1000 | 0.242238 | 0.108601 | 0.283954 | 0.119327 | ~50 |
| 1000/1000 | 23.942599 | 10.120017 | 28.663496 | 11.057303 | ~1000 |
| 1000/10000 | 239.077704 | 100.792247 | 286.340558 | 108.474911 | ~800 |


Architecture:          x86_64

CPU op-mode(s):        32-bit, 64-bit

Byte Order:            Little Endian

CPU(s):                4

On-line CPU(s) list:   0-3

Thread(s) per core:    1

Core(s) per socket:    2

Socket(s):             2

NUMA node(s):          2

Vendor ID:             AuthenticAMD

CPU family:            15

Model:                 33

Model name:            Dual Core AMD Opteron(tm) Processor 285

Stepping:              2

CPU MHz:               2592.646

BogoMIPS:              5184.29

L1d cache:             64K

L1i cache:             64K

L2 cache:              1024K

NUMA node0 CPU(s):     0,1

NUMA node1 CPU(s):     2,3





