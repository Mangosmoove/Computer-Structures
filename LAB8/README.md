1. How many characters do you see printed on screen?
   I saw 2.
   
2. What happened to the executing program? Explain.
   It printed out two characters and then it just didn't print out the last character. It got stuck and I had to ctrl+c out of it.
   
3. You are allowed to add a single line which is a semaphore related function to the code to make sure your code prints all three
   characters. Add that line and comment it with // FIX for code issue. Add an extraction of the code where you added the FIX on the 
   README file. Note that you're only allowed to add a line. NOT alter any lines.
   sem_post(&s);
