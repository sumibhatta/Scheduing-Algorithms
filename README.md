Operating System Process Scheduling Algorithms
  
Which process in ready queue will get the processor?  
Criterias:
  - Processor Utilization
  - Throughput
  - Turn Around Time
  - Waiting TIme
  - Response Time  
    
Scheduling Decisions take place under 5 possible scenarios:
  1. After process switches from Running to Blocked(Waiting) State [Process Request & I/O]
  2. After process switches from Running to Ready [Interrupt Occors]
  3. After process switches from Blocked to Ready State [Completion of I/O]
  4. Process Terminates [Completion of Running Processes]
  5. Newly created process arrives at ready state [New Job Accepted]

For scenario 1 and 4   => A new process must be selected for ready process queue  
For scenario 2,3 and 5 => Should a previously running process be reselected? Or Would it be possible to select new process form ready queue?

Pre-emptive  | Non Pre-emptive
------------- | -------------
It acts on all above scenarios  | It acts only on 1,4 scenarios (reselects previous running process in 2,3,5)
Highest Priority process among all ready process is allocated to CPU  |  Once CPU has been allocated to a process, processor keeps CPU until release of CPU
They allow real multi-programming | They do not allow real multiprogramming
They can lead the system to race condition | They do not lead the system to race condition
They are complex | They are simple  


#### Algorithms: ####
    1. First Come First Serve (FCFS)
    2. Shortest-Job-First (SJF) Scheduling
    3. Shortest Remaining Time
    4. Priority Scheduling
    5. Round Robin Scheduling
    6. Multilevel Queue Scheduling
    
#### First Come First Serve (FCFS) ####
- Simplest
- Set of ready process is FIFO queue
- The process are serviced by CPU until completion of their order of their FIFO queue
- Once process is allocated, CPU keeps it until releasing CPU either by terminating or requesting I/O

#### Shortest-Job-First (SJF) Scheduling ####
#### Shortest Remaining Time ####
#### Priority Scheduling ####
#### Round Robin Scheduling ####
#### Round Robin Scheduling ####
