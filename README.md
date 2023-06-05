# Lottery-Scheduling-XV6

# Project Description

The project is a part of the CS 5348 Operating Systems curriculum, where the task is to introduce a lottery scheduler to xv6, replacing the current round-robin scheduler. The lottery scheduler is a probabilistic scheduling algorithm that allocates to each running process a slice of the processor in proportion to the number of tickets it has. The more tickets a process possesses, the more it runs. This mechanism brings in the randomness of a lottery as each time slice chooses the winning process via a randomized process. This project aims to further your knowledge of a real kernel, familiarize you with the scheduler, change it to a new algorithm, and produce a graph to demonstrate your project's performance.

## Key Components

1. **Setting Tickets**: Implement a system call, `settickets(int)`, to set the ticket count of a process. By default, each process should have one ticket. If a process wishes to change the ticket count, it should use this system call. On success, it returns 0; on error, such as inputting a number less than one, it returns -1.

2. **Implementing the Scheduler**: The scheduler in the xv6 kernel needs to be replaced with the lottery scheduler. The existing scheduler code resides in `proc.c` and `proc.h`. Child processes should inherit their parent's ticket count. For creating random numbers in the kernel, a simple pseudo-random number generator can be used.

3. **Getting Process Statistics**: A system call, `getpinfo(struct pstat *)`, is needed to retrieve running processes' statistics, including the number of times each process has been chosen to run and their respective process IDs. You must use the structure `pstat` exactly as defined in `pstat.h`.

4. **Graphical Representation**: A graph representing the allocation of time slices to three processes over time is required as a part of the deliverable. The processes should have a ticket ratio of 3:2:1, and the graph should show that the lottery scheduler is functioning correctly.
