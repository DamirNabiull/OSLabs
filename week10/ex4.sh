if [ ! -d "./tmp" ];
then
	mkdir tmp
else
	rm ./tmp/link1
	rm ./tmp/file1
	rm ./tmp/file2
fi

> ./tmp/file1
> ./tmp/file2

link ./tmp/file1 ./tmp/link1

gcc ex4.c -o ex4

./ex4 > ex4.txt