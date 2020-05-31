#include <stdio.h>
#include <mpi.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  MPI_Init(&argc, &argv); //Se li passa el argument del programa per a que pugui distribuïr el treball

  int rank, len;
  char name[MPI_MAX_PROCESSOR_NAME];

  MPI_Comm_rank( MPI_COMM_WORLD, &rank );
  MPI_Get_processor_name(name, &len);
  printf("Hola Mundo Paralelo!, nom executable %s, el num pid %i, num rang %i, maquina %s\n", argv[0], getpid(), rank, name);

  MPI_Finalize();
  return 0;
}
