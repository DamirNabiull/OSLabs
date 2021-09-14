read -p 'Number N: ' N
gcc ex1.c -o ex1.o
for ((i=0; i<N; i++))
do
    ./ex1.o
done 
