#include<QPushButton>
#include<QVBoxLayout>
#include<QtQuickWidgets/QQuickWidget>
#include "centerwindow.h"


CenterWindow::CenterWindow(QWidget *parent)
    :QFrame(parent)
{
    setObjectName(QString("CenterWindow"));
    titleBar = new TitleBar();
    navagationBar = new NavgationBar();

    stackWidget = new QStackedWidget();

    QQuickWidget* qmlViwer1 = new QQuickWidget;
    qmlViwer1->setResizeMode(qmlViwer1->SizeRootObjectToView);
    QQuickWidget* qmlViwer2 = new QQuickWidget;
    qmlViwer2->setResizeMode(qmlViwer2->SizeRootObjectToView);
    QQuickWidget* qmlViwer3 = new QQuickWidget;
    qmlViwer3->setResizeMode(qmlViwer3->SizeRootObjectToView);
    QQuickWidget* qmlViwer4 = new QQuickWidget;
    qmlViwer4->setResizeMode(qmlViwer4->SizeRootObjectToView);
    qmlViwer1->setSource(QUrl(QString("qrc:/tiger/tiger/tiger.qml")));
    qmlViwer2->setSource(QUrl(QString("qrc:/home/home.qml")));
    qmlViwer3->setSource(QUrl(QString("qrc:/quickwindow/application/appquick.qml")));
    qmlViwer4->setSource(QUrl(QString("qrc:/about/about.qml")));
    stackWidget->addWidget(qmlViwer1);
    stackWidget->addWidget(qmlViwer2);
    stackWidget->addWidget(qmlViwer3);
    stackWidget->addWidget(qmlViwer4);

    QVBoxLayout* mainlayout = new QVBoxLayout;
    mainlayout->addWidget(titleBar);
    mainlayout->addWidget(navagationBar);
    mainlayout->addWidget(stackWidget);
//    mainlayout->addStretch();
    mainlayout->setContentsMargins(0, 0 ,0 ,0);
    mainlayout->setSpacing(0);
    setLayout(mainlayout);
    initConnect();
}

void CenterWindow::initConnect()
{
    connect(navagationBar, SIGNAL(indexChanged(int)), this, SLOT(switchscreen(int)));
}

void CenterWindow::switchscreen(const int index)
{
    stackWidget->setCurrentIndex(index);
}
