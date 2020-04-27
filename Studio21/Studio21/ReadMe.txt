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