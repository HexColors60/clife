#!/usr/bin/env sh
gold=`cat arch/svf/gol.rtf`
loca=`cat arch/svf/loc.rtf`
moti=`cat arch/svf/mot.rtf`
name=`cat arch/svf/nom.rtf`
role=`cat arch/svf/rol.rtf`

conf="[GOLD]=$gold[LOCA]=$loca[MOTI]=$moti[NAME]=$name[ROLE]=$role"

echo "$conf" > arch/svf/svf.rtf
