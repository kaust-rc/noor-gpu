---
layout: post
title: "VASP on noor-gpu"
date: 2016-08-19 16:25:06 -0800
comments: false
---


# VASP 5.4.1
VASP Website: http://cms.mpi.univie.ac.at/vasp/
To initialize your environment for using VASP, load the associated module.
```bash
$ module load vasp/5.4.1
```
 
To submit a VASP job to the cluster, create a batch submission script called ''vasp.sbatch'' as follows:

```bash
#!/bin/bash -l

#SBATCH -J [your_job_name]
#SBATCH -o JOB.%J.out        # File to which STDOUT will be written
#SBATCH -e JOB.%J.err        # File to which STDERR will be written
#SBATCH -t [D-HH:MM]         # ALWAYS specify runtime! Format in D-HH:MM (e.g. 0-00:05)
#SBATCH --ntasks=[no_cores]  # Number of cores (e.g. 64). If you arent running in parallel, this should be 1
#SBATCH --gres=gpu:k20:[no_of_gpu_cards_per_node] 
 
# Clean environment first then load desired module
module purge
module load vasp/5.4.1

# Go to your work directory
# ALWAYS run your jobs in your /scratch directory
cd /scratch/$USER/<your_input_directory>

# run lammps with input file
srun --cpu_bind=cores lmp_kaust -sf gpu < [in.xxxx]
```

Then submit your job:
```bash
$ sbatch vasp.sbatch
```


## Further Reading


  * [[https://www.vasp.at/index.php/documentation|Documentation & Workshop Lectures]]
  * Bow to the Master - [[https://www.nsc.liu.se/~pla/|Peter Larsson]]
    * Read through Peter's blog to gain great insight on how to optimize your VASP runs.
  * [[http://cniu.me/KPAR_and_NPAR_in_VASP/|Interesting article on KPAR and NPAR]]
  
  
