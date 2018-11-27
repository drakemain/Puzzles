#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <iostream>
#include <cassert>

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

    bool BFPathTo(T start, T end, bool log = false) {
        std::queue<T> toVisit;
        std::set<T> wasQueued;

        toVisit.push(start);
        wasQueued.insert(start);

        while(!toVisit.empty()) {
            T node = toVisit.front();

            if (log) std::cout << node << std::endl;

            if (node == end) {
                return true;
            }

            toVisit.pop();

            for (T connection : this->connections[node]) {
                if (log) std::cout << "\t↘" << connection;
                if (wasQueued.find(connection) == wasQueued.end()) {
                    if (log) std::cout << '*';
                    toVisit.push(connection);
                    wasQueued.insert(connection);
                }
                if (log) std::cout << std::endl;
            }
        }

        return false;
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

void intBFTests(Graph<int>& graph);

int main() {
    Graph<int> graph = Graph<int>({
        {1, 2}, {1, 3}, {1, 100},
        {2, 4}, {2, 6},
        {3, 2}, {3, 5}, {3, 7}, {3, 50},
        {100, 101}, {100, 102},
        {6, 5},
        {50, 31},
        {31, 55},
        {55, 1},
        {99, 31}
    });

    intBFTests(graph);

    return 0;

    
}

void intBFTests(Graph<int>& graph) {
    assert(graph.BFPathTo(1, 55));
    assert(graph.BFPathTo(1, 100));
    assert(graph.BFPathTo(1, 7));

    assert(graph.BFPathTo(99, 1));
    assert(graph.BFPathTo(99, 50));

    assert(!graph.BFPathTo(1, 99));
    assert(!graph.BFPathTo(100, 1));
    assert(!graph.BFPathTo(101, 7));

    std::cout << "All graph int BF tests passed!" << std::endl;
}

