studio 18 answers here
1. julian nussenzweig mark gandolfo

2. each file system in this implementation depends on the types of files that are allowed in it, so if we wanted to add a new file type to different types of systems, this would be incredibly tedious and we would need to change code in each system. if the systems are unaware of the concrete file types, then they do not need to worry about what types of files are in the system, because all they need to know is that there are abstract files in the system. 
3. the advantages of this would be that it is more flexible, and it allows the file systems to not worry about the types of file. the disadvantages i guess would be that the file system can no longer create files, but this is not really that big of a deal. we might want to create a new file factory class if you creating a file that is not an abstract file. if a new file is added, more if statements can be added into the createFile method in simplefilefactory.cpp. yes, because the factory is just outputting abstract files, and the file system adds files using these returned abstract files. in this case the answer would be no, because the factories would have to output different types depending on the system
4. the test i ran constructed a filesystem and a filefactory, added a text file created through the factory into the system, wrote "hi" to the file, successfully opened the file, read the file, and then closed the file
the output was "hi" because this is what i wrote to the file.

5. the simplefilesystem only depends on abstractfile types. 
	