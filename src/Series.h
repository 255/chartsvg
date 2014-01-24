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
    SVGProperties properties;

protected:
    /*
        Print the data points
    */
    virtual void printSVGData(std::ostream& os) const = 0;

public:
    Series(const std::string n) : name(n) {
        // TODO: THESE ARE DEFAULTS FOR TESTING PURPOSES
        properties.setFill(Color(0,255,0));
        properties.setStroke(Color(0,0,255));
        properties.setProperty("stroke-width", "2");
    }

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
    void printSVG(std::ostream& os) const {
        // A group for the properties to all data points/items
        os << "<g";
        properties.printSVG(os);
        os << ">\n";

        printSVGData(os);

        os << "</g>\n";
    }
};

#endif