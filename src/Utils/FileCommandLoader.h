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

using namespace std;


enum CommandType {
	COMMAND_ONE_LINE = 0,
	COMMAND_MULTI_LINE
};

struct FuncParams {
	string line;
	size_t delimiter;
	int line_num;
};

using Command_Func = function<void(const FuncParams& Params)>;

struct Command {
	CommandType mCommandType = COMMAND_ONE_LINE;
	string mCommand = "";
	Command_Func Command_function = nullptr;
};

class FileCommandLoader {
public:
	void AddCommand(const Command& c);
	bool LoadFile(const string& FilePath);

	static int readint(const FuncParams& Params);
	static char readchar(const FuncParams& Params);
	static string readString(const FuncParams& Params);
	static Vec2D readSize(const FuncParams& Params);
	static Color readColor(const FuncParams& Params);

private:
	vector<Command> mCommands;
};



#endif /* UTILS_FILECOMMANDLOADER_H_ */
