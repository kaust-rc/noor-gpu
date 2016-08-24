---
layout: post
title: "Using SLURM on noor-gpu"
date: 2016-08-22 16:25:06 -0700
comments: false
---


# Using slurm on noor-gpu


Request 1 k20, on 1 process on 1 node
```
#SBATCH --gres=gpu:k20:1 -n 1 -N 1
```

Request 4 k20 and 4 processes, with 2 on each node
```
#SBATCH --gres=gpu:k20:2 -n 4 -N 2
```
