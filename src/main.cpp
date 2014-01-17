#include <iostream>
#include <regex>
#include <string>

#include "ScatterPlot.h"

using namespace std;

int main(int argc, char** argv) {
    if (argc != 3)
        return 1;

    ScatterPlot plot;

    plot.parseData(argv[1]);

    cout << "The parser found:" << endl;
    cout << plot;

    plot.print(cout, SVGProperties());

    ofstream out(argv[2]);
    plot.print(out, SVGProperties());
    out.close();

    system("pause");
    return 0;
}