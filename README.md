parser: Grampower
=========

Parser is a C source simple state machine parser.

 - To compile the code, open file directory, enter `make` in terminal
 - To run the code, enter `make run` in terminal
 - To run test cases, enter `make test` in terminal - this runs all border test cases
 - Type some input string and press `enter`
 - `parser` cheks for 'hello' in input 
 - Prints if found, continues if not found
   
  
Implementation
--------------
**A**.	The string needed to be parsed is saved in a variable named ‘string’ and the success_state, i.e., the state denoting that the string was found, is defined as the length of the string to be parsed. 

**B**.	The first input character is taken from the command line and compared with the first character of string. One of the following can occur:
>a.	The characters match and hence the value of state and the index of the string are incremented by 1. Following this any one of the following can occur:
>* 	The next set of characters match and the state and index is incremented.
>* 	The next set of character do not match and the input character 
And the input character is same as the first character of the string wherein the state is set to 1.
>*	The next set of character do not match and the input character is not same as the first character of the string, in which case the state is set to the initial state, i.e., state=0.

>>b.	The characters do not match and the state remains unchanged, i.e, the initial state and the program takes the next character from the command line.

**C**.	Once the state becomes equal to the success_state (end of the string to be parsed), a variable called ‘helloFound’ is set to 1 in which case the program stops execution, indicating that the string was found in the input stream of characters.
