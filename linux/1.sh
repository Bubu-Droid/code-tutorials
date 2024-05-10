#!/bin/bash
echo "Hello World"

# name="bubu"
# age=17

# echo "name:" $name", age:" $age

# read title

# echo "Your title:" $title

# read -p "Enter your age: " age

# echo "Your age is:" $age

# read -sp "Enter your password: " passwd

# echo "Your password is:" $passwd

# current_dir=`pwd`
# current_dir=$(pwd)
# echo "Your current directory is:" $current_dir

# newfile=$(cat > hello.txt)
# current_dir=$(pwd)
# disp_file=$(cat hello.txt)

# echo $newfile
# echo $disp_file

# echo $0
# echo $1
# echo $2
#
# echo $@
# echo $#
#
# name=$1
# echo $name "and total of" $# "that are" $@

read -p "Enter no 1: " n1
# read -p "Enter no 2: " n2
# read -p "Enter no 3: " n3

# echo "Add:" $((n1 + n2))
# echo "Sub:" $((n1 - n2))
# echo "Mul:" $((n1*n2))
# echo "Div:" $((n1/n2))
# echo "Mod:" $((n1%n2))
# echo "Inc:" $((n1++))
# echo "Inc2:" $((++n1))

# if [ $n1 -gt $n2 -a $n2 -gt $n3 ]
# then
#
# echo "good"
#
# fi
#
# if [ $n1 -gt $n2 -o $n2 -gt $n3 ]
# then
#
# echo "bad"
#
# fi

# if [ $n1 -lt 18 ]
# then
#
# echo "Can't vote"
#
# elif [ $n1 -eq 18 ]
# then
#
# echo "Apply for voter ID card"
#
# else
# echo "Can vote"
#
# fi

# case $n1 in
#     A)
#         echo "91-100"
#         ;;
#     B)
#         echo "81-90"
#         ;;
#     C)
#         echo "71-80"
#         ;;
#     *)
#         echo "Below 70"
# esac
#

namearr=("horipodo krishno" bubu avi anshu)
#
# echo ${namearr[0]}
#
# echo ${namearr[*]}
#
# echo ${namearr[@]}

# for((i=0;i<=5;i++)){
#     echo ${namearr[$i]}
# }
#
# for i in 1 2 3 4 5 6 7 8 9 10
# do
#     echo "Iteration:" $i
# done
#
# for i in bubu avi anshu
# do
#     if [ $i == avi ]
#     then
#         echo "Avigyan"
#     fi
# done
#
# for((i=0;i<=3;i++)){
#     echo ${namearr[i]}
# }

i=0
# while [ $i -le 3 ]
# do
#     echo ${namearr[$i]}
#     let i++
# done

# until [ $i -ge 3 ]
# do
#     echo "Bubu"
#     let i++
# done
#
# until [ $i -ge 11 ]
# do
#     echo $((5*$i))
#     let i++
# done

# for((i=0;i<=10;i++)){
#     if [ $i -eq 5 ]
#     then
#         continue
#     elif [ $i -eq 8 ]
#     then
#         break
#     else
#         echo $i
#     fi
# }

# for((i=0;i<=2;i++)){
#     echo $(mkdir -v $n1$i)
# }
#
# for((i=0;i<=2;i++)){
#     echo $(rm -rf -v $n1$i)
# }

# greetings(){
#     echo "good morning"
# }
#
# greetings
#
# sum(){
#     a=$1
#     b=$2
#     c=$(($1+$2))
#     echo "The value of the sum of" $a "and" $b "is =" $c
#     echo $0
# }
#
# sum 12 23

# sub(){
#     a=$1
#     b=$2
#     c=$(($1-$2))
#     return $c
# }
#
# sub 13 12
# sub 15 12
# ret=$?
#
# echo $ret

# read -p "Enter repo link: " repolink
#
# gitrepo(){
#     echo "getting repository..."
#     git clone $repolink
# }
#
# gitrepo


