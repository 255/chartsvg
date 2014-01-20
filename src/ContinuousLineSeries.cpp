#include "ContinuousLineSeries.h"

void ContinuousLineSeries::printSVG(std::ostream& os) const {
    // start a group to store the common properties
    os << "<g";
    properties.printSVG(os);
    os << ">\n";

    // TODO: This is still very temporary
    for (const auto& datum : data)
        os << "<circle cx=\"" << datum.first << "\" cy=\"" << datum.second << "\" r=\"10\"/>\n";

    os << "</g>\n";
}

std::ostream& operator<< (std::ostream& os, const ContinuousLineSeries& series) {
	os << series.getName() << std::endl;

    for (const auto& datum : series.data) {
        os << '(' << datum.first << ',' << datum.second << ')' << std::endl;
    }

    return os;
}
