#ifndef CHART_H
#define CHART_H

#include <string>
#include <vector>

/**
    An abstract class representing a chart.
*/
template <typename series_t>
class Chart {
private:
    std::string title;
    double chart_width, chart_height;

    // TODO: could include background fill/gradient/pattern
    // TODO: could include border?

    // TODO: create a point style class (circle, square, bar, etc
    

protected:
    // All of the series for this chart
    std::vector<series_t> series;

    /*
        Print the body of the SVG file. The header and footer is printed in
        the non-virtual function Chart::printSVG().
    */
    virtual void printSVGBody(std::ostream& os) const = 0;

public:
    Chart(const std::string& title, double width, double height)
        : title(title), chart_width(width), chart_height(height) {};

    // TODO: change this
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
    void printSVG(std::ostream& os) const {
        static const char XML_HEADER[] = "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n";

        os << XML_HEADER
           << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" "
           << "width=\"" << chart_width << "\" height=\"" << chart_height << "\">\n";
        
        printSVGBody(os);

        os << "</svg>";
    };

    /**
        Get the title of this chart.
    */
    const std::string& getTitle() const { return title; }

    /**
        Set the title of this chart.
    */
    void setTitle(const std::string& newTitle) { title = newTitle; }
};

#endif
