#ifndef CSVPARSER_H
#define CSVPARSER_H

#include <string>
#include <cstdlib>
#include <fstream>
#include <limits>
#include <vector>
// #include <exception> // TODO: USE EXCEPTIONS AND ERROR-CHECKING AND THE LIKE

/**
    Parses a CSV file.
*/


// TODO: handle "" and other decimal points

class CSVParser {
private:
    std::ifstream inputFile;
    std::vector<std::string> header; // the column titles
    size_t columnsCount;
    bool hasHeaderLine;

    
    static bool isNewline(char c) {
        return c == '\n' || c == '\r';
    }

    /*
        Skip \n and \r. Should allow for stupid Windows-style newlines.
    */
    void skipNewlines() {
        while (isNewline(inputFile.peek()))
            inputFile.ignore(1);
    }

    /*
        Parse the header line and count the number of columns.
        Changes the stream position.
    */
    void parseHeader();


    /*
        Only count the number of columns. (No header line.)
        Does NOT change the stream position.
    */
    void countColumns();

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
        Return whether the CSV file appears to have a header line.
        This simply checks to see if the next character in the stream is 
        a letter.

        TODO: decide how robust this parser should be. Should this seek to 
        the beginning before checking or not?
    */
    bool hasHeader() const { return hasHeaderLine; }

    /**
        Get the header titles as an array of strings;

        @return Whether the CSV appears to have headers or not.
    */
    const std::vector<std::string>& getHeader() { return header; }

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
    size_t getColumnsCount() const { return columnsCount; }
};

#endif
