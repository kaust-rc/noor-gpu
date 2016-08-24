/*
	Lifted from here https://developer.nvidia.com/cuda-education#HelloWorldSample
*/

#include <stdio.h>


__global__ void hello()
{
	printf("hello world, Im thread %d on block %d\n", threadIdx.x, blockIdx.x);
}


int main(void)
{
	int num_threads = 2;

	int num_blocks = 2;

	hello<<<num_blocks,num_threads>>>();
	cudaDeviceSynchronize();

	return 0;
}




