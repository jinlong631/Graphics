/*************************************************
**版  权：RenGu Company
**文件名: mypageswitch.h
**作  者: wey       Version: 1.0       Date: 2016.10.03
**描  述:
**Others: 页面切换
**
**修改历史:
**20161004:wey:修复删除工作区奔溃问题
**20161017: gx:调整新建工作区后默认插入到最后
**20161015:wey:增加Alt+左右键快速切换工作区间
*************************************************/
#ifndef MYPAGESWITCH_H
#define MYPAGESWITCH_H

#include <QWidget>

class QPushButton;
class QHBoxLayout;
class MyScene;
class MyPageItem;

class MyPageSwitch : public QWidget
{
    Q_OBJECT
public:
    static MyPageSwitch * instance();

    void closePage();
    void switchFrontBack(bool isFront = true);

    struct PageMapping
    {
        QString id;
        MyPageItem * pageItem;
        MyScene * scene;
        qreal hScrollValue;
        qreal vScrollValue;
        qreal scaleView;
    };

signals:
    void deletePage();
    void switchPage();

public slots:
    void addPage();

private slots:
    void switchToPage(QString pageId);
    void deleteThisPage(QString pageId);

private:
    MyPageSwitch(QWidget * parent = 0);
    static MyPageSwitch * pageSwitch;

    void siwtchPage(QString pageId,bool firstView = false);

    void initWidget();

    QPushButton * addPageButt;
    QHBoxLayout * layout;

    QList<PageMapping *> pages;
    int pagePosition;                     //页面位置
    PageMapping * selectedPage;
    bool isFirstView;
};

#endif // MYPAGESWITCH_H
