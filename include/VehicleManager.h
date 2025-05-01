// VehicleManager.h
#ifndef VEHICLE_MANAGER_H
#define VEHICLE_MANAGER_H
#include <unordered_map>
#include <string>

class VehicleManager {
private:
    std::unordered_map<std::string, int> vehiclesAtNode;

public:
    void addVehicle(const std::string& node);
    void removeVehicle(const std::string& node);
    int getTraffic(const std::string& node) const;
};
#endif