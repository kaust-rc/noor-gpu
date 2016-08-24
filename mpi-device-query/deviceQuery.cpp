/*
 * This software contains source code provided by NVIDIA Corporation.
 */


// Shared Utilities (QA Testing)
//#define MPI_CHECK(call) \
  //  if((call) != MPI_SUCCESS) { \
    //    cerr << "MPI error calling \""#call"\"\n"; \
      //  my_abort(-1); }


#define MPI_CHECK(call) call
#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <iostream>
#include <cuda_runtime.h>
#include <helper_cuda.h>
#include <mpi.h>

int *pArgc = NULL;
char **pArgv = NULL;

#if CUDART_VERSION < 5000

// CUDA-C includes
#include <cuda.h>


// This function wraps the CUDA Driver API into a template function
template <class T>
inline void getCudaAttribute(T *attribute, CUdevice_attribute device_attribute, int device)
{
    CUresult error =    cuDeviceGetAttribute(attribute, device_attribute, device);

    if (CUDA_SUCCESS != error)
    {
        fprintf(stderr, "cuSafeCallNoSync() Driver API error = %04d from file <%s>, line %i.\n",
                error, __FILE__, __LINE__);

        // cudaDeviceReset causes the driver to clean up all state. While
        // not mandatory in normal operation, it is good practice.  It is also
        // needed to ensure correct operation when the application is being
        // profiled. Calling cudaDeviceReset causes all profile data to be
        // flushed before the application exits
        cudaDeviceReset();
        exit(EXIT_FAILURE);
    }
}

#endif /* CUDART_VERSION < 5000 */

////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int
main(int argc, char **argv)
{
    pArgc = &argc;
    pArgv = argv;

    // Initialize MPI state
    MPI_CHECK(MPI_Init(&argc, &argv));

    // Get our MPI node number and node count
    int commSize, commRank;
    MPI_CHECK(MPI_Comm_size(MPI_COMM_WORLD, &commSize));
    MPI_CHECK(MPI_Comm_rank(MPI_COMM_WORLD, &commRank));



    int deviceCount = 0;
    cudaError_t error_id = cudaGetDeviceCount(&deviceCount);

    if (error_id != cudaSuccess)
    {
        printf("cudaGetDeviceCount returned %d\n-> %s\n", (int)error_id, cudaGetErrorString(error_id));
        printf("Result = FAIL\n");
        exit(EXIT_FAILURE);
    }

    // This function call returns 0 if there are no CUDA capable devices.
    if (deviceCount == 0)
    {
        printf("There are no available device(s) that support CUDA\n");
    }

    int dev;
    std::ostringstream ss;

    char hostname[32];
    gethostname(hostname, 32);
    if (deviceCount > 0 ){
        ss << "Host " << hostname;
        ss << "  Rank " << commRank;
        ss << " of " << commSize;
        ss << ". Devices " << deviceCount << "; PCIBusId: ";

        for (dev = 0; dev < deviceCount; ++dev)
        {
            cudaSetDevice(dev);
            cudaDeviceProp deviceProp;
            cudaGetDeviceProperties(&deviceProp, dev);
            //cudaDeviceGetPCIBusId ( char* pciBusId, int  len, int  device );
            //printf("  Device PCI Domain ID / Bus ID / location ID:   %d / %d / %d\n", deviceProp.pciDomainID, deviceProp.pciBusID, deviceProp.pciDeviceID);
            //printf("(%s loc:%d) ", deviceProp.name, deviceProp.pciBusID);
            //
           ss << deviceProp.pciBusID << " ";
        }
        ss << "\n";
        std::string result = ss.str();
        std::cout << result;
    } else {
        printf("Node %d of %d: No GPU found\n", commRank, commSize);
    }


    cudaDeviceReset();
    MPI_CHECK(MPI_Finalize());
    exit(EXIT_SUCCESS);
}
