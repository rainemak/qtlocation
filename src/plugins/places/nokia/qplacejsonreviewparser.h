#ifndef QPLACEJSONREVIEWPARSER_H
#define QPLACEJSONREVIEWPARSER_H

#include <QObject>
#include <QList>

#include <qplacesearchresult.h>

class QScriptEngine;
class QScriptValue;

QTM_BEGIN_NAMESPACE

class QPlaceJSonReviewParser : public QObject
{
    Q_OBJECT
public:
    enum Error {
        NoError,
        ParsingError
    };

    explicit QPlaceJSonReviewParser(QObject *parent = 0);
    virtual ~QPlaceJSonReviewParser();

    QList<QPlaceReview> results();
    int allReviewsCount();
    static QPlaceReview buildReview(const QScriptValue &place);

signals:
    void finished(const QPlaceJSonReviewParser::Error &error, const QString &errorMessage);

public slots:
    void processData(const QString &data);

private:
    void processReviews(const QScriptValue &contacts);

private:
    QScriptEngine *engine;
    QList<QPlaceReview> reviews;
    int allReviews;
};

QTM_END_NAMESPACE

#endif // QPLACEJSONREVIEWPARSER_H