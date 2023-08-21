class SparseMatrix:
    def __init__(self, nr_row, nr_col):
        self.nr_row = nr_row
        self.nr_col = nr_col
        self.matrix_elem = []

    def set(self, row, col, value):
        element = [row, col, value]
        self.matrix_elem.append(element)

    def get(self, row, col):
        for list in self.matrix_elem:
            if list[0] == row and list[1] == col:
                return list[2]

    def print(self):
        sir = ""
        for i in range(0, self.nr_row):
            for j in range(0, self.nr_col):
                elem = False
                for list in self.matrix_elem:
                    if list[0] == i and list[1] == j:
                        sir+= str(list[2]) + " "
                        elem = True
                if elem ==False:
                    sir+=str(0) + " "
            sir+="\n"
        return sir


if __name__=="__main__":
    m1 = SparseMatrix(3,3)
    print(m1.print())
    print("\n")
    m1.set(1,1,2)
    m1.print()





