from copy import deepcopy
from random import randrange
from queue import Queue

class Graph:
    def __init__(self):
        self.__predecessors_dict = {} #here i have the successors as key and the predecessors as values
        self.__successors_dict ={} #here i have the predecessors as key and the successors as values
        self.__cost_of_edges_dict = {} #here i have the two vertices that form te edge in a tuple which represents the key, and the cost of the edge is its value
        self.__set_of_vertices = []
        self.__list_of_copies = []
        self.__nr_of_vertices = 0
        self.__nr_of_edges = 0

    #vertex_in e cel in care intra muchia, vertex_out e cel din care iese muchia, adica originea. vertex_in e succesorul lui vertex_out, vertex_out e predecsorul lui vertex_in

##################CREATE DATA STRUCTURES#########################################################################################################################################

    def create_successors_and_predecessor_dict_with_empty_list_for_isolated_nodes(self):
         for i in range(self.__nr_of_vertices):
             if i not in self.__successors_dict:
                 self.__successors_dict[i] = []
             if i not in self.__predecessors_dict:
                 self.__predecessors_dict[i] = []

    '''
    am facut chestia asta pt ca in fisierele facute de mine, nodurile izolate sunt scrise singure pe o linie ex:
    1 2 2 
    3
    4 1 3
    si eu pt genul asta de fisier am facut functia de citire. PLUS CA eu nu consider ca in fisierul meu exista elemente de la 0 la n, n elemente
    eu zic ca sunt noduri intre 1 si 1000, dar nu trb sa aiba toate valorile. in fisierele de la scoala, nodurile izolate nu sunt scrise deloc in fisier,
    dar se considera ca exista n nofuri, toate de la 1 la n. deci de asta am facut si functia asta, pt ca nodurile care nu apar deloc in fisier practic eu
    nu le am citit de niciunde, pt ca eu populez dictionarele doar cu nodurile care imi apar efectiv in fisier, ca pt mine cealalte sunt inexistente
    ca nu consider ca existe toate la start de la 1 la n. asa ca dupa citirea mea normala, pt fisierle cum le am gandit eu, apelez si functia asta,
    care ia toate valorile de la 1 la n, si daca vede ca o valoare nu are dictionar, ii face, pt ca inseamna ca era nod izolat in genu de fisier de la scoala
    asa nu am mai schimbat functia mea de citire, da, e mai ineficient, puteam sa fac doua tipuri de functii de citire separat, dar totul se complica
    mai mult si trebuiau schimbate mai multe. daca vreau sa lucrez doar pe fisiere de genul meu, pur si simpu sterg apelul functiei acesteia din read_file
    '''


    def create_data_dictionaries(self, vertex_out, vertex_in, cost_edge):
        if vertex_out not in self.__successors_dict:
            self.__successors_dict[vertex_out] = []
        self.__successors_dict[vertex_out].append(vertex_in)

        if vertex_out not in self.__predecessors_dict:
            self.__predecessors_dict[vertex_out] = []

        if vertex_in not in self.__predecessors_dict:
            self.__predecessors_dict[vertex_in] = []
        self.__predecessors_dict[vertex_in].append(vertex_out)

        if vertex_in not in self.__successors_dict:
            self.__successors_dict[vertex_in] = []

        self.__cost_of_edges_dict[(vertex_out, vertex_in)] = cost_edge



    def create_the_set_of_vertices(self):
        for i in range(0, self.__nr_of_vertices):
            if i in self.__successors_dict:
                self.__set_of_vertices.append(i)
            else:
                if i in self.__predecessors_dict:
                    self.__set_of_vertices.append(i)
        self.__set_of_vertices.sort()

    def read_file(self, file_name_read):
        file = open(file_name_read, "r")
        self.__nr_of_vertices, self.__nr_of_edges = file.readline().split()
        self.__nr_of_vertices = int(self.__nr_of_vertices)
        self.__nr_of_edges = int(self.__nr_of_edges)
        for line in file.readlines():
            elements = line.split() #foarte tare asta
            if len(elements) == 1:
                vertex_out = elements[0]
                vertex_in = None
                cost_edge = None
                if vertex_out not in self.__successors_dict:
                    self.__successors_dict[vertex_out] = []
                    #aici de ce fac doar de successors?
            else:
                vertex_out = int(elements[0]) #nu pot face int la split
                vertex_in = int(elements[1])
                cost_edge = int(elements[2])
                self.create_data_dictionaries(vertex_out, vertex_in, cost_edge)
        self.create_the_set_of_vertices()
        self.create_successors_and_predecessor_dict_with_empty_list_for_isolated_nodes()


    def write_file(self, file_name_write):
        file = open(file_name_write, "w")
        file.write(f"{self.get_nr_of_vertices()} {self.get_nr_of_edges()}\n")
        for vertex_out in self.parse_set_of_vertices():
            if self.get_out_degree_of_vertex(vertex_out) == 0 and self.get_in_degree_of_vertex(vertex_out) == 0:
                file.write(f"{vertex_out}\n")
            else:
                for vertex_in in self.parse_successors_of_a_vertex(vertex_out):
                    file.write(f"{vertex_out} {vertex_in} {self.get_cost_of_edge(vertex_out, vertex_in)}\n")
        file.close()

