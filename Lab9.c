#include<stdio.h>
#include<mpi.h>
int main(int argc , char**argv){
    int rank,sum,prod,min,max,value;
    MPI_Init(&argc , &argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    value=rank+1;
    MPI_Reduce(&value,&sum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
    MPI_AllReduce(&value,&prod,1,MPI_INT,MPI_PROD,0,MPI_COMM_WORLD);
    MPI_AllReduce(&value,&max,1,MPI_INT,MPI_MAX,0,MPI_COMM_WORLD);
    MPI_AllReduce(&value,&min,1,MPI_INT,MPI_MIN,0,MPI_COMM_WORLD);
    if(rank==0)
      
      printf("Reduce SUM(only root):%d\n",sum);
    printf("AllReduce PROD(rank %d):%d\n",rank,prod);
    printf("AllReduce MAX(rank %d):%d\n",rank,max);
    printf("AllReduce MIN(rank %d):%d\n",rank,min);
    MPI_Finalize():
    return 0;
}
