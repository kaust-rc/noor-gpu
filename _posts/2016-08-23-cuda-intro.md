---
layout: post
title: "CUDA on noor-gpu"
date: 2016-08-22 16:25:06 -0700
comments: false
---
# Introduction to CUDA on Noor GPU


Some information from [Nvidia Developer Zone](https://developer.nvidia.com/accelerated-computing-training)

[Good video](https://youtu.be/Ed_h2km0liI) to start writing CUDA.

<iframe width="560" height="315" src="https://www.youtube.com/embed/Ed_h2km0liI" frameborder="0" allowfullscreen></iframe>

Nvidia provides some great samples:

```bash
#Copy the nvidia-samples from /opt/share to user home
cp -r /opt/share/cuda/7.5/NVIDIA_CUDA-7.5_Samples/ ~
cd ~/NVIDIA_CUDA-7.5_Samples/

#Compile all the samples  (this takes some time)
module load cuda/7.5 mpich gcc
make

#Run a sample, should return useful information about the GOU cards
cd ~/NVIDIA_CUDA-7.5_Samples/1_Utilities/deviceQuery
./deviceQuery
```
