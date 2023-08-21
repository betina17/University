#include "ResearchGrantProposals.h"
#include <QtWidgets/QApplication>
#include "Repository.h"
#include "IdeasTableModel.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository repository;
    IdeasTableModel* model = new IdeasTableModel{ repository.get_ideas()}; 
    //puteam sa ii dau tot repo-ul, sau pot sa ii dau doar baza de date pe care o foloseste, cum am facaut si la observer.
    //la observer ai sesiunea in care se intampla chestii, pe aia o observi, la model view ai modelul in care se intampla chestii
    //la sesiunea ii dadeam dadeam doar partea din repo de care avea nevoie, de ex doar un vector din repo, nu tot repo-ul
    //si pe langa mai adaugam in sesiune ce aveam nevoi. asa fac si la model, ii dau doar partea de repo de care are nevoie, pe
    //care o afiseaza/prelucreaza/la care mai adauga etc
    for (Researcher& researcher : repository.get_researchers())
    {
        ResearchGrantProposals* new_window = new ResearchGrantProposals(researcher,model);
        //ResearchGrantProposal e numele proiectului, practic, numele window-ului, cum la modelele cu observer am dat in care 
        //proiectu se chema Window am dat Window* new_window
        new_window->show();
    }
   
    //F IMP!!!asa faci ca la inchiderea modelului sa se execute functia write_to_file....
    //connect(sender, signal, instance of class of receiver, receiver)
    return a.exec();
   
}
//trebe neaparat sa pun -> si nu ., pt ca model e declarat pointer , deci ca sa 
    //accesez o metoda de acolo trebe sa pun ->, altfel imi da "expression must have class type but it has 
    //type class* (asta inseamna ca daca pun punct, trebe model sa aiba tipul clasei simplu,
    //dar are tipul clasei pointer
