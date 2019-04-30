# Multi Level Feedback Queue Assignment
## First
seed:100
File  src → mlfq.py
      result → first.txt
 - What I found
When I run this program with two jobs and two queues, using I/O is slower than not using I/O.
time:
no IO → 92
using IO → 132
Relationship between maximum number of IO value and time.
If maximum number of IO value is over 55 time will be very close to no IO.

## Second
Files src → mlfq2.py
      fig8.2 → second8-2.txt
      fig8.3 → second8-3.txt
      fig8.4 → second8-4.txt
      fig8.5left → second8-5left.txt
      fig8.5right　→ second8-5right.txt

command: fig8.2 → python mlfq2.py -l 0,200,0 -n 3 -c > second8-2.txt
         fig8.3 → python mlfq2.py -l 0,200,0:100,20,0 -n 3 -c > second8-3.txt
         fig8.4 → python mlfq2.py -l 0,150,0:50,10,1:110,10,1 -c > second8-4.txt
         fig8.5left → python mlfq2.py -l 0,100,0:100,10,1:100,10,1 -c > second8-5left.txt
         fig8.5right → python mlfq2.py -l 0,100,0:100,10,1:100,10,1 -B 50 -c > second8-5right.txt

 - What I found and implemented.

I implemented function to describe gantt chart of each job.
I had no idea how to implement I/O as a separated job. So, I regarded I/O as a short job and kept it high priority.

## Third
Description of how I would calculate fairness.
I use prediction time which is predicted before job started(ex. Xpre = 100) 
and actual time which cpu takes actually(ex. Xact = 120)

Definition:
     Fairness = ((Σ(Xact - Xpre))^2)/(n*Σ((Xact - Xpre)^2))
     n ... number of jobs

 - What I implemented.
 a, b. function calc_fairness in line 10.

File src　→ mlfq3.py
     result → third1.txt (job1 100, job2 100, no I/O)
              third2.txt (job1 100, job2 200, no I/O)
              third3.txt (job1 100, job2 100, with I/O) 
              third4.txt (job1 100, job2 200, with I/O)

c. Experiment.
Job: job1 start:0, length:100, noIO  job2 start:0 length:100, noIO
result: fairness →　0.9972375690607734(~1.0)

d. Experiment
Job : job1 start:0, length:100, noIO  job2 start:0 length:200, noIO
result: fairness → 0.9972375690607734(~1.0)

Extra experiment1
Job : job1 start:0, lenth:100, noIO  job2 start:0 length:100, IO with 2freq
result: fairness　→　0.5920633314785776(~0.6)

Extra experiment2
Job : job1 start:0, lenth:100, noIO  job2 start:0 lenth:200, IO with 2freq
result: fairness　→ 0.5489388300139216(~0.5)

