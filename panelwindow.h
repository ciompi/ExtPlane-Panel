#ifndef PANELWINDOW_H
#define PANELWINDOW_H

#ifdef MAEMO
#include <QDBusConnection>

#include <QDBusMessage>
#include "mce/mode-names.h"
#include "mce/dbus-names.h"
#endif
#include <QTimer>
#include <QTime>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsItemGroup>
#include <QObject>
#include <QMessageBox>
#include <QString>
#include <QStringList>
#include <extplaneconnection.h>
#include "panelitemfactory.h"
#include "menubutton.h"

class PanelWindow : public QGraphicsView {
    Q_OBJECT

public:
    explicit PanelWindow();
    ~PanelWindow();
signals:
    void tickTime(double dt, int total);
public slots:
    void connectionError(QString txt);
    void itemDestroyed(QObject *obj);
    void addItem(PanelItem *g);
    void panelRotationChanged(int r);
    void fullscreenChanged(bool fs);
    void setServerAddress(QString host);
    void editModeChanged(bool em);
    void disableBlanking();
private slots:
    void tick();
protected:
    virtual void resizeEvent(QResizeEvent * event);
private:
    MenuButton *menuButton;
    QGraphicsScene scene;
    ExtPlaneConnection *connection;
    QGraphicsTextItem errorMessage;
    QList<PanelItem *> panelItems;
    PanelItemFactory itemFactory;
    int panelRotation;
    bool editMode;
    QTimer blankingTimer, tickTimer;
    QTime time, totalTime;
};

#endif // PANELWINDOW_H