#################################################VERTEX OPERATIONS##############################################################################################################
    def verify_if_vertex(self, vertex):
        if vertex not in self.__set_of_vertices:
            return False
        return True

    def get_nr_of_vertices(self):
        return len(self.__set_of_vertices)

    def get_nr_of_edges(self):
        return len(self.__cost_of_edges_dict)

    def parse_successors_of_a_vertex(self,vertex): #outbound edges = successors
        if not self.verify_if_vertex(vertex):
            raise Exception("Invalid vertex!")
        for successor in self.__successors_dict[vertex]:
            yield successor

    def parse_predecessors_of_a_vertex(self,vertex): #outbound edges = successors
        if not self.verify_if_vertex(vertex):
            raise Exception("Invalid vertex!")
        for predecessor in self.__predecessors_dict[vertex]:
            yield predecessor


    def get_in_degree_of_vertex(self, vertex):
        if not self.verify_if_vertex(vertex):
            raise Exception("Invalid vertex!")
        return len(self.__predecessors_dict[vertex])

    def get_out_degree_of_vertex(self, vertex):
        if not self.verify_if_vertex(vertex):
            raise Exception("Invalid vertex!")
        return len(self.__successors_dict[vertex])

    def parse_set_of_vertices(self):
        for vertex in self.__set_of_vertices:
            yield vertex

    def add_vertex(self, new_vertex, file_name_write):
        if self.verify_if_vertex(new_vertex):
            raise Exception("Vertex already exists!")
        self.__set_of_vertices.append(new_vertex)
        self.__predecessors_dict[new_vertex] = []
        self.__successors_dict[new_vertex] = []
        self.write_file(file_name_write)

    def remove_vertex(self, vertex_to_remove, file_name_write):
        if not self.verify_if_vertex(vertex_to_remove):
            raise Exception("Vertex doesn't exist!")
        for predecessor in self.__predecessors_dict[vertex_to_remove]:
            self.__cost_of_edges_dict.pop((predecessor, vertex_to_remove)) #key in cost_dict e (vertex_out, vertex_in), iar predecesorul e vertex_out, iar vertex_to_remove
                                                                           #e successorul

            self.__successors_dict[predecessor].remove(vertex_to_remove)
        self.__predecessors_dict.pop(vertex_to_remove)

        #mergem in dictionarul cu predecesori, unde vertex_to_remove e succesorul, si luam fiecare predecesor al lui vertex_to_remove si eliminam
        #cost_of_edge(predecesor, vertex_to_remove), apoi mergem in dictionarul cu succesori, unde predecesorul actual va fi cheia, iar de acolo il stergem pe vertex_to_remove
        #din lista de succesori. dupa ce am facut asta pentru toti predecesorii, sterg cu totul din dictionarul de predecesori perechea cu cheia=vertex_to_remove

        for successor in self.__successors_dict[vertex_to_remove]:
            self.__cost_of_edges_dict.pop((vertex_to_remove, successor)) #aici vertex_out = vertex_to_remove, vertex_in e succesorul

            self.__predecessors_dict[successor].remove(vertex_to_remove)
        self.__successors_dict.pop(vertex_to_remove)

        self.__set_of_vertices.remove(vertex_to_remove)
        self.write_file(file_name_write)

        # mergem in dictionarul cu succesori, unde vertex_to_remove e predecesorul, si luam fiecare succesor al lui vertex_to_remove si eliminam
        # cost_of_edge( vertex_to_remove, succesor), apoi mergem in dictionarul cu predecesori, unde succesorul actual va fi cheia, iar de acolo il stergem pe vertex_to_remove
        # din lista de predecesori. dupa ce am facut asta pentru toti succesorii, sterg cu totul din dictionarul de successori perechea cu cheia=vertex_to_remove
        #e acelasi proces ca inaite, dar cu ordinea dictionarelor inversata


