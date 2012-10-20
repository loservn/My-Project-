#!/bin/bash
pacman -Syu
while [[ $(pacman -Qdtq) ]]
do
	pacman -R $(pacman -Qdtq)
done
