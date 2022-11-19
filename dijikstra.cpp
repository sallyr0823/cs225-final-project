#include "dijikstra.h"
#include <map>
#include <iostream>


Dijisktra::Dijisktra(Graph graph, Airport source) {
    airports_ = graph.get_airports();
    edges_ = graph.get_routes();
}
