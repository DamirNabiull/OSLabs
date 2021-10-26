rm _ex1_1.txt _ex1_2.txt _ex1.txt ex1.txt
echo "some text" > _ex1.txt
ln _ex1.txt _ex1_1.txt
ln _ex1.txt _ex1_2.txt
ls -i _ex1.txt >> ex1.txt
ls -i _ex1_1.txt >> ex1.txt
ls -i _ex1_2.txt  >> ex1.txt