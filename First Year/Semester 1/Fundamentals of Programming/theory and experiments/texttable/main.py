# Import required module
from texttable import Texttable

class Board:
	def __init__(self, rows, cols):
		self.rows = rows
		self.cols = cols
		self.board = [[0 for j in range(self.cols)] for i in range(self.rows)]

	@property
	def board_get(self):
		return self.board

	def change_elem_in_board(self, row, col, elem):
		self.board[row][col] = elem

	def __str__(self):
		table = Texttable()
		create_header = ['X']
		for i in range(self.cols):
			create_header.append(chr(ord('A') + i))  #ord('A')-codul ascii, adica 65, +i=+cat e i, si chr(ord('A')+i) imi da B/C...etc
		table.header(create_header)
	    #asa pun headeru, adica linia de sus cu literele
		#X e neutru, apoi deasupra fiecarei coloane a matricei punem litera, de aia parcurgem self.cols
		for i in range(self.rows):
			current_row = self.board[i]
			for j in range(self.cols):
				if self.board[i][j] == 0:
					current_row[j] = ' ' #asta e o singura lista, e un singur rand, si j e indexul ei
					#eu asa schimb elem din matrice, in loc sa scriu self.board[i][j] = ' ', adica matricea de rand si coloana
	                #eu iau direct randul pe care sunt acum de coloana. e same shit oricum, dar fac asa ca sa imi schimbe
			        #doar in randul pe care vreau eu sa il pun in textable, nu schimba si in matrice. acolo ramane 0
					#e doar o chestie de afisaj
					#toate operatiile de schimbare de elemente pe care le fac le fac de fapt, le fac pe matrice
#si nu pe texttable. texttable ul doar ia fiecare linie din matrice si o afiseaza sub forma de texttable
#in el nu prelucrez nimic, decat ce tine de nivel de afisaj
			table.add_row([i] + self.board_get[i]) #tu in text table poti adauga doar liste, de asta adaug rand cu rand din matrice
			#am fc [i] +  self.board[i] ca sa imi puna coloana cu 1,2,3...aia din cea mai stanga si langa ea concatenat randul
		    #la care suntem

		return table.draw()

#bun, efectiv m am complicat, p