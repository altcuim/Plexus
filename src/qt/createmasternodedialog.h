// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_QT_CREATEMASTERNODEDIALOG_H
#define BITCOIN_QT_CREATEMASTERNODEDIALOG_H

#include <QAbstractButton>
#include <QAction>
#include <QDialog>
#include <QList>

#include <QPoint>
#include <QString>



namespace Ui
{
class MNodeConfigDialog;
}


class MNodeConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MNodeConfigDialog(QWidget *parent = 0);
    ~MNodeConfigDialog();

protected:

private Q_SLOTS:
    void on_okButton_clicked();
    void on_cancelButton_clicked();

signals:

private:
    Ui::MNodeConfigDialog *ui;

};

#endif // BITCOIN_QT_CREATEMASTERNODEDIALOG_H
