#include "Table.h"
#include <fstream>
int Table::rowCount(const QModelIndex& parent) const
{
	return bacteriums.size();
}

int Table::columnCount(const QModelIndex& parent) const
{
	return 4;
}

QVariant Table::data(const QModelIndex& index, int role) const
{	
	
	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		int col = index.column();
		int row = index.row();
		Bacterium bacterium = bacteriums[row];
		switch(col)
			{
		case 0:
			return QString::fromStdString(bacterium.get_name());
		case 1:
			return QString::fromStdString(bacterium.get_species());
		case 2:
			return QString::fromStdString(std::to_string(bacterium.get_size()));
		case 3:
			return QString::fromStdString(bacterium.get_list_of_diseases());
		default:
			break;
			}

	}
	return QVariant();
}

QVariant Table::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
		{
			switch (section)
			{
			case 0:
				return QString::fromStdString("Name");
			case 1:
				return QString::fromStdString("Species");
			case 2:
				return QString::fromStdString("Size");
			case 3:
				return QString::fromStdString("List of diseases it causes");
			default:
				break;
			}
		}
	}
	return QVariant();
}

void Table::add_bacterium(Bacterium& new_bacterium)
{
	beginInsertRows(QModelIndex{}, rowCount(), rowCount());
	bacteriums.push_back(new_bacterium);
	endInsertRows();

	emit dataChanged(index(0, 0), index(rowCount() - 1, columnCount() - 1));
}
void Table::save_bacteriums_in_file()
{
	std::ofstream fout("saved_bacteriums.txt");
	for (Bacterium& bacterium : bacteriums)
	{
		fout << bacterium.get_name() + "|" + bacterium.get_species() + "|" + std::to_string(bacterium.get_size()) + "|" +
			bacterium.get_list_of_diseases() + "|" + "\n";

	}
	fout.close();
}
