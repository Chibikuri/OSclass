source code is t2-approx.c
binary is t2-approx

1 6core.
2
3. plot
#threads.png is varying the number of threads from 1 to 1000.(1, 10, 50, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000)

#threshold.png is varying the value of threshold from 1 to 1000.(the same as threads)

simultaneous.png is varying the values of threshold and threads at the same time from 1 to 1000.

logsimultaneous.png is logscale of threshold.

Awareness:
As the number of threads increase, the execution time will increase. Once it increased, execution time is stable at around 15s(systime).
As the value of threshold increase, the execution time won't change dramatically.
In the logscale plot, from 0 to 10^1, ratio of increasing is lenear. After that, threre no change.
