class Graph:
    def __init__(self):
        self.vertices = {}

    def addNeighbour(self,vertex_index,neighbour_index):

        if vertex_index in self.vertices and neighbour_index in self.vertices:
            neighbour = self.vertices[neighbour_index]

            if neighbour not in self.vertices[vertex_index].neighbours:
                self.vertices[vertex_index].neighbours.append(neighbour)

            return True

        else:
            return False

class Vertex:
    def __init__(self,index):
        self.index = index
        self.neighbours = []
        self.visited = False
        self.disc = 0
        self.low =0

class Solution:

    def depthFirstTraversal(self,parent,vertex):

        self.disc+=1
        vertex.visited=True
        vertex.disc = self.disc
        vertex.low=self.disc

        for neighbour in vertex.neighbours:

            if not neighbour.visited:
                self.depthFirstTraversal(vertex,neighbour)

                vertex.low = min(vertex.low,neighbour.low)

                # Decide if there is a critical edge
                if neighbour.low>vertex.disc:

                    crit_tuple=(vertex.index,neighbour.index) if neighbour.index>vertex.index else (neighbour.index,vertex.index)
                    if crit_tuple not in self.critical_connections:
                        self.critical_connections[crit_tuple]=1

            elif neighbour!=parent:
                vertex.low = min(vertex.low,neighbour.disc)


    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:

        self.graph = Graph()
        self.critical_connections = {}
        self.disc = 0

        for i in range(n):
            self.graph.vertices[i]=Vertex(i)

        for connection in connections:
            self.graph.addNeighbour(connection[0],connection[1])
            self.graph.addNeighbour(connection[1],connection[0])

        if len(self.graph.vertices)>0:

            # Do Depth First Traversal
            self.depthFirstTraversal(self.graph.vertices[0],self.graph.vertices[0])

        self.critical_connections=list(self.critical_connections)

        for i in range(len(self.critical_connections)):
            self.critical_connections[i]=list(self.critical_connections[i])

        return self.critical_connections


        