################################################################EDGE OPERATIONS################################################################################################

    def verify_if_edge(self, vertex_out, vertex_in):
        if self.verify_if_vertex(vertex_in) and self.verify_if_vertex(vertex_out):
            #check if vertex out has vertex in as a successor
            for successor in self.__successors_dict[vertex_out]:
                if successor == vertex_in:
                    return True
        return False

    def modify_cost_of_edge(self, vertex_out, vertex_in, new_cost, file_name_write):
        if not self.verify_if_edge(vertex_out, vertex_in):
            raise Exception("Invalid edge!")
        self.__cost_of_edges_dict[(vertex_out, vertex_in)] = new_cost
        self.write_file(file_name_write)
        #return self.__cost_of_edges_dict[(vertex_out, vertex_in)]


    def get_cost_of_edge(self, vertex_out, vertex_in):
        if not self.verify_if_edge(vertex_out, vertex_in):
            raise Exception("Invalid edge!")
        return self.__cost_of_edges_dict[(vertex_out, vertex_in)]


    def add_edge(self, vertex_out, vertex_in, cost_of_edge, file_name_write):
        #so both vertices have to already exist in order to add this edge, or if they don't exist, then we should add the vertices first?
        if not self.verify_if_vertex(vertex_out) and self.verify_if_vertex(vertex_in):
            raise Exception("One or both vertices don't exist, so you cannot add this edge!")
        if self.verify_if_edge(vertex_out, vertex_in):
            raise Exception("This edge already exists!")
        self.create_data_dictionaries(vertex_out, vertex_in, cost_of_edge)
        self.write_file(file_name_write)


    def remove_edge(self, vertex_out, vertex_in, file_name_write):
        if not self.verify_if_edge(vertex_out, vertex_in):
            raise Exception("This edge does not exist!")
        self.__predecessors_dict[vertex_in].remove(vertex_out)
        self.__successors_dict[vertex_out].remove(vertex_in)
        self.__cost_of_edges_dict.pop((vertex_out, vertex_in))
        self.write_file(file_name_write)

    def copy(self):
        copy_of_graph = deepcopy(self)
        self.__list_of_copies.append(copy_of_graph)

    def get_nr_of_copies(self):
        return len(self.__list_of_copies)

    def get_copy(self, index):
        if index < 0 or index >= len(self.__list_of_copies):
            raise Exception("Invalid index!")
        return self.__list_of_copies[index]

    def delete_copy(self, index):
        if index < 0 or index >= len(self.__list_of_copies):
            raise Exception("Invalid index!")
        self.__list_of_copies.pop(index)

    def generate_random_graph(self, nr_of_vertices, nr_of_edges, file_name_write):
        for i in range(nr_of_vertices):
            self.add_vertex(i, file_name_write)
        self.create_successors_and_predecessor_dict_with_empty_list_for_isolated_nodes(nr_of_vertices)
        for j in range(nr_of_edges):
            vertex_out = randrange(nr_of_vertices)
            vertex_in = randrange(nr_of_vertices)
            while self.verify_if_edge(vertex_out, vertex_in):
                vertex_out = randrange(nr_of_vertices)
                vertex_in = randrange(nr_of_vertices)
            #cat timp edge-ul ala exista deja, incearca alte variante pt vertexuri. cand gaseste 2 care nu formeaza un edge deja, iese din while
            cost_of_edge = randrange(100)
            self.create_data_dictionaries(vertex_out, vertex_in, cost_of_edge)
        self.write_file(file_name_write)

    def find_shortest_path_between_2_vertex_backward_bfs(self, start_vertex, target_vertex):
        #pt ca e backward, plec de la target_vertex pana la start, si atunci parcurg bfs-ul doar pe predecesorii fiecarui nod
        visited = []
        successors = {}
        queue = Queue()
        path_found = 0
        #iau asta pt ca poate nu e o cale pana la acel nod de la nodul de start, mai ales ca e orientat, dar si pt ca poate e izolat

        successors[target_vertex] = None
        #nu ne intereseaza succesorii targetului, pt ca de la el plecam si mergem pe predecesori, adica o sa mergem inapoi de la target la start, si asta inseamna
        #ca parcurgem succesorii de la start la target(doar ca in cazul backward, invers) si acolo ne oprim, adica succesorii targetului nu ne intereseaza
        #deci spunem ca successors[target_vertex] = None
        queue.put(target_vertex)
        visited.append(target_vertex)


        start_reached = False
        while queue.empty() == False and start_reached == False:
            current_node = queue.get()
            if current_node == start_vertex: #daca gasim nodul de start, oprim iteratia, am gasit path-ul
                path_found = 1
                break
            else:
                for predecessor in self.__predecessors_dict[current_node]: #parcurgem dictionarul de predecesori al fiecarui nod curent-backward
                    if predecessor not in visited:
                        successors[predecessor] = current_node
                        if predecessor == start_vertex: #daca gasim nodul de start, oprim iteratia, am gasit path-ul.
                            path_found = 1
                            start_reached = True
                            break
                        else:
                            visited.append(predecessor)
                            queue.put(predecessor)

        if path_found == 1: #reconstruim path-ul plecand de la nodul de inceput, mergand pe succesorul fiecarui nod, pana la nodul target
            path = []
            node_in_path = start_vertex
            path.append(node_in_path)
            while successors[node_in_path] != None:
                if node_in_path == target_vertex:
                    path.append(target_vertex)
                else:
                    node_in_path = successors[node_in_path]
                    path.append(node_in_path)

            return path

        else:
            return "The path between these vertices doesn't exist"



    def find_lowest_cost_walk(self,start_vertex, end_vertex):
        inf = 99999
        distance = [inf] * self.__nr_of_vertices #initializez distantele cu infinit, asta inseamna ca inca nu am gasit niciun path pana la acel nod
                                                #de la start_vertex inca
        distance[start_vertex] = 0
        predecessor = [-1] * self.__nr_of_vertices
        for i in range(0, self.__nr_of_vertices-1): #parcurg de nr_of_vertices-1 ori, pt ca la ultima iteratie nu mai am ce actualiza
            updated = False
            for edge in self.__cost_of_edges_dict: #edge o sa fie fiecare cheie din dictionar
                edge_start=edge[0]
                edge_end=edge[1]
                if edge_end != start_vertex: #aici as avea o muchie care se termina in start vertex, si nu ma intereseaza distanta pana la ea
                    if distance[edge_start] + self.__cost_of_edges_dict[edge] < distance[edge_end]:
                        updated = True
                        predecessor[edge_end] = edge_start
                        distance[edge_end] = distance[edge_start] + self.__cost_of_edges_dict[edge]
                        #daca distanta "noua" e mai mica decat cea veche, atunci o actualizez

            if updated == False:
                        break

        if distance[end_vertex] == inf: #daca distanta a ramas tot inf, inseamna ca nu am gasit nicio cale de la nodul de start pana la cel de final
                                        #pentru ca distanta nu s-a modificat deloc
            return "There is no path between these two vertices"

        #daca avem path, il construim
        path = []
        current_vertex = end_vertex
        path_length = 0
        while predecessor[current_vertex] != -1 and path_length < self.__nr_of_vertices:
            path.append(current_vertex)
            path_length = path_length+1
            current_vertex = predecessor[current_vertex]
        path.append(current_vertex)
        path.reverse()

        #verificam daca path-ul este un ciclu de cost negativ, daca nu, il afisam
        #e ciclu negativ daca putem mai relaxa cel putin un nod din acel path- ca inseamna ca acel nod se poate relaxa la infinit, adica costul
        #de la start la acel nod poate fi infinit, deci e ciclu negativ, si tot path-ul e ciclu negativ
        for edge in self.__cost_of_edges_dict:
            edge_start = edge[0]
            edge_end = edge[1]
            if edge_end != start_vertex: #din nou, nici aici nu ma intereseaza costul nodului de start
                if distance[edge_start] + self.__cost_of_edges_dict[edge] < distance[edge_end]:
                    if edge_end in path: #daca nodul care se poate relaxa la infinit se afla in path, atunci path-ul e ciclu negativ
                        return "The lowest cost path between these two vertices is a negtive cycle"

        return f"The lowest cost path between {start_vertex} and {end_vertex} is {distance[end_vertex]}  and the path is {path}"

