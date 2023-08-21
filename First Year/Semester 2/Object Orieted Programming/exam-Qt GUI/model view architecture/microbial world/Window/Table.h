#pragma once
#include <QAbstractItemModel>
#include <vector>
#include "Repository.h"
class Table : public QAbstractTableModel
{
private:
	std::vector<Bacterium>& bacteriums;
public:
	Table(std::vector<Bacterium>& bacteriums) : bacteriums{ bacteriums } {};
	int rowCount(const QModelIndex& parent = QModelIndex()) const;
	int columnCount(const QModelIndex& parent = QModelIndex()) const;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
	std::vector<Bacterium>& get_bacteriums() { return bacteriums; };
	void add_bacterium(Bacterium& new_bacterium);
	void save_bacteriums_in_file();

};

