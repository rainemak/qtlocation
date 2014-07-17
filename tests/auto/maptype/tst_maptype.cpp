/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the test suite of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtCore/QString>
#include <QtTest/QtTest>

#include <QtLocation/private/qgeomaptype_p.h>

QT_USE_NAMESPACE

Q_DECLARE_METATYPE(QGeoMapType)

class tst_MapType : public QObject
{
    Q_OBJECT

public:
    tst_MapType();

private Q_SLOTS:
    void constructorTest();
    void comparison();
    void comparison_data();
};

tst_MapType::tst_MapType() {}

void tst_MapType::constructorTest()
{
    QGeoMapType *testObjPtr = new QGeoMapType(QGeoMapType::StreetMap, QStringLiteral("street map"),
                                              QStringLiteral("map description"), true, true, 1);
    QVERIFY(testObjPtr);
    QCOMPARE(testObjPtr->style(), QGeoMapType::StreetMap);
    QCOMPARE(testObjPtr->name(), QStringLiteral("street map"));
    QCOMPARE(testObjPtr->description(), QStringLiteral("map description"));
    QVERIFY(testObjPtr->mobile());
    QVERIFY(testObjPtr->night());
    QCOMPARE(testObjPtr->mapId(), 1);
    delete testObjPtr;

    testObjPtr = new QGeoMapType();
    QCOMPARE(testObjPtr->style(), QGeoMapType::NoMap);
    QVERIFY2(testObjPtr->name().isEmpty(), "Wrong default value");
    QVERIFY2(testObjPtr->description().isEmpty(), "Wrong default value");
    QVERIFY2(!testObjPtr->mobile(), "Wrong default value");
    QVERIFY2(!testObjPtr->night(), "Wrong default value");
    QCOMPARE(testObjPtr->mapId(), 0);
    delete testObjPtr;
}

void tst_MapType::comparison_data()
{
    QTest::addColumn<QGeoMapType>("type1");
    QTest::addColumn<QGeoMapType>("type2");
    QTest::addColumn<bool>("expected");

    QTest::newRow("null") << QGeoMapType() << QGeoMapType() << true;

    QTest::newRow("equal") << QGeoMapType(QGeoMapType::StreetMap, QStringLiteral("street name"),
                                          QStringLiteral("street desc"), false, false, 42)
                           << QGeoMapType(QGeoMapType::StreetMap, QStringLiteral("street name"),
                                          QStringLiteral("street desc"), false, false, 42)
                           << true;

    QTest::newRow("style") << QGeoMapType(QGeoMapType::StreetMap, QStringLiteral("street name"),
                                          QStringLiteral("street desc"), false, false, 42)
                           << QGeoMapType(QGeoMapType::TerrainMap, QStringLiteral("street name"),
                                          QStringLiteral("street desc"), false, false, 42)
                           << false;

    QTest::newRow("name") << QGeoMapType(QGeoMapType::StreetMap, QStringLiteral("street name"),
                                         QStringLiteral("street desc"), false, false, 42)
                          << QGeoMapType(QGeoMapType::StreetMap, QStringLiteral("different name"),
                                         QStringLiteral("street desc"), false, false, 42)
                          << false;

    QTest::newRow("description") << QGeoMapType(QGeoMapType::StreetMap,
                                                QStringLiteral("street name"),
                                                QStringLiteral("street desc"), false, false, 42)
                                 << QGeoMapType(QGeoMapType::StreetMap,
                                                QStringLiteral("street name"),
                                                QStringLiteral("different desc"), false, false, 42)
                                 << false;

    QTest::newRow("mobile") << QGeoMapType(QGeoMapType::StreetMap, QStringLiteral("street name"),
                                           QStringLiteral("street desc"), false, false, 42)
                            << QGeoMapType(QGeoMapType::StreetMap, QStringLiteral("street name"),
                                           QStringLiteral("street desc"), true, false, 42)
                            << false;

    QTest::newRow("night") << QGeoMapType(QGeoMapType::StreetMap, QStringLiteral("street name"),
                                           QStringLiteral("street desc"), false, false, 42)
                            << QGeoMapType(QGeoMapType::StreetMap, QStringLiteral("street name"),
                                           QStringLiteral("street desc"), false, true, 42)
                            << false;

    QTest::newRow("id") << QGeoMapType(QGeoMapType::StreetMap, QStringLiteral("street name"),
                                       QStringLiteral("street desc"), false, false, 42)
                        << QGeoMapType(QGeoMapType::StreetMap, QStringLiteral("street name"),
                                       QStringLiteral("street desc"), false, false, 99)
                        << false;
}

void tst_MapType::comparison()
{
    QFETCH(QGeoMapType, type1);
    QFETCH(QGeoMapType, type2);
    QFETCH(bool, expected);

    QCOMPARE(type1 == type2, expected);
    QCOMPARE(type1 != type2, !expected);
}

QTEST_APPLESS_MAIN(tst_MapType)

#include "tst_maptype.moc"
