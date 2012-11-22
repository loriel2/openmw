#ifndef CSV_DOC_VIEW_H
#define CSV_DOC_VIEW_H

#include <QMainWindow>

class QAction;

namespace CSMDoc
{
    class Document;
}

namespace CSVDoc
{
    class ViewManager;

    class View : public QMainWindow
    {
            Q_OBJECT

            ViewManager& mViewManager;
            CSMDoc::Document *mDocument;

            // not implemented
            View (const View&);
            View& operator= (const View&);

        private:

            void closeEvent (QCloseEvent *event);

            void setupUi();

        public:

            View (ViewManager& viewManager, CSMDoc::Document *document);
            ///< The ownership of \a document is not transferred to *this.

            const CSMDoc::Document *getDocument() const;

            CSMDoc::Document *getDocument();

        private slots:

            void newView();
    };
}

#endif