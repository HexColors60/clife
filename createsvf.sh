#!/usr/bin/env sh
gold=`cat arch/svf/gol.rtf`
loca=`cat arch/svf/loc.rtf`
moti=`cat arch/svf/mot.rtf`
name=`cat arch/svf/nom.rtf`
role=`cat arch/svf/rol.rtf`

conf="[GOLD]=$gold[LOCA]=$loca[MOTI]=$moti[NAME]=$name[ROLE]=$role"

echo "GOLD=$gold" > arch/svf/svf.rtf
echo "LOCA=$loca" >> arch/svf/svf.rtf
echo "MOTI=$moti" >> arch/svf/svf.rtf
echo "NAME=$name" >> arch/svf/svf.rtf
echo "ROLE=$role" >> arch/svf/svf.rtf

# echo -n "$conf" > arch/svf/svf.rtf
