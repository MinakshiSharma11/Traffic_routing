// TrafficRouter.h
#ifndef TRAFFIC_ROUTER_H
#define TRAFFIC_ROUTER_H
#include "Graph.h"
#include "VehicleManager.h"
#include <string>

class TrafficRouter {
private:
    Graph& graph;
    VehicleManager& vehicleManager;
    int congestionFactor = 2; // Multiply traffic penalty

public:
    TrafficRouter(Graph& g, VehicleManager& vm);
std::pair<int, std::vector<std::string>> findShortestPathWithPath(const std::string& start, const std::string& end);

};
#endif