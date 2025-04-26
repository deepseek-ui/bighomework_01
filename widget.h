#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QMap>
#include<QList>
#include<QUrl>
#include<QTimer>
#include<QEvent>
#include<QMouseEvent>
#include<QPoint>
#include<QContextMenuEvent>
#include<QMenu>
class QPaintEvent;
namespace Act{
Q_NAMESPACE
enum RoleAct{
    cold,
    fly,
    happy,
    jump,
    liedown,
    oioioi,
    sayhello};
Q_ENUM_NS(RoleAct)

}
using namespace Act;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
public:
    void showAction(RoleAct k);


protected:
    void paintEvent(QPaintEvent*event)override;
protected:
    void contextMenuEvent(QContextMenuEvent *event) override;  // 确保声明这个函数


private:
    void loadRoleActRes();
    void initMenu();
private:
    QMap<RoleAct,QList<QUrl>>action_map;
    QTimer*timer;
    RoleAct cur_role_act;
    QUrl cur_role_pix;
    QMenu*menu;
};



class DragFilter:public QObject{
    Q_OBJECT
public:
    bool eventFilter(QObject*obj,QEvent*event)
    {
        auto w=dynamic_cast<QWidget*>(obj);
        if(!w)return false;
        if(event->type()==QEvent::MouseButtonPress){
            auto e=dynamic_cast<QMouseEvent*>(event);
            if(e){
                pos=e->pos();
            }
        }
        else if(event->type()==QEvent::MouseMove)
        {
            auto e=dynamic_cast<QMouseEvent*>(event);
            if(e){
                if(e->buttons()&Qt::MouseButton::LeftButton)
                {
                    w->move(e->globalPos()-pos);
                }
            }
        }
        return QObject::eventFilter(obj,event);
    }
private:
    QPoint pos;
};















#endif // WIDGET_H
