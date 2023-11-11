# push_swap


The goal of the project was to create a program that sorts any amount of numbers from smallest to largest using only two stacks. This had to be done with as little moves as possible.

**Allowed moves:**

sa = Swap two first numbers of stack A

sb = Swap two first numbers of stack B

ss = sa and sb at once

pa = Push first number of stack A to the top of stack B

pb = Push first number of stack B to the top of stack A

ra = Moves all numbers in stack A by one. First number moves to be last one

rb = Moves all numbers in stack B by one. First number moves to be last one

rr = ra and rb at once

rra = Moves all numbers in stack A by one. Last element moves to be first one

rrb = Moves all numbers in stack B by one. Last element moves to be first one

rrr = rra and rrb at once

---

I approached this project by thinking what could be the most efficient way to keep the move count low. 

This was also a great introduction to linked lists as my implementation creates the stack A and stack B as two separate linked lists.

What I ended up doing is that after every move the program counts for each number in stack A, starting from the top, how many moves/rotations would it take in stack A and stack B to push (pb) the number into right position in stack B. After checking a number, the rotation count of stack A and stack B will be compared to the current lowest rotations and if the new result is lower, then those rotations will be saved.

When the program has checked the numbers, it will start to do the rotations that were saved as the lowest count ones. It will get the number to the top of stack A and stack B will rotate to the right position for that number and then it will be pushed from the top of stack A to stack B.

In this way the numbers in stack B will always be in right order and in the end all numbers will be pushed (pa) back to stack A and stack A is then sorted.

If the numbers are 3 or less there is a separate simple function to solve this. That is why three highest numbers are saved and those are never pushed to stack B as they can be sorted easily after there is only 3 numbers left on stack A.

push_swap also uses libft, a function library that has been made as a previous project.

---

**How to use**

Go to push_swap folder and type "make". Then run ./push [numbers you want to sort]

After this program will give a list of previously mentioned moves that would sort the given numbers.

---


After this program will give a list of previously mentioned moves that would sort the given numbers.