'''
FOARTE IMPORTANT!!!!
DE CE AVEM NEVOIE DE IF-UL if edge_end in path: LA VERIFICAREA CICLULUI NEGATIV
incearca pe exemplul de pe ford2.txt
la ford2.txt nu exista path intre A si E (0 si 4), pentru ca E e implicat in ciclu negativ(vezi pe parcurgerea manuala, sau fa debug)
cum E e conectat totusi cu A, ai putea spune ca este un ciclu negativ de la starting vertex, si gata, nu putem gasi path intre nodul de start
si oricare altul, deci doar returnam "ciclu negativ de la vertex de start". dar asta ar fi gresit, pentru ca, chiar daca exista ciclu
negativ in graf, si A are path pana la el, daca vrem sa gasim lowest cost path de la A la C, ne va gasi, nu ne va arata ca avem ciclu negativ.
pt ca exista lowest cost path de la A la C chiar daca exista si un ciclu negativ de la A (daca mergem spre E). dar el nu afecteaza nodurile
din path-ul de la A la C (de A nu ne intereseaza, pe el nu-l luam in considerare, pt ca costul lui A va ramane mereu constant, ca nu ne pasa
de el, e nod de inceput). o sa vezi ca daca stergi if-ul, o sa iti dea ca ai negative cycle si la A-C, ceea ce nu e corect, pt ca nu ai, si 
poti gasi lowest cost path intre A si E
'''

    #pentru parcurgerea manuala as fi putut alege si un graf care sa nu aiba negative cost cycles, doar sa nu exista vreun path
    #de la A la E, si atunci mi s-ar fi afisat mesajul path not found, dar am ales sa am graf cu negative cost cycle
    #ca sa inteleg mai bine cum functioneaza ciclurile astea.




