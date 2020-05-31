#include <stdio.h>
#include <mpi.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  int rank, i, count, j = 0;
  int data[128], value[256];
  double t1, t2, avg;
  bool f = true; //Bool per detectar si toca recv o send

  MPI_Init(&argc, &argv);

  MPI_Status status;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);//Cada proces tindrà un rank diferent

  while (j < 200) {//200 missatges cada proces entra 200 cops= 100 rev i 100 send
    if(rank == 1 && f == true){//Proces 1
      for(i = 0; i < 128; i++) data[i] = i;
      t1 = MPI_Wtime();
      MPI_Send(data, 128, MPI_INT, 0, 22, MPI_COMM_WORLD);
      f = false;
    }else if(rank == 1 && f == false){
      MPI_Recv(value, 256, MPI_INT, MPI_ANY_SOURCE, 22, MPI_COMM_WORLD, &status);
      t2 = MPI_Wtime();
      f = true;
    }else if(rank == 0 && f == false){//Proces 0
      t1 = MPI_Wtime();
      for(i = 0; i < 128; i++) data[i] = i;
      MPI_Send(data, 128, MPI_INT, 1, 22, MPI_COMM_WORLD);
      f = true;
    }else{
      MPI_Recv(value, 256, MPI_INT, MPI_ANY_SOURCE, 22, MPI_COMM_WORLD, &status);
      t2 = MPI_Wtime();
      f = false;
    }
    avg = (t1 - t2) / 2;
    printf("%f\n", avg);
    j++;
  }

  MPI_Finalize();
  return 0;
}
