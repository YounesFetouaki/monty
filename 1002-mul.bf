,          Read the first digit and store it in cell 0
-,         Subtract 48 to convert ASCII to integer
>,         Move to cell 1
,          Read the second digit and store it in cell 1
-,         Subtract 48 to convert ASCII to integer
<,         Move back to cell 0
[          Start a loop
    >,     Move to cell 2
    [      Start a loop
        ->+>[-]<[->>+<<]
        >[<->-]
    ],     End the inner loop
    <[-]>  Clear cell 2
    <-     Move back to cell 0
    [->+<] Multiply cell 0 by cell 1, store result in cell 0, and move to cell 2
    ->     Move to cell 2
    <.     Print the result as a character
    >>[-]  Clear cells 0 and 1
    <-     Move back to cell 0
    ,      Read the first digit (for the next multiplication) and store it in cell 0
    -,     Subtract 48 to convert ASCII to integer
]          End the outer loop
