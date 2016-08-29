#!/bin/bash -l
#SBATCH -t 0-00:10                 # Specify Runtime in D-HH:MM  , for e.g 10 minutes.
#SBATCH -J gpu-help-hello-world    # Specify the job name syntax ApplicatioName-JobName


#SBATCH -o gpu.out                # Specify File to which standard out will be written
#SBATCH -e gpu.err                # Specify File to which standard err will be written

##Request 1 k20 on 1 node
#SBATCH --gres=gpu:k20:1 -N 1


module purge                       # Unloads all existing modules (clean environment)
module load cuda


cd ~/noor-gpu/gpu-hello-world

date
hostname
./hello-world
