/*
 * FileCommandLoader.cpp
 *
 *  Created on: Jun 1, 2021
 *      Author: sherif
 */


#include "FileCommandLoader.h"
#include <fstream>
#include <iostream>

void FileCommandLoader::AddCommand(const Command& c) {
	mCommands.push_back(c);
}

bool FileCommandLoader::LoadFile(const string& FilePath) {

	ifstream infile;
	infile.open(FilePath);

	if (!infile.is_open()) {
		cout<<"File is not opened"<<endl;
		return false;
	}
	else {

		while (!infile.eof()) {
			string line;
			getline(infile, line);
			size_t commandpos = string::npos;
			if ((commandpos = line.find(":")) != string::npos) {
				string commandstr = "";
				size_t delim = 0;

				delim = line.find_first_of(" ", commandpos);
				if (delim == string::npos) {
					delim = line.length();
				}
				else {
					delim -= 1;
				}

				commandstr = line.substr(commandpos+1, delim-commandpos);
				delim += 1;
				for (auto commandindex : mCommands) {
					if (commandstr == commandindex.mCommand) {
						if (commandindex.mCommandType == COMMAND_ONE_LINE) {
							FuncParams Params;
							Params.line = line;
							Params.delimiter = delim;
							Params.line_num = 0;
							commandindex.Command_function(Params);
						}
						else {
							int total_lines =  stoi(line.substr(delim+1));
							int line_num = 0;
							while(line_num < total_lines) {
								getline(infile, line);
								if (line.empty()) {
									continue;
								}
								else {
									FuncParams Params;
									Params.line = line;
									Params.delimiter = 0;
									Params.line_num = line_num;
									commandindex.Command_function(Params);
									line_num++;
								}
							}
						}
					}
				}

			}
		}
		return true;
	}
}

int FileCommandLoader::readint(const FuncParams& Params) {
	return stoi(Params.line.substr(Params.delimiter+1));
}

char FileCommandLoader::readchar(const FuncParams& Params) {
	return Params.line.substr(Params.delimiter+1)[0];
}

string FileCommandLoader::readString(const FuncParams& Params) {
	return Params.line.substr(Params.delimiter+1);
}

Vec2D FileCommandLoader::readSize(const FuncParams& Params) {
	size_t nextpos = Params.line.find_first_of(" ", Params.delimiter+1);
	int width = stoi(Params.line.substr(nextpos+1, nextpos-Params.delimiter));
	size_t Lastpos = nextpos;
	nextpos = Params.line.find_first_of(" ", nextpos+1);
	int height = stoi(Params.line.substr(Lastpos+1, nextpos-Lastpos));

	return Vec2D(width, height);
}

Color FileCommandLoader::readColor(const FuncParams& Params) {
	size_t nextpos = Params.line.find_first_of(" ", Params.delimiter+1);
	int r = stoi(Params.line.substr(nextpos+1, nextpos-Params.delimiter));
    // 255 255 255
	size_t Lastpos = nextpos;
	nextpos = Params.line.find_first_of(" ", nextpos+1);
	int g = stoi(Params.line.substr(Lastpos+1, nextpos-Lastpos));

	Lastpos = nextpos;
	nextpos = Params.line.find_first_of(" ", nextpos+1);
	int b = stoi(Params.line.substr(Lastpos+1, nextpos-Lastpos));

	int a = stoi(Params.line.substr(nextpos+1));

	return Color(r, g, b, a);

}

