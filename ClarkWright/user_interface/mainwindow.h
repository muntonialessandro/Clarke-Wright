#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/qmath.h>
#include "utils.h"
#include "classes/graph_routes.h"
#include <QWheelEvent>
#include <QFileDialog>
#include <QStackedLayout>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QFormLayout>
#include <QMessageBox>
#include <QPushButton>
#include <QGroupBox>
#include <QTranslator>
#include <QRadioButton>
#include <QProgressBar>
#include <QMenuBar>
#include <QApplication>
#include <QWidget>
#include <QDialog>
#include <QMenu>
#include <QMenuBar>
#include <QLabel>
#include <QSettings>
#include <QTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    QString APPNAME;
    QString APP_VERSION;


    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static int design_interface( int argc, char *argv[] );
    void design_route( QList<QPoint> route );
    void design_routes( QList< QList<QPoint> > routes );
    void design_nodes( QList< QPair<QPoint,QString> > pointsList );

private:
    Ui::MainWindow *ui;     // l'interfaccia con tutti i suoi oggetti
    QWidget *window;        // finestra dell'interfaccia
    int pixelMultip;        // maggiore sara' questo numero, piu grande sara' la visualizzazione
    bool firstAperture;     // appena viene aperto il programma passa da true a false, dopo la fase di inizializzazione
    bool gridEnabled;       // memorizza se e' già attiva la griglia
    QVector<Client> nodes_list; //la lista dei nodi cliente

    // vari oggetti della scena
    QGraphicsScene *scene;
    QGraphicsEllipseItem *node;
    QGraphicsRectItem *rectangle;
    QGraphicsLineItem *line;
    QGraphicsTextItem *text;
    QGraphicsPolygonItem* poligon;
    QList<QGraphicsLineItem*> *gridLines;

    // funzioni per disegnare la scena
    void addNode(QPoint p, QString name);
    void addArrowTo(QPoint p1,QPoint p2);

private slots: // le varie funzioni che vengono chiamate quando si interagisce con l'interfaccia
    void handleButton();
    void zoomGraph( int i );
    void grid(bool on);
    void open_file();
    void reset(void);
    void compute();
    void zoomInGraphButton();
    void zoomOutGraphButton();

};

#endif // MAINWINDOW_H
