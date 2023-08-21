from graph import Graph
class InputException(Exception):
    def __init__(self, message:str):
        self.__message = message

    @property
    def message(self):
         return self.__message
class UserInterface:
    def __init__(self, graph:Graph):
        self.__graph = graph

    def start(self):

        print("Introduce the file that you want to read from>")
        file_name_read = input()
        print("Introduce the file that you want to write to>")
        file_name_write = input()
        self.__graph.read_file(file_name_read)

        print("\nPress 1 to get the number of vertices")
        print("Press 2 to parse the set of vertices")
        print("Press 3 to introduce 2 vertices and find out if there's an edge from the first to the second one")
        print("Press 4 to get the in degree of a specified vertex")
        print("Press 5 to get the out degree of a specified vertex")
        print("Press 6 to parse the set of outbound edges, which are the successors of a specified vertex")
        print("Press 7 to parse the set of inbound edges, which are the predecessors of a specified vertex")
        print("Press 8 to modify the cost of an edge")
        print("Press 9 to add an edge")
        print("Write 10 to remove an edge")
        print("Write 11 to add a vertex")
        print("Write 12 to remove a vertex")
        print("Write 13 to make an exact copy of the graph")
        print("Write 14 to display one of the copies of the graph in a file")
        print("Write 15 to delete one of the copies of the graph")
        print("Write 16 to create a random graph with a specified number of vertices and edges")
        print("Write 17 to read the graph from a file")
        print("Write 18 to write the graph to a file")
        print("Write 19 to find the shortest path between two vertices that you introduce-with backward breadth first search")
        print("Write 20 to find the lowest cost path between two vertices you introduce-with Ford's algorithm")
        print("Write 21 to exit the program")
        while True:
                print("Introduce the option that you want>")

                user_option = int(input())
                if user_option == 1:
                    print(self.__graph.get_nr_of_vertices())
                elif user_option == 2:
                    for i in self.__graph.parse_set_of_vertices():
                        print(i)
                elif user_option == 3:
                    print("Introduce the origin vertex>")
                    vertex_out = int(input())
                    print("Introduce its succesor>")
                    vertex_in = int(input())
                    if self.__graph.verify_if_edge(vertex_out, vertex_in):
                        print("There is an edge")
                    else:
                        print("There's no edge")
                elif user_option == 4:
                    print("Introduce the vertex>")
                    vertex = int(input())
                    print(f"The in degree of this vertex is {self.__graph.get_in_degree_of_vertex(vertex)}")
                elif user_option == 5:
                    print("Introduce the vertex>")
                    vertex = int(input())
                    print(f"The out degree of this vertex is {self.__graph.get_out_degree_of_vertex(vertex)}")
                elif user_option == 6:
                    print("Introduce the vertex>")
                    vertex = int(input())
                    for i in self.__graph.parse_successors_of_a_vertex(vertex):
                        print(i)
                elif user_option == 7:
                    print("Introduce the vertex>")
                    vertex = int(input())
                    for i in self.__graph.parse_predecessors_of_a_vertex(vertex):
                        print(i)
                elif user_option == 8:
                    print("Introduce the origin vertex>")
                    vertex_out = int(input())
                    print("Introduce its succesor>")
                    vertex_in = int(input())
                    print("Introduce the new cost of the edge>")
                    new_cost_of_edge = int(input())
                    print("The previous cost of the edge was:")
                    print(self.__graph.get_cost_of_edge(vertex_out, vertex_in))
                    print("The current cost of the edge is:")
                    self.__graph.modify_cost_of_edge(vertex_out, vertex_in, new_cost_of_edge, file_name_write)
                    print(self.__graph.get_cost_of_edge(vertex_out, vertex_in))
                elif user_option == 9:
                    print("Introduce the origin vertex>")
                    vertex_out = int(input())
                    print("Introduce its succesor>")
                    vertex_in = int(input())
                    print("Introduce the cost of the edge")
                    cost_of_edge = int(input())
                    self.__graph.add_edge(vertex_out, vertex_in, cost_of_edge, file_name_write)
                elif user_option == 10:
                    print("Introduce the origin vertex>")
                    vertex_out = int(input())
                    print("Introduce its succesor>")
                    vertex_in = int(input())
                    self.__graph.remove_edge(vertex_out, vertex_in, file_name_write)
                elif user_option == 11:
                    print("Introduce the vertex>")
                    new_vertex = int(input())
                    self.__graph.add_vertex(new_vertex, file_name_write)
                elif user_option == 12:
                    print("Introduce the vertex>")
                    vertex_to_remove = int(input())
                    self.__graph.remove_vertex(vertex_to_remove, file_name_write)
                elif user_option == 13:
                    self.__graph.copy()
                elif user_option == 14:
                    print("Introduce the name of the file where you want to write the copy>")
                    file_name_write_copy = input()
                    print(f"The number of copies is currently {self.__graph.get_nr_of_copies()}")
                    print("Introduce the index of the copy that you want to display>")
                    index_of_copy = int(input())
                    copy_to_display = self.__graph.get_copy(index_of_copy)
                    copy_to_display.write_file(file_name_write_copy)
                elif user_option == 15:
                    if(self.__graph.get_nr_of_copies() == 0):
                        print("There are no copies to delete")
                    else:
                        print(f"The number of copies is currently {self.__graph.get_nr_of_copies()}")
                        print("Introduce the index of the copy that you want to delete>")
                        index_of_copy = int(input())
                        self.__graph.delete_copy(index_of_copy)
                elif user_option == 16:
                    print("Introduce the name of the file where you want to write the random graph>")
                    file_name_write_random_graph = input()
                    print("Introduce the number of vertices>")
                    nr_of_vertices = int(input())
                    print("Introduce the number of edges>")
                    nr_of_edges = int(input())
                    random_graph = Graph()
                    random_graph.generate_random_graph(nr_of_vertices, nr_of_edges, file_name_write_random_graph)
                elif user_option == 17:
                    print("Introduce the name of the file where you want to read the graph>")
                    file_name_read = input()
                    self.__graph.read_file(file_name_read)
                elif user_option == 18:
                    print("Introduce the name of the file where you want to write the graph>")
                    file_name_write = input()
                    self.__graph.write_file(file_name_write)
                elif user_option == 19:
                    start_vertex = int(input("Introduce the start vertex>"))
                    target_vertex = int(input("Introduce the target vertex>"))
                    path = self.__graph.find_shortest_path_between_2_vertex_backward_bfs(start_vertex, target_vertex)
                    print(path)
                elif user_option == 20:
                    start_vertex = int(input("Introduce the start vertex>"))
                    target_vertex = int(input("Introduce the target vertex>"))
                    path = self.__graph.find_lowest_cost_walk(start_vertex, target_vertex)
                    print(path)

                elif user_option == 21:
                    break




