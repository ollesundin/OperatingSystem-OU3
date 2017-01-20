#!/bin/sh

for i in {1..10}
do
    ./a.out ./test_${i}.txt 1000000000 >> largeFileNOOP.txt & 
done


for i in {1..33}
do
    ./a.out ./test_${i}.txt 100000000 >> mediumFileNOOP.txt &
	./a.out /home/user/Downloads/test_${i}.txt 100000000 >> mediumFileNOOP.txt &
    ./a.out /home/user/Desktop/ollesKernel/kernel/linux/test_${i}.txt 100000000 >> mediumFileNOOP.txt &
done

for i in {1..333}
do
    ./a.out ./test_${i}.txt 10000000 >> smallFileNOOP.txt &
	./a.out /home/user/Downloads/test_${i}.txt 10000000 >> smallFileNOOP.txt &
    ./a.out /home/user/Desktop/ollesKernel/kernel/linux/test_${i}.txt 10000000 >> smallFileNOOP.txt &
done

wait
echo complete
