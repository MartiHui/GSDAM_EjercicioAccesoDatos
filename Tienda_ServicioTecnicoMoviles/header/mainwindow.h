#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QPair>
#include <functional>
#include <QMap>

#include "datainfo.h"

class ServerConnection;
class QListWidgetItem;
class Action;

namespace Ui {
class MainWindow;
}

enum class InfoType {
    MARCA,
    MODELO,
    REPARACION,
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //void switchCentralWidgetEnabled(); // Alterna los elementos de la ui entre bloqueados y desbloqueados

private:
    Ui::MainWindow *ui;
    ServerConnection *m_serverConnection;
    QVector<Marca> m_marcas;

    void establishConnectionReply(Action *action);
    void fillListaOrdenes(Action *action);
    void fillMarcasVector(InfoType infoType, Action *action);
    void fillMarcasCmBox();
    void fillModelosCmBox(QVector<Modelo> &modelos);
    void clearReparacionesLists();
    void fillReparacionesPosiblesList(QVector<Reparacion> &reparaciones);
    void showErrorMsgBox();

    /*void fillMarcasCmbBox(QVector<QPair<QString, int> > marcas);
    void fillModelosCmbBox(QVector<QPair<QString, int> > modelos);
    void fillReparacionesPosiblesList(QVector<QPair<QString, int> > reparaciones);
    void clearLists();
    void resetLists();*/

private slots:
    void replyReceived(QString message);
    /*void on_marcasCmbBox_currentIndexChanged(int index);
    void on_conectarServidor_clicked();
    void on_modelosCmbBox_currentIndexChanged(int index);
    void on_ordenRequest_clicked();
    void on_ordenEstado_clicked();
    void on_reparacionesPosibles_itemDoubleClicked(QListWidgetItem *item);
    void on_reparacionesElegidas_itemDoubleClicked(QListWidgetItem *item);*/
    void on_conectarServidor_clicked();
    void on_marcasCmBox_currentIndexChanged(int index);
    void on_modelosCmBox_currentIndexChanged(int index);
    void on_reparacionesPosibles_itemDoubleClicked(QListWidgetItem *item);
    void on_reparacionesElegidas_itemDoubleClicked(QListWidgetItem *item);
};

#endif // MAINWINDOW_H
