// Graph.h
#ifndef GRAPH_H
#define GRAPH_H
#include <unordered_map>
#include <vector>
#include <string>
#include <utility>

class Graph {
private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> adj;

public:
    void addEdge(const std::string& u, const std::string& v, int weight);
    const std::vector<std::pair<std::string, int>>& getNeighbors(const std::string& node) const;
    void loadFromFile(const std::string& filename);  // <-- added here
    const std::unordered_map<std::string, std::vector<std::pair<std::string, int>>>& getAdjList() const;
    void exportToDot(const std::string& filename) const;

};
#endif