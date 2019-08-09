#!/bin/bash
>timeOut/testC
cd C
make
#for i in {1..10};do
	make run #>> ../timeOut/testC
#done
cd ..
#./stripTime.py ./timeOut/testC >> Times.txt
