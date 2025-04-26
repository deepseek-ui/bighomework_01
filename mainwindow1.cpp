#include "mainwindow1.h"
#include "ui_mainwindow1.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_released()//查看规则按钮
{
    ui->stackedWidget->setCurrentWidget(ui->page_2);

}


void MainWindow::on_pushButton_released()//开始按钮
{
    // 如果游戏窗口已存在，先关闭
    if(gamewindow) {
        gamewindow->close();
        delete gamewindow;
    }

    // 创建新游戏窗口
    gamewindow = new GameWindow(this);
    gamewindow->setWindowTitle("跑酷游戏");

    // 设置关闭时自动删除
    gamewindow->setAttribute(Qt::WA_DeleteOnClose);

    // 游戏窗口关闭时重置指针
    connect(gamewindow, &QWidget::destroyed, this, [this](){
        this->gamewindow = nullptr;
    });

    // 隐藏主窗口（可选）
    this->hide();

    // 显示游戏窗口
    gamewindow->show();

}


void MainWindow::on_pushButton_3_released()//退出按钮
{
    close();
}


void MainWindow::on_pushButton_4_released()//返回
{
     ui->stackedWidget->setCurrentWidget(ui->page);
}

