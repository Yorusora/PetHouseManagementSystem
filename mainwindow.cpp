#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "LinkNode.h"

LinkNode* pet;

QStandardItemModel* model = new QStandardItemModel();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    InitList(pet);
    setAllEditInvisible();
    initTableView();
    QStringList comboBoxList;
    comboBoxList<<"物种"<<"名字"<<"屋名";
    ui->comboBox_searchMode->addItems(comboBoxList);
    ui->comboBox_changeInfoMode->addItems(comboBoxList);
//    statusBar()->setStyleSheet(QString("QStatusBar::item{border:100px;border-color:black}")); //设置状态栏样式，因为没时间学qss所以先加入TODOLIST
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initLineEdit() //初始化所有LineEdit
{
    ui->lineEdit_petKind_add->setText("");
    ui->lineEdit_petName_add->setText("");
    ui->lineEdit_petHouse_add->setText("");
    ui->lineEdit_petName_delete->setText("");
    ui->lineEdit_pet_search->setText("");
    ui->lineEdit_pet_changeInfo->setText("");
    ui->lineEdit_pet_changeInto->setText("");
}

void MainWindow::setAllEditInvisible()  //设置所有编辑区域为不可见
{
    ui->label_petKind_add->setVisible(false);
    ui->label_petName_add->setVisible(false);
    ui->label_petHouse_add->setVisible(false);
    ui->label_petName_delete->setVisible(false);
    ui->label_pet_search->setVisible(false);
    ui->label_searchMode->setVisible(false);
    ui->label_changeInfoMode->setVisible(false);
    ui->label_pet_changeInfo->setVisible(false);
    ui->label_pet_changeInto->setVisible(false);
    ui->lineEdit_petKind_add->setVisible(false);
    ui->lineEdit_petName_add->setVisible(false);
    ui->lineEdit_petHouse_add->setVisible(false);
    ui->lineEdit_petName_delete->setVisible(false);
    ui->lineEdit_pet_search->setVisible(false);
    ui->lineEdit_pet_changeInfo->setVisible(false);
    ui->lineEdit_pet_changeInto->setVisible(false);
    ui->pushButton_addNewPet_confirm->setVisible(false);
    ui->pushButton_deletePet_confirm->setVisible(false);
    ui->pushButton_searchPet_confirm->setVisible(false);
    ui->pushButton_searchChangingInfo_confirm->setVisible(false);
    ui->pushButton_changeInfo_confirm->setVisible(false);
    ui->pushButton_back->setVisible(false);
    ui->comboBox_searchMode->setVisible(false);
    ui->comboBox_changeInfoMode->setVisible(false);
}

void MainWindow::setFunctionPushbuttonVisible() //设置所有功能按钮为可见
{
    ui->pushButton_searchPet->setVisible(true);
    ui->pushButton_addNewPet->setVisible(true);
    ui->pushButton_deletePet->setVisible(true);
    ui->pushButton_showAllPet->setVisible(true);
    ui->pushButton_changePetInfo->setVisible(true);
    ui->pushButton_exit->setVisible(true);
}

void MainWindow::setFunctionPushbuttonInvisible()   //设置所有功能按钮为不可见
{
    ui->pushButton_searchPet->setVisible(false);
    ui->pushButton_addNewPet->setVisible(false);
    ui->pushButton_deletePet->setVisible(false);
    ui->pushButton_showAllPet->setVisible(false);
    ui->pushButton_changePetInfo->setVisible(false);
    ui->pushButton_exit->setVisible(false);
}

void MainWindow::setAllEditState_addNewPet()    //设置编辑区域状态为“添加新宠物”功能状态
{
    setAllEditInvisible();
    ui->label_petKind_add->setVisible(true);
    ui->label_petName_add->setVisible(true);
    ui->lineEdit_petKind_add->setVisible(true);
    ui->lineEdit_petName_add->setVisible(true);
    ui->lineEdit_petHouse_add->setVisible(true);
    ui->label_petHouse_add->setVisible(true);
    ui->pushButton_addNewPet_confirm->setVisible(true);
    ui->pushButton_back->setVisible(true);
}

