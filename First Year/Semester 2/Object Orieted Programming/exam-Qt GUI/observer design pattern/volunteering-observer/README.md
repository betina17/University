﻿Volunteering
Write an application for the management of volunteers in an NGO, as follows:
1. The information about the departments is in a text file. A department has a name and a description. The file is manually created and it is read when the application starts.
2. Another file contains information about the volunteers. Each volunteer has a name, an email, a list of interests (separated by a separator of your choice) and the department he currently belongs to. It is possible for a volunteer to be part of no department at the current time. These are read when the application starts.
3. When the application is launched, a new window is opened for each department, having as title the department's name. The department's description will be shown on the window (0.25p). The window will show the list of all volunteers who belong to that department, sorted by their name (1p). The unassigned volunteers will be shown in a separate list (0.5p).
4. A new volunteer can be added from any window, by inputting the name, email and list of interests. A new volunteer is by default unassigned (1p). Display an error if the name or e-mail are empty (0.5p).
5. The application allows searching the top 3 most suitable unassigned volunteers for the current department. A suitability score for each volunteer is computed as: number of words from the volunteer's list of interest that are found in the department's description. divided by number of words in the department's description. The top 3 most suitable volunteers are displayed in the unassigned volunteers list (1.5p).
6. A selected volunteer in the unassigned volunteers list can be assigned to the current department, which involves updating the lists (1p).
7. Another window will show all departments, as well as the number of volunteers in each, sorted by the number of their volunteers (0.75p).
8. When a modification is made by any user, all the other users will see the modified list of items. Use the Observer design pattern (2p).
9. When the application finishes, the volunteers file is updated (0.5p)
Observations
1. 1p-of
2. The application must use layered architecture for functionalities to be graded.
3. If you do not read the data from file, you will receive 50% of functionalities 4, 5, 6 and 7.
You are allowed to use Qt Designer. You are allowed to use the following sites for documentation, but nothing else:
- http://doc.qt.io/qt-6/
- http://en.cppreference.com/w/
-http://www.cplusplus.com/