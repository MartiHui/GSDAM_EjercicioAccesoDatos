#ifndef ACTIONTECNICO_H
#define ACTIONTECNICO_H
#include "action.h"

class ActionTecnico : public Action {
public:
    ActionTienda(const QString &message);
    QString getReply();
}
#endif // ACTIONTECNICO_H