# integer pointer calulation question in c

#### write up for an exam question I recieved as part of my Programming Fundamentals course

## question
write a program that given the user input *n* and *k* from the command line, generate *n* numbers, starting at a randomly generated number, where each number is the sum of the previous *k* numbers (or all the previous if there have been less than *k* numbers generated). You may not use indexes, only pointers.

## write up
I approached this question understanding I would have to use the `malloc` function to allocate space in memory that could contain all of the integers I would be generating. So I started with this line;
```c
int* firstPointer = malloc(sizeof(int) * n);
```
this would be where I would read and write all the generated numbers to. Next up I would have to write a for loop that would walk through the entire allocated memory to write the appropriate numbers to it. I originally did it like this;
```c
for (int* currentPointer = firstPointer+4; currentPointer < endPointer; currentPointer+=4){
	//loop code here
}
```
this would set a variable `currentPointer` to 4 bytes (1 integer) after the first point (as the first integer was already set by the random generator). It would then walk through all the integers increasing by 4 bytes each time before reaching the end of the allocated memory. However this would give me a seg fault later on in the code when I was attempting to print, an inspection in valgrind then showed the problem wasn't with the reading but rather with the writing and that I was writing outside of the buffer that I allocated earlier. In my frustration and due to the time constraint of the exam I just allocated far more memory than I needed and called it a day. This worked but in hind sight it was also very inefficient and kind of negated the point of dynamic memory allocation with malloc. After some investigation after the exam I found out that the pointer math did not work how I expected it to. In the for loop I increased the pointer address by 4 each time as I expected it to move 4 bytes (the size of an int) but I was instead moving 4 ints forward and so was writing to memory after the allocated memory, so after fixing this and some other lines it began working.