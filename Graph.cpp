#include "Graph.hpp"
//  kkorenn1@gmail.com 209271535


namespace ariel {

void Graph::loadGraph(const std::vector<std::vector<int>>& matrix) {
    if (matrix.empty() || matrix.size() != matrix[0].size()) {
        throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
    }
     for (size_t i = 0; i < matrix.size(); i++){
            for (size_t j = 0; j < matrix.size()-i; j++){
                if(i == j && matrix[i][j]!= 0){
                    throw std::invalid_argument("Invalid graph: The graph is not an adjoint matrix.");
                    continue;
                }
                else{
                    if(matrix[i][j] != matrix[j][i]){
                                throw std::invalid_argument("Invalid graph: The graph is not an adjoint matrix");
                    }
                }
            }
        }

    numVertices = (matrix.size());
    adjMatrix = matrix;
}

void Graph::printGraph() const {
    int numEdges = 0;
    for (std::size_t i = 0; i < adjMatrix.size(); ++i) {
        for (std::size_t j = 0; j < adjMatrix.size(); ++j) {
            if (adjMatrix[i][j] != 0 && i != j) {
                numEdges++;
            }
        }
    }
    std::cout << "Graph with " << numVertices << " vertices and " << numEdges << " edges." << std::endl;
}

size_t Graph::getNumVertices() const {
    return numVertices;
}

int Graph::getNumEdges() const {
    int numEdges = 0;
    for (std::size_t i = 0; i < adjMatrix.size(); ++i) {
        for (std::size_t j = 0; j < adjMatrix.size(); ++j) {
            if (adjMatrix[i][j] != 0 && i != j) {
                numEdges++;
            }
        }
    }
    return numEdges;
}

const std::vector<std::vector<int>>& Graph::getAdjMatrix() const {
    return adjMatrix;
}

// Second assignment changes ;
// const to make sure that the original graphs will not change
void Graph::isSameSize(const Graph &g1) const {
    if (numVertices != g1.getNumVertices()) {
        throw std::invalid_argument("Graphs are not of the same size!");
    }
}
// Const to make sure originals grpahs will not change
Graph Graph::operator+(const Graph &toAdd) const {
    // First, check if both graphs are of the same size
    isSameSize(toAdd);

    // create a new graph to store the result
    Graph result;
    std::vector<std::vector<int>> mat(this->numVertices, std::vector<int> (this->numVertices, 0));
    // adjust the newly created matrix

    // adds element from both matrices to the new one
    for (size_t i = 0; i < numVertices; ++i) {
        for (size_t j = 0; j < numVertices; ++j) {
            mat[i][j] = this->adjMatrix[i][j] + toAdd.adjMatrix[i][j];
        }
    }
    result.loadGraph(mat);

    return result;
}
// const only at the given matrix because we want to change the original but not to change the given.
Graph Graph::operator+=(const Graph &toAdd){
    isSameSize(toAdd);

    for(size_t i = 0 ; i<numVertices ; i++){
        for(size_t j = 0 ; j < numVertices ; j++){
            adjMatrix[i][j] += toAdd.adjMatrix[i][j];
        }
    }
    // a refrence to current matrix
    return *this;
}
// unaric addition returns the same matrix value
Graph Graph::operator+()const{

    return *this;
}

Graph Graph::operator-(const Graph &toAdd) const {
    // First, check if both graphs are of the same size
    isSameSize(toAdd);
    // create a new graph to store the result
    Graph result;
    std::vector<std::vector<int>> mat(this->numVertices, std::vector<int> (this->numVertices, 0));
    // adjust the newly created matrix
    // adds element from both matrices to the new one
    for (size_t i = 0; i < numVertices; ++i) {
        for (size_t j = 0; j < numVertices; ++j) {
            mat[i][j] = this->adjMatrix[i][j] - toAdd.adjMatrix[i][j];
        }
    }
    result.loadGraph(mat);

    return result;
}


Graph Graph::operator-=(const Graph &toAdd){
    isSameSize(toAdd);

    for(size_t i = 0 ; i<numVertices ; i++){
        for(size_t j = 0 ; j < numVertices ; j++){
            adjMatrix[i][j] -= toAdd.adjMatrix[i][j];
        }
    }
    // a refrence to current matrix
    return *this;
}

Graph Graph::operator-()const{
    // new graph to see if thers 
    Graph result;
    std::vector<std::vector<int>> mat(this->numVertices, std::vector<int> (this->numVertices, 0));
    for(size_t i = 0 ; i< numVertices ; i++){
        for (size_t j = 0; j < numVertices; j++)
        {
           mat[i][j] = -adjMatrix[i][j];
        }
        
    }
    result.loadGraph(mat);

    return result;
}


bool Graph::operator==(const Graph &toCompare)const{
    if(numVertices == toCompare.getNumVertices()){
        for(size_t i = 0 ; i < numVertices ; i++){
            for (size_t j = 0; j < numVertices; j++)
            {
                if(adjMatrix[i][j] != toCompare.adjMatrix[i][j]){
                  return false;
             }
         }
     }
    return true;
    }
    return false;
}

bool Graph::operator!=(const Graph &toCheck)const{
    if((*this==toCheck)){return false;}
    return true;

     }

bool Graph::operator<=(const Graph &toCheck)const{
    
    if(getNumEdges() > toCheck.getNumEdges()){
        return false;
    }
    for(size_t i = 0; i < numVertices ; i++){
        for (size_t j = 0; j < numVertices; j++)
        {
            if(adjMatrix[i][j] >= 0 && (toCheck.adjMatrix[i][j]!= adjMatrix[i][j])){
                return false;
            }
        }
        
    }
    return true;
}

bool Graph::operator>=(const Graph &toCheck)const{
    if(getNumEdges() < toCheck.getNumEdges()){
        return false;
    }
    for(size_t i = 0; i < toCheck.getNumVertices() ; i++){
        for (size_t j = 0; j < toCheck.getNumVertices(); j++)
        {
            if(toCheck.adjMatrix[i][j] >= 0 && (toCheck.adjMatrix[i][j]!= adjMatrix[i][j])){
                return false;
            }
        }
        
    }
    return true;
}

bool Graph::operator>(const Graph &toCheck)const{
    canBeContained(toCheck);
    
    if(getNumEdges() <= toCheck.getNumEdges()){
        return false;
    }
    for(size_t i = 0; i < toCheck.getNumVertices() ; i++){
    for (size_t j = 0; j < toCheck.getNumVertices(); j++){
        if(toCheck.adjMatrix[i][j] >= 0 && (toCheck.adjMatrix[i][j]!= adjMatrix[i][j])){
            return false;
        }
    }
    
    }
    return true;
}

bool Graph::operator<(const Graph &toCheck)const{
    canIBeContained(toCheck);
    
    if(getNumEdges() >= toCheck.getNumEdges()){
        return false;
    }
    for(size_t i = 0; i < toCheck.getNumVertices() ; i++){
    for (size_t j = 0; j < toCheck.getNumVertices(); j++)
    {
        if(toCheck.adjMatrix[i][j] <= 0 && (toCheck.adjMatrix[i][j]!= adjMatrix[i][j])){
            return false;
            }
        }
    
    }
    return true;
}

Graph Graph::operator++(){
    //Assuming were still working on an adjacent matrix - therefor not touching the edges from the same vertex
    for(size_t i = 0 ; i<numVertices ; i ++){
        for(size_t j = 0 ; j < numVertices ; j++){
            if(i != j){
                adjMatrix[i][j]++;
            }
        }
    }
    return *this;
}
Graph Graph::operator--(){
    //Assuming were still working on an adjacent matrix - therefor not touching the edges from the same vertex
    for(size_t i = 0 ; i<numVertices ; i ++){
        for(size_t j = 0 ; j < numVertices ; j++){
            if(i != j){
                adjMatrix[i][j] = adjMatrix[i][j]-1;
            }
        }
    }
    return *this;
}

Graph Graph::multByInt(int a){
    for(size_t i = 0 ; i<numVertices ; i ++){
        for(size_t j = 0 ; j < numVertices ; j++){
            if(i != j){
                adjMatrix[i][j]*=a;
            }
        }
    }
    return *this;
}

Graph Graph::operator*(const Graph &toAdd) const {
    isSameSize(toAdd);
    Graph result;
    std::vector<std::vector<int>> mat(this->numVertices, std::vector<int> (this->numVertices, 0));
    
    for (size_t i = 0; i < numVertices; i++) {
        for (size_t j = 0; j < numVertices; j++) {
            result.adjMatrix[i][j] = 0;
        }
    }
    
    // Matrix multiplication
    for (size_t i = 0; i < numVertices; ++i) {
        for (size_t j = 0; j < numVertices; ++j) {
            for (size_t k = 0; k < numVertices; ++k) {
                mat[i][j] += adjMatrix[i][k] * toAdd.adjMatrix[k][j];
            }
        }
    }
    result.loadGraph(mat);

    return result;
}



// Changes the std print methods to operate on matrices
std::ostream& operator<<(std::ostream& os, const Graph& graph) {
        const auto& adjMatrix = graph.getAdjMatrix();
        os << "[";
        for (size_t i = 0; i < adjMatrix.size(); ++i) {
            os << "[";
            for (size_t j = 0; j < adjMatrix[i].size(); ++j) {
                os << adjMatrix[i][j];
                if (j != adjMatrix[i].size() - 1) {
                    os << ", ";
                }
            }
            os << "]";
            if (i != adjMatrix.size() - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;

}




        






} // namespace ariel
