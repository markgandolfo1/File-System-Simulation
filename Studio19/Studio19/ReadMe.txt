studio 19 answers here

1. Mark Gandolfo and Julian Nussenzweig

2. First, I created a TextFile and appended a vector with one element, '1'. Then, I read the file using read() and printed out the 
results to test to see if the read() function worked properly - '1' was correctly printed out. Next, I called write() on the TextFile 
using a modified vector as the parameter - the vector contained the elements '1' and '2'. I then tested this by reading the file using 
read() and printed out the results - '1' and '2' were correctly printed out.

3. When we want to see how a file a displayed, we can created an abstract file visitor to "visit" the file. The file, whether it is a
TextFile, ImageFile, or another file, can accept the file visitor and then interact with its corresponding visit function 
(i.e. visit_TextFile). This method then properly outputs the display without having the add a display function to the AbstractFile
interface, therefore preventing the class from taking on too much responsibility.

4. 