/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
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
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qdeclarativegeomaptype_p.h"
#include <qnumeric.h>
#include <QtQml/qqml.h>
#include <QDebug>

QT_BEGIN_NAMESPACE

/*!
    \qmlclass MapType QDeclarativeGeoMapType
    \inherits QObject
    \inqmlmodule QtLocation 5
    \ingroup qml-QtLocation5-maps
    \since QtLocation 5.0

    \brief The MapType element holds information about a map type.

    This includes the map type's \l name and \l description, the \l style and
    a flag to indicate if the map type is optimized for mobile devices (\l mobile).
*/

QDeclarativeGeoMapType::QDeclarativeGeoMapType(const QGeoMapType mapType, QObject* parent)
    : QObject(parent),
      mapType_(mapType) {}

QDeclarativeGeoMapType::~QDeclarativeGeoMapType() {}

/*!
    \qmlproperty enumeration MapType::style

    This read-only property gives access to the style of the map type.

    \list
    \o MapType.NoMap - No map.
    \o MapType.StreetMap - A street map.
    \o MapType.SatelliteMapDay - A map with day-time satellite imagery.
    \o MapType.SatelliteMapNight - A map with night-time satellite imagery.
    \o MapType.TerrainMap - A terrain map.
    \o MapType.HybridMap - A map with satellite imagery and streen information.
    \o MapType.GrayStreetMap - A gray-shaded street map.
    \o MapType.CustomMap - A custom map type.
    \endlist
*/
QDeclarativeGeoMapType::MapStyle QDeclarativeGeoMapType::style() const
{
    return QDeclarativeGeoMapType::MapStyle(mapType_.style());
}

/*!
    \qmlproperty string MapType::name

    This read-only property holds the name of the map type.
*/
QString QDeclarativeGeoMapType::name() const
{
    return mapType_.name();
}

/*!
    \qmlproperty string MapType::description

    This read-only property holds the description of the map type.
*/
QString QDeclarativeGeoMapType::description() const
{
    return mapType_.description();
}

/*!
    \qmlproperty bool MapType::mobile

    \brief This read-only property indicates whether the map type is optimized
    for the use on a mobile device.

    Map types for mobile devices usually have higher constrast to counteract the
    effects of sunlight and a reduced color for improved readability.
*/
bool QDeclarativeGeoMapType::mobile() const
{
    return mapType_.mobile();
}

#include "moc_qdeclarativegeomaptype_p.cpp"

QT_END_NAMESPACE
