#include <vector>
#include <map>
#include <string>
#include <iostream>

template <typename T>
struct Edge {
    T source, destination;
};

template <typename T>
class Graph {
    std::map<T, std::vector<T>> connections;

public:
    Graph(const std::vector<Edge<T>>& edges) {
        for (Edge<T> edge : edges) {
            this->connections[edge.source].push_back(edge.destination);
        }
    }

    std::string toString() const {
        std::string result = "";

        for (std::pair<T, std::vector<T>> pair : this->connections) {
            result += std::to_string(pair.first) + "->";

            for (std::size_t i = 0; i < pair.second.size(); ++i) {
                result += std::to_string(pair.second[i]);
                if (i != pair.second.size() - 1) {
                    result += ',';
                }
            }

            result += '\n';
        }

        return result;
    }
};

int main() {
    Graph<int> graph = Graph<int>({
        {1, 2}, {1, 3}, {1, 100},
        {2, 4}, {2, 6},
        {3, 5}, {3, 7}, {3, 50},
        {100, 101}, {100, 102},
        {50, 31},
        {31, 55},
        {55, 1},
        {99, 31}
    });

    std::cout << graph.toString();
    return 0;
}