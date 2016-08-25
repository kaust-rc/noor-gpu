mpi-device-query
================


mpi device query is a small utility to test the slurm allocation is correct.


```bash
ssh noor-gpu

#After logging into noor-gpu cluster
module load git cuda mpich
git clone https://github.com/kaust-rc/noor-gpu
cd noor-gpu
git checkout master
cd mpi-device-query
make
sbatch test.sbatch

# Use sjobs to review the job then

cat slurm-<jobId>



```