'''
DE CE VERIFICAM ASA LA FINAL DACA EXISTA NEGATIVE CYCLE?
Now, the key point is that after num_vertices - 1 iterations of the main loop, we should have found the shortest paths to all vertices if there are no negative-weight cycles. 
This is because, in a graph with num_vertices vertices, the longest possible shortest path (i.e., the path passing through the most edges) has num_vertices - 1 edges.

Therefore, if we can still find an edge that would provide a shorter path to its destination vertex (distance[edge.u] + edge.weight < distance[edge.v]), this means that
 we have a cycle, and because we're relaxing the edge, it must be a negative cycle. That's why we print a message and return early in this case.
 
because if we can still relax the edge and make the distance from the starting to the end vertex less costly(relax the edge), then that means that the cost is negative
in this context, distance refers to the total cost of the walk froms start to end vertex (which is the shortest path in our case, cause that's what we're looking for)
so if the total cost of a walk is negative, then we have a negative cycle
Checking if any of the distances are negative after the first loop would only indicate if there exists a path from the start vertex to some vertex with a negative total 
cost. However, this doesn't necessarily imply the presence of a negative cycle.

A negative cycle refers to a cycle (a path starting and ending at the same vertex) where the total weight of the cycle is negative. The danger of negative cycles is 
that you can keep going around the cycle indefinitely to decrease the total cost of the path, so the concept of a "shortest path" doesn't really make sense.

The check for negative cycles in the Bellman-Ford algorithm is done by doing one more relaxation step for all edges after the first loop. If we can still relax any edges 
(i.e., find a shorter path to a vertex), then we have a negative cycle. This is because, in a graph with no negative cycles, the shortest path between any two vertices can
 be found within |V| - 1 iterations (where |V| is the number of vertices in the graph). If we can still find a shorter path after |V| - 1 iterations, this means we have 
 a negative cycle.

'''



