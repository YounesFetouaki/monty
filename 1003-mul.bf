,          Read the first digit and store it in cell 0
-,         Subtract 48 to convert ASCII to integer
>,         Move to cell 1
,          Read the second digit and store it in cell 1
-,         Subtract 48 to convert ASCII to integer
<<[->>+<<] Multiply the values in cells 0 and 1, store result in cells 0 and 1
>>>++++++ Print the result (cell 0) as a character and add 6 (to print a newline)
.          Print the newline character
