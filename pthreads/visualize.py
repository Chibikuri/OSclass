import matplotlib.pyplot as plt
import numpy as np
# change number of threads
# realtime = [0.58,1.737,1.749,1.733,1.811,1.937,1.93,1.957,1.994,1.939,1.956,1.916,1.941]
# usrtime = [0.573,2.122,1.726,1.593,1.696,1.236,1.346,1.21,1.226,1.348,1.193,1.301,1.211]
# systime = [0.003,13.022,17.588,17.042,17.941,15.158,15.929,15.1,15.046,16.127,15.294,15.637,14.909]
# numthreads = [1, 10, 50, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000]

# plt.plot(numthreads, realtime, label="realtime")
# plt.plot(numthreads, usrtime, label="usrtime")
# plt.plot(numthreads, systime, label="systime")
# plt.title("threshold=1")
# plt.ylabel("execution time")
# plt.xlabel("The number of threads")
# plt.legend(bbox_to_anchor=(1, 0), loc='lower right', borderaxespad=1, fontsize=10)
# plt.show()


# change threshold
# realtime = [0.557, 0.419,0.435,0.412,0.414,0.403,0.435,0.449,0.427,0.408,0.527,0.408,0.518]
# usrtime = [0.553,0.415,0.428,0.404,0.404,0.397,0.406,0.406,0.401,0.397,0.43,0.395,0.418]
# systime = [0.003,0.003,0.004,0.004,0.005,0.003,0.006,0.006,0.004,0.003,0.008,0.003,0.009]
# threshold = [1, 10, 50, 100, 200,300, 400, 500, 600, 700, 800, 900, 1000]

# plt.plot(threshold, realtime, label="realtime")
# plt.plot(threshold, usrtime, label="usrtime")
# plt.plot(threshold, systime, label="systime")
# plt.title("the number of thread = 1")
# plt.ylabel("execution time")
# plt.xlabel("Threshold")
# plt.legend(bbox_to_anchor=(1, 0), loc='lower right', borderaxespad=1, fontsize=10)
# plt.show()

realtime = [0.556,1.301,1.235,1.261,1.334,1.31,1.433,1.482,1.373,1.274,1.528,1.345,1.576]
usrtime = [0.551,1.794,1.406,1.418,1.331,1.449,1.312,1.487,1.24,1.417,1.433,0.902,1.383]
systime = [0.003,8.508,11.503,11.98,11.865,12.246,11.675,12.542,11.637,12.196,12.314,10.218,12.272]
threshold = [1, 10, 50, 100, 200,300, 400, 500, 600, 700, 800, 900, 1000]
# thresholdlog = [np.log10(i) for i in threshold]

plt.plot(threshold, realtime, label="realtime")
plt.plot(threshold, usrtime, label="usrtime")
plt.loglog(threshold, systime, label="systime")
plt.title("varying #of threads and #threshold at the same time.")
plt.ylabel("execution time")
plt.xlabel("Threshold and threads(log10)")
plt.legend(bbox_to_anchor=(1, 0), loc='lower right', borderaxespad=1, fontsize=10)
plt.show()
