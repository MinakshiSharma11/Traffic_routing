// VehicleManager.cpp
#include "../include/VehicleManager.h"

void VehicleManager::addVehicle(const std::string& node) {
    vehiclesAtNode[node]++;
}

void VehicleManager::removeVehicle(const std::string& node) {
    if (vehiclesAtNode[node] > 0) {
        vehiclesAtNode[node]--;
    }
}

int VehicleManager::getTraffic(const std::string& node) const {
    auto it = vehiclesAtNode.find(node);
    if (it != vehiclesAtNode.end()) {
        return it->second;
    }
    return 0;
}
