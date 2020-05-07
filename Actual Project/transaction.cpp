#include "transaction.h"
/*

Layout for csv file:

11772201,1436,OmkarGajananPhansopkar,4500
11772202,1234,KaranSudhakarKotian,5800
11834592,2020,AniruddhaShriwant,15500
11773503,9876,RupeshSandeshRaut,5400
11773505,4567,RohanDarade,9000

*/

transaction::transaction(string accNo)
{
        this->accNo = accNo;
        fstream file;
        file.open("accountsDatabase.csv",ios::in);
        this->accLineNo=0;
        while(!file.eof()){
            this->accLineNo++;
            getline(file,accRecord);
            stringstream ss(accRecord);
            getline(ss,this->accNo,',');
            getline(ss,this->pinString,',');
            getline(ss,this->name,',');
            getline(ss,this->balanceString,',');

            if(this->accNo==accNo){
                this->pin = stoi(pinString);
                this->currBalance = stoi(balanceString);
                break;
            }

        }

        file.close();
        //      Fetch out pin for the given account no              and             set Line no when line found     and     String  accRecord
}

void transaction::updateBalance(){
    // update balance of csv file using this.balance        and     also change String accRecord
    accRecord = this->accNo+","+this->pinString+","+this->name+","+this->balanceString;

    ifstream fileReader;
    fileReader.open("accountsDatabase.csv",ios::in);

    ofstream fileWriterNewer;
    fileWriterNewer.open("newTempFile.csv",fstream::app);

    int traverse = this->accLineNo;
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

}
void transaction::deposit(int amount){
        this->currBalance = this->currBalance + amount;
        balanceString = to_string(this->currBalance);
        updateBalance();
}
bool transaction::withdraw(int amount){
        if( (this->currBalance - amount) < 0  )
            return false;

        this->currBalance = currBalance - amount;
        balanceString = to_string(currBalance);

        updateBalance();

        return true;
}

/*


/*                      My csv file code :

int csvFile::displaySingleCust(string custID, vector<string> &newValuePredefined){
    int nthLine=0;
    string check = custID.substr (0, 9);
    if(check==custID){
        cout<<"Invalid ID entered :(\t";
        return -1;
    }
    inputStream.open(fileName);
    getline(inputStream,line);
    bool flag = false;
    int numericalID;
    while(!inputStream.eof()){
        nthLine++;
        getline(inputStream,line);
        stringstream ss(line);
        getline(ss,newValuePredefined[0],',');
        getline(ss,newValuePredefined[1],',');
        getline(ss,newValuePredefined[2],',');
        getline(ss,newValuePredefined[3],',');
        getline(ss,newValuePredefined[4],',');
        numericalID = stoi(newValuePredefined[4]);
        newValuePredefined[4] = prefix + newValuePredefined[4];
        if(newValuePredefined[4]==custID){
            flag = true;
            break;
        }
    }
    if(!flag){
        cout<<"ID not found :-(\n";
        return -1;
    }
    cout<<"------------------------------------------------------------------------------------"<<endl;
    cout<<"Name: "<<newValuePredefined[0]<<endl;
    cout<<"Address: "<<newValuePredefined[1]<<endl;
    cout<<"Total Transaction: "<<newValuePredefined[2];
    cout<<"\t\t\tPhone: "<<newValuePredefined[3];
    cout<<"\t\t\tCust ID: "<<newValuePredefined[4]<<endl;
    cout<<"------------------------------------------------------------------------------------"<<endl;
    inputStream.close();
    newValuePredefined[4] = to_string(numericalID);
    return nthLine;
}
string csvFile::addCustomer(string name, string addr, string amount, string phone){
        string newID;
        int newNumericID = ++IDnumeric;
        currentID = prefix + to_string(IDnumeric);
        ofstream fout;
        fout.open(fileName,ios::app);

        fout<<"\n"<<name<<","<<addr<<","<<amount<<","<<phone<<","<<newNumericID;
        fout.close();
        return currentID;
}
void csvFile::editRecord(string newLine, string custID, int dataLineNth){
    inputStream.open(fileName);
    ofstream newTemp;
    if(doesExist("newTempFile.csv")){
        remove("newTempFile.csv");
    }
    newTemp.open("newTempFile.csv",fstream::app);
    getline(inputStream,line);
    newTemp<<heading;
    while(dataLineNth>1){
        getline(inputStream,line);
        newTemp<<"\n"<<line;
        dataLineNth--;
    }
    newTemp<<"\n"<<newLine;
    getline(inputStream,line);
    while(!inputStream.eof()){
        getline(inputStream,line);
        newTemp<<"\n"<<line;
    }

    inputStream.close();
    newTemp.close();
    // removing the existing file
    remove("custRec.csv");

    // renaming the updated file with the existing file name
    rename("newTempFile.csv", "custRec.csv");

    cout<<"Successfully edited the record for ID: "<<custID<<endl;
    cout<<"Whole data: "<<endl;
    display();
}


*/
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
 * Layout for csv file:

11772201,1436,OmkarGajananPhansopkar,4500
11772202,1234,KaranSudhakarKotian,5800
11834592,2020,AniruddhaShriwant,15500
11773503,9876,RupeshSandeshRaut,5400
11773505,4567,RohanDarade,9000




utility::utility(string accNo) : data(new utilityData)
{
        this->accNo = accNo;
        fstream file;
        file.open("accountsDatabase.csv",ios::in);
        this->accLineNo=0;
        while(!file.eof()){
            this->accLineNo++;
            getline(file,accRecord);
            stringstream ss(accRecord);
            getline(ss,this->accNo,',');
            getline(ss,this->pinString,',');
            getline(ss,this->name,',');
            getline(ss,this->balanceString,',');

            if(this->accNo==accNo){
                this->pin = stoi(pinString);
                this->currBalance = stoi(balanceString);
                break;
            }

        }

        file.close();
        //      Fetch out pin for the given account no              and             set Line no when line found     and     String  accRecord
}

utility::utility(const utility &rhs) : data(rhs.data)
{

}

utility &utility::operator=(const utility &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}
void utility::updateBalance(){
    // update balance of csv file using this.balance        and     also change String accRecord
    accRecord = this->accNo+","+this->pinString+","+this->name+","+this->balanceString;

    ifstream fileReader;
    fileReader.open("accountsDatabase.csv",ios::in);

    ofstream fileWriterNewer;
    fileWriterNewer.open("newTempFile.csv",fstream::app);

    int traverse = this->accLineNo;
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

}
void utility::deposit(int amount){
        this->currBalance = this->currBalance + amount;
        balanceString = to_string(currBalance);
        updateBalance();
}
bool utility::withdraw(int amount){
        if( (this->currBalance - amount) < 0  )
            return false;

        this->currBalance = currBalance - amount;
        balanceString = to_string(currBalance);

        updateBalance();

        return true;
}

*/
