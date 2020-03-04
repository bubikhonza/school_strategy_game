#ifndef STORYDIALOG_H
#define STORYDIALOG_H

#include <QDialog>

namespace Ui {
class StoryDialog;
}

class StoryDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for the class.
     */
    explicit StoryDialog(QWidget *parent = nullptr);
    ~StoryDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::StoryDialog *ui;
};

#endif // STORYDIALOG_H
