<b>Sudoku solver with C</b><br>



this C code solve 9-by-9 sudokus<br><br>
the algorithm is based on recursive functions<br><br>
here is the method:<br>
1-enumerating all empty cells<br>
2-'current cell' is the first cell in the enumeration<br>
3-we enter 1 into the current cell if this breaches the sudoku conditions, try entering 2 if not 3 and so on; until:<br>
	3.1-the entry does not breach game conditions,or<br>
	3.2-We have reached 9 and still breach game rulee<br>
4-in case 3.1: if the current cell was the last empty one so the puzzle solved if not then we go back to step 2 with the current cell set to next cell<br>
in case 3.2: if the current cell is the first cell in enumeration so puzzle doesn't have a solution if not then we erase 9 from current cell and<br>
set the previous cell to the current cell and go to step 3





write your unsolved sudoku in the code as variable 'sdk' which comes at the beginning of the code(don't change 'sdk_')
