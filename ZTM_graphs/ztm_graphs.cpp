// Make a graph using C++

#include <iostream>
#include <cmath>
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
    Node(): left(nullptr), right(nullptr) {}
};

class Graph 
{
public:
    Graph(int value) : root(nullptr)
    {
        Node* temp = new Node(value);
        root = temp;
        parent = root;
    }
    void AddVertex(std::string label)
    {
        auto it = adjacentList.find(label);
        if (it != adjacentList.end())
        {
            std::cout << "Vertex " + label + " already exists" << std::endl;
        }
        else
        {
            std::vector<std::string> stringList;
            adjacentList[label] = stringList;
        }
    }
    void AddEdge(std::string vertex_1, std::string vertex_2)
    {
        auto node_1_exist = adjacentList.find(vertex_1);
        auto node_2_exist = adjacentList.find(vertex_2);
        if (node_1_exist != adjacentList.end() && 
            node_2_exist != adjacentList.end())
        {
            adjacentList[vertex_1].push_back(vertex_2);
            adjacentList[vertex_2].push_back(vertex_1);
        }
        else
        {
            std::cout << "One of the nodes doesn't exist" << std::endl;
        }
    }
    void ShowConnections()
    {
        // Extract keys from the unordered_map
        std::vector<std::string> allNodes;
        allNodes.reserve(adjacentList.size());  // Optional: Reserve space for efficiency

        // Setup the node connections
        std::vector<std::string> nodeConnections;
        std::string connections;
        std::string vertex;
        for (const auto& pair : adjacentList) {
            allNodes.push_back(pair.first);
            nodeConnections = adjacentList[pair.first]; 
            connections = "";
            for (const auto& vertex : nodeConnections) {
                connections += vertex + " ";
            } 
            std::cout << pair.first + "-->" + connections << std::endl;
        } 
    }
private:
    Node* root;
    Node* parent;
    Node* current;
    int numberOfNodes;
    std::unordered_map<std::string, std::vector<std::string>> adjacentList;
    std::unordered_map<std::string, std::vector<std::string>> edgeList;
    int adjacencyMatrix[];
};

int main() 
{
    Graph myGraph(6);
    myGraph.AddVertex("0");
    myGraph.AddVertex("1");
    myGraph.AddVertex("2");
    myGraph.AddVertex("3");
    myGraph.AddVertex("4");
    myGraph.AddVertex("5");
    myGraph.AddVertex("6");
    myGraph.AddEdge("3", "1"); 
    myGraph.AddEdge("3", "4"); 
    myGraph.AddEdge("4", "2"); 
    myGraph.AddEdge("4", "5"); 
    myGraph.AddEdge("1", "2"); 
    myGraph.AddEdge("1", "0"); 
    myGraph.AddEdge("0", "2"); 
    myGraph.AddEdge("6", "5");
    myGraph.ShowConnections();

    return 0;
}