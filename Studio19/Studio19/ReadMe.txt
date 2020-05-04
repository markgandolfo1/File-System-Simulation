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
Now, the code has much been readability and functionality.

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
have the command prompt iteract with the simple file factory and the simple file system instead, it would not be nearly as flexible. Since
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

Lab 5:

1. Mark Gandolfo and Julian Nussenzweig

We worked on everything together over Zoom screen sharing and took turns for who would type alternating between each studio or lab5 part.

We did not run into any errors or warnings. These are some of the tests we ran:

1. We ran every command by passing "correct"/ideal arguments, and they all performed correctly.

2. $  cat

We ran the cat command with no arguments and it correctly outputted "command failed".

3. $  rn

We ran the rn command with no arguments and it correctly outputted "command failed".

4. $  rn hi.txt yo

We ran the rn command with a file that does not exist and it correctly outputted "command failed".

5.  $  cp og.txt second
	$  cat og.txt
	sup
	:wq
	$  ds og.txt
	$  ds second.txt

We tested the above lines to make sure that writing to the copy does not change the original, and it correctly does not.

6. $  touch false

We ran the touch command and provided a file name without the extension and it correctly outputted "command failed".

7. $  ds hi.img -d

Correctly outputs unformatted image file

8. $  ds hi.img

Correctly outputs formatted image file

9. $  rm no.txt

Removing a file that does not exist correctly outputs command failed.

10. $  touch hi.txt
	$  touch keep.txt
	$  rm hi.txt
	$  rn keep.txt newkeep
	$  ls -m

This correctly adds two files, removes one, renames the one that was kept, and lists the files correcly with ls -m.

Extra Credit:

We added a "TouchCat" command that creates a file and allows you to edit it immediately.

1. $  tc hi.txt

This creates a text file called hi and lets you edit it.

2. $  tc no

This correctly causes the command to fail.