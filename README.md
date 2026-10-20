"# Corner-Grocer-Item-Tracking-Program" 

### Summarize the project and what problem it was solving.
This is a program that analyzes the text records that “Corner Grocer” generates throughout the day. The program lets them know how often items are purchased so they can create the most effective layout for their customers.

### What did you do particularly well?
I think the object-oriented design turned out well. Splitting everything into a separate GroceryItem class made the code much easier to manage. Using a C++ std::map also made counting and looking up items easier. Also adding a capitalization helper kept duplicate entries from showing up just because of messy casing in the text file.

### Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
Even though I fixed the issues that were pointed out, I could still make the error handling better. Like if the input text file is missing or gets corrupted, adding stronger checks would keep the program from crashing unexpectedly. 

### Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
The trickiest part for me was handling file input and making sure the program didn't go into an infinite loop if a letter is typed  instead of a number on the menu. I had to look up how `cin.clear()` and `cin.ignore()` work to clear out bad input properly. For my support network, I relied on the ZyBooks course material.

### What skills from this project will be particularly transferable to other projects or course work?
Building a separate class with its own header and source files (`.h` and `.cpp`) gave me a really good grasp of object-oriented programming and keeping code organized. Getting comfortable using `std::map` and working with file streams (`ifstream` and `ofstream`) are also practical skills I know I'll use a lot in future coding classes.

### How did you make this program maintainable, readable, and adaptable?
I kept the code organized by splitting things up—keeping the data inside the GroceryItem class and putting the main logic in main(). Using clear variable names, setting up constants for the menu choices, and writing a helper function to fix up capitalization all make the code much easier to read. Adding comments to every function also means anyone looking at the code later can easily see what it's supposed to do.
