#include "imagecontrollersettings.h"
#include "ui_imagecontrollersettings.h"



#include <QDebug>

ImageControllerSettings::ImageControllerSettings(ImageController *ctrl,QString wndTitle, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImageControllerSettings)
{
    this->controller = ctrl;
    this->bufferController = *this->controller;


   //ui->listFilters->setSelectionMode(QAbstractItemView::SingleSelection);

    this->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
    this->setFocus();

    this->setMouseTracking(true);

    this->installEventFilter(this);
    ui->setupUi(this);    
    this->setWindowTitle(wndTitle);
    this->fillListView();
}



ImageControllerSettings::~ImageControllerSettings()
{
    delete ui;
}

void ImageControllerSettings::fillListView()
{
    ui->listFilters->clear();
    for(auto obj : bufferController.getFilters())
        ui->listFilters->addItem(obj->getFilterName());
}

std::vector<QString> ImageControllerSettings::getDeclaratedNames() const
{
    std::vector<QString> names;
    for(auto obj : controller->getFilters())
        names.push_back(obj->getFilterName());
    return names;
}



void ImageControllerSettings::on_btnAdd_clicked()
{
    int currentIndex = ui->comboBox->currentIndex();
    AbstractFilter *filter = nullptr;
    switch (currentIndex) {
    case 0: filter = genericFilterFactory<KernelFilterEditor>(); break;
    case 2: filter = genericFilterFactory<MorphFilterForm>(); break;
    }
    if (filter)
        bufferController.getFilters().push_back(filter);
    fillListView();
}

void ImageControllerSettings::on_btnAccept_clicked()
{
    this->controller->Clone(this->bufferController);
    this->close();
}


void ImageControllerSettings::keyPressEvent(QKeyEvent *event) {}

void ImageControllerSettings::mouseMoveEvent(QMouseEvent *event) {}

void ImageControllerSettings::on_btnDelete_clicked()
{
    int indexToDelete = ui->listFilters->currentRow();
    if (indexToDelete != -1)
    {
        QMessageBox::StandardButton reply;
          reply = QMessageBox::question(this, "Подтверждение действия", "Вы действительно хотите удалить фильтр " +
                                        ui->listFilters->currentItem()->text() + "?",
                                        QMessageBox::Yes|QMessageBox::No);
          if (reply == QMessageBox::Yes) {
              bufferController.getFilters().erase(bufferController.getFilters().begin() + indexToDelete);
              fillListView();
          }
    }
}

void ImageControllerSettings::on_listFilters_doubleClicked(const QModelIndex &index)
{
    AbstractFilter* editedFilter = bufferController.getFilters()[index.row()];
    QString filterType = editedFilter->getFilterType();

    qDebug() << filterType << "\n";
    if (filterType == "AbstractKernelFilter")
        editedFilter = genericFilterFactory<KernelFilterEditor>(editedFilter);
    if (filterType == "AbstractMorphFilter")
        editedFilter = genericFilterFactory<MorphFilterForm>(editedFilter);

    if (editedFilter)
        bufferController.getFilters()[index.row()] = editedFilter;
    fillListView();
}

template<class T>
AbstractFilter *ImageControllerSettings::genericFilterFactory(AbstractFilter *filter)
{
    T editor(filter, getDeclaratedNames());
    editor.exec();
    while(!editor.isClosed());
    return editor.getFilter();
}
