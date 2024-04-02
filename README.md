# LBYARCH S12 G1 MP2
## Members:
- GUIAO, Miguel Stephen G.
- ARTECHE, Pryne Melton

## I. Comparative execution time and short analysis
For both debug and release mode, we did 30 runs for each vector size (both C and Assembly) then averaged these runtimes.
***
### Debug

| Vector size   | C Avg Runtime | Assembly Avg Runtime  |
| :-----------: |:-------------:| ---------------------:|
| 2^20          | 0.003         | 0.0005                |
| 2^24          | 0.046         | 0.012                 |
| 2^30          | 3.2725        | 0.759                 |

Analysis for debug mode:
For debug mode, the runtime values shown in the table above gets slower as the vector size gets larger regardless of the programming language which is expected. For the vector size 2^20, 2^24, and 2^30, the average runtime of assembly consistently executes faster than C which is impressive since Assembly language has a simple design wherein it’s directly assembled into CPU instructions.

### Release

| Vector size   | C Avg Runtime | Assembly Avg Runtime  |
| :-----------: |:-------------:| ---------------------:|
| 2^20          | 0.006         | 0.006                 |
| 2^24          | 0.0115        | 0.011                 |
| 2^30          | 0.8395        | 0.7195                |

Analysis for release mode:
As we can observe the runtimes in the table above, release mode is generally faster than debug mode and Assembly executes faster than C. However, the average runtime values of both C and assembly have a value of 0.006 for the vector size of 2^20 which might come out as unexpected but this is due to the fact that the floating point values are randomized and it’s something interesting to see in our results.

## II. Program output with correctness check (C and Assembly)
