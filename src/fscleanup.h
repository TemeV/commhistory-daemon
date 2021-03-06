/****************************************************************************
**
** This file is part of commhistory-daemon.
**
** Copyright (C) 2014 Jolla Ltd.
** Contact: Slava Monich <slava.monich@jolla.com>
**
** This library is free software; you can redistribute it and/or modify
** it under the terms of the GNU Lesser General Public License version 2.1
** as published by the Free Software Foundation.
**
** This library is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
** Lesser General Public License for more details.
**
** You should have received a copy of the GNU Lesser General Public
** License along with this library; if not, write to the Free Software
** Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
**
****************************************************************************/

#ifndef FSCLEANUP_H
#define FSCLEANUP_H

#include <QObject>
#include <QString>
#include <QList>

class FsCleanup: public QObject
{
    Q_OBJECT

public:
    FsCleanup(QObject* aParent);

private Q_SLOTS:
    void onEventDeleted(int aEventId);
    void onGroupsDeleted(QList<int> aGroupIds);

private:
    static void fullCleanup();
    static void deleteFiles(int aEventId);
    static bool removeDir(QString aDirPath);
};

#endif // FSCLEANUP_H
