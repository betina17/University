class SparseMatrix:
    def __init__(self, nr_row, nr_col):
        self.nr_row = nr_row
        self.nr_col = nr_col
        self.matrix_elem = []

    def set(self, row, col, value):
        if row>=self.nr_row or col>=self.nr_col:
            raise ValueError
        ok = 0
        for list in self.matrix_elem:
            if list[0] == row and list[1] == col:
                ok = 1
                list[2] = value
        if ok == 0:
            element = [row, col, value]
            self.matrix_elem.append(element)
"""
    def set(self, row, col, value):
        if row>=self.nr_row or col>=self.nr_col:
            raise ValueError
        for list in self.matrix_elem:
            if list[0] == row and list[1] == col:
                self.matrix_elem.remove(list)
        element = [row, col, value]
        self.matrix_elem.append(element)
        
        cum mai puteam sa fac
"""

    def __str__(self):
        sir = ""
        for i in range(0, self.nr_row):
            for j in range(0, self.nr_col):
                elem = False
                for list in self.matrix_elem:
                    if list[0] == i and list[1] == j:
                        sir += str(list[2]) + " "
                        elem = True
                if elem == False:
                    sir += str(0) + " "
            sir += "\n"
        return sir

    def __repr__(self):
        return str(self)

    def get(self, row, col):
        for list in self.matrix_elem:
            if list[0] == row and list[1] == col:
                return list[2]

if __name__=="__main__":
    m1 = SparseMatrix(3,3)
    print(m1)
    m1.set(1,1,2)
    print(m1)
    print(m1.get(1,1))
    m1.set(1,1,m1.get(1,1)+1)
    print(m1)

