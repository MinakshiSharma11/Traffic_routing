#include "../include/Graph.h"
#include "../include/VehicleManager.h"
#include "../include/TrafficRouter.h"

#include <iostream>
#include <string>

int main() {
    Graph graph;
    VehicleManager vehicleManager;
    TrafficRouter router(graph, vehicleManager);

    // Load city map from file
    graph.loadFromFile("city_map.txt");

    // Add vehicles (simulate traffic)
    vehicleManager.addVehicle("B");
    vehicleManager.addVehicle("B");
    vehicleManager.addVehicle("C");

    // Take user input
    std::string start, end;
    std::cout << "Enter start node: ";
    std::cin >> start;
    std::cout << "Enter end node: ";
    std::cin >> end;

    // Routing
    auto [cost, path] = router.findShortestPathWithPath(start, end);

    if (cost != INT_MAX) {
        std::cout << "Shortest cost from " << start << " to " << end << " considering traffic: " << cost << std::endl;
        std::cout << "Path: ";
        for (size_t i = 0; i < path.size(); ++i) {
            std::cout << path[i];
            if (i != path.size() - 1) std::cout << " -> ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No path found from " << start << " to " << end << "!" << std::endl;
    }
    // Export graph for visualization
    graph.exportToDot("graph_output.dot");

    // Auto-generate PNG using dot (Graphviz must be installed)
    std::cout << "Generating PNG visualization with circo...\n";
    int result = system("dot -Tpng graph_output.dot -o graph_output.png");

    if (result == 0) {
        std::cout << "Visualization saved as 'graph_output.png'.\n";
    } else {
        std::cout << "Failed to generate visualization. Ensure Graphviz is installed and in PATH.\n";
    }

    return 0;
}

