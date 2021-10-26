if [ ! -d "./week01" ];
then
	mkdir week01
fi

echo "some data" > ./week01/file.txt

if [ ! -d "./week10" ];
then
	mkdir week10
else
	rm ./week10/_ex2.txt
fi

link ./week01/file.txt ./week10/_ex2.txt

find ./week01/file.txt -inum "$(ls -i ./week01/file.txt | cut -d ' ' -f 1)"  > ./week10/ex2.txt

cat ./week10/ex2.txt

find ./week01/file.txt -inum "$(ls -i ./week01/file.txt | cut -d ' ' -f 1)" -exec rm {} \; >> ./week10/ex.txt
