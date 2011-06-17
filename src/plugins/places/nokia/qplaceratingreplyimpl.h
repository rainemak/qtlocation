#ifndef QPLACERATINGREPLYIMPL_H
#define QPLACERATINGREPLYIMPL_H

#include <QObject>
#include <QHash>

#include <qplacereply.h>
#include "qplacerestreply.h"

QTM_BEGIN_NAMESPACE

class QPlaceRatingReplyImpl : public QPlaceReply
{
    Q_OBJECT
public:
    explicit QPlaceRatingReplyImpl(QPlaceRestReply *reply, QObject *parent = 0);
    ~QPlaceRatingReplyImpl();
    void abort();

Q_SIGNALS:
    void processingFinished(QPlaceReply *reply);
    void processingError(QPlaceReply *reply, const QPlaceReply::Error &error, const QString &errorMessage);

private slots:
    void restError(QPlaceRestReply::Error error);
    void restFinished(const QString &data);

private:
    QPlaceRestReply *restReply;
};

QTM_END_NAMESPACE

#endif // QPLACERATINGREPLYIMPL_H