## cs225-final-project
## Team:csGO, Member: Yanyi Lu, Kelin Pan, Chenyan Rong
## Description of function and data
| Dataset | airports.txt   | routes.txt  | test_airports.txt | test_routes.txt | test_data.txt | 
| :---:   | :---: | :---: | :---: | :---: |:---: | 
|  | information of airports  | information of routes  | some artificial airports for test | some artificial routes for test | a comma separated data for test |

| Function | Airports | Edges  | Airport_graph | BFS | Dijkstra | Pagerank | File_reader|
| :---:   | :---: | :---: | :---: | :---: |:---: | :---: |:---: | 
| | airport class | edge class(using route data)| graph class, build graph with airport as vertex and routes as edges | BFS traversal implementation | Dijkstra implementation | Pagerank implementation | helper function for reading files |

| Executable | main | test |
| :---:   | :---: | :---: |

## How to run the executable
- Our program is running under CS225 docker environment. You may find how to run it in this tutorial.

[Docker File On Your Own Machine](https://courses.engr.illinois.edu/cs225/fa2022/resources/own-machine/)

In the directory, you need run the following command:
```
mkdir build
cd build
cmake ..
```
- Now you are ready to run the code, pay attention that every command should be run inside build repository

The program can be ran by using the 'main' executable:
```
make main
./main
```
 - We use datasets from OpenFlights.org. If you want to go on with our program, enter **y**, else enter **q**.
 
 Then the user will be given three choices on presenting algorithms. User needs to enter the algorithm's name to run it.
 
<img width="668" alt="image" src="https://user-images.githubusercontent.com/77268283/206890963-510e478f-1082-47bd-a4fb-c1f8ecb7707f.png">

There will be guidance on each algorithm. Generally, user needs to enter the id of airport to find required results. When printing results, our program will also print the name of the airport.


To quit each algorithm, the user needs to enter **-1**.

- Program can be quitted with entering **q** after the user is quitted from algorithm with entering **-1**.

## How to run the test

- We have prepared test cases for each function. User needs to use the following command to compile and run it.

```
make test
./test
```
## Links to our presentation
[Youtube Video](https://www.youtube.com/watch?v=bL0Qnfx56qk&t=4s)
