#include <mpi.h>
#include <iostream>
#include <vector>

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int msg_count;
    if (rank == 0) {
        std::cout << "请输入要处理的数字个数: ";
        std::cin >> msg_count;

        MPI_Bcast(&msg_count, 1, MPI_INT, 0, MPI_COMM_WORLD);

        for(int i = 0; i < msg_count; i++) {
            int val;
            std::cout << "请输入第 " << (i+1) << " 个数字: ";
            std::cin >> val;

            if (val == 3) {
                val += 1;
            }
            MPI_Send(&val, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        }
    }
    else {
        MPI_Bcast(&msg_count, 1, MPI_INT, 0, MPI_COMM_WORLD);

        for (int i = 0; i < msg_count; i++) {
            int v;
            MPI_Recv(&v, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            if (v % 2 == 0) {
                std::cout << "even number\n";
            } else {
                std::cout << "odd number\n";
            }
        }
    }

    MPI_Finalize();
    return 0;
}