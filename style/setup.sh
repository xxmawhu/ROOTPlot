#!/bin/sh
PLOTSTYLE="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
sed "s:PATH_TO_THIS:${PLOTSTYLE}:"  ${PLOTSTYLE}/rootrc/rootlogon.C >~/.rootlogon.C 
