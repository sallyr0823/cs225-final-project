## Leading Question 
Our dataset is OpenFlight dataset. We are planning to use Dijkstra's shortest path algorighm to find the preferred route using a weighted graph with count the number of paths on some edge as the weight. We also plan to use PageRank algorithm to measure the significance of airports.
Combined with these two main algorighms, we want to know the connection between airports based on routes and we can also conclude some connection between popularity of each airport. 

## Dataset Acquisition

## Data Format
Generally, we will apply databases of airports, airlines and routes from https://openflights.org/data.html. Dataset airlines is of size ~400kb and routes if of size ~ 2MB. All of them are in “.dat” format. To develop the algorithms, all of these datasets will be applied. Also if required, more datasets in this source will be added in our project. For airports dataset, we will augment the graph with a separate node for IATA code of each airport. Then add edges between each node and count the number of paths on some edge as the weight. Based on airlines, we will make the main graph and link them with airports.

## Data Correction
After downloading the CSV file, we will create a convert function to parse airports into graph nodes and all possible routes into graph edges. We will record the IATA code for each airport in our dataset. If we encounter a missing data error, we will manually complete the dataset by searching for the corresponding airport.

## Data Storage
We will store our datafiles locally. Data will be storing in an vector of nodes which will be adjacency list and we plan to apply a weighted graph to use these nodes.
Space Complexity: Dataset will be the most efficient to use with O(V), where V is the number of airports. For auxiliary datasets, we will be using array to retrieve the data. Reading the dataset will also take linear time.


## Algorithm 
The stored dataset will have two csv input files that contains nodes and edges (airport.dat and routes.dat). We will create nodes as IATA code of the airports and edges as routes between the airports. Then we conduct BFS to check if there is a path between the source and target node (origin and destination airport). The BFS function should have O(m+n) time complexity, and the output would be a Boolean.

Then, we will utilize the Dijikstra's Algorithm to find the shortest route between two nodes (airports). The function should output the shortest path between two nodes (airports) with the shortest number of connections. Based on the lecture material, the algorithm will have O(n^2) time complexity and O(n) space complexity. 

Finally, we will measure the significance of the nodes (airports) using PageRank algorithm. According to Wikipedia, the algorithm counts the number and quality of links among the nodes (airports) to determine a rough estimate of how significant the node (airport) is. The underlying assumption is that more important nodes (airports) are likely to receive more links from other nodes (airports). The algorithm should have O(m+n) time complexity.



## Timeline
Timeline Below are our timeline goals. These are the tasks that we hope to accomplish by the provided dates. November 4th: Algorithm Skeleton set up properly: Djikstra’s, Page Rank; November 14th have Djikstra’s written and verify with tests. November 20rd: have Page Rank completed and verify with tests. November 25th : Final presentation completed December 8th : have project report completed