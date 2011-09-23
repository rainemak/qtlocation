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

#ifndef QPLACEREVIEW_P_H
#define QPLACEREVIEW_P_H

#include <QtCore/QUrl>
#include <QtCore/QSharedData>

#include "qplacecontent_p.h"

QT_BEGIN_NAMESPACE

class QPlaceReviewPrivate : public QPlaceContentPrivate
{
public:
    QPlaceReviewPrivate();
    QPlaceReviewPrivate(const QPlaceReviewPrivate &other);

    ~QPlaceReviewPrivate();

    bool compare(const QPlaceContentPrivate *other) const;

    Q_DEFINE_CONTENT_PRIVATE_HELPER(QPlaceReview, QPlaceContent::ReviewType);

    QString date;
    QString description;
    QString language;
    int helpfulVotings;
    QStringList mediaIds;
    int unhelpfulVotings;
    qreal rating;
    QString reviewId;
    QString title;
    QString userId;
    QString userName;
    QUrl originatorUrl;
};

QT_END_NAMESPACE

#endif
