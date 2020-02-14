#!/bin/bash

echo "> Migrating old CLIfe save files"

echo ">> gel.rtf -> gol.rtf"
if [ -f ./arch/svf/gel.rtf ]; then
    mv ./arch/svf/gel.rtf ./arch/svf/gol.rtf
fi

echo ">> dab.rtf -> rol.rtf"
if [ -f ./arch/svf/dab.rtf ]; then
    mv ./arch/svf/dab.rtf ./arch/svf/rol.rtf
fi
