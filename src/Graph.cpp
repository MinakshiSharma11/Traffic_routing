#include "../include/Graph.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <set>

void Graph::addEdge(const std::string& u, const std::string& v, int weight) {
    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight}); // undirected
}

const std::vector<std::pair<std::string, int>>& Graph::getNeighbors(const std::string& node) const {
    static const std::vector<std::pair<std::string, int>> empty;
    auto it = adj.find(node);
    if (it != adj.end()) {
        return it->second;
    }
    return empty;
}

void Graph::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << "\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') continue; // Skip empty lines and comments

        std::istringstream iss(line);
        std::string u, v;
        int weight;
        if (iss >> u >> v >> weight) {
            addEdge(u, v, weight);
        } else {
            std::cerr << "Invalid line in map file: " << line << "\n";
        }
    }
}
const std::unordered_map<std::string, std::vector<std::pair<std::string, int>>>& Graph::getAdjList() const {
    return adj;
}

void Graph::exportToDot(const std::string& filename) const {
    std::ofstream out(filename);
    out << "graph CityMap {\n";

    std::set<std::pair<std::string, std::string>> printed;
    for (const auto& [u, neighbors] : adj) {
        for (const auto& [v, w] : neighbors) {
            if (printed.count({v, u}) == 0) {
                out << "  \"" << u << "\" -- \"" << v << "\" [label=\"" << w << "\"];\n";
                printed.insert({u, v});
            }
        }
    }

    out << "}\n";
    out.close();
}


