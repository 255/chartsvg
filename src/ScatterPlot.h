#ifndef SCATTERPLOT_H
#define SCATTERPLOT_H

#include "Chart.h"
#include "ScatterPlotSeries.h"
#include "CSVParser.h"

#include <vector>

/**
    A scatter plot is a set of points in a Cartesian plane. The coordinates 
    are real numbers.
*/
class ScatterPlot : Chart {
private:
    ScatterPlotSeries series;

public:
    /**
        Parse an input data file.
    */
    void parseData(const std::string& filename);

    /**
        Print the chart to an output stream in SVG format.
    */
    void print(std::ostream& os, const SVGProperties& properties);

    friend std::ostream& operator<< (std::ostream& os, const ScatterPlot& series);
};

/**
    Print information about this ScatterPlot
*/
std::ostream& operator<< (std::ostream& os, const ScatterPlot& series);

#endif
