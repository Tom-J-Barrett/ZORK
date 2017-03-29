#include "background.h"

//constructor that sets blank window and creates rooms
Background::Background(Zork* zork1){
    this->zork1 = zork1;
    player=zork1->play();
    inventoryContString = "";
    setRoomExits(zork1->currentRoom);
    setSceneRect(0,0,1000,500);
    createCave();
    createMapGUI();
    createTextBox();
    inventoryBox();
    controlsBox();
    addText();
    addToScene();
}

Background::~Background()
{
    delete player;
    delete cave;
    delete smallEditor;
    delete RoomA;
    delete RoomB;
    delete RoomC;
    delete RoomD;
    delete RoomE;
    delete RoomF;
    delete RoomG;
    delete RoomH;
    delete RoomI;
    delete RoomJ;
    delete inventoryComboBox;
    delete controlsComboBox;
    delete timer;
}

//Sets a new scne when you move rooms
void Background::setScene(const string direction)
{
    nextRoom = zork1->currentRoom->nextRoom(direction);
    if(nextRoom->getCanEnter()==true){
        clearBackground();

        nextRoom = zork1->currentRoom->nextRoom(direction);
        zork1->currentRoom=nextRoom;

        setRoomExits(zork1->currentRoom);
        addToScene();
        createMapGUI();
        addText();
    }
}

void Background::refreshScene(){
    clearBackground();
    setRoomExits(zork1->currentRoom);
    addToScene();
    createMapGUI();
}


//creates buttons depending on room exits
void Background::setRoomExits(Room * r){
    zork1->currentRoom = r;

    vector<string> listOfExits= zork1->currentRoom->exitString();
    for(int i=0;i<listOfExits.size();i++)
    {
        if(listOfExits[i]=="north"){
            button1= new QPushButton();
            button1->move(450,25);
            button1->raise();
            button1->setText("North");
            delB1=1;
            this->addWidget(button1);

            connect(button1,SIGNAL(released()),this, SLOT(on_button1_clicked()));
        }
        else if(listOfExits[i]=="south"){
            button2= new QPushButton();
            button2->move(450,410);
            button2->setText("South");
            button2->raise();
            delB2=1;
            connect(button2,SIGNAL(released()),this, SLOT(on_button2_clicked()));
            this->addWidget(button2);
        }
        else if(listOfExits.at(i)=="east"){
            button3= new QPushButton();
            button3->move(750,200);
            button3->setText("East");
            button3->raise();
            delB3=1;
            connect(button3,SIGNAL(released()),this, SLOT(on_button3_clicked()));
            this->addWidget(button3);
        }
        else if(listOfExits.at(i)=="west"){
            button4= new QPushButton();
            button4->move(175,200);
            button4->setText("West");
            button4->raise();
            delB4=1;
            this->addWidget(button4);
            connect(button4,SIGNAL(released()),this, SLOT(on_button4_clicked()));
        }

    }
    if(find(zork1->player->getInventory()->getInventoryList().begin(), zork1->player->getInventory()->getInventoryList().end(), zork1->teleporter) != zork1->player->getInventory()->getInventoryList().end()){
        button5= new QPushButton();
        button5->move(750,25);
        button5->setText("Teleport");
        button5->raise();
        this->delB5=1;
        this->addWidget(button5);
        connect(button5,SIGNAL(released()),this, SLOT(on_button5_clicked()));
    }

}
void Background::createCave(){
    cave= new QGraphicsPixmapItem();
    cave->setPos(50,0);
    cave->setPixmap(QPixmap(":/Images/cave.jpg"));
    cave->setZValue(-1);
}

void Background:: createTextBox(){
    smallEditor = new QTextEdit;
    smallEditor->move(250,450);
    smallEditor->setReadOnly(true);
    this->addWidget(smallEditor);
}

void Background::createMapGUI()
{

    RoomA= new QGraphicsRectItem();
    RoomB= new QGraphicsRectItem();
    RoomC= new QGraphicsRectItem();
    RoomD= new QGraphicsRectItem();
    RoomE= new QGraphicsRectItem();
    RoomF= new QGraphicsRectItem();
    RoomG= new QGraphicsRectItem();
    RoomH= new QGraphicsRectItem();
    RoomI= new QGraphicsRectItem();
    RoomJ= new QGraphicsRectItem();

    RoomA->setRect(10,10,10,10);
    this->addItem(RoomA);

    RoomB->setRect(20,10,10,10);
    this->addItem(RoomB);

    RoomC->setRect(0,10,10,10);
    this->addItem(RoomC);

    RoomD->setRect(10,20,10,10);
    this->addItem(RoomD);

    RoomE->setRect(20,20,10,10);
    this->addItem(RoomE);

    RoomF->setRect(10,0,10,10);
    this->addItem(RoomF);

    RoomG->setRect(20,0,10,10);
    this->addItem(RoomG);

    RoomH->setRect(0,0,10,10);
    RoomH->setZValue(5);
    this->addItem(RoomH);

    RoomI->setRect(0,20,10,10);
    this->addItem(RoomI);

    RoomJ->setRect(0,30,10,10);
    this->addItem(RoomJ);

    if(zork1->currentRoom->getDescription()=="a")
        RoomA->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="b")
        RoomB->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="c")
        RoomC->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="d")
        RoomD->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="e")
        RoomE->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="f")
        RoomF->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="g")
        RoomG->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="h")
        RoomH->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="i")
        RoomI->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="j")
        RoomJ->setBrush(Qt::green);
}

