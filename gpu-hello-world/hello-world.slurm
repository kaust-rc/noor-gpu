#!/bin/bash -l
#SBATCH -p gpu
#SBATCH --ntasks=1                 # Specify number of tasks, i.e. cores you need
#SBATCH --ntasks-per-node=1        # Specify the number of tasks (processes) per node
#SBATCH -t 0-00:10                 # Specify Runtime in D-HH:MM  , for e.g 10 minutes.
#SBATCH -J gpu-help-hello-world    # Specify the job name syntax ApplicatioName-JobName


#SBATCH -o gpu.out                # Specify File to which standard out will be written
#SBATCH -e gpu.err                # Specify File to which standard err will be written

date
module purge                       # Unloads all existing modules (clean environment)
module load cuda/7.5


cd ~/workspace/gpu-help/hello-world

nvcc hello-world.cu -o hello-world

./hello-world
