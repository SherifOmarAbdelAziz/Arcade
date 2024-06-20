/*
 * FileCommandLoader.cpp
 *
 *  Created on: Jun 1, 2021
 *      Author: sherif
 */


#include "FileCommandLoader.h"
#include <fstream>
#include <iostream>

void FileCommandLoader::addCommand(const Command& c) {
	mCommands.push_back(c);
}

bool FileCommandLoader::loadFile(const std::string& filePath) 
{
	bool retVal = false;
	std::ifstream infile;
	infile.open(filePath);

	if (!infile.is_open()) 
	{
		std::cout<<"File is not opened"<<std::endl;
	}
	else 
	{
		while (!infile.eof()) 
		{
			std::string line;
			getline(infile, line);
			size_t commandpos = std::string::npos;
			if ((commandpos = line.find(":")) != std::string::npos) 
			{
				std::string commandstr = "";
				size_t delim = 0;

				delim = line.find_first_of(" ", commandpos);
				if (delim == std::string::npos) 
				{
					delim = line.length();
				}
				else 
				{
					delim -= 1;
				}

				commandstr = line.substr(commandpos+1, delim-commandpos);
				delim += 1;
				for (auto commandindex : mCommands) 
				{
					if (commandstr == commandindex.command) {
						if (commandindex.commandType == COMMAND_ONE_LINE) 
						{
							FuncParams Params;
							Params.line = line;
							Params.delimiter = delim;
							Params.lineNum = 0;
							commandindex.parseCommandFunc(Params);
						}
						else 
						{
							int total_lines =  stoi(line.substr(delim+1));
							int lineNum = 0;
							while(lineNum < total_lines) 
							{
								getline(infile, line);
								if (line.empty()) 
								{
									continue;
								}
								else 
								{
									FuncParams Params;
									Params.line = line;
									Params.delimiter = 0;
									Params.lineNum = lineNum;
									commandindex.parseCommandFunc(Params);
									lineNum++;
								}
							}
						}
					}
				}

			}
		}
		retVal = true;
	}
	return retVal;
}

int FileCommandLoader::readint(const FuncParams& Params) 
{
	return stoi(Params.line.substr(Params.delimiter+1));
}

char FileCommandLoader::readchar(const FuncParams& Params) 
{
	return Params.line.substr(Params.delimiter+1)[0];
}

std::string FileCommandLoader::readString(const FuncParams& Params) 
{
	return Params.line.substr(Params.delimiter+1);
}

Vec2D FileCommandLoader::readSize(const FuncParams& Params) 
{
	size_t nextpos = Params.line.find_first_of(" ", Params.delimiter+1);
	int width = stoi(Params.line.substr(nextpos+1, nextpos-Params.delimiter));
	size_t Lastpos = nextpos;
	nextpos = Params.line.find_first_of(" ", nextpos+1);
	int height = stoi(Params.line.substr(Lastpos+1, nextpos-Lastpos));

	return Vec2D(width, height);
}

Color FileCommandLoader::readColor(const FuncParams& Params) 
{
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

