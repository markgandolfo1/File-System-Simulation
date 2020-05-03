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

4. Delegation helps prevent one class from taking on too much responsibility by assigning duties to other classes. The visitor pattern 
uses delegation in that it pushes off the display functionality to a separate class, AbstractVisitor, rather than forcing AbstractFile
to be responsible for it - AbstractFile already had enough duties, and incorporating a display functionality would clutter the interface.
Now, the codehas much been readability and functionality.

5. If we were to add a new concrete file type that should be visitable, we would have to override the accept function in the new concrete 
file object's cpp. Additionally, we would have to add a new visit_<file_type> function for every new concrete object in the 
AbstractFileVisitor class. Hence, a negative consequence of the visitor pattern is that the AbstractFileVisitor could have to support 
a ton of function, to the point where it s cluttered. When there are a lot of different concrete file types, this pattern would not be a 
good idea.


Studio 20.

2. it is important to delete the files because this could lead to memory leaks which could mean errors when compiling
3. the tests i preformed created a password proxy and used the proxy to create, writing and displaying files. 
this was the output:
"Input a Password: pass
Input a Password: pass
test"
it asks for a password after attempting to write and attempting to display

Studio 21:

1. Mark Gandolfo and Julian Nussenzweig

2. It is important to declare a virtual destructor in the base class so that the derived object gets correctly destructed - by having the
virtual destructor in the base class, the derived object will first be destructed, and then the base object will be destructed.

3. The command prompt is very flexible and reusable because it iteracts with an abstract file system and an abstract file factory.
Because of this, we can use different types of file systems and factories without having to change the command prompt. Had we chosen to
have the cmmand prompt iteract with the simple file factory and the simple file system instead, it would not be nearly as flexible. Since
the command prompt does not know which concrete classes it is interacting with, the command prompt be easily configured.

4. First, I dynamically created a simple file system, a system file factory, a touch command, and a command prompt linked the 
aforementioned factory and system. I then added a command called "touch". Within the command line, I tested the 'q' command - it 
successfully quit when I did this. I also tested 'help', which listed the commands successfully (touch). Then, I tested "help touch",
where it properly printed out a description of the touch command. Finally, I created a file called "hi.txt" using the touch command, 
and was able to successfuly open the file afterwards.

	SimpleFileSystem* sys = new SimpleFileSystem();
	SimpleFileFactory* fact = new SimpleFileFactory();
	TouchCommand* touch = new TouchCommand(sys,fact);
	CommandPrompt* com = new CommandPrompt();
	com->setFileSystem(sys);
	com->setFileFactory(fact);
	com->addCommand("touch",touch);
	com->run();