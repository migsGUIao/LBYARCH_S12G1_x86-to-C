# LBYARCH S12 G1 MP2
## Members:
- GUIAO, Miguel Stephen G.
- ARTECHE, Pryne Melton
***
### Machine Project 2 Specifications
The kernel is to perform a dot product between vector A and vector B and place the result in **sdot**. This is expected to be written in C and x86-64 assembly language.
![mco2_specs](https://github.com/migsGUIao/LBYARCH_S12G1_x86-to-C/assets/118590095/c7cbe675-32cd-48d6-b6bc-1c30b9ee7129)

## I. Comparative execution time and short analysis
For both debug and release mode, we did 30 runs for each vector size (both C and Assembly) then averaged these runtimes.

### Debug mode results

| Vector size   | C Avg Runtime | Assembly Avg Runtime  |
| :-----------: |:-------------:| :--------------------:|
| 2^20          | 0.003         | 0.0005                |
| 2^24          | 0.046         | 0.012                 |
| 2^30          | 3.2725        | 0.759                 |

### Analysis for debug mode:
For debug mode, the runtime values shown in the table above gets slower as the vector size gets larger regardless of the programming language which is expected. For the vector size 2^20, 2^24, and 2^30, the average runtime of assembly consistently executes faster than C which is impressive since Assembly language has a simple design wherein it’s directly assembled into CPU instructions. It's also worth mentioning that as the vector size gets larger, the average runtime of C gets significantly slower when compared to Assembly.

### Release mode results

| Vector size   | C Avg Runtime | Assembly Avg Runtime  |
| :-----------: |:-------------:| :--------------------:|
| 2^20          | 0.006         | 0.006                 |
| 2^24          | 0.0115        | 0.011                 |
| 2^30          | 0.8395        | 0.7195                |

### Analysis for release mode:
As we can observe the runtimes in the table above, release mode is generally faster than debug mode and Assembly executes faster than C. However, the average runtime values for the vector size 2^20 (both C and assembly) have a value of 0.006 which might come out as unexpected but this is due to the fact that the floating point values are randomized for all tests and it’s something interesting to see in our results. It's also worth noting that even though the average runtimes for vector size 2^20 are the same, both are still faster when compared to the runtimes of larger vector sizes. 

***

## II. Program output with correctness check (C and Assembly)
Our sanity check answer key is based from the C program. The result (sdot) of C is compared to Assembly, "The results match!! The x86-64 Kernel output is correct!" is displayed if results match. Else, the program will display "Warning! The x86-64 Kernel output is not correct."

### Example when results don't match
![incorrect](https://github.com/migsGUIao/LBYARCH_S12G1_x86-to-C/assets/118590095/21fbaa7f-2876-4a13-9048-4103d95d2fde)

## Vector size = 2^20 
### Debug mode:
![2^20_debug](https://github.com/migsGUIao/LBYARCH_S12G1_x86-to-C/assets/118590095/7f6bbd52-8ba6-4592-b3e6-385b4ea526b5)

### Release mode:
![2^20_release](https://github.com/migsGUIao/LBYARCH_S12G1_x86-to-C/assets/118590095/fae1e3a4-50a7-4ae4-8b93-6ef3ca969d5c)

## Vector size = 2^24 
### Debug mode:
![2^24_debug](https://github.com/migsGUIao/LBYARCH_S12G1_x86-to-C/assets/118590095/1c52b4e2-a793-4be1-9679-cc3648935c66)

### Release mode:
![2^24_release](https://github.com/migsGUIao/LBYARCH_S12G1_x86-to-C/assets/118590095/a7cbef77-6664-4a6e-973a-f6d3509180a4)

## Vector size = 2^30 
### Debug mode:
![2^30_debug](https://github.com/migsGUIao/LBYARCH_S12G1_x86-to-C/assets/118590095/0e4047da-c40f-43e6-9362-01badd46136c)

### Release mode:
![2^30_release](https://github.com/migsGUIao/LBYARCH_S12G1_x86-to-C/assets/118590095/8e93b43d-8c6e-4b20-9334-51a9f57c2983)

