cd ~/My-Project-
ssh -T git@github.com
echo "you want to add or remove ? (a/r)"
read ans
echo "please enter your file you will commit"
read file_name
echo "you describe you file: "
read -e describe
if [ $ans = 'a' ];
then
 git add $file_name
fi
if [ $ans = "r" ];
then
 git rm $file_name
fi
git commit -m "$describe"
git remote add origin git@github.com:NgoHuy/My-Project-.git
git push origin master
