Microbial World
Write an application for biologists studying bacteria, as follows:
1. The information about the biologists is in a text file. Each biologist has a name (string) and a list of bacterial species that he/she studies. A bacterial species can be studied by more biologists. This file is manually created and it is read when the application starts.
2. Another file contains information about bacteria. Each Bacterium has a name, a species it belongs to, a size (int) and a list of diseases it causes. These are read when the application starts.
3. When the application is launched, a new window is created for each biologist, having as title the biologist's name. The window will show all bacteria having as species the species that the biologist studies, sorted by name, with all their information. This will be shown in a QTableView. (1.5p)
4. A combobox will be populated with the bacterial species that the biologist studies and will allow biologists to see only the bacteria in the selected species. (1p)
5. Any biologist can add a new bacterium, by inputting all its information (1p). This operation fails if there is another bacterium with the same name and species (0.5p)
6. When a bacterium is selected, a new list shows all diseases it causes. New diseases can be added to the list (0.75p). A biologist can update any bacterium's information, directly in the table. If the new species is not in the biologist's list, the bacterium disappears from the biologist's window. (0.75p)
7. When a modification is made by any biologist, all the other biologists will see the modified list of bacteria. The score for this functionality is given only if you are using the Qt Model/View architecture with custom models (2p).
8. Each biologist will have a "View" button that allows him/her to see all bacterium, by species, in a new window. On the window, each species is represented by a text with the species' name and above/below the text a new shape (circle/rectangle) will be drawn for each bacterium of that species. (1p) (Hint: method paintEvent of the QWidget class and the QPainter class.)
9. When the application finishes, all bacteria are saved to the file. (0.5p)
?
Sc
nvi
Observations
1. 1p-of
2. The application must use layered architecture in order for functionalities to be graded.
3. If you do not read the data from file, you will receive 50% of functionalities 3, 4, 5 and 6.
You are allowed to use Qt Designer.
You are allowed to use the following sites for documentation, but nothing else:
- http://doc.qt.io/qt-6/
- http://en.cppreference.com/w/
- http://www.cplusplus.com/
F