echo "some data" > _ex3.txt

chmod 666 _ex3.txt -v > ex3.txt

echo " " >> ex3.txt

chmod u=rwx _ex3.txt -v >> ex3.txt
chmod o=rwx _ex3.txt -v >> ex3.txt

echo " " >> ex3.txt

chmod g=u _ex3.txt -v >> ex3.txt

echo " " >> ex3.txt

echo "Answers:" >> ex3.txt
echo "660 - read and write for user and group, nothing for other" >> ex3.txt
echo "775 - all for user and group, reand and exeecute for other" >> ex3.txt
echo "777 - all for user, group, and other" >> ex3.txt