void Background:: addText(){
     string x="You are in Room "+zork1->currentRoom->getDescription()+ " and you have health of: "+ to_string(zork1->player->getHealth());
     smallEditor->setPlainText(QString::fromStdString(x));
}

void Background::inventoryBox()
{
    inventoryComboBox=new QComboBox();
    inventoryComboBox->move(550,450);
    inventoryComboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    this->addWidget(inventoryComboBox);
}

void Background::controlsBox()
{
    controlsComboBox=new QComboBox();
    controlsComboBox->move(700,450);
    controlsComboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    controlsComboBox->addItem("Controls");

    controls+=("Attack: X");
    controls+=("Pick up item: P");
    controls+=("Drop selected item: D");
    controls+=("Kiss: K");

    for(int i=0; i<controls.size();i++)
       controlsComboBox->addItem(controls.get(i));

    this->addWidget(controlsComboBox);
}

//adds monster and rectangle to scene
void Background::addToScene(){
    if(zork1->currentRoom->monsterInRoom()){
        zork1->vampire->setVisible(true);
        zork1->vampire->setFocus();
        timer = new MyTimer(zork1->vampire, player, zork1->currentRoom);
        this->addItem(zork1->vampire);
    }
    else if(zork1->currentRoom->bossInRoom()){
        zork1->dragon->setVisible(true);
        zork1->dragon->setFocus();
        timer = new MyTimer(zork1->dragon, player, zork1->currentRoom);
        this->addItem(zork1->dragon);
    }
    else if(zork1->currentRoom->princessInRoom()){
        zork1->princess->setVisible(true);
        zork1->princess->setFocus();
        this->addItem(zork1->princess);
    }

    this->addItem(cave);

    if(zork1->currentRoom->itemInRoom()){
        item=zork1->currentRoom->item;
        item->setVisible(true);
        this->addItem(item);
    }
}


void Background::on_button1_clicked()
{
    setScene("north");
}

void Background::on_button2_clicked()
{
    setScene("south");
}
void Background::on_button3_clicked()
{
    setScene("east");
}
void Background::on_button4_clicked()
{
    setScene("west");
}

void Background::on_button5_clicked(){
    int randNum = rand() % zork1->rooms.size();
    nextRoom = zork1->rooms[randNum];
    if(nextRoom->getCanEnter()==true){
        clearBackground();
        zork1->currentRoom=nextRoom;
        setRoomExits(zork1->currentRoom);
        addToScene();
        createMapGUI();
        addText();
    }
}

void Background::clearBackground(){
    RoomA->setBrush(Qt::white);
    RoomB->setBrush(Qt::white);
    RoomC->setBrush(Qt::white);
    RoomD->setBrush(Qt::white);
    RoomE->setBrush(Qt::white);
    RoomF->setBrush(Qt::white);
    RoomG->setBrush(Qt::white);
    RoomH->setBrush(Qt::white);
    RoomI->setBrush(Qt::white);
    RoomJ->setBrush(Qt::white);

    if(delB1)
    {
        button1->deleteLater();
        delB1=0;
    }
    if(delB2)
    {
        button2->deleteLater();
        delB2=0;
    }
    if(delB3)
    {
       button3->deleteLater();
        delB3=0;
    }
    if(delB4)
    {
        button4->deleteLater();
        delB4=0;
    }
    if(delB5)
    {
        button5->deleteLater();
        delB5=0;
    }

    if(zork1->currentRoom->monsterInRoom()){
        this->removeItem(zork1->vampire);
    }
    else if(zork1->currentRoom->bossInRoom()){
        this->removeItem(zork1->dragon);
    }
    else if(zork1->currentRoom->princessInRoom()){
        this->removeItem(zork1->princess);
    }

    this->removeItem(cave);

    if(zork1->currentRoom->itemInRoom()){
        this->removeItem(item);
    }

    zork1->vampire->resetHealth();
    zork1->dragon->resetHealth();
    if(zork1->currentRoom->bossInRoom()){
        timer->stopTimer();
        timer->deleteLater();
    }
    else if(zork1->currentRoom->monsterInRoom()){
        timer->stopTimer();
        timer->deleteLater();
    }
}

