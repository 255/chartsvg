#ifndef SERIES_H
#define SERIES_H

#include "Color.h"
#include "SVGProperties.h"

#include <string>
#include <iostream>

/**
    An abstract class representing any data series.
    
    Data series implementation depends on which type of graph they are being 
    used for.
*/
class Series {
private:
    std::string name;

protected:
    SVGProperties properties;

public:
    Series(const std::string n) : name(n) {}

    /*
        Destructor
    */
    virtual ~Series() {}

    /**
        Return the name of this data series.
    */
    const std::string& getName() const { return name; }

    /**
        Set the name of this data series.
    */
    void setName(const std::string& n) { name = n; }

    /**
        Print the series data in SVG format.
    */
    virtual void printSVG(std::ostream& os) const = 0;
};

#endif