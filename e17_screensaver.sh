#!/bin/bash
while [[ 1 ]]
 do 
	idle=$(/home/dragon/xprintidle/./idle)
 	if [ $idle -eq 300 ] ; then 
	enlightenment_remote -desktop-lock
	xset dpms force off	
	continue	
	fi 
done

