#include "ContinuousLineChart.h"

void ContinuousLineChart::parseData(const std::string& filename) {
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

void ContinuousLineChart::printSVGBody(std::ostream& os) const {
    x_axis.printSVG(os);
    y_axis.printSVG(os);

    for (const auto& s : series)
        s.printSVG(os);
}

// TODO: If I keep this, I will need to do some work to it
std::ostream& operator<< (std::ostream& os, const ContinuousLineChart& plot) {
    for (const auto& s : plot.series)
        os << s;

    return os;
}