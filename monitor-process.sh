#!/bin/bash

pid=$(ps -eo pmem,pid,cmd | sort -n -r | head -1 | awk '{printf("%d",$2)}')
mem_used=$(ps -eo pmem,pid,cmd | sort -n -r | head -1 | awk '{printf("%d",$1)}')
name=$(ps -eo pmem,pid,cmd | sort -n -r | head -1 | awk '{printf("%s",$3)}')

while [[ 1 ]]
do
	if [ $mem_used -gt 80 ] ; then
		kill $pid
	        $name &
	fi
	sleep 10
done
