#include "pch.h"
#include "CppUnitTest.h"
#define protected public
#include "../../SharedCode/TextFile.cpp"
#include "../../SharedCode/ImageFile.cpp"
#include "../../SharedCode/SimpleFileFactory.cpp"
#include "../../SharedCode/SimpleFileSystem.cpp"
#include "../../SharedCode/BasicDisplayVisitor.cpp"
#include "../../SharedCode/MetadataDisplayVisitor.cpp"
#include "../../SharedCode/DirectoryFile.cpp"
#include "../../SharedCode/HierarchicalFileSystem.cpp"
#include "..//..//SharedCode/HierarchicalFileFactory.cpp"
#include "..//..//SharedCode/CommandPrompt.cpp"
#include "..//..//SharedCode/CommandTest.cpp"
#include "..//..//SharedCode/TouchCommand.cpp"
#undef protected


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(commandPrompt) {
		TEST_METHOD(addAndListCommands) { // ensures the add command and list command are working correctly, we would expect the command name for the command we added (in this case the testCommand) to be printed out by the listCommand() method
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			CommandPrompt cp;
			cp.setFileSystem(sfs);
			cp.setFileFactory(sff);
			// ADD COMMAND -- TEST COMMAND
			CommandTest* ct = new CommandTest(sfs);
			string commandname = "test";
			Assert::AreEqual(cp.addCommand(commandname, ct), 0);
			// REDIRECT STD STREAM
			streambuf* backup;
			backup = cout.rdbuf();
			stringstream ss;
			cout.rdbuf(ss.rdbuf());
			// LIST COMMANDS
			cp.listCommands();
			string word;
			std::vector<string> printedWords;
			while (ss >> word) {
				printedWords.push_back(word);
			}
			// EXPECTATION -- COMMAND NAME SHOULD BE PRINTED TO COUT
			Assert::AreEqual(static_cast<int>(printedWords.size()), 1);
			Assert::AreEqual(printedWords[0], commandname);
			// ASSIGN COUT BACK TO STDOUT
			cout.rdbuf(backup);
		}
		TEST_METHOD(prompt) { // checks prompt method, ensures that prompt returns what is typed in the terminal by the filesystem user
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			CommandPrompt* cp = new CommandPrompt;
			cp->setFileSystem(sfs);
			cp->setFileFactory(sff);
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// MIMIC USER INPUT -- SAMPLE COMMAND FOR TOUCH
			string input = "touch file.txt";
			ss_in << input;
			// EXPECTATION -- PROMPT SHOULD RETURN THE USER INPUT
			string promptResponse = cp->prompt();
			Assert::AreEqual(promptResponse, input);
			// ASSIGN COUT BACK TO STDOUT
			cout.rdbuf(backup_out);
			// ASSIGN CIN BACK TO STDIN
			cin.rdbuf(backup_in);
		}
		TEST_METHOD(runQuit) { // ensures that the run method ends when quit by the user (entering q), we would expect a non-zero return value
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			CommandPrompt* cp = new CommandPrompt;
			cp->setFileSystem(sfs);
			cp->setFileFactory(sff);
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// MIMC USER INPUT -- QUITTING COMMAND -- 'Q'
			string input = "q";
			ss_in << input;
			// CAPUTRE RETURN VALUE -- Q SHOULD END THE RUN LOOP
			int response = cp->run();
			Assert::AreNotEqual(response, 0);
			// ASSIGN COUT BACK TO STDOUT
			cout.rdbuf(backup_out);
			// ASSIGN CIN BACK TO STDIN
			cin.rdbuf(backup_in);
		}
		TEST_METHOD(runHelp) { // we would expect help to list all of the commands that have been added, in this case only the test command should be printed
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			CommandPrompt* cp = new CommandPrompt;
			cp->setFileSystem(sfs);
			cp->setFileFactory(sff);
			// ADD COMMAND -- COMMAND TEST
			CommandTest* ct = new CommandTest(sfs);
			string commandname = "test";
			Assert::AreEqual(cp->addCommand(commandname, ct), 0);
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// MIMIC USER INPUT -- HELP & QUIT -- USE QUIT TO END RUN 
			string input = "help\nq";
			ss_in << input;
			int response = cp->run();
			Assert::AreNotEqual(response, 0);
			// CAPTURE COUT DATA
			string word;
			std::vector<string> printedWords;
			while (ss_out >> word) {
				printedWords.push_back(word);
			}
			// EXPECTATION -- PROGRAM SHOULD PRINT ALL COMMANDS
			std::vector<string>::iterator it1;
			it1 = std::find(printedWords.begin(), printedWords.end(), commandname);
			bool notEqual1 = it1 == printedWords.end();
			Assert::IsFalse(notEqual1);
			// ASSIGN COUT BACK TO STDOUT
			cout.rdbuf(backup_out);
			// ASSIGN CIN BACK TO STDIN
			cin.rdbuf(backup_in);
		}
	};
	TEST_CLASS(commandTest) {
		TEST_METHOD(commandDisplayInfo) { // uses the CommandTest object to check that help + command name will successfully call the displayInfo() method for the correct command type
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			CommandPrompt* cp = new CommandPrompt;
			cp->setFileSystem(sfs);
			cp->setFileFactory(sff);
			// ADD COMMAND
			CommandTest* ct = new CommandTest(sfs);
			string commandname = "test";
			Assert::AreEqual(cp->addCommand(commandname, ct), 0);
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// MIMIC USER INPUT -- SPECIFIC HELP COMMAND
			string input = "help test\nq\n";
			ss_in << input;
			int response = cp->run();
			Assert::AreNotEqual(response, 0);
			string word;
			std::vector<string> printedWords;
			while (ss_out >> word) {
				printedWords.push_back(word);
			}
			/// EXPECTATION -- DISPLAY INFO OF OUR COMMAND TEST SHOULD BE PRINTED TO COUT
			std::vector<string>::iterator it1;
			string expectedString = "aRandomStringz"; // MATCHES GIVEN COMMAND TEST FILE
			it1 = std::find(printedWords.begin(), printedWords.end(), expectedString);
			bool notEqual1 = it1 == printedWords.end();
			Assert::IsFalse(notEqual1);
			// ASSIGN COUT BACK TO STDOUT
			cout.rdbuf(backup_out);
			// ASSIGN CIN BACK TO STDIN
			cin.rdbuf(backup_in);
		}
		TEST_METHOD(commandExecuteNoInfo) { //  uses the CommandTest object to check passing variables to execute - expects no inputs to be passed as the parameter in this case
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			CommandPrompt* cp = new CommandPrompt;
			cp->setFileSystem(sfs);
			cp->setFileFactory(sff);
			// ADD COMMAND
			CommandTest* ct = new CommandTest(sfs);
			string commandname = "test";
			Assert::AreEqual(cp->addCommand(commandname, ct), 0);
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// MIMIC USER INPUT -- COMMAND TEST EXECUTE 
			string input = "test\nq\n";
			ss_in << input;
			// CAPTURE RUN OUTPUT
			int response = cp->run();
			Assert::AreNotEqual(response, 0);
			string word;
			std::vector<string> printedWords;
			while (ss_out >> word) {
				printedWords.push_back(word);
			}
			// EXPECTATION -- NOTHING SHOULD BE PASSED TO THE FUNCTION
			std::vector<string>::iterator it1;
			string expectedOutput = "command-test-no-info";
			it1 = std::find(printedWords.begin(), printedWords.end(), expectedOutput);
			bool notEqual1 = it1 == printedWords.end();
			Assert::IsFalse(notEqual1);
			// ASSIGN COUT BACK TO STDOUT
			cout.rdbuf(backup_out);
			// ASSIGN CIN BACK TO STDIN
			cin.rdbuf(backup_in);
		}
		TEST_METHOD(commandExecuteOneInput) { //  uses the CommandTest object to check passing variables to execute - expects one input, foo, to be passed to the function
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			CommandPrompt* cp = new CommandPrompt;
			cp->setFileSystem(sfs);
			cp->setFileFactory(sff);
			// ADD COMMAND
			CommandTest* ct = new CommandTest(sfs);
			string commandname = "test";
			Assert::AreEqual(cp->addCommand(commandname, ct), 0);
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// MIMIC USER INPUT
			string input = "test foo\nq\n";
			ss_in << input;
			int response = cp->run();
			Assert::AreNotEqual(response, 0);
			string word;
			std::vector<string> printedWords;
			while (ss_out >> word) {
				printedWords.push_back(word);
			}
			// EXPECTATION -- THE SECOND PARAMETER SHOULD BE PRINTED TO COUT
			std::vector<string>::iterator it1;
			string expectedOutput = "foo";
			it1 = std::find(printedWords.begin(), printedWords.end(), expectedOutput);
			bool notEqual1 = it1 == printedWords.end();
			Assert::IsFalse(notEqual1);
			// ASSIGN COUT BACK TO STDOUT
			cout.rdbuf(backup_out);
			// ASSIGN CIN BACK TO STDIN
			cin.rdbuf(backup_in);
		}
		TEST_METHOD(commandExecuteMoreInputs) { // uses the CommandTest object to check passing variables to execute - expects two inputs to be passed 
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			CommandPrompt* cp = new CommandPrompt;
			cp->setFileSystem(sfs);
			cp->setFileFactory(sff);
			// ADD COMMAND
			CommandTest* ct = new CommandTest(sfs);
			string commandname = "test";
			Assert::AreEqual(cp->addCommand(commandname, ct), 0);
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// MIMIC USER INPUT
			string input = "test foo moo\nq\n";
			ss_in << input;
			int response = cp->run();
			Assert::AreNotEqual(response, 0);
			string word;
			std::vector<string> printedWords;
			while (ss_out >> word) {
				printedWords.push_back(word);
			}
			// EXPECTATION -- ALL PARAMETERS SHOULD BE PRINTED TO COUT
			std::vector<string>::iterator it1;
			string expectedOutput = "foo:moo";
			it1 = std::find(printedWords.begin(), printedWords.end(), expectedOutput);
			bool notEqual1 = it1 == printedWords.end();
			Assert::IsFalse(notEqual1);
			// ASSIGN COUT BACK TO STDOUT
			cout.rdbuf(backup_out);
			// ASSIGN CIN BACK TO STDIN
			cin.rdbuf(backup_in);
		}
	};
	TEST_CLASS(touchCommand) {
		TEST_METHOD(execute) { // confirms that execute, when passed a valid filename, will create and add a file in the filesystem
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			CommandPrompt* cp = new CommandPrompt;
			cp->setFileSystem(sfs);
			cp->setFileFactory(sff);
			// ADD COMMAND
			TouchCommand* ct = new TouchCommand(sfs, sff);
			string commandname = "touch";
			Assert::AreEqual(cp->addCommand(commandname, ct), 0);
			// CALL EXECUTE ON TOUCH COMMAND
			string filename = "file.txt";
			Assert::AreEqual(ct->execute(filename), 0);
			// EXPECTATION -- FILE EXISTS IN THE FILE SYSTEM
			AbstractFile* file = sfs->openFile(filename);
			bool isNull = file == nullptr;
			Assert::IsFalse(isNull);
			Assert::AreEqual(filename, file->getName());
		}
		TEST_METHOD(executeInvalidExtension) { // confirms that execute, when passed a valid filename, will create and add a file in the filesystem
		// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			CommandPrompt* cp = new CommandPrompt;
			cp->setFileSystem(sfs);
			cp->setFileFactory(sff);
			// ADD COMMAND
			TouchCommand* ct = new TouchCommand(sfs, sff);
			string commandname = "touch";
			Assert::AreEqual(cp->addCommand(commandname, ct), 0);
			// CALL EXECUTE ON TOUCH COMMAND
			string filename = "file.foo";
			Assert::AreNotEqual(ct->execute(filename), 0);
			// EXPECTATION -- FILE DOES NOT EXISTS IN THE FILE SYSTEM
			AbstractFile* file = sfs->openFile(filename);
			bool isNull = file == nullptr;
			Assert::IsTrue(isNull);
		}
		TEST_METHOD(executeFileAlreadyExists) { // confirms that execute, when passed a valid filename, will create and add a file in the filesystem
		// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			CommandPrompt* cp = new CommandPrompt;
			cp->setFileSystem(sfs);
			cp->setFileFactory(sff);
			// ADD COMMAND
			TouchCommand* ct = new TouchCommand(sfs, sff);
			string commandname = "touch";
			Assert::AreEqual(cp->addCommand(commandname, ct), 0);
			// CALL EXECUTE ON TOUCH COMMAND
			string filename = "file.txt";
			Assert::AreEqual(ct->execute(filename), 0);
			Assert::AreNotEqual(ct->execute(filename), 0);
			// EXPECTATION -- FILE DOES EXISTS IN THE FILE SYSTEM - FIRST EXECUTION
			AbstractFile* file = sfs->openFile(filename);
			bool isNull = file == nullptr;
			Assert::IsFalse(isNull);
		}
	};
}

