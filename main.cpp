#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

// QStandardItemModel derived class
#include <QStandardItemModel>
class MyModel : public QStandardItemModel {

public:
    enum Role {
        role1=Qt::UserRole,
        role2,
        role3
    };

    explicit MyModel(QObject * parent = 0): QStandardItemModel(parent){}
    explicit MyModel( int rows, int columns, QObject * parent = 0 )
        : QStandardItemModel(rows, columns, parent){}

    QHash<int, QByteArray> roleNames() const{
         QHash<int, QByteArray> roles;
         roles[role1] = "one";
         roles[role2] = "two";
         roles[role3] = "three";
         return roles;
    }
};


// Main
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    MyModel* model = new MyModel;


    QStandardItem* it = new QStandardItem();
    it->setData("data 1", MyModel::role1);
    it->setData("data 2", MyModel::role2);
    it->setData("data 3", MyModel::role3);
    model->appendRow(it);

    it = new QStandardItem();
    it->setData("more data 1", MyModel::role1);
    it->setData("more data 2", MyModel::role2);
    it->setData("more data 3", MyModel::role3);
    model->appendRow(it);

    QQmlApplicationEngine engine;
    // register cpp model with QML engine
    engine.rootContext()->setContextProperty("myModel", model);

    // Load qml file in QML engine
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
