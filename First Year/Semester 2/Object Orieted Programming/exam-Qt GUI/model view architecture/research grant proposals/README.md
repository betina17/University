Research grant proposals
Write an application which simulates proposing research grants by a research team, as follows:
1. The information about the researchers working in the team is in a text file. Each researcher has a name (string) and his/her position - can be phd student, postdoc or senior (string). This file is manually created and it is read when the application starts.
2. Another file contains information about the research ideas that were proposed by researchers. Each Idea has a title, a description, a status (can be proposed or accepted), the creator - the name of the researcher who proposed it and the duration - the number of years needed for implementation (can be 1, 2 or 3). These are read when the application starts.
3. When the application is launched, a new window is created for each researcher, having as title the researcher's name. The researcher's position will also be shown on the window (0.25p). The window will show all the ideas launched so far (title, status, creator, duration), sorted by duration. These will be shown in a QTableView (1p).
4. Any researcher can add a new idea, by inputting the idea's title, description and duration. The idea's creator will automatically be the name of the researcher who added it and the status will be proposed. (1p). This operation fails if the title is empty or if the duration is not 1, 2 or 3 (0.5p).
5. Senior researchers can revise ideas and accept them. This will be possible only if the status of the selected idea is proposed. When an idea is accepted, its status changes to accepted (1p).
6. When a modification is made by any researcher, all the other researchers will automatically see the modified list of ideas. The score for this functionality is given only if you are using the Qt Model/View architecture with custom models (2p).
7. Each researcher has the possibility to further develop his accepted ideas. A button "Develop" will be available only to the researchers having accepted ideas (0.5p). When this button is clicked, each accepted idea will be shown separately, including its description, and a new "Save" button will be available for each (1p). The researcher can develop each accepted idea's description, which will be updated and then save each idea to a file. The file name will be the idea's title (0.75p).
8. Senior researchers have a button "Save all", which will save to a file all accepted ideas: the file will contain the accepted ideas (title), their creators (in brackets), duration, description and will be sorted by duration (1p).
Hints
To be able to select a row from a QTableView: use function
setSelectionBehavior (QAbstractItemView:: SelectRows) and make sure to set the Qt::ItemIsSelectable flag in the associated model;
To create a QModelIndex you can use function createIndex.
Observations
1. 1p-of
2. The application must use layered architecture in order for functionalities to be graded.
3. If you do not read the data from file, you will receive 50% of functionalities 3, 4, 5 and 6.
You are allowed to use Qt Designer..
You are allowed to use the following sites for documentation, but nothing else:
- http://doc.qt.io/qt-6/
- http://en.cppreference.com/w/
- http://www.cplusplus.com/