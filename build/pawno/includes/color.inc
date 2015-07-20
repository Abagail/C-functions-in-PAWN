// C++ functions for PAWN plugin by Abagail
// Plugin initially written: 7/18/2015
// This plugin for now doesn't have a software license just make sure you give me credit if you copy code or whatever. Please do not re-upload without my permission.

// More information and a up-to-date download / source can be found on github:
	// https://github.com/Abagail/C-functions-in-PAWN
native SetConsoleColor(color[]);
native systemEx(cmd[]);
native getDirectory(directory[]);
native cleanConsole();
native strcopy(string[], dest[]);
native printfEx(string[], color);
native setTextColor(color);

// Colors (usable in printfEx and setTextColor)

#define CONSOLE_COLOR_DARKBLUE 1
#define CONSOLE_COLOR_DARKDARKGREEN 2
#define CONSOLE_COLOR_DARKTEAL 3
#define CONSOLE_COLOR_DARKRED 4
#define CONSOLE_COLOR_DARKPINK 5
#define CONSOLE_COLOR_DARKYELLOW 6
#define CONSOLE_COLOR_GRAY 7
#define CONSOLE_COLOR_DARKGRAY 8
#define CONSOLE_COLOR_BLUE 9
#define CONSOLE_COLOR_GREEN 10
#define CONSOLE_COLOR_TEAL 11
#define CONSOLE_COLOR_RED 12
#define CONSOLE_COLOR_PINK 13
#define CONSOLE_COLOR_YELLOW 14
#define CONSOLE_COLOR_WHITE 15