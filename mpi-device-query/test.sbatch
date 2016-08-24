#!/bin/bash -l


#Request 1 k20, on 1 process on 1 node
#SBATCH --gres=gpu:k20:1 -n 1 -N 1
 
 
#Request 8 k20 on 8 processes on 1 node
##SBATCH --gres=gpu:k20:8 -n 8 -N 1
 
 
#Request 12 k20 on 2 nodes, with 8 gpu on 1 node, and 4 on the other
##SBATCH --gres=gpu:k20:8,gpu:k20:4 -n 12 -N 2

cat test.sbatch
module load mpich
srun hostname
env|grep -i cuda


mpirun ./deviceQuery

wait