void Background::keyPressEvent(QKeyEvent *event)
{
    if(zork1->currentRoom->monsterInRoom()){
        if(event->key()==Qt::Key_X)
        {
                if(zork1->vampire->scenePos()==QPointF(470,200)){
                    if(find((zork1->player->getInventory()->getInventoryList()).begin(), (zork1->player->getInventory()->getInventoryList()).end(), zork1->weapon) != (zork1->player->getInventory()->getInventoryList()).end()){
                        zork1->vampire->decreaseHealthByAttack(50);
                    }
                    else{
                        zork1->vampire->decreaseHealthByAttack(10);
                    }
                    zork1->vampire->setPixmap(QPixmap(":/Images/vampireAttacked.png"));
                    zork1->vampire->z=1;
                }
        }
    }
    else if(zork1->currentRoom->bossInRoom()){
        if(event->key()==Qt::Key_X)
        {

                if(zork1->dragon->scenePos()==QPointF(470,200)){
                    if(find((zork1->player->getInventory()->getInventoryList()).begin(), (zork1->player->getInventory()->getInventoryList()).end(), zork1->weapon) != (zork1->player->getInventory()->getInventoryList()).end()){
                        zork1->dragon->decreaseHealthByAttack(50);
                    }
                    else{
                        zork1->dragon->decreaseHealthByAttack(10);
                    }
                    zork1->dragon->setPixmap(QPixmap(":/Images/dragonAttack.png"));
                    zork1->dragon->z=1;
                    if(zork1->dragon->getHealth()<=0){
                        zork1->currentRoom->setBoss(false);
                        zork1->currentRoom->addItem(zork1->key);
                        zork1->currentRoom->setItem(true);
                        addToScene();
                    }
                }
        }
    }
    else if(zork1->currentRoom->princessInRoom()){
        if(event->key()==Qt::Key_X)
        {
            msgBox.setText("You killed the princess! Game Over.");
            msgBox.setInformativeText("");
            int ret = msgBox.exec();
            switch(ret){
                case QMessageBox::Ok:
                    exit(1);
                    break;
                case QMessageBox::Cancel:
                    exit(1);
                    break;
                default:
                    break;
            }
        }
    }

    if(event->key()==Qt::Key_P)
    {
            if(zork1->currentRoom->itemsInRoom.size() > 0)
            {
                if(zork1->currentRoom->item->getInvFlag()){
                inventory=player->getInventory();
                inventory->addToInventory(zork1->currentRoom->item);
                item->setVisible(false);
                zork1->currentRoom->setItem(false);

                inventoryContString = item->getDescription();
                inventoryComboBox->addItem(inventoryContString);
                }
                if(item->getDescription()==zork1->potion->getDescription() && !zork1->potion->getUsed()){
                    zork1->player->increaseHealth(50);
                    item->setVisible(false);
                    zork1->currentRoom->setItem(false);
                    zork1->potion->setUsed();
                }
                if(item->getDescription()==zork1->key->getDescription()){
                    zork1->g->setCanEnter(true);
                }
                if(item->getDescription()==zork1->teleporter->getDescription()){
                    item->setVisible(false);
                    zork1->currentRoom->setItem(false);
                    refreshScene();
                }
            }
    }

    if(event->key()==Qt::Key_D)
    {
        if(zork1->currentRoom->itemInRoom()==false && player->getInventory()->inventoryQty() > 0){
            int currentItem = inventoryComboBox->currentIndex();
            itemsInInventory=player->getInventory()->getInventoryList();
            itemToDrop=itemsInInventory.operator [](currentItem);
            itemsInInventory.erase(itemsInInventory.begin() + currentItem);
            zork1->currentRoom->addItem(itemToDrop);
            zork1->currentRoom->setItem(true);
            inventoryComboBox->removeItem(currentItem);
            zork1->player->getInventory()->setInventoryList(itemsInInventory);
            button5->setVisible(false);
            refreshScene();
        }
    }

    if(event->key()==Qt::Key_K){
        if(zork1->currentRoom->princessInRoom()){
            //exit(1);
            msgBox.setText("You Win!!!! Game Over.");
            msgBox.setInformativeText("");
            int ret = msgBox.exec();
            switch(ret){
                case QMessageBox::Ok:
                    exit(1);
                    break;
                case QMessageBox::Cancel:
                    exit(1);
                    break;
                default:
                    break;
            }
        }
    }

    if(event->key()==Qt::Key_H){
        controlsBox();
    }
}


