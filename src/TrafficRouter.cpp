// TrafficRouter.cpp
#include "../include/TrafficRouter.h"
#include <queue>
#include <unordered_set>
#include <climits>
#include <algorithm>

using pii = std::pair<int, std::string>;

TrafficRouter::TrafficRouter(Graph& g, VehicleManager& vm) : graph(g), vehicleManager(vm) {}

std::pair<int, std::vector<std::string>> TrafficRouter::findShortestPathWithPath(const std::string& start, const std::string& end) {
    const auto& adj = graph.getAdjList();
    std::unordered_map<std::string, int> dist;
    std::unordered_map<std::string, std::string> parent;
    std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, std::greater<>> pq;

    for (const auto& node : adj) {
        dist[node.first] = INT_MAX;
    }

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [curr_dist, u] = pq.top(); pq.pop();

        if (curr_dist > dist[u]) continue;

        for (const auto& [v, w] : adj.at(u)) {
            int traffic_penalty = vehicleManager.getTraffic(v);  

            int weight = w + traffic_penalty;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    std::vector<std::string> path;
    if (dist[end] == INT_MAX) return {INT_MAX, path};

    for (std::string at = end; at != start; at = parent[at]) {
        path.push_back(at);
    }
    path.push_back(start);
    std::reverse(path.begin(), path.end());

    return {dist[end], path};
}

