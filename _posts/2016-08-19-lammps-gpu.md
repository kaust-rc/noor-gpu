---
layout: post
title: "LAMMPS on noor-gpu"
date: 2016-08-19 16:25:06 -0700
comments: false
---


# LAMMPS 2016
This version was compiled with GPU support.

To initialize your environment for using LAMMPS, load the associated module.
```bash
$ module load lammps/2016
```
 
To run LAMMPS in batch mode, create a batch submission script called ''lammps.sbatch'' as follows:

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

# This will load lammps module and its dependencies
module load lammps/2016

# Go to your work directory
# ALWAYS run your jobs in your /scratch directory
cd /scratch/$USER/<your_input_directory>

# run lammps with input file
srun --cpu_bind=cores lmp_kaust -sf gpu < [in.xxxx]
```

Then submit your job:
```bash
$ sbatch lammps.sbatch
```

In the command line add ```-sf gpu``` or ```-pk gpu``` switches.

If ```-sf gpu``` switch is not used, you must invoke the package gpu command in your input script or via the ''-pk gpu'' command-line switch.

## XMOVIE Tool

The xmovie tool is an X-based visualization package that can read LAMMPS dump files and animate them. It is available after loading the LAMMPS module. You may run xmovie via:

```bash
$ xmovie options dump.file1 dump.file2 ...
```

If you just type "xmovie" you will see a list of options. Note that by default, LAMMPS dump files are in scaled coordinates, so you typically need to use the -scale option with xmovie as follows:

```bash
$ xmovie -scale dump.indent
```

## Further Reading

  * [Package Commands](http://lammps.sandia.gov/doc/package.html)
  * [LAMPS on GPU Documentation](http://lammps.sandia.gov/doc/accelerate_gpu.html)

