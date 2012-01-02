sudo pacman -Syu 
while [ `pacman -Qdtq`]; do
 sudo pacman -R `pacman -Qdtq`
done 
