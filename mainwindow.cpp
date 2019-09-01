#include "mainwindow.h"
#include "ui_mainwindow.h"


/* Declaring Global Variables */
QString filename = "./cron.txt";
QStringListModel *model;
QStringList jobs;
QString jobs_string;
QStringList weekdayStrList = {"Every","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
QStringList weekdayList = {"*","1","2","3","4","5","6","0"};

QStringList monthStrList = {"Every","January","February","March","April","May","June","July","August","September","October","November","December"};
QStringList monthList = {"*","1","2","3","4","5","6","7","8","9","10","11","12"};

QStringList dayStrList = {"Every","01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31"};
QStringList dayList = {"*","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31"};

QStringList hourStrList = {"Every","00:00","01:00","02:00","03:00","04:00","05:00","06:00","07:00","08:00","09:00","10:00","11:00","12:00","13:00","14:00","15:00","16:00","17:00","18:00","19:00","20:00","21:00","22:00","23:00"};
QStringList hourList = {"*","0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23"};

QStringList minuteStrList = {"Every","00","01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31","32","33","34","35","36","37","38","39","40","41","42","43","44","45","46","47","48","49","50","51","52","53","54","55","56","57","58","59"};
QStringList minuteList = {"*","0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31","32","33","34","35","36","37","38","39","40","41","42","43","44","45","46","47","48","49","50","51","52","53","54","55","56","57","58","59"};





// Function that takes a string a split into an array with the crontab variables.
QVector<QString> split(const QString& str){
    QVector<QString> tokens(QVector<QString>(100));
    QString temp = "";
    QString comp = " ";
    int i = 0;
    int n = 0;
    for(i; i < str.size(); i++){
       if(str[i] != comp){
           temp += str[i];
       }else{
           tokens[n] = temp;
           temp = "";
           n++;
       }

    }
    return tokens;
}



// Function that refresh the ListView with the current crontabs
void MainWindow::refreshList(){
    // Create a system call
    QProcess *process2 = new QProcess();
    // Start process to retrieve crontabs from the OS.
    process2->start("crontab -l");
    QString result;
    process2->waitForFinished(-1);
    result = process2->readAllStandardOutput();
    // Store it in an Array
    jobs_string = result;

    // Create a model for the List
    model = new QStringListModel(this);
    jobs = result.split("\n",QString::SkipEmptyParts);
    QString numberOfJobsString = QString::number(jobs.size());

    // Set the model for the list
    model->setStringList(jobs);
    ui->listView->setModel(model);



}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Setting ui configs
    using namespace std;
    ui->setupUi(this);

    ui->listView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->listViewWeekday->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->listViewMonth->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->listViewDay->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->listViewHour->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->listViewMinute->setSelectionMode(QAbstractItemView::ExtendedSelection);
    // Model for WeekDays
    model = new QStringListModel(this);
    model->setStringList(weekdayStrList);
    ui->listViewWeekday->setModel(model);
    ui->listViewWeekday->setCurrentIndex(model->index(0, 0));

    // Model for Month
    model = new QStringListModel(this);
    model->setStringList(monthStrList);
    ui->listViewMonth->setModel(model);
    ui->listViewMonth->setCurrentIndex(model->index(0, 0));

    // Model for Day
    model = new QStringListModel(this);
    model->setStringList(dayStrList);
    ui->listViewDay->setModel(model);
    ui->listViewDay->setCurrentIndex(model->index(0, 0));

    // Model for Hour
    model = new QStringListModel(this);
    model->setStringList(hourStrList);
    ui->listViewHour->setModel(model);
    ui->listViewHour->setCurrentIndex(model->index(0, 0));

    // Model for Minute
    model = new QStringListModel(this);
    model->setStringList(minuteStrList);
    ui->listViewMinute->setModel(model);
    ui->listViewMinute->setCurrentIndex(model->index(0, 0));

    // Refresh list with OS Crontabs
    refreshList();

}

MainWindow::~MainWindow()
{
    delete ui;
}


/*
 *Function: getVarValues
 *Input: ListView, QStringList
 * Retrieve the selected indexes on list and return a proper string to add to the crontab command.
 **/
QString getVarValues(QListView* list, QStringList valList ){
    QModelIndexList modelList;
    modelList = list->selectionModel()->selectedIndexes();
    QString resultado = "";
    for(int i =0; i<modelList.size(); i++){
        int a = modelList[i].row();

        resultado += valList[a]+",";
    }

    resultado = resultado.remove(resultado.size()-1,1);
    return resultado;


}



/*
 * Function removeCronTab
 * Input: String that corresponds to the crontab
 * Remove the crontab in the system.
 */
void removeCronTab(QString tab){

    QFile f(filename);
    if(f.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QString s;
        QTextStream t(&f);
        while(!t.atEnd())
        {
            QString line = t.readLine();
            if(!line.contains(tab))
                s.append(line + "\n");
        }
        f.resize(0);
        t << s;
        f.close();
    }
    QProcess *process = new QProcess();
    process->start("crontab", QStringList{filename});
    process->waitForFinished(-1);


}


// Remove ButtonListener
void MainWindow::on_pushButton_3_clicked()
{

    QModelIndex index = ui->listView->currentIndex();
    QString itemText = index.data(Qt::DisplayRole).toString();
    removeCronTab(itemText);
    refreshList();


}


/*Function: RefreshJobs
 * Retrieve all the CronJobs from the OS and update the list
 */
void refreshJobs(){
    // Create a system call
    QProcess *process2 = new QProcess();
    // Start process
    process2->start("crontab -l");
    QString result;
    process2->waitForFinished(-1);
    result = process2->readAllStandardOutput();
    jobs_string = result;

}


/*Function:addCronTab
 * Input: String that represent a cronTab
 * Add the crontab to the system
 */
void addCronTab(QString job){


    refreshJobs();
    QFile file(filename);
    if(!file.exists()){
        qDebug() << "File not found!"<<filename;
    }else{
        qDebug() << filename<<" File found!";
    }

   jobs_string += job;
   if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&file);
        out << jobs_string;
        file.close();
    }


   QProcess *process = new QProcess();
   process->start("crontab", QStringList{filename});
   process->waitForFinished(-1);

}



// Add crontab button lister
void MainWindow::on_pushButton_5_clicked()
{

    if(ui->textEdit_2->toPlainText() != ""){
        // Retrieve values from the lists
        QString minute = getVarValues(ui->listViewMinute, minuteList);
        QString hour = getVarValues(ui->listViewHour, hourList);
        QString day = getVarValues(ui->listViewDay, dayList);
        QString month = getVarValues(ui->listViewMonth, monthList);
        QString weekday = getVarValues(ui->listViewWeekday, weekdayList);
        QString command = ui->textEdit_2->toPlainText();

        QString result;
        QTextStream(&result) << "" << minute << " " << hour << " " << day << " " << month << " " << weekday << " " << command << "\n";
        // Add crontab
        addCronTab(result);
        // refresh list
        refreshList();
    }else{
        QMessageBox Msgbox;
        Msgbox.setText("No cronTab action!!!");
        Msgbox.exec();

    }


}
