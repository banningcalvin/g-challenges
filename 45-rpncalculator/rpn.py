#!/usr/bin/env python

import sys

def rpn(args):
    stack = []
    operators = ["+", "-", "*", "/"]

    for atom in args:
        if(atom not in operators):
            stack.append(int(atom))
        else:
            op1 = stack.pop()
            op2 = stack.pop()
            if(atom == "+"):
                stack.append(op2 + op1)
            if(atom == "-"):
                stack.append(op2 - op1)
            if(atom == "*"):
                stack.append(op2 * op1)
            if(atom == "/"):
                stack.append(op2 / op1)
    return stack[0]



def main():
    print("Enter a string in Reverse Polish Notation or type exit\n")
    equation = raw_input("> ")
    while(equation != "exit"):
        print(rpn(equation.split(" ")))
        equation = raw_input("> ")
    sys.exit()

if __name__ == "__main__":
    main()
