#!/bin/sh
PLOTSTYLE="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
echo $PLOTSTYLE
sed "s:PATH_TO_THIS:${PLOTSTYLE}:"  ${PLOTSTYLE}/rootrc/rootlogon.C >~/.rootlogon.C 
