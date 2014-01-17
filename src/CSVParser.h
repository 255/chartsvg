#ifndef CSVPARSER_H
#define CSVPARSER_H

#include <string>
#include <cstdlib>
#include <fstream>
#include <limits>
// #include <exception> // TODO: USE EXCEPTIONS AND ERROR-CHECKING AND THE LIKE

/**
    Parses a CSV file.

    Always skips whitespace.
*/
class CSVParser {
private:
    std::ifstream inputFile;
    std::streampos start;
    
    bool isNewline(char c) {
        return c == '\n' || c == '\r';
    }

    void skipWhitespace() {
        while (isspace(inputFile.peek()))
            inputFile.ignore(1);
    }

public:
    static const char DECIMAL_MARK = '.';
    static const char DELIMETER = ','; // TODO: something about this

    /**
        Create a new parser with a file to parse.
    */
    CSVParser(const std::string& filename, char field_delim = ',');

    virtual ~CSVParser() {}
    
    /**
        Get the next double from the file.

        TODO: There is NO error checking at all.
    */
    double nextDouble();

    /**
        Get the header titles as an array of strings;

        @return Whether the CSV appears to have headers or not.
    */
    bool getHeader(std::string titles[]) { return false; } //TODO: Implement


    /**
        Get whether the input file has reached the end.
    */
    bool eof() const { return inputFile.eof(); }

    /**
        Get whether there is data to be extracted.
    */
    bool good() const { return inputFile.good(); }

    /**
        Get how many columns this CSV file has.
    */
    size_t getColumnsCount();
};

#endif
