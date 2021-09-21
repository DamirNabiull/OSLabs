if ! (test -f ex2.txt ); then
    printf 0 >> ex2.txt
fi

while true
do
    printf "\n$(($(tail -n 1 ex2.txt) + 1))" >> ex2.txt
done