/*************************************************
**版  权：RenGu Company
**文件名: SimulateHeader.h
**作  者: wey       Version: 1.0       Date: 2016.10.11
**描  述:
**Others: 推演模块结构体定义文件
**
**修改历史:
**
*************************************************/
#ifndef SIMULATEHEADER_H
#define SIMULATEHEADER_H

#include "../Header.h"

class QGraphicsItem;

//单元类型
enum ProcessType
{
    PRO_START,              //开始:圆角矩形
    PRO_INPUT,              //输入:平行四边形
    PRO_OUTPUT,             //输出:平行四边形
    PRO_PROCESS,            //处理:矩形
    PRO_JUDGE,              //判断:菱形
    PRO_PARALLEL,           //并行:平行线
    PRO_LOOP,               //循环:
    PRO_END                 //结束:圆角矩形
};

//处理单元
struct ProcessUnit
{
    ProcessType ptype;               //处理单元类型
    GraphicsType gtype;              //控件的类型

    QGraphicsItem * item;            //指向的Item

    QString id;


    ProcessUnit * next;
};

#endif // SIMULATEHEADER_H
