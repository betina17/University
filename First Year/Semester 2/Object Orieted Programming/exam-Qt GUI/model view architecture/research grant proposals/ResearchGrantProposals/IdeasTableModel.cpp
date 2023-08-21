#include "IdeasTableModel.h"
#include <fstream>
#include <QMessageBox>
IdeasTableModel::IdeasTableModel(std::vector<Idea>& ideas)
{
	std::sort(ideas.begin(), ideas.end(), [](Idea& idea1, Idea& idea2) {return idea1.get_duration()
		> idea2.get_duration(); });
	this->ideas = ideas;
}

int IdeasTableModel::rowCount(const QModelIndex& parent) const
{
	return ideas.size();
}

int IdeasTableModel::columnCount(const QModelIndex& parent) const
{
	return 5;
}

QVariant IdeasTableModel::data(const QModelIndex& index, int role) const //se apeleaza pt fiecare casuta din table
																		//fiecare casuta are index de coloana si row
{
	if (role == Qt::DisplayRole || role == Qt::EditRole) //the function provides data to be displayed or edited
	{
		int row = index.row();
		int column = index.column();
		Idea idea = ideas[row];
		switch (column)
		{
		case 0: //coloana 0
			return QString::fromStdString(idea.get_title());
		case 1:
			return QString::fromStdString(idea.get_description());
		case 2:
			return QString::fromStdString(idea.get_status());
		case 3:
			return QString::fromStdString(idea.get_creator());
		case 4:
			return QString::fromStdString(std::to_string(idea.get_duration()));
		default:
			break;
		}
	}
	return QVariant(); //in caz ca nu returneaza altceva, am terminat casutele
}

QVariant IdeasTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{	
	if (role == Qt::DisplayRole) //in header doar se da display la date, ele nu pot fi editate deci nu are si rol de edit
	{
		if (orientation == Qt::Horizontal)
		{
			switch (section) //stie ca sectiunile sunt coloanele, ca i-am zis ca orientarea e orizontala
			{
			
			case 0:
				return QString{ "title" };
			case 1:
				return QString{ "description" };
			case 2:
				return QString{ "status" };
			case 3:
				return QString{ "creator" };
			case 4:
				return QString{ "duration" };
			default:
				break;
			}
		}
	}
	return QVariant();
}
void IdeasTableModel::add_idea(Idea& new_idea)
{
	//implementare standard a functiei de add
	beginInsertRows(QModelIndex{}, this->rowCount(), this->rowCount()); 
	ideas.push_back(new_idea);
	endInsertRows();
	emit dataChanged(this->index(0, 0), this->index(this->rowCount() - 1, this->columnCount() - 1));
	//asta e gen update de la observer. asta anunta fiecare view ca modelu s-a schimbat, fiecare view 
	//fiind fiecare window 
}

void IdeasTableModel::write_to_file_ideas_from_model()
{
	std::ofstream fout("Ideas.txt");
	for (int i = 0; i < ideas.size(); i++)
	{
		fout << ideas[i].get_title() + "|" + ideas[i].get_description() + "|" +
			ideas[i].get_status() + "|" + ideas[i].get_creator() + "|" + std::to_string(ideas[i].get_duration()) + "|";
		if (i != ideas.size() - 1)
			fout << "\n";
	}
	fout.close();
}

bool IdeasTableModel::setData(const QModelIndex& index, const QVariant& value, int role)
{	
	if(role!= Qt::EditRole)
		return false;
	else
	{
		int row = index.row();
		int col = index.column();
		Idea& current_idea = ideas[row]; //iei ideea de pe row-ul pe care esti
		switch (col)
		{
		case 0: //daca suntem pe coloana 0, inseamna ca vom schimba title-ul
		{	
			if (current_idea.get_status() == "proposed")
				current_idea.set_title(value.toString().toStdString());
			break;
		}
		//toString e ca sa faci din QVariant in QString, iar toStdString e ca sa faci din QString in string normal
		case 1:
		{	
			if (current_idea.get_status() == "proposed")
				current_idea.set_description(value.toString().toStdString());
			break;
		}
		case 2:
		{
			if (current_idea.get_status() == "proposed" && value.toString() == "accepted")
				current_idea.set_status("accepted");
			break;
		}
		case 3:
		{	if (current_idea.get_status() == "proposed")
				current_idea.set_creator(value.toString().toStdString());
			break;
		}
		case 4:
		{	if (current_idea.get_status() == "proposed")
				current_idea.set_duration(value.toString().toInt());
			break;
		}
		default:
			break;
		}
	}
	emit dataChanged(this->index(0, 0), this->index(this->rowCount() - 1, this->columnCount() - 1));
}
//revise ideas = be able to edit/update ideas

