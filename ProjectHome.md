I/O in applications has become the biggest bottleneck in desktops, scientific computing, large scale simulations etc. Improvement in CPU speeds has shown significant improvement as compared to improvement in disk and memory speeds. Multi-tasking in Operating Systems gives rise to multiple I/O streams. Unlike the shared resource, the CPU, multiple I/O
streams can actually degrade the performance of the disk. In this article, we present a simple case study where we look at multiple sequential I/O streams accessing the same disk and study the degradation in performance caused by this scenario. We further propose a simple solution to remedy this situation. Readers who study this article are more likely to realize how to improve the performance of simple applications running on their desktop.

We believe that any reader familiar with programming and using any Operating system such as Linux, AIX, Solaris etc can immediately grasp the underlying idea and benefit from it.

We based our project on the coreutils package. We modified the existing file "copy.c", and added a header file, both of which can be found in the "Source" repository.

A full report of our project, explaining the idea, its implementation and the description and results of all the tests we ran, is available in the download section.