# -*- coding: utf-8 -*-
import sys

def even_odd():
    try:
        assert len(sys.argv) == 2
    except AssertionError:
        print('AssertionError: more than one argument is provided')
        return
    try:
        if int(sys.argv[1])%2 == 0:
            print("I'm Even")
        else:
            print("I'm Odd")
    except ValueError:
        print('Not an integer')


even_odd()
