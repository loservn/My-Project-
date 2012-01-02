ssh -T git@github.com
echo "you want to add or remove ? (a/r)"
read ans
echo "please enter your file you will commit"
read file_name  
echo "you describe you file: "
read describe
if [$ans -eq 'a']; then
 git add $file_name
else 
 exec "git rm $file_name"
fi
git commit -m $describe
git remote add origin git@github.com:NgoHuy/My-Project-.git 
git push origin master
