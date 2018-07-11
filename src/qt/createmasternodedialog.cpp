#include "createmasternodedialog.h"
#include "ui_createmasternodedialog.h"

#include "addresstablemodel.h"
#include "bitcoingui.h"
#include "csvmodelwriter.h"
#include "editaddressdialog.h"
#include "guiutil.h"
#include "util.h"
//#include "masternodeconfig.h"
//m#include "masternodeman.h"
#include <boost/filesystem/fstream.hpp>
#include <QIcon>

#include <QMessageBox>

using namespace std;
//CCriticalSection cs_masternodes;

MNodeConfigDialog::MNodeConfigDialog(QWidget* parent) : QDialog(parent),
                                                        ui(new Ui::MNodeConfigDialog)
                                                        //mapper(0),
                                                        //model(0)
{
    ui->setupUi(this);
    //Labels
        ui->aliasLineEdit->setPlaceholderText("Enter your Masternode alias");
        ui->addressLineEdit->setPlaceholderText("Enter your IP & port");
        ui->privkeyLineEdit->setPlaceholderText("Enter your Masternode private key");
        ui->txhashLineEdit->setPlaceholderText("Enter your 10000 Plexus TXID");
        ui->txindexLineEdit->setPlaceholderText("Enter your transaction output index");

}

MNodeConfigDialog::~MNodeConfigDialog()
{
    delete ui;
}



void MNodeConfigDialog::on_okButton_clicked()
{
    if(ui->aliasLineEdit->text() == "")
    {
    QMessageBox msg;
        msg.setText("Please enter an alias.");
    msg.exec();
    return;
    }
    else if(ui->addressLineEdit->text() == "")
    {
    QMessageBox msg;
        msg.setText("Please enter an address.");
    msg.exec();
    return;
    }
    else
     {
         std::string sAlias = ui->aliasLineEdit->text().toStdString();
         std::string sAddress = ui->addressLineEdit->text().toStdString();
         std::string sMasternodePrivKey = ui->privkeyLineEdit->text().toStdString();
         std::string sTxHash = ui->txhashLineEdit->text().toStdString();
         std::string sOutputIndex = ui->txindexLineEdit->text().toStdString();


         boost::filesystem::path pathMasternodeConfigFile = GetMasternodeConfigFile();
         boost::filesystem::ifstream streamConfig(pathMasternodeConfigFile);

         if (!streamConfig.good()) {
             FILE* configFile = fopen(pathMasternodeConfigFile.string().c_str(), "a");

             return ; // Nothing to read, so just return
         }
         //masternodeConfig.add(sAlias, sAddress, sMasternodePrivKey, sTxHash, sOutputIndex, sDonationAddress, sDonationPercentage);
         accept();
     }

}

void MNodeConfigDialog::on_cancelButton_clicked()
{
    reject();
}

