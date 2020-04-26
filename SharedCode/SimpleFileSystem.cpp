//// define methods of SimpleFileSystem class here
#include "SimpleFileSystem.h"
//
//
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
int SimpleFileSystem::closeFile(AbstractFile* f) {
	auto g = openFiles.find(f);
	if (g == openFiles.end()) {
		return return_vals::notopen;
	}
	openFiles.erase(f);
	return return_vals::success;
}
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