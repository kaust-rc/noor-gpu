---
layout: post
title: "Using SLURM on noor-gpu"
date: 2016-08-22 16:25:06 -0700
comments: false
---

# Using slurm on noor-gpu

Generic resource (GRES) scheduling is supported through a flexible plugin mechanism. Support is currently provided for Graphics Processing Units (GPUs).  [Find the documentation here](http://slurm.schedmd.com/gres.html)


A small utility is provided to test the allocation on [https://github.com/kaust-rc/noor-gpu](https://github.com/kaust-rc/noor-gpu/tree/master/mpi-device-query)


At the moment, only 1 process is mapped to 1 gpu, (we may change this in the near future).
```bash
## Request 1 k20, on 1 process on 1 node
#SBATCH --gres=gpu:k20:1 -n 1 -N 1


## Request 4 k20 and 4 processes, with 2 on each node
#SBATCH --gres=gpu:k20:2 -n 4 -N 2

## Request 24 k40 
#SBATCH --gres=gpu:k40:8 -N 3
```
