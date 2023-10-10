# .HACK Assembler

This is a simple C++ program that serves as an assembler for the .HACK machine language. It takes as input a .asm file (Hack assembly code) and produces a corresponding .hack file (Hack machine code).

## Usage

```bash
./assembler input_file.asm
```

- `input_file.asm`: The input Hack assembly file.

## Functions

### `std::string extractFileName(const char* str)`

This function extracts the file name (excluding the extension) from a given path.

### `void fileExistCheck(const std::string& str)`

This function checks if the output .HACK file already exists and prompts the user for confirmation to replace it.

### `std::string numToBin(const std::string& str)`

This function converts a decimal number (passed as a string) to its binary representation in a 15-bit format.

### `int main(int charc, char** charv)`

The main function of the assembler. It performs the following tasks:

1. Checks for correct command-line arguments.
2. Extracts the file name from the input path.
3. Checks if the output .HACK file already exists.
4. Initializes a HackParser and HackCoder for parsing and encoding Hack assembly code.
5. Reads the input file line by line and translates each instruction to Hack machine code.
6. Writes the resulting machine code to the output .HACK file.

## Compilation

```bash
g++ -std=c++11 -o assembler main.cpp
```

## Example

```bash
./assembler input.asm
```

## Notes

- This program assumes a specific syntax for Hack assembly code. Make sure your input files adhere to this syntax.
- The program uses C++11 features, so ensure your compiler supports this standard.
- Ensure you have the necessary permissions to read and write files in the specified directories.

Feel free to modify and extend this program as needed. Happy assembling!


## Classes

### HackParser

This class handles parsing Hack assembly code. It provides functions to load a file, read and interpret lines, and manage the symbol table.

```cpp
#include "HackParser.hpp"

HackParser::HackParser()
{
    // ... (constructor details)
}

HackParser::~HackParser()
{
    // ... (destructor details)
}

void HackParser::reset()
{
    // ... (reset function details)
}

bool HackParser::endOfFile()
{
    // ... (endOfFile function details)
}

// ... (other HackParser member functions)
```

## HackParser Functions

- `HackParser()`: Constructor that initializes the parser.

- `~HackParser()`: Destructor that closes the file if one is open.

- `void reset()`: Resets internal state variables.

- `bool endOfFile()`: Checks if the end of the file has been reached.

- `void sendOpenErrorMessage()`: Sends an error message if a file cannot be opened.

- `void loadFile(const std::string& filepath)`: Loads a file for parsing.

- `std::string trimWhiteSpace(const std::string& str)`: Trims leading and trailing whitespaces.

- `std::string trimComments(const std::string& str)`: Trims comments from a line.

- `void setInstructionType()`: Sets the instruction type (A, C, or L).

- `void AINS()`, `void CINS()`, `void LINS()`: Handle different instruction types.

- `void fillCurrentLine()`: Fills `currentLine` with the next line from the file.

- `void getNext()`: Gets the next line of code and processes it.

- `void closeFile()`: Closes the file if one is open.

- `void fillSymbolTableDefaults()`: Fills the symbol table with default symbols.

- `void fillSymbolTableLoopFunction()`: Handles symbol table filling in a loop.

- `void fillSymbolTable()`: Fills the symbol table.

- `bool hasSymbol(const std::string& sym)`: Checks if a symbol is in the symbol table.

- `std::string getSymbolVallue(const std::string& sym)`: Gets the value of a symbol.



## Notes

- This program assumes a specific syntax for Hack assembly code. Make sure your input files adhere to this syntax.
- The program uses C++11 features, so ensure your compiler supports this standard.
- Ensure you have the necessary permissions to read and write files in the specified directories.

Feel free to modify and extend this program as needed. Happy assembling!