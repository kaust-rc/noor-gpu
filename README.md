# noor-gpu


noor-gpu is a GPU cluster managed by Research Computing at KAUST.

| Num Nodes | GPU     | GPU per Node  |GPU Mem/Card|CUDA cores|
|:---------:|:-------:|:-------------:|:----------:|:--------:|
| 8 | k20 | 8 | 5GB|2496|
| 3 | k40 | 8 | 12GB|2880|
| 2 | k40 | 1 | 12GB|2880|




|Application/Compilers/Libraries|	Version|
| ------------------------------|--------|
|CUDA|	7.5|
|cuDNN|	5.0|
|Keras with Thaeno backend||
|NAMD|2.11|
|gromacs|	2016|
|lammps|	2016|
|vasp|	not installed yet, under testing|
|intel compiler|	2015|
|gcc|	4.6.0, 4.8.1|


~~~~bash
#!/bin/bash -l
#SBATCH -t 0-24:00                  # Specify Runtime in D-HH:MM  , for e.g 24 hrs.
#SBATCH -J myapp-gpu                # Specify the job name syntax ApplicatioName-JobName
#SBATCH -o gpu.%j.out               # Specify File to which standard out will be written
#SBATCH -e gpu.%j.err               # Specify File to which standard err will be written
 
#SBATCH --gres=gpu:k20:2 -n 2 -N 1 #2 processes with 2 GPU on 1 node (note lowercase 'k')
 
module purge
module load cuda mpich
 
mpirun ./deviceQuery
~~~~