void MainWindow::setAllEditState_deletePet()    //设置编辑区域状态为“删除宠物”功能状态
{
    setAllEditInvisible();
    ui->label_petName_delete->setVisible(true);
    ui->lineEdit_petName_delete->setVisible(true);
    ui->pushButton_deletePet_confirm->setVisible(true);
    ui->pushButton_back->setVisible(true);
}

void MainWindow::setAllEditState_searchPet()    //设置编辑区域状态为“查找宠物”功能状态
{
    setAllEditInvisible();
    ui->label_pet_search->setVisible(true);
    ui->label_searchMode->setVisible(true);
    ui->lineEdit_pet_search->setVisible(true);
    ui->pushButton_searchPet_confirm->setVisible(true);
    ui->pushButton_back->setVisible(true);
    ui->comboBox_searchMode->setVisible(true);
}

void MainWindow::setAllEditState_changeInfo()    //设置编辑区域状态为“修改宠物信息”功能状态
{
    setAllEditInvisible();
    ui->label_changeInfoMode->setVisible(true);
    ui->label_pet_changeInfo->setVisible(true);
    ui->lineEdit_pet_changeInfo->setVisible(true);
    ui->pushButton_searchChangingInfo_confirm->setVisible(true);
    ui->pushButton_back->setVisible(true);
    ui->comboBox_changeInfoMode->setVisible(true);
}

void MainWindow::setAllEditState_changeInto()    //设置编辑区域状态为“编辑修改的宠物信息”功能状态
{
    setAllEditInvisible();
    ui->label_pet_changeInto->setVisible(true);
    ui->pushButton_changeInfo_confirm->setVisible(true);
    ui->pushButton_back->setVisible(true);
    ui->lineEdit_pet_changeInto->setVisible(true);
}

void MainWindow::initTableView()    //初始化TableView
{
    QStringList labels = QObject::trUtf8("宠物物种,宠物名字,宠物屋名").simplified().split(",");
    model->setHorizontalHeaderLabels(labels);
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->show();
}

void MainWindow::updateTableView()  //更新TableView
{
    LinkNode* temp;
    temp = pet;
    model->removeRows(0,model->rowCount());
    for(int i = 0; temp != NULL; i++)
    {
        QStandardItem* item_petKind = new QStandardItem(temp->petKind);
        QStandardItem* item_petName = new QStandardItem(temp->petName);
        QStandardItem* item_petHouse = new QStandardItem(temp->petHouse);
        item_petKind->setTextAlignment(Qt::AlignCenter);
        item_petName->setTextAlignment(Qt::AlignCenter);
        item_petHouse->setTextAlignment(Qt::AlignCenter);
        model->setItem(i, 0, item_petKind);
        model->setItem(i, 1, item_petName);
        model->setItem(i, 2, item_petHouse);
        temp = temp->next;
    }
}

void MainWindow::on_pushButton_addNewPet_clicked()  //“添加新宠物”按钮事件
{
    initLineEdit();
    setAllEditState_addNewPet();
    setFunctionPushbuttonInvisible();
}

void MainWindow::on_pushButton_deletePet_clicked()  //“删除宠物”按钮事件
{
    initLineEdit();
    setAllEditState_deletePet();
    setFunctionPushbuttonInvisible();
}

void MainWindow::on_pushButton_searchPet_clicked()  //“查找宠物”按钮事件
{
    initLineEdit();
    setAllEditState_searchPet();
    setFunctionPushbuttonInvisible();
}

void MainWindow::on_pushButton_changePetInfo_clicked()  //“修改宠物信息”按钮事件
{
    initLineEdit();
    setAllEditState_changeInfo();
    setFunctionPushbuttonInvisible();
}

void MainWindow::on_pushButton_showAllPet_clicked() //“查看所有宠物”按钮事件
{
    setAllEditInvisible();
    initLineEdit();
    updateTableView();
    statusBar()->showMessage("查看所有宠物。当前宠物数量：" + QString::number(LenthList(pet)), 1000);
}

