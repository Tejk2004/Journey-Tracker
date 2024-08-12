# Journey-Tracker
The Journey Tracker is a C++ project designed to help users find the shortest path between metro stations numbered from 0 to 9. The program employs Dijkstra's algorithm, a popular and efficient method for finding the shortest paths in a graph. Graph Representation: The metro stations are represented as nodes in a graph, and the connections between them (with their respective distances) are represented as weighted edges. The graph is undirected, meaning the path can be traversed in both directions.

KEY FEATURES:- 

Efficient Pathfinding: Using Dijkstra's algorithm, the program computes the shortest distance from the user's current station to the desired destination. The algorithm efficiently finds the shortest path by exploring all possible routes and updating the shortest known distance for each station.

User Interaction: The program prompts the user to enter their current station and destination station. After validating the input, it calculates and displays the shortest path along with the total distance.

Path Reconstruction: Once the shortest path is determined, the program reconstructs the path taken from the source to the destination and outputs the sequence of stations to be followed.


