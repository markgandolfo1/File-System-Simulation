Answer studio 16 questions here

1. julian nussenzweig mark gandolfo


2. first we must declare interface as a class with virtual methods. then we make derived classes, which define the interface.

3. interface inheritance since it is public

4. output:
"created new text file named: test
added 'x' to file. here is what is in the file now
x
this is size: 1
appended another x to file. here is what is in the file now
x
x
this is size: 2"
i tested each of the methods and they behaved how they should have as shown above

5. 
i did this by creating an abstract file pointer and declared this as the dereferenced version of the textfile. then i called the methods through the abstractfile
"TextFile i("test");
	AbstractFile* a = &i;
	vector<char> x;
	cout << "created new text file named: " << a->getName() << endl;
	x.push_back('x');
	a->write(x);
	cout << "added 'x' to file. here is what is in the file now" << endl;
	a->read();
	cout << "this is size: " << a->getSize()<< endl;
	
	a->append(x);
	cout << "appended another x to file. here is what is in the file now" << endl;
	a->read();
	cout << "this is size: " <<a->getSize() << endl;"

	code generated same output