# Tutorial-MPI

> Fer un tutorial sobre MPI per l'assignatura de Computació Distribuida tal i com s'indica a
> _Programación Aplicaciones Paralelas.pdf_

### Introducció MPI
MPI es un estàndard (segueix el paradigma de pas de missatges).

Llenguatges: C, C++ i FORTRAN

Serveix principalment per fer programes paral·lels portables i llibreries paral·leles.

Característiques:
- Thread-safe
- Soporta arquitectures diferents
- Comunicació punt-a-punt
- Comunicació Col·lectiva
- Topologia processos orientat a app
- Profiling

## Instal·lació 

Instal·larem la versió MPICH que és gratuita i que està entre la versió 1 i 2 de MPI.

Per a poder instal·lar MPICH usarem `sudo apt-get install mpich`

## Compilació i execució

Per a poder compilar i obtindre el executable usarem la mateixa comanda de C `gcc -o nom_fitxer_font nom_executable` però en aquest cas en ser una apliació MPICH fem :
````
mpicc -o nom_fitxer_font nom_executable
````

Per la seva execució s'usa `mpiexec` junt amb el executable. 
Aquesta comanda admet diverses opcions:
````
-n N: indica el número de procesos que es vol en la execució del programa. 

-f : fitxer de màquines al que executar-ho (se usa en combinació amb –n). 

-host : especifica els host on se executarà els procesos de l'apliacació
````

## Funcions Bàsiques

Per a fer una aplicació senzilla amb MPI es necessari conèixer aquestes comandes:
- MPI_Init -> Inicia el entorn de MPI
- MPI_Finalize -> Tanca el entorn MPI
- MPI_Common_size -> Retorna el número de processos comunicador (0, ..., n-1)
- MPI_Common_rank -> Retorna el rank del proces.
- MPI_Send -> Envia Missatge
- MPI_Recv -> Rep el missatge

### Authors

-   [Joan Martí](https://github.com/Navy22junda)

### Professorat

-   Fernando Cores

### Eines utilitzades

- [Interfície MPI (versió MPICH)](http://www.mpich.org/downloads/)
- Llenguatge C++
- Cluster Udl

