#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


//  Too lazy to put into headers
struct Node {
    int val;
    Node* next;
};

struct Edge {
    int src, dest;
};

class Graph {
    // Function to allocate new node of Adjacency List
    Node* getAdjListNode(int dest, Node* head) {
        Node* newNode = new Node;
        newNode->val = dest;

        // point new node to current head
        newNode->next = head;

        return newNode;
    }

    int N;  // number of nodes in the graph
    public:
    // An array of pointers to Node to represent
    // adjacency list
    Node **head;

    // Constructor
    Graph(Edge edges[], int n, int N) {
        // allocate memory
        head = new Node*[N]();
        this->N = N;

        // initialize head pointer for all vertices
        for (int i = 0; i < N; i++)
            head[i] = nullptr;

        // add edges to the directed graph
        for (unsigned i = 0; i < n; i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;

            // insert in the beginning
            Node* newNode = getAdjListNode(dest, head[src]);

            // point head pointer to new node
            head[src] = newNode;

            // Uncomment below lines for undirected graph

            /*
            newNode = getAdjListNode(src, head[dest]);

            // change head pointer to point to the new node
            head[dest] = newNode;
            */
        }
    }

    // Destructor
    ~Graph() {
        for (int i = 0; i < N; i++)
            delete[] head[i];

        delete[] head;
    }
};


void prob1();
void prob2();
void prob3();
void addEdge(vector<int> adj[], int u, int v);
void printGraph(vector<int> adj[], int V);
void printList(Node* ptr);

int main(int argc, char** argv) {
    cout << "Problem 1" << endl << endl;
    prob1();
    cout << endl;

    cout << "Problem 2" << endl << endl;
    prob2();
    cout << endl;

    cout << "Problem 3" << endl << endl;
    prob3();
    cout << endl;

    return 0;
}

void prob1() {
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, V);
    cout << endl << endl;

    cout << "1e. - Yes, the output matches with exercise one." << endl;
    cout << "1f. - Fills out container and pushes to vector. It displays the"
         << " adjacency list." << endl;
    cout << "1g. - No, you need to see how the verticies and relate to others via"
         << " adjacency." << endl << endl;
};

void prob2() {
    // array of graph edges as per above diagram.
    Edge edges[] =
    {
        // pair (x, y) represents edge from x to y
        { 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
        { 3, 2 }, { 4, 5 }, { 5, 4 }
    };

    // Number of vertices in the graph
    int N = 6;

    // calculate number of edges
    int n = sizeof(edges)/sizeof(edges[0]);

    // construct graph
    Graph graph(edges, n, N);

    // print adjacency list representation of graph
    for (int i = 0; i < N; i++)
    {
        // print given vertex
        cout << i << " --";

        // print all its neighboring vertices
        printList(graph.head[i]);
    }

    cout << endl << endl;
    cout << "2d. - Edges are represented in the ADT struct in paired element arrays"
         << ", verticies are the set number of nodes so a default integer, and"
         << " adjacency is show by looping through and printing using a pointer."
         << endl;
    cout << "2e. - My answer is the same, 2 -> 0, 1; however console print shows"
         << " 2 -> 1 -> 0 from the program." << endl;
    cout << "2f. - I believe you still need to see how verticies relate to others."
         << endl;
    cout << "2g. - The Graph class has loops in the constructor which list the"
         << " source & destinations, to represent edge directions. Overall, "
         << "the program uses pointers and a class with a constructor that initializes"
         << " the graphs nodes, edges, and such." << endl;
};

void prob3() {
};

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V) {
    for (int v = 0; v < V; ++v) {
        cout << "\n Adjacency list of vertex "
             << v << "\n head ";
        for (auto x : adj[v])
           cout << "-> " << x;
        printf("\n");
    }
}

void printList(Node* ptr) {
    while (ptr != nullptr)
    {
        cout << " -> " << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
