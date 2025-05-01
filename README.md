📘 Smart Traffic Routing System
A simple C++ project that simulates real-time traffic-aware pathfinding using a graph representation of a city. It uses Dijkstra’s algorithm while considering traffic congestion and visualizes the road network using Graphviz (dot).

🧠 Features

Feature	Description

Graph-based routing->     	|Intersections = nodes, Roads = weighted edges

Traffic simulation->	      |Multiple vehicles per node (tracked via multiset logic)

Shortest path calculation->	|Modified Dijkstra’s algorithm to include traffic cost

Path display->	            |Shows full route from source to destination

Graph visualization->	      |Exports .dot and .png using Graphviz dot layout

🔧 Prerequisites

C++17 compatible compiler (e.g., g++)

Graphviz installed with dot in your system PATH
