#include "transaction.h"
#include<QFile>
#include<QMessageBox>
#include<QTextStream>
/*

Layout for csv file:

11772201,1436,OmkarGajananPhansopkar,4500
11772202,1234,KaranSudhakarKotian,5800
11834592,2020,AniruddhaShriwant,15500
11773503,9876,RupeshSandeshRaut,5400
11773505,4567,RohanDarade,9000

*/

transaction::transaction(QWidget* parent, int lineNoObtained)
{
    this->parent = parent;
    this->lineNo = lineNoObtained;
    this->lineNo = lineNoObtained;
    userPath = "userNameNPass.csv";
    accPath = "accountsDatabase.csv";

    QFile file(accPath);

    // Exception code
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            QMessageBox::warning(parent,"Exception","file could not be opened for transaction");
            return;
        }
    // Exception code

       QTextStream in(&file);
       while (lineNoObtained>0)
       {
          lineNoObtained--;
          QString eachLine = in.readLine(); //read one line at a time
          QStringList words = eachLine.split(',');
          accNoString = words.at(0);
          pinString = words.at(1);
          name = words.at(2);
          balanceString = words.at(3);
       }
       accNo = accNoString.toInt();
       pin = accNoString.toInt();
       balance = balanceString.toInt();
       file.close();

}

void transaction::updateBalance(){   
     // For now, not using csv editing
    accRecord = this->accNoString+","+this->pinString+","+this->name+","+this->balanceString;
    //QMessageBox::about(parent," Done with updating, Replacement: ",accRecord);
    int lines = lineNo;

    QFile file(accPath);

    // Exception code
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            QMessageBox::warning(parent,"Exception","file could not be opened for updating balance !");
            return;
        }
    // Exception code
        QVector<QString> eachLine;
       QTextStream in(&file);
       while (lines>1)
       {
          eachLine.push_back(in.readLine());    //read one line at a time
          lines--;
       }

       QString doucheBag = in.readLine();

       eachLine.push_back(accRecord);

       while(!in.atEnd()){
           eachLine.push_back(in.readLine());
        }
        QString actualText;
        for(int i=0; i<eachLine.length(); i++){
                actualText.append(eachLine[i]);
                actualText.append("\n");
        }

        file.close();
        file.remove();

                QFile nfile("accountsDatabaseNew.csv");
                    if(nfile.open(QIODevice::WriteOnly | QIODevice::Truncate))
                    {
                        // QMessageBox::about(parent,"Succesful","Opened new try");
                        QTextStream out(&nfile);
                        out << actualText;
                        nfile.close();
                    }
                   nfile.rename(accPath);
        //QMessageBox::about(parent,"new txt for DB: ",actualText);

        // each line has all updated data           in  form of a vector
       // qstring with whole data buckled up as a single qstring


            /*
          for(int i=0; i<eachLine.length(); i++){
                 QMessageBox::about(parent,QString::number(eachLine.length()),eachLine[i]);
          }
            */


        //if(!writeFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
           // QMessageBox::warning(parent,"New file creation","Unsuccessful");
            //return;
          //}



        //QTextStream out(&writeFile);
        // out << actualText;






            /*
                    Some more shitty code:

            QFile write(":/database/DB/accountsDatabaseTemp.csv");
            if(!file.open(QFile::WriteOnly | QFile::Text)) {
                QMessageBox::warning(parent,"New file creation","Unsuccessful");
                return;
              }
            QTextStream out(&file);

            out << actualText;

            write.flush();
            write.close();
            */



          /*        Old shitty code:
           *
          QFile writeFile(accRecord);
          if(!writeFile.open(QFile::WriteOnly | QFile::Text)) {
              QMessageBox::warning(parent,"..","file not open");
              return;
            }

          QTextStream write(&writeFile);
         for(int i=0; i<eachLine.length(); i++){
                write<< eachLine[i]<<"\n";
         }

      writeFile.flush();
      writeFile.close();
      */
    /*
    ifstream fileReader;
    fileReader.open("accountsDatabase.csv",ios::in);

    ofstream fileWriterNewer;
    fileWriterNewer.open("newTempFile.csv",fstream::app);

    int traverse = this->lineNo;
    string currentLine;

    while(traverse>1){
        getline(fileReader,currentLine);
        fileWriterNewer<<currentLine<<"\n";
        traverse--;
    }

    fileWriterNewer<< this->accRecord <<"\n";
    getline(fileReader,currentLine);

    while(!fileReader.eof()){
        getline(fileReader,currentLine);
        fileWriterNewer<<currentLine<<"\n";
    }

    fileReader.close();
    fileWriterNewer.close();

    remove("accountsDatabase.csv");
    rename("newTempFile.csv","accountsDatabase.csv");

    */
}
void transaction::deposit(int amount){
        this->balance = this->balance + amount;
        balanceString = QString::number(balance);
        updateBalance();
}
bool transaction::withdraw(int amount){
        if( (this->balance - amount) < 0  ){
            QMessageBox::warning(parent,"Invalid Value","Insufficient balance to withdraw entered amount");
            return false;
        }
        this->balance = this->balance - amount;
        balanceString = QString::number(balance);
        updateBalance();

        return true;
}
QString transaction::getBalance(){
        return balanceString;
}

QString transaction::encrypt(QString givenQString, int p1, int p2){

}

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
 * Layout for csv file:


11772201,1436,OmkarGajananPhansopkar,4500
11772202,1234,KaranSudhakarKotian,5800
11834592,2020,AniruddhaShriwant,15500
11773503,9876,RupeshSandeshRaut,5400
11773505,4567,RohanDarade,9000



*/