'''
DE CE FACEM N-1 ITERATII?
CHATGPT:
After each iteration, the algorithm ensures that the shortest path of at most a certain number of edges is calculated correctly. After the first
 iteration, all vertices directly connected to the source have their shortest path calculated. After the second iteration, all vertices two edges 
 away from the source have their shortest path calculated, and so on. After n-1 iterations, the shortest path for all vertices, considering paths 
 of at most n-1 edges (which is the maximum number of edges that any shortest path can have in a graph without cycles) is calculated.

And as you pointed out, if there are fewer edges in the shortest path to a vertex, it will reach its final shortest path value even before the n-1 
iterations, but we do n-1 iterations to ensure that all vertices reach their final shortest path values, even in the worst case where the shortest
 path involves n-1 edges.

Finally, if we perform another iteration and any vertex's shortest path estimate improves, it means there's a negative cycle, because without a 
negative cycle, n-1 iterations should have been enough to find the shortest paths. This is how the Bellman-Ford algorithm detects negative cycles.

EU:
so the idea is that after the first iteration, it is sure that the cost of the vertex that follows the start vertex will be the lowest, and after 
the second iteration, the cost of the third vertex in the path (the first being the starting one, the second the one that follows the starting one)
 will be the lowest, and after the n-1 iteration, the cost of the last vertex from the path, which is the target one (which is the number n vertex
  if the path had the maximum length n-1, cause that's the maximum length that a path from a vertex to another one can have, is the maximum. this is
   why we iterate n-1 times. cause if we have a maximum length path, meaning n-1 edges path, it is 100% sure only at the n-1 iteration that the 
   number n vertex will have the lowest cost. its lowest cost can be found even faster, but as chatgpt said earlier, this is the worst case scenario
   , but its sure that at this iteration we will have found its lowest cost-if the path is not a negative cycle, of course)
   
nu am stat sa parcug sa vad exact DE CE e chiar asa, de ce am nevoie doar de o iteratie sa gasesc lowest cost pt nodul 2, de 2 iteratii sa gasesc
shortest path pt nodul 3, de 3 iteratii sa gasesc shortest path pt nodul 4, si asa mai departe, dar nici nu mai stau, imp e ca stiu
de ce facem atatea iteratii

'''
'''
ai grija cand mai faci fisiere cu noduri, sa le pui in ordine, toate edge-urile care incep cu 0, apoi care incep cu 1 si tot asa, ca asa sunt
toate fisierele tale, si pt ca pt algoritmu asta, tu asa parcurgi, de la start vertex mergi pe fiecare muchie, apoi iei urmatoru vertex
si toate muchiile si tot asa, si e mai bine sa le ai in ordine, ca sa iti fie mai usor la debugging 
'''

'''
sunt foarte mandra de mine ca m am gandit singura la situatia asta si mi-am dat seama singura de if-ul asta, pe curs nu era si nici chatgpt nu mi-a 
zis de el:
DE CE AVEM NEVOIE DE IF-UL if edge_end in path: LA VERIFICAREA CICLULUI NEGATIV
'''

'''
PENTRU BFS BACKWARD
uita-te si pe parcurgere manuala daca vrei. fiecare nod are un singur copil pt ca copiii sunt ceicare alcatuiesc path-ul de la start vertex la end vertex
cand consruim path-ul, plecam de la start vertex
conditia de visited e pusa pentru ca noi avem nevoie de shortest path. dif dintre 2->4 si 2->3->4 e ca 3 a fost deja vizitat pt ca e deja tata cuiva
, are succesor pe 4. deci mai direct va fi drumul de la 2 la 4 decat de la 2 3 4. tre sa parcurgi ca sa inteleg ce zic. ideea e ca e pus pt shortest path.
The condition if predecessor not in visited: is an important aspect of the breadth-first search (BFS) algorithm which is used to avoid revisiting the same vertex in the graph multiple times. Here are a few reasons why this condition is crucial:

Prevents infinite loops: Without this condition, the algorithm might end up traversing the same edges over and over again, especially in cyclic
 graphs, leading to an infinite loop.

Optimization: It's computationally inefficient to visit the same vertex multiple times. This condition ensures that each vertex is visited only 
once, thereby reducing unnecessary operations.

Correct path reconstruction: The visited list and the successors dictionary together are used to trace back the path from the start_vertex to the 
target_vertex. By ensuring that each vertex is visited only once, the successors dictionary will correctly represent the shortest path.

Avoiding overlapping paths: If the visited condition was not present, a single node might be reachable from multiple paths. In such a case, we might
 end up with multiple entries for the same node in the successors dictionary, potentially leading to incorrect path reconstruction.

So, in essence, the condition if predecessor not in visited: ensures that the algorithm doesn't revisit vertices, thus ensuring computational 
efficiency and correct path reconstruction.

ai pe tableta la grafuri un graf, fa pe el parcurgere sa vezi la 2 3 4 cum merge si de ce e imp visited
'''

'''793 e nod izolat in g10k.txt
'''






