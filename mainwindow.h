#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_addNewPet_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_addNewPet_confirm_clicked();

    void on_pushButton_exit_clicked();

    void on_pushButton_deletePet_clicked();

    void on_pushButton_deletePet_confirm_clicked();

    void on_pushButton_searchPet_confirm_clicked();

    void on_pushButton_searchPet_clicked();

    void on_pushButton_showAllPet_clicked();

    void on_pushButton_changePetInfo_clicked();

    void on_pushButton_searchChangingInfo_confirm_clicked();

    void on_pushButton_changeInfo_confirm_clicked();

private:
    Ui::MainWindow *ui;
    void initLineEdit();
    void setAllEditInvisible();
    void setFunctionPushbuttonVisible();
    void setFunctionPushbuttonInvisible();
    void setAllEditState_addNewPet();
    void setAllEditState_deletePet();
    void setAllEditState_searchPet();
    void setAllEditState_changeInfo();
    void setAllEditState_changeInto();
    void initTableView();
    void updateTableView();
};
#endif // MAINWINDOW_H
