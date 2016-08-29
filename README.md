# noor-gpu


noor-gpu is a GPU cluster managed by Research Computing at KAUST.
Documentation available at [kaust-rc.github.io/noor-gpu](https://kaust-rc.github.io/noor-gpu)


| Num Nodes | GPU     | GPU per Node  |GPU Mem/Card|CUDA cores|
|:---------:|:-------:|:-------------:|:----------:|:--------:|
| 1 | k20 | 7 | 5GB||Awaiting delivery of extra k20|
| 8 | k20 | 8 | 5GB|2496|
| 3 | k40 | 8 | 12GB|2880|
| 2 | k40 | 1 | 12GB|2880|




|Application/Compilers/Libraries |
| -------------------------------|
|CUDA, cuDNN|
|Keras with Thaeno backend|
|NAMD, gromacs, lammps|
|vasp: under testing|
|nvcc, gcc, icc|



~~~~bash
#!/bin/bash -l
#SBATCH -t 0-24:00                  # Specify Runtime in D-HH:MM  , for e.g 24 hrs.
#SBATCH -J myapp-gpu                # Specify the job name syntax ApplicatioName-JobName
#SBATCH -o gpu.%j.out               # Specify File to which standard out will be written
#SBATCH -e gpu.%j.err               # Specify File to which standard err will be written
 
#SBATCH --gres=gpu:k20:1 -n 1 -N 1 #1 processes with 1 GPU on 1 node (note lowercase 'k')
 
module purge
module load cuda
 
mpirun ./deviceQuery
~~~~


