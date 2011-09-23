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

#include "qdeclarativedescription_p.h"

QT_USE_NAMESPACE

/*!
    \qmlclass Description QDeclarativeDescription

    \brief The Description element holds description data.
    \ingroup qml-places
    \since 5.0

    Description cointains many properties holding data of the description like content,
    language, title, etc.
*/

QDeclarativeDescription::QDeclarativeDescription(QObject* parent)
        : QObject(parent)
{
}

QDeclarativeDescription::QDeclarativeDescription(const QPlaceDescription &src,
        QObject *parent)
        : QObject(parent),
          m_declarativeSupplier(src.supplier()),
          m_src(src)
{
}

QDeclarativeDescription::~QDeclarativeDescription()
{
}

void QDeclarativeDescription::setDescription(const QPlaceDescription &src)
{
    QPlaceDescription previous = m_src;
    m_src = src;

    if (previous.content() != m_src.content()) {
        emit contentChanged();
    }
    if (previous.contentTitle() != m_src.contentTitle()) {
        emit contentTitleChanged();
    }
    if (previous.contentType() != m_src.contentType()) {
        emit contentTypeChanged();
    }
    if (previous.language() != m_src.language()) {
        emit languageChanged();
    }
    if (previous.sourceUrl() != m_src.sourceUrl()) {
        emit sourceUrlChanged();
    }
    if (previous.supplier() != m_src.supplier()) {
        m_declarativeSupplier.setSupplier(src.supplier());
        emit supplierChanged();
    }
}

QPlaceDescription QDeclarativeDescription::description()
{
    m_src.setSupplier(m_declarativeSupplier.supplier());
    return m_src;
}

/*!
    \qmlproperty string Description::content

    This property holds content of the description.
*/

void QDeclarativeDescription::setContent(const QString &content)
{
    if (m_src.content() != content) {
        m_src.setContent(content);
        emit contentChanged();
    }
}

QString QDeclarativeDescription::content() const
{
    return m_src.content();
}

/*!
    \qmlproperty string Description::contentTitle

    This property holds title of description.
*/

void QDeclarativeDescription::setContentTitle(const QString &contentTitle)
{
    if (m_src.contentTitle() != contentTitle) {
        m_src.setContentTitle(contentTitle);
        emit contentTitleChanged();
    }
}

QString QDeclarativeDescription::contentTitle() const
{
    return m_src.contentTitle();
}

/*!
    \qmlproperty string Description::contentType

    This property holds content type.
*/

void QDeclarativeDescription::setContentType(const QString &contentType)
{
    if (m_src.contentType() != contentType) {
        m_src.setContentType(contentType);
        emit contentTypeChanged();
    }
}

QString QDeclarativeDescription::contentType() const
{
    return m_src.contentType();
}

/*!
    \qmlproperty string Description::language

    This property holds language of description.
*/

void QDeclarativeDescription::setLanguage(const QString &language)
{
    if (m_src.language() != language) {
        m_src.setLanguage(language);
        emit languageChanged();
    }
}

QString QDeclarativeDescription::language() const
{
    return m_src.language();
}

/*!
    \qmlproperty url Description::sourceUrl

    This property holds source URL.
*/

void QDeclarativeDescription::setSourceUrl(const QUrl &sourceUrl)
{
    if (m_src.sourceUrl() != sourceUrl) {
        m_src.setSourceUrl(sourceUrl);
        emit sourceUrlChanged();
    }
}

QUrl QDeclarativeDescription::sourceUrl() const
{
    return m_src.sourceUrl();
}

/*!
    \qmlproperty string Description::supplier

    This property holds supplier info.

   Note: this property's changed() signal is currently emitted only if the
   whole element changes, not if only the contents of the element change.
*/

void QDeclarativeDescription::setSupplier(QDeclarativeSupplier *src)
{
    if (m_declarativeSupplier.supplier() != src->supplier()) {
        m_declarativeSupplier.setSupplier(src->supplier());
        emit supplierChanged();
    }
}

QDeclarativeSupplier *QDeclarativeDescription::supplier()
{
    return &m_declarativeSupplier;
}
