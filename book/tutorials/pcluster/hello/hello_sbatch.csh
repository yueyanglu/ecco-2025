#!/bin/csh
#SBATCH -J hello_sbatch
#SBATCH --nodes=2
#SBATCH --tasks-per-node=6
#SBATCH --exclusive
#SBATCH --partition=sealevel-c5n18xl-demand
#SBATCH --time=00:01:00 
#SBATCH --output=hello_job_%j.log
#SBATCH --error=hello_job_%j.log

set nprocs  = 12

mpirun -np ${nprocs}  ./hello
