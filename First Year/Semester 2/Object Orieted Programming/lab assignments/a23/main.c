
#include "Ui.h"

///pot imbunatati proiectul sa arate mai mult ca a45
int main() {
    DynamicArray* array = createDynamicArray(100);
    Service* service = createService(array);
    UserInterface* userInterface = createUserInterface(service);
    TestDynamicArray();
    TestAdd();
    TestRemove();
    TestUpdate();
    menu(userInterface);
    destroyDynamicArray(array);
    destroyService(service);
    destroyUserInterface(userInterface);
    return 0;

}

