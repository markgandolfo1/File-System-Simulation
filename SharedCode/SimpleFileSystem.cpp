//// define methods of SimpleFileSystem class here
#include "SimpleFileSystem.h"
//
//adds file to the map
int SimpleFileSystem::addFile(string s, AbstractFile* f) {

	//http://www.cplusplus.com/reference/map/map/find/
	auto  e = files.find(s);
	if (e != files.end()) {
		return return_vals::exists;
	}
	if (f == nullptr) {
		return return_vals::invalid;
	}
	files.insert(pair<string, AbstractFile*>(s, f));
	return return_vals::success;
	
}
//adds file to the open file sets
AbstractFile* SimpleFileSystem::openFile(std::string s) {
	auto  e = files.find(s);
	if (e == files.end()) {
		return nullptr;
	}
	AbstractFile* f = files.at(s);
	auto g = openFiles.find(f);
	if (g != openFiles.end()) {
		return nullptr;
	}
	openFiles.insert(f);
	return f;

}
//takes file out of set
int SimpleFileSystem::closeFile(AbstractFile* f) {
	auto g = openFiles.find(f);
	if (g == openFiles.end()) {
		return return_vals::notopen;
	}
	openFiles.erase(f);
	return return_vals::success;
}
//delete fie from map and deletes file
int SimpleFileSystem::deleteFile(std::string s) {
	auto  e = files.find(s);
	if (e == files.end()) {
		return return_vals::nonexist;
	}
	AbstractFile* f = files.at(s);
	auto g = openFiles.find(f);
	if (g != openFiles.end()) {
		return return_vals::open;
	}
	files.erase(s);
	delete f;
	return return_vals::success;
}
//get names of all files in map for ls
std::set<string> SimpleFileSystem::getFileNames() {
	set<string>* names = new set<string>;
	for (map<string, AbstractFile*>::iterator it = files.begin(); it != files.end(); it++) {
		names->insert(it->first);
	}
	return *names;
}