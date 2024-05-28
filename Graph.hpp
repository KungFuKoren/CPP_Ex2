#ifndef GRAPH_HPP
#define GRAPH_HPP
//  kkorenn1@gmail.com 209271535

#include <vector>
#include <stdexcept>
#include <iostream>

namespace ariel {

class Graph {
public:
    //Assignment 2
    friend std::ostream& operator<<(std::ostream& os, const Graph& graph);
    Graph operator*(const Graph &toAdd)const;
    Graph multByInt(int a);
    Graph operator++();
    Graph operator--();
    bool operator==(const Graph &toAdd) const;
    bool operator<=(const Graph &toAdd) const;
    bool operator>=(const Graph &toAdd) const;
    bool operator<(const Graph &toAdd) const;    
    bool operator>(const Graph &toAdd) const;    
    bool operator!=(const Graph &toAdd) const;
    Graph operator-() const;
    Graph operator-=(const Graph &toAdd);
    Graph operator-(const Graph &toAdd) const;
    Graph operator+() const;
    Graph operator+=(const Graph &toAdd);
    Graph operator+(const Graph &toAdd) const;
    void isSameSize(const Graph &g) const;
    void canBeContained(const Graph &g) const;
    void canIBeContained(const Graph &g) const;


    //Assignment 1
    void loadGraph(const std::vector<std::vector<int>>& matrix);
    void printGraph() const;
    size_t getNumVertices() const;
    int getNumEdges() const;
    const std::vector<std::vector<int>>& getAdjMatrix() const;

private:
    std::vector<std::vector<int>> adjMatrix;
    size_t numVertices = 0;
};

} // namespace ariel

#endif // GRAPH_HPP
