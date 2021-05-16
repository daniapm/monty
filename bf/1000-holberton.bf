[ This program prints "Holberton" and a newline to the screen, its
  length is 106 active command characters. [It is not the shortest.]

]
++++++++               Set Cell #0 to 8
[
    >++++               Add 4 to Cell #1; this will always set Cell #1 to 4
    [                   as the cell will be cleared by the loop
        >++             Add 2 to Cell #2
        >+++            Add 3 to Cell #3
        >+++            Add 3 to Cell #4
        >+              Add 1 to Cell #5
        <<<<-           Decrement the loop counter in Cell #1
    ]                   Loop till Cell #1 is zero; number of iterations is 4
    >+                  Add 1 to Cell #2
    >+                  Add 1 to Cell #3
    >-                  Subtract 1 from Cell #4
    >>+                 Add 1 to Cell #6
    [<]                 Move back to the first zero cell you find; this will
                        be Cell #1 which was cleared by the previous loop
    <-                  Decrement the loop Counter in Cell #0
]                       Loop till Cell #0 is zero; number of iterations is 8

The result of this is:
Cell No :   0   1   2   3   4   5   6
Contents:   0   0  72 104  88  32   8
Pointer :   ^

>>.                     Cell #2 has value 72 which is 'H'
>+++++++.               111 es o celda(3)
---.                    108 que es l celda (3)
----------.             98 que es b celda (3)
+++.                    101 que es la el celda(3)
+++++++++++++.          114 que es 0 celda(3)
++.                     116 que es d celda(3)
-----.                  111 que es 0 celda(3)
-.                      110 que es n celda (3)
>>>++.                  salto de linea celda (6)