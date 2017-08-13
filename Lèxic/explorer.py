#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import re

filetext = ""

def myFunction (txt):
    print ("m'agradaria poder debuggegar ;)")

prog = re.compile ("d")
result = prog.match (filetext)

# Inicialitzem el fitxer i el enviem a ser treballat.
if __name__ == "__main__":
    arg = sys.argv[1:]
    if arg:
        try:
            textfile = open (arg[0], 'r')
        except IOError:
            print ("Error!!\nEl fitxer: ", arg[0], "\nNo existeix.")
            sys.exit (1)
        filetext = textfile.read ()
        textfile.close ()

        myFunction (filetext)
        sys.exit (0)
    else:
        # Error amb accent "introduit", no se com arreclar-ho
        print ("Error!\nNo s'ha intruduit un fitxer.")
        sys.exit (2)
