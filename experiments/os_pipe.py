#!/usr/bin/python3
# tutorialspoint.com/python3/os_pipe.htm
# cython > how to use Cyton to compile Python 3 into C

import os, sys, time

def main():
    print("The child will write text to a pipe and \n the parent will read the text written by child.")

    # File descriptors r, w for reading and writing
    r,w = os.pipe()

    pid = os.fork()
    if pid: # Parent
        # Closes file descriptor w
        os.close(w)
        r = os.fdopen(r, 'r')
        print("Parent reading")
        str = r.read()
        print("text =", str)
        sys.exit(0)
    else:
        os.close(r)
        w = os.fdopen(w, 'w')
        print("Child writing")
        w.write("El que tinc ganes d'escirure")
        w.close()
        print("Child closing")
        sys.exit(0)
