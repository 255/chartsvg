#ifndef CHART_H
#define CHART

#include <string>

// TODO: MOVE THIS
struct SVGProperties {
    double height;
    double width;
};

/**
    An abstract class representing a chart.
*/
class Chart {
private:
    std::string title;

public:
    static const char DECIMAL_MARK = '.';
    static const char DELIMETER = ',';

    virtual ~Chart() {}

    /**
        Parse an input data file.
    */
    virtual void parseData(const std::string& filename) = 0;

    /**
        Print the chart to an output stream in SVG format.
    */
    virtual void print(std::ostream& os, const SVGProperties& properties) = 0;
};

#endif
