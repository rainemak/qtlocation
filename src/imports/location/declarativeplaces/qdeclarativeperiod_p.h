/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtLocation module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QDECLARATIVEPERIOD_P_H
#define QDECLARATIVEPERIOD_P_H

#include <qplaceperiod.h>
#include <QtDeclarative/qdeclarative.h>

#include <QObject>

QT_BEGIN_NAMESPACE

class QDeclarativePeriod : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QDate startDate READ startDate WRITE setStartDate NOTIFY startDateChanged)
    Q_PROPERTY(QTime startTime READ startTime WRITE setStartTime NOTIFY startTimeChanged)
    Q_PROPERTY(QDate endDate READ endDate WRITE setEndDate NOTIFY endDateChanged)
    Q_PROPERTY(QTime endTime READ endTime WRITE setEndTime NOTIFY endTimeChanged)

public:
    explicit QDeclarativePeriod(QObject* parent = 0);
    explicit QDeclarativePeriod(const QPlacePeriod &period, QObject* parent = 0);
    ~QDeclarativePeriod();

    QPlacePeriod period() const;
    void setPeriod(const QPlacePeriod &period);

    QDate startDate() const;
    void setStartDate(const QDate &data);
    QTime startTime() const;
    void setStartTime(const QTime &data);
    QDate endDate() const;
    void setEndDate(const QDate &data);
    QTime endTime() const;
    void setEndTime(const QTime &data);

signals:
    void startDateChanged();
    void startTimeChanged();
    void endDateChanged();
    void endTimeChanged();

private:
    QPlacePeriod m_period;
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QT_PREPEND_NAMESPACE(QDeclarativePeriod));

#endif // QDECLARATIVEPERIOD_P_H
