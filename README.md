# Record-and-Selective-Replay-program

# how to run
## install mpi
linux
```bash
sudo apt-get install openmpi-bin
```

macos
```bash
brew install openmpi
```

## run

```bash
mpic++ odd_even_mpi.cpp -o odd_even_mpi
mpirun -np 2 ./odd_even_mpi 2 1
mpirun -np 2 ./odd_even_mpi 3 1 2
```
