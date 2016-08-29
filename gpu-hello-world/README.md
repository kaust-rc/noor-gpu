#This small tutorial returns a hello-world from a gpu kernel


This will compile and run a hello-world on a gpu on one of gpu nodes.


As usual to start with
```
    ssh noor-gpu
```
then
```bash
cd ~
module load git cuda
git clone https://github.com/kaust-rc/noor-gpu
cd noor-gpu/
git checkout master
cd gpu-hello-world/
nvcc hello-world.cu -o hello-world
./hello-world


#Submit as job to cluster
sbatch hello-world.slurm
```



And look at the file ```gpu.out``` .. to see the output





