
DriveConnect
Write an application which simulates the communication between drivers, as follows:
1. The information about all registered drivers is in a text file. Each Driver has a name (string), a current location (latitude and longitude) and a score. This file is manually created and it is read when the application starts.
2. Another file contains road reports. Each Report has a description, the reporter - the name of the driver who reported it, the exact location (latitude and longitude) and a validation status (bool). These are read when the application starts.
3. When the application is launched, a new window is created for each driver, having as title the driver's name. The driver's current location and score are also shown (0.25p). The window will show all reports for the driver's region of interest (a radius of 10 units from the driver's current location - use the Euclidean distance). Reports will be shown with all their information and valid reports are shown with a bold font (1.5p)
4. Each driver's window will contain a real-time chat control, which allows all drivers to communicate. Messages sent by any driver will be visible to all other drivers. Messages are displayed together with the sender drivers' names (1.25p).
5. Any driver can add a new report, by inputting the description and exact location. The reporter will automatically be the name of the driver who added the report (1p). This operation fails if the description is empty, or if the report's location is more than 20 units away from the driver's location) (0.25p).
6. Drivers can validate reports, only if these were not validated yet. If a report is validated by 2 drivers other than the reporter, the report becomes valid and the reporter's score increases by 1 (1.25p)
7. A new window will show the "map" of all valid reports. Each report's location and description will be shown (use circles/rectangles/any geometry figure). This is shown when the application starts. (Hint: method paintEvent of the QWidget class and the QPainter class). (1p)
8. When a modification is made by any driver, all other drivers will see it, automatically. The map window will also be updated automatically. Use the Observer design pattern. (2p) 9. When the application closes, the reports file will be updated. (0.5p)
Observations
1. 1p-of
2. The application must use layered architecture in order for functionalities to be graded.
3. If you do not read the data from file, you will receive 50% of functionalities 3, 4, 5 and 6.
You are allowed to use Qt Designer.
You are allowed to use the following sites for documentation, but nothing else: -http://doc.qt.io/qt-6/
http://en.cppreference.com/w/
- http://www.cplusplus.com/