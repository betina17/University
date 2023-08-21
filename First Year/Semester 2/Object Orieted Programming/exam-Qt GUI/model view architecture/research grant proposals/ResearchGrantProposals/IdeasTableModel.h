#pragma once
#include <qabstractitemmodel.h>
#include "Repository.h"
#include <vector>

class IdeasTableModel : public QAbstractTableModel
{
private:
	std::vector<Idea> ideas;
public:
	IdeasTableModel(std::vector<Idea>& ideas);
	int rowCount(const QModelIndex& parent = QModelIndex()) const;
	int columnCount(const QModelIndex& parent = QModelIndex()) const;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
	void add_idea(Idea& new_idea);
	std::vector<Idea>& get_ideas_from_model() {
		return ideas;
	};
	void write_to_file_ideas_from_model();
	bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
	Qt::ItemFlags flags(const QModelIndex& index) const override;
	

};