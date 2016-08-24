# Introduction to CUDA on Noor GPU


Some information from [Nvidia Developer Zone](https://developer.nvidia.com/accelerated-computing-training)

[Good video](https://youtu.be/Ed_h2km0liI) to start writing CUDA.


Nvidia provides some great samples:
```
#Copy the nvidia-samples from /opt/share to user home
cp -r /opt/share/cuda/7.5/NVIDIA_CUDA-7.5_Samples/ ~
cd ~/NVIDIA_CUDA-7.5_Samples/

#Compile all the samples  (this takes some time)
module load cuda mpich gcc
make

#Run a sample, should return useful information about the GOU cards
cd ~/NVIDIA_CUDA-7.5_Samples/1_Utilities/deviceQuery
./deviceQuery
```



# Cuda Hello World
