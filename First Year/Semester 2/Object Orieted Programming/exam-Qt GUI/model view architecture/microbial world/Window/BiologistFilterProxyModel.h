#pragma once
#include <QSortFilterProxyModel>
class BiologistFilterProxyModel : public QSortFilterProxyModel {
    Q_OBJECT
    QStringList speciesStudied;
public:
    BiologistFilterProxyModel(const QStringList& species, QObject* parent = 0)
        : QSortFilterProxyModel(parent), speciesStudied(species) {}

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const override {
        QModelIndex index = sourceModel()->index(sourceRow, 1, sourceParent);
        QString species = sourceModel()->data(index).toString();
        return speciesStudied.contains(species);
    }
};
