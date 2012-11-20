#!/bin/bash
pacman -Syu
if [[ $(pacman -Qdtq) ]] ; then
	
	while [[ $(pacman -Qdtq) ]]
	do
		pacman -R $(pacman -Qdtq)
	done
else echo "Nothing to remove"
fi
