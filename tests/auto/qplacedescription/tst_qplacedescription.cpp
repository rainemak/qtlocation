/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the test suite of the Qt Toolkit.
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

#include <QtCore/QString>
#include <QtTest/QtTest>

#include <qplacedescription.h>

QT_USE_NAMESPACE

class tst_QPlaceDescription : public QObject
{
    Q_OBJECT

public:
    tst_QPlaceDescription();

private Q_SLOTS:
    void constructorTest();
    void supplierTest();
    void contentTest();
    void contentTitleTest();
    void contentTypeTest();
    void sourceUrlTest();
    void languageTest();
    void operatorsTest();
};

tst_QPlaceDescription::tst_QPlaceDescription()
{
}

void tst_QPlaceDescription::constructorTest()
{
    QPlaceDescription testObj;
    testObj.setContent("testId");
    QPlaceDescription *testObjPtr = new QPlaceDescription(testObj);
    QVERIFY2(testObjPtr != NULL, "Copy constructor - null");
    QVERIFY2(*testObjPtr == testObj, "Copy constructor - compare");
    delete testObjPtr;
}

void tst_QPlaceDescription::supplierTest()
{
    QPlaceDescription testObj;
    QVERIFY2(testObj.supplier().supplierId() == QString(), "Wrong default value");
    QPlaceSupplier sup;
    sup.setName("testName1");
    sup.setSupplierId("testId");
    testObj.setSupplier(sup);
    QVERIFY2(testObj.supplier() == sup, "Wrong value returned");
}

void tst_QPlaceDescription::contentTest()
{
    QPlaceDescription testObj;
    QVERIFY2(testObj.content() == QString(), "Wrong default value");
    testObj.setContent("testText");
    QVERIFY2(testObj.content() == "testText", "Wrong value returned");
}

void tst_QPlaceDescription::contentTitleTest()
{
    QPlaceDescription testObj;
    QVERIFY2(testObj.contentTitle() == QString(), "Wrong default value");
    testObj.setContentTitle("testText");
    QVERIFY2(testObj.contentTitle() == "testText", "Wrong value returned");
}

void tst_QPlaceDescription::contentTypeTest()
{
    QPlaceDescription testObj;
    QVERIFY2(testObj.contentType() == QString(), "Wrong default value");
    testObj.setContentType("testText");
    QVERIFY2(testObj.contentType() == "testText", "Wrong value returned");
}

void tst_QPlaceDescription::sourceUrlTest()
{
    QPlaceDescription testObj;
    const QUrl testUrl = QUrl::fromEncoded("http://example.com/testUrl");
    QVERIFY2(testObj.sourceUrl() == QUrl(), "Wrong default value");
    testObj.setSourceUrl(testUrl);
    QVERIFY2(testObj.sourceUrl() == testUrl, "Wrong value returned");
}

void tst_QPlaceDescription::languageTest()
{
    QPlaceDescription testObj;
    QVERIFY2(testObj.language() == QString(), "Wrong default value");
    testObj.setLanguage("testText");
    QVERIFY2(testObj.language() == "testText", "Wrong value returned");
}

void tst_QPlaceDescription::operatorsTest()
{
    QPlaceDescription testObj;
    testObj.setLanguage("testValue");
    QPlaceDescription testObj2;
    testObj2 = testObj;
    QVERIFY2(testObj == testObj2, "Not copied correctly");
    testObj2.setContent("testValue2");
    QVERIFY2(testObj != testObj2, "Object should be different");
}

QTEST_APPLESS_MAIN(tst_QPlaceDescription);

#include "tst_qplacedescription.moc"
