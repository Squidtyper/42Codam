# -*- coding: utf-8 -*-
import sys
import string


def main() -> int:
    if len(sys.argv) < 2:
        print("Please provide an argument.")
        return 1
    if len(sys.argv) > 2:
        print("AssertionError")
        return 1

    n_char = len(sys.argv[0])
    n_upper = sum(1 for c in sys.argv[1] if c is c.isupper())
    n_lower = sum(1 for c in sys.argv[1] if c is c.islower())
    n_punct = sum(1 for c in sys.argv[1] if c in string.punctuation)
    n_spaces = sum(1 for c in sys.argv[1] if c in string.whitespace)
    n_digits = sum(1 for c in sys.argv[1] if c in string.digits)

    print(f"The text contains {n_char} characters:\n\
{n_upper} upper letters\n\
{n_lower} lower letters\n\
{n_punct} punctuation marks\n\
{n_spaces} spaces\n\
{n_digits} digits")
    return 0


if __name__ == '__main__':
    main()
