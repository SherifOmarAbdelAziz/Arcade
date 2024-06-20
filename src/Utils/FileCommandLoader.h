/*
 * FileCommandLoader.h
 *
 *  Created on: Jun 1, 2021
 *      Author: sherif
 */

#ifndef UTILS_FILECOMMANDLOADER_H_
#define UTILS_FILECOMMANDLOADER_H_

#include <string>
#include <vector>
#include <functional>
#include "Color.h"
#include "Vec2D.h"


enum CommandType 
{
	COMMAND_ONE_LINE = 0,
	COMMAND_MULTI_LINE
};

struct FuncParams 
{
	std::string line;
	size_t delimiter;
	int lineNum;
};

using commandFunc = std::function<void(const FuncParams& Params)>;

struct Command {
	CommandType commandType = COMMAND_ONE_LINE;
	std::string command = "";
	commandFunc parseCommandFunc = nullptr;
};

class FileCommandLoader {
public:
	void addCommand(const Command& c);
	bool loadFile(const std::string& filePath);

	static int readint(const FuncParams& Params);
	static char readchar(const FuncParams& Params);
	static std::string readString(const FuncParams& Params);
	static Vec2D readSize(const FuncParams& Params);
	static Color readColor(const FuncParams& Params);

private:
	std::vector<Command> mCommands;
};



#endif /* UTILS_FILECOMMANDLOADER_H_ */
