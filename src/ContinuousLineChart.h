#ifndef CONTINUOUSLINECHART_H
#define CONTINUOUSLINECHART_H

// TODO: This will probably move. Still testing things.
#include "Axis.h"

#include "Chart.h"
#include "ContinuousLineSeries.h"
#include "CSVParser.h"

/**
    A scatter plot is a set of points in a Cartesian plane. The coordinates 
    are real numbers.
*/
class ContinuousLineChart : public Chart<ContinuousLineSeries> {
private:
    Axis x_axis;
    Axis y_axis;

public:
    ContinuousLineChart(const std::string& title, double width, double height)
        : Chart(title, width, height), x_axis(Axis::Orientation::HORIZONTAL, 1990, 2010, 20, 20, 400, SVGProperties()),
          y_axis(Axis::Orientation::VERTICAL, 1990, 2010, 20, 20, 400, SVGProperties()) {}

    // TODO: push most of this stuff up into a pure virtual continuous class.
    //       I will implement Scatter Plots (multiple y per x), which will use
    //       most of this code.
    /**
        Parse an input data file.
    */
    void parseData(const std::string& filename);

    /**
        Print the chart to an output stream in SVG format.
    */
    void printSVGBody(std::ostream& os) const;

    friend std::ostream& operator<< (std::ostream& os, const ContinuousLineChart& series);
};

/**
    Print information about this line chart (for debugging)
*/
std::ostream& operator<< (std::ostream& os, const ContinuousLineChart& series);

#endif
