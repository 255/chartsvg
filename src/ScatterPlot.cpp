#include "ScatterPlot.h"

void ScatterPlot::parseData(const std::string& filename) {
    CSVParser input(filename);
    
    size_t columns = input.getColumnsCount();
    
    // TODO: ERROR CHECKING (one column, e.g.)
    while (input.good()) {
        double x = input.nextDouble();

        for (size_t i = 0; i < columns-1; ++i) {
            // TODO: add support for multiple series
            series.addDatum(x, input.nextDouble());
        }
    }
}

void ScatterPlot::print(std::ostream& os, const SVGProperties& prop) {
    //TODO: THIS IS A VERY ROUGH MOCKUP!!!
    series.print(os);
}

// TODO: If I keep this, I will need to do some work to it
std::ostream& operator<< (std::ostream& os, const ScatterPlot& plot) {
    return os << plot.series;
}