void MainWindow::on_pushButton_back_clicked()   //“返回”按钮事件
{
    setAllEditInvisible();
    initLineEdit();
    setFunctionPushbuttonVisible();
}

void MainWindow::on_pushButton_addNewPet_confirm_clicked()  //“添加新宠物_确定”按钮事件
{
    QString name;
    bool isEqual = false;
    LinkNode* temp = pet;
    while (temp != NULL)
    {
        name = temp->petName;
        temp = temp->next;
        //判断是否有同名宠物
        if(name.compare(ui->lineEdit_petName_add->text()) == 0)
            isEqual = true;
        else
            isEqual = false;
    }
    if(isEqual == false)
    {
        InsertList(pet, ui->lineEdit_petKind_add->text(), ui->lineEdit_petName_add->text(), ui->lineEdit_petHouse_add->text());
        statusBar()->showMessage("宠物添加成功。当前宠物数量：" + QString::number(LenthList(pet)), 1000);
        updateTableView();
        setAllEditInvisible();
        initLineEdit();
    }
    else if(isEqual == true)
    {
        statusBar()->showMessage("宠物添加失败，存在同名宠物。当前宠物数量：" + QString::number(LenthList(pet)), 1000);
        updateTableView();
        setAllEditInvisible();
        initLineEdit();
    }
    setFunctionPushbuttonVisible();
}

void MainWindow::on_pushButton_deletePet_confirm_clicked()  //“删除宠物_确定”按钮事件
{
    bool isDeleted;
    //判断是否删除成功
    isDeleted = DeleteList(pet, ui->lineEdit_petName_delete->text());
    if(isDeleted == true)
        statusBar()->showMessage("宠物删除成功。当前宠物数量：" + QString::number(LenthList(pet)), 1000);
    else
        statusBar()->showMessage("宠物删除失败。或许是不是没有这个宠物？当前宠物数量：" + QString::number(LenthList(pet)), 1000);
    updateTableView();
    setAllEditInvisible();
    initLineEdit();
    setFunctionPushbuttonVisible();
}

