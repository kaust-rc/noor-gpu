---
layout: post
title: "VASP on noor-gpu"
date: 2017-02-07 16:25:06 -0700
comments: false
---


# VASP on GPU

You can run version 5.4.1, ```module load vasp/5.4.1/openmpi-1.10.4-intel-2016```, on one of our GPU nodes. Our tests showed a speedup of 2x to 5x. You get the best performance gains for medium to large systems. We ran tests on three 16-cores node for pure CPU calculations while we ran the GPU test on three eight GPU nodes. The pure CPU test used 48 MPI ranks while the GPU test used only 24 ranks, one per GPU.

Today's limit is that you can use at most as many ranks as GPU cards on the node. We're working with NVIDIA to allow using more ranks than available GPU cards.

## Running on GPU

VASP on GPU comes in two flavors:

  - ```vasp-gpu``` to run **standard** VASP on GPU cards
  - ```vasp-gpu-so``` to run **non-collinear** VASP on GPU cards

To run VASP on GPU cards in batch mode, create a batch submission script called **vasp.sbatch** as follows:

```bash
#!/bin/bash -l

#SBATCH --job-name=vasp-gpu
#SBATCH --output=vasp-gpu.%j.out
#SBATCH --error=vasp-gpu.%j.err
#SBATCH --time=1-0
#SBATCH --nodes=3
#SBATCH --ntasks=24
#SBATCH --gres=gpu:k40:8

# Note that no_nodes * no_of_gpu_cards_per_node = no_cores to specify

module purge
module load vasp/5.4.1/openmpi-1.10.4-intel-2016
mpirun --bind-to core vasp_gpu
```

Then submit your job to the batch system via sbatch:
```bash
$ sbatch vasp.sbatch
```

You should see something like this in your output file, e.g. ```vasp-gpu.227452.out``` if your ranks are using the GPU cards correctly:

```bash
Tue Feb 07 09:53:48 AST 2017
Using device 0 (rank 0, local rank 0, local size 8) : Tesla K40m
Using device 1 (rank 1, local rank 1, local size 8) : Tesla K40m
Using device 2 (rank 2, local rank 2, local size 8) : Tesla K40m
Using device 3 (rank 3, local rank 3, local size 8) : Tesla K40m
Using device 4 (rank 4, local rank 4, local size 8) : Tesla K40m
Using device 5 (rank 5, local rank 5, local size 8) : Tesla K40m
Using device 6 (rank 6, local rank 6, local size 8) : Tesla K40m
Using device 7 (rank 7, local rank 7, local size 8) : Tesla K40m
Using device 1 (rank 9, local rank 1, local size 8) : Tesla K40m
Using device 3 (rank 11, local rank 3, local size 8) : Tesla K40m
Using device 4 (rank 12, local rank 4, local size 8) : Tesla K40m
Using device 5 (rank 13, local rank 5, local size 8) : Tesla K40m
Using device 6 (rank 14, local rank 6, local size 8) : Tesla K40m
Using device 7 (rank 15, local rank 7, local size 8) : Tesla K40m
Using device 0 (rank 8, local rank 0, local size 8) : Tesla K40m
Using device 2 (rank 10, local rank 2, local size 8) : Tesla K40m
Using device 1 (rank 17, local rank 1, local size 8) : Tesla K40m
Using device 3 (rank 19, local rank 3, local size 8) : Tesla K40m
Using device 7 (rank 23, local rank 7, local size 8) : Tesla K40m
Using device 5 (rank 21, local rank 5, local size 8) : Tesla K40m
Using device 6 (rank 22, local rank 6, local size 8) : Tesla K40m
Using device 0 (rank 16, local rank 0, local size 8) : Tesla K40m
Using device 2 (rank 18, local rank 2, local size 8) : Tesla K40m
Using device 4 (rank 20, local rank 4, local size 8) : Tesla K40m
 running on   24 total cores
 distrk:  each k-point on    3 cores,    8 groups
 distr:  one band on    1 cores,    3 groups
 using from now: INCAR

 *******************************************************************************
  You are running the GPU port of VASP! When publishing results obtained with
  this version, please cite:
   - M. Hacene et al., http://dx.doi.org/10.1002/jcc.23096
   - M. Hutchinson and M. Widom, http://dx.doi.org/10.1016/j.cpc.2012.02.017

  in addition to the usual required citations (see manual).

  GPU developers: A. Anciaux-Sedrakian, C. Angerer, and M. Hutchinson.
 *******************************************************************************

 vasp.5.4.1 05Feb16 (build Feb 06 2017 15:17:54) complex
```

You should have one rank per GPU otherwise you will not benefit from GPU performance.

## Caveat
  * You cannot set NPAR or NCORE parameters, let VASP set the NOCRE value for you
  * You can only use ```ALGO=Normal, Fast, and VeryFast``` when running VASP on GPU
  * You have to use ```mpirun``` to see the rank to GPU mapping otherwise you could use ```srun``` as used in pure CPU runs

## Further Reading

  * [VASP on GPU pdf from Max Hutchinson]({{ site.baseurl }}/docs/vaspongpus_update.pdf)
  * [Max Huthinson's Paper](http://www.sciencedirect.com/science/article/pii/S0010465512000707){:target="_blank"}
  * [GPU port of VASP](http://cms.mpi.univie.ac.at/wiki/index.php/GPU_port_of_VASP){:target="_blank"}
  * [Release Notes](https://www.vasp.at/index.php/news/44-administrative/115-new-release-vasp-5-4-1-with-gpu-support){:target="_blank"}
  * [Peter Larsson (Linkoping Uni) experience with VASP on GPU](https://www.nsc.liu.se/~pla/blog/2015/11/16/vaspgpu/){:target="_blank"}
  * [Talk (18:36 duration) by Max Hutchinson at SC 15](http://images.nvidia.com/events/sc15/SC5120-vasp-gpus.html){:target="_blank"}
