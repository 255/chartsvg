#include "ScatterPlot.h"

void ScatterPlot::parseData(const std::string& filename) {
    CSVParser input(filename);
    
    size_t columns = input.getColumnsCount();
    
    if (input.hasHeader()) {
        const std::vector<std::string>& columnTitles(input.getHeader());

        for (size_t i = 1; i < columnTitles.size(); ++i)
            series.emplace_back(columnTitles[i]);

    } else {
        std::string defaultName("Data Series 1");
        for (size_t i = 1; i < columns; ++i) {
            series.emplace_back(defaultName);

            // TODO: breaks at 9, an easy fix for later
            defaultName.back()++;
        }
    }

    // TODO: ERROR CHECKING (one column, e.g.), make robust
    while (input.good()) {
        double x = input.nextDouble();

        for (size_t i = 0; i < columns-1; ++i) {
            series[i].addDatum(x, input.nextDouble());
        }
    }
}

void ScatterPlot::print(std::ostream& os, const SVGProperties& prop) {
    //TODO: THIS IS A VERY ROUGH MOCKUP!!!
    os << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n"
       << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"1000\" height=\"1000\" version=\"1.1\">\n";

    for (auto s : series)
        s.print(os);

    os << "</svg>\n";
}

// TODO: If I keep this, I will need to do some work to it
std::ostream& operator<< (std::ostream& os, const ScatterPlot& plot) {
    for (auto s : plot.series)
        os << s;

    return os;
}