Qt::ItemFlags IdeasTableModel::flags(const QModelIndex& index) const
{
	return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

/*ABOUT FUNCTION "ADD_IDEA"
* addStar(std::string name, std::string constellation, int RA, int dec, int diameter): This function adds a new
Star to the underlying repository and notifies any connected views about the change.

beginInsertRows(QModelIndex{}, this->rowCount(), this->rowCount());: This line is necessary to correctly
interact with views. It informs the model/view framework that rows are about to be inserted. In this case,
one row at the end of the table.


endInsertRows();: This line signals the end of row insertion.

emit dataChanged(this->index(0, 0), this->index(this->rowCount() - 1, this->columnCount() - 1));: This line is
similar to the one in updateInternalData(). It signals that data has changed in the range from the top-left to
the bottom-right cell. After the new star is added, the model is letting any views know that they should 
refresh to display the new data.
*/
/*ABOUT FUNCTION "HEADERDATA"
* This function takes three parameters: an int representing the section, a Qt::Orientation indicating whether the header is 
horizontal (column header) or vertical (row header), and an int representing the role.

section corresponds to the index of the header. For a table view, a horizontal header's section would correspond to the column 
index, and a vertical header's section would correspond to the row index.
orientation specifies whether the header is horizontal or vertical.
role is used to specify what kind of data is being requested, similar to the data function you asked about earlier. The most 
commonly used role is Qt::DisplayRole for displaying data.
If the role is Qt::DisplayRole, it means the function needs to provide data to be displayed in the header.

If the orientation is Qt::Horizontal, it means the function is being asked to provide the headers for the columns of the table
(as opposed to the rows).

A switch statement is used to determine what header text to return based on the section index. It looks like if the section is 0,
the header is "Name"; if the section is 1, the header is "Constellation"; and so on for the other cases.

If the section index does not fall into any of the defined cases, or if the role is not Qt::DisplayRole, or if the orientation is
not Qt::Horizontal, a default constructed QVariant is returned. The QVariant class in Qt is a union for the most common Qt data
types, capable of storing different types of data.
*/

/*ABOUT FUNCTION "DATA":
* This function is part of a QAbstractTableModel subclass and it's an implementation of the data method which is called to populate
a Qt table view with data. Here's how it works:

The function takes two parameters: a QModelIndex and an int representing the role.

QModelIndex is used to indicate the cell for which the data is requested. It holds the row and column information for the cell.
role is used to specify what kind of data is being requested. The most commonly used roles are Qt::DisplayRole for displaying data 
and Qt::EditRole for data that is being edited.
If the role is either Qt::DisplayRole or Qt::EditRole, it means we need to provide the data to be displayed or edited in the table
view.

Then, the row and column of the cell are extracted from the QModelIndex.

A Star object is retrieved from the repository. The Star at the index corresponding to the current row is fetched. Note: this
assumes that the order of stars in the repository matches the order of rows in the table.

A switch statement is used to determine which attribute of the Star object should be returned based on the column index. The
getName(), getConstellation(), getRA(), getDec(), and getDiameter() methods are presumably getter methods that return the name, 
constellation, RA (right ascension), Dec (declination), and diameter of the star respectively. The results are converted to a
QString to be displayed in the table view. For instance, if the column is 0, the name of the star is returned; if the column is 1,
the constellation is returned, and so on.

If the column index is not 0 to 4, the switch statement breaks and no data is provided.

If the role is not Qt::DisplayRole or Qt::EditRole, no data is provided.

If no data is provided (either because the role was not display or edit, or because the column index was not between 0 and 4), 
a default constructed QVariant is returned. The QVariant class is a union for the most common Qt data types, capable of storing
different types of data.

This function is called by the Qt framework whenever it needs to display or edit the data in the table view, and it uses the 
information provided by this function to determine what to show in each cell of the table.





User
so this function is called by default as many times until the whole table is completed
ChatGPT
Yes, that's correct. The data function is called by the Qt framework for each cell in the table that needs to be displayed or 
edited.

When the table view is shown, or when it is refreshed (e.g., due to scrolling, hiding/showing, resizing, etc.), the Qt framework
will call this function for every visible cell in the table. The QModelIndex passed to the function tells you which row and column
is being requested, and the role parameter tells you what kind of data is being requested (display, edit, etc.).

Therefore, for a table with N rows and M columns, in the simplest case where just the visible cells are being displayed, this 
function could be called up to N*M times initially. It might be called even more times as the user interacts with the table view,
as cells are edited, or as the table view is refreshed due to other user interactions.
*/