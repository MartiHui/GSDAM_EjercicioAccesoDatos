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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ServerConnection *m_serverConnection;

    void establishConnectionReply(Action *action);
    void showErrorMsgBox(QString msg);
    void fillListaOrdenes(Action *action);
    void fillStatusCmBox(Action *action);
    void newOrderReceived(Action *action);

private slots:
    void replyReceived(QString message);
    void on_conectarServidor_clicked();
    void on_actualizarEstado_clicked();
};

#endif // MAINWINDOW_H
