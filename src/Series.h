#ifndef SERIES_H
#define SERIES_H

#include <string>

/**
    An abstract class representing any data series.
    
    Data series implementation depends on which type of graph they are being 
    used for.
*/
class Series {
private:
    std::string name;

public:
    /*
        Destructor
    */
    virtual ~Series() {}

    /**
        Return the name of this data series.
    */
    const std::string& getName() const { return name; }
};

#endif