void MainWindow::on_pushButton_searchPet_confirm_clicked()  //“查找宠物_确定”按钮事件
{
    int j = 0;
    LinkNode* temp = pet;
    bool isFound;
    if(ui->comboBox_searchMode->currentText() == "物种")  //若搜索方式为“物种”
    {
        isFound = FindListPetKind(pet, ui->lineEdit_pet_search->text());
        if(isFound == true)
        {
            model->removeRows(0,model->rowCount());
            for(int i = 0; temp != NULL; i++)
            {
                if(temp->petKind.compare(ui->lineEdit_pet_search->text()) == 0)
                {
                    QStandardItem* item_petKind = new QStandardItem(temp->petKind);
                    QStandardItem* item_petName = new QStandardItem(temp->petName);
                    QStandardItem* item_petHouse = new QStandardItem(temp->petHouse);
                    item_petKind->setTextAlignment(Qt::AlignCenter);
                    item_petName->setTextAlignment(Qt::AlignCenter);
                    item_petHouse->setTextAlignment(Qt::AlignCenter);
                    model->setItem(j, 0, item_petKind);
                    model->setItem(j, 1, item_petName);
                    model->setItem(j, 2, item_petHouse);
                    j++;
                }
                temp = temp->next;
            }
            statusBar()->showMessage("成功查找物种为<" + ui->lineEdit_pet_search->text() + ">的宠物", 1000);
        }
        else
        {
            model->removeRows(0,model->rowCount());
            statusBar()->showMessage("查找物种为<" + ui->lineEdit_pet_search->text() + ">的宠物无结果", 1000);
        }
    }
    else if(ui->comboBox_searchMode->currentText() == "名字") //若搜索方式为“名字”
    {
        isFound = FindListPetName(pet, ui->lineEdit_pet_search->text());
        if(isFound == true)
        {
            model->removeRows(0,model->rowCount());
            for(int i = 0; temp != NULL; i++)
            {
                if(temp->petName.compare(ui->lineEdit_pet_search->text()) == 0)
                {
                    QStandardItem* item_petKind = new QStandardItem(temp->petKind);
                    QStandardItem* item_petName = new QStandardItem(temp->petName);
                    QStandardItem* item_petHouse = new QStandardItem(temp->petHouse);
                    item_petKind->setTextAlignment(Qt::AlignCenter);
                    item_petName->setTextAlignment(Qt::AlignCenter);
                    item_petHouse->setTextAlignment(Qt::AlignCenter);
                    model->setItem(j, 0, item_petKind);
                    model->setItem(j, 1, item_petName);
                    model->setItem(j, 2, item_petHouse);
                    j++;
                }
                temp = temp->next;
            }
            statusBar()->showMessage("成功查找名字为<" + ui->lineEdit_pet_search->text() + ">的宠物", 1000);
        }
        else
        {
            model->removeRows(0,model->rowCount());
            statusBar()->showMessage("查找名字为<" + ui->lineEdit_pet_search->text() + ">的宠物无结果", 1000);
        }
    }
    else if(ui->comboBox_searchMode->currentText() == "屋名") //若搜索方式为“屋名”
    {
        isFound = FindListPetHouse(pet, ui->lineEdit_pet_search->text());
        if(isFound == true)
        {
            model->removeRows(0,model->rowCount());
            for(int i = 0; temp != NULL; i++)
            {
                if(temp->petHouse.compare(ui->lineEdit_pet_search->text()) == 0)
                {
                    QStandardItem* item_petKind = new QStandardItem(temp->petKind);
                    QStandardItem* item_petName = new QStandardItem(temp->petName);
                    QStandardItem* item_petHouse = new QStandardItem(temp->petHouse);
                    item_petKind->setTextAlignment(Qt::AlignCenter);
                    item_petName->setTextAlignment(Qt::AlignCenter);
                    item_petHouse->setTextAlignment(Qt::AlignCenter);
                    model->setItem(j, 0, item_petKind);
                    model->setItem(j, 1, item_petName);
                    model->setItem(j, 2, item_petHouse);
                    j++;
                }
                temp = temp->next;
            }
            statusBar()->showMessage("成功查找住在屋名为<" + ui->lineEdit_pet_search->text() + ">的宠物", 1000);
        }
        else
        {
            model->removeRows(0,model->rowCount());
            statusBar()->showMessage("查找住在<" + ui->lineEdit_pet_search->text() + ">的宠物无结果", 1000);
        }
    }
    setAllEditInvisible();
    initLineEdit();
    setFunctionPushbuttonVisible();
}

void MainWindow::on_pushButton_searchChangingInfo_confirm_clicked() //“修改宠物信息_确定”按钮事件
{
    LinkNode* temp = pet;
    //判断是否查找成功
    bool isFound = FindListPetName(pet, ui->lineEdit_pet_changeInfo->text());
    if(isFound == true)
    {
        model->removeRows(0,model->rowCount());
        for(int i = 0; temp != NULL; i++)
        {
            if(temp->petName.compare(ui->lineEdit_pet_changeInfo->text()) == 0)
            {
                QStandardItem* item_petKind = new QStandardItem(temp->petKind);
                QStandardItem* item_petName = new QStandardItem(temp->petName);
                QStandardItem* item_petHouse = new QStandardItem(temp->petHouse);
                item_petKind->setTextAlignment(Qt::AlignCenter);
                item_petName->setTextAlignment(Qt::AlignCenter);
                item_petHouse->setTextAlignment(Qt::AlignCenter);
                model->setItem(0, 0, item_petKind);
                model->setItem(0, 1, item_petName);
                model->setItem(0, 2, item_petHouse);
            }
            temp = temp->next;
        }
        statusBar()->showMessage("成功查找名字为<" + ui->lineEdit_pet_changeInfo->text() + ">的宠物", 1000);
        setAllEditState_changeInto();
    }
    else
    {
        statusBar()->showMessage("查找名字为<" + ui->lineEdit_pet_changeInfo->text() + ">的宠物无结果，请重新输入", 1000);
        ui->lineEdit_pet_changeInfo->setText("");
    }
}

void MainWindow::on_pushButton_changeInfo_confirm_clicked() //“编辑修改的宠物信息_确定”按钮事件
{
    int i = 0;
    LinkNode* temp = pet;
    if(ui->comboBox_changeInfoMode->currentText() == "物种")  //若修改“物种”信息
    {
        for(i = 0; pet != NULL; i++)
        {
            if(pet->petName.compare(ui->lineEdit_pet_changeInfo->text()) == 0)
            {
                pet->petKind = ui->lineEdit_pet_changeInto->text();
                statusBar()->showMessage("宠物物种修改成功", 1000);
                model->removeRows(0,model->rowCount());
                QStandardItem* item_petKind = new QStandardItem(pet->petKind);
                QStandardItem* item_petName = new QStandardItem(pet->petName);
                QStandardItem* item_petHouse = new QStandardItem(pet->petHouse);
                item_petKind->setTextAlignment(Qt::AlignCenter);
                item_petName->setTextAlignment(Qt::AlignCenter);
                item_petHouse->setTextAlignment(Qt::AlignCenter);
                model->setItem(0, 0, item_petKind);
                model->setItem(0, 1, item_petName);
                model->setItem(0, 2, item_petHouse);
                pet = temp;
                break;
            }
            pet = pet->next;
        }
    }
    else if(ui->comboBox_changeInfoMode->currentText() == "名字") //若修改“名字”信息
    {
        for(i = 0; pet != NULL; i++)
        {
            if(pet->petName.compare(ui->lineEdit_pet_changeInfo->text()) == 0)
            {
                pet->petName = ui->lineEdit_pet_changeInto->text();
                statusBar()->showMessage("宠物名字修改成功", 1000);
                model->removeRows(0,model->rowCount());
                QStandardItem* item_petKind = new QStandardItem(pet->petKind);
                QStandardItem* item_petName = new QStandardItem(pet->petName);
                QStandardItem* item_petHouse = new QStandardItem(pet->petHouse);
                item_petKind->setTextAlignment(Qt::AlignCenter);
                item_petName->setTextAlignment(Qt::AlignCenter);
                item_petHouse->setTextAlignment(Qt::AlignCenter);
                model->setItem(0, 0, item_petKind);
                model->setItem(0, 1, item_petName);
                model->setItem(0, 2, item_petHouse);
                pet = temp;
                break;
            }
            pet = pet->next;
        }
    }
    else if(ui->comboBox_changeInfoMode->currentText() == "屋名") //若修改“屋名”信息
    {
        for(i = 0; pet != NULL; i++)
        {
            if(pet->petName.compare(ui->lineEdit_pet_changeInfo->text()) == 0)
            {
                pet->petHouse = ui->lineEdit_pet_changeInto->text();
                statusBar()->showMessage("宠物屋名修改成功", 1000);
                model->removeRows(0,model->rowCount());
                QStandardItem* item_petKind = new QStandardItem(pet->petKind);
                QStandardItem* item_petName = new QStandardItem(pet->petName);
                QStandardItem* item_petHouse = new QStandardItem(pet->petHouse);
                item_petKind->setTextAlignment(Qt::AlignCenter);
                item_petName->setTextAlignment(Qt::AlignCenter);
                item_petHouse->setTextAlignment(Qt::AlignCenter);
                model->setItem(0, 0, item_petKind);
                model->setItem(0, 1, item_petName);
                model->setItem(0, 2, item_petHouse);
                pet = temp;
                break;
            }
            pet = pet->next;
        }
    }
    setAllEditInvisible();
    initLineEdit();
    setFunctionPushbuttonVisible();
}

void MainWindow::on_pushButton_exit_clicked()   //"退出小屋，拜拜！"按钮事件
{
    QApplication::exit();
}
