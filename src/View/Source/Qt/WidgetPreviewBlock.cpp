#include <View/Qt/WidgetPreviewBlock.h>
#include <Model/Blocks/AbstractBlock.h>


namespace Tetris::View::Qt
{
    WidgetPreviewBlock::WidgetPreviewBlock(QWidget* parent): Map(parent)
    {}

    void WidgetPreviewBlock::SetBlock(const AbstractBlockPtr block)
    {
        using Model::TypeColor::None;

        if (block == nullptr)
            return;
        
        // Проверка на изменение типа блока и цвета
        if (block->GetType() == _typeShape && block->GetColor() == _typeColor)
            return;

        _typeShape = block->GetType();
        _typeColor = block->GetColor();

        std::vector<Model::TypeColor> map;
        Model::MapSize size;

        // Заполнение карты в зависимости от типа блока
        switch (_typeShape)
        {
            case Model::TypeBlock::Iblock:
                size = Model::MapSize{4,6};
                map =  {None, None, None, None, None, None, // 1 строка
                        None, None, None, None, None, None,
                        None, _typeColor, _typeColor, _typeColor, _typeColor, None,
                        None, None, None, None, None, None}; // 4 строка
                break;

            case Model::TypeBlock::Jblock:
                size = Model::MapSize{4, 5};
                map =  {None, None, None, None, None, // 1 строка
                        None, _typeColor, _typeColor, _typeColor, None,
                        None, _typeColor, None, None, None,
                        None, None, None, None, None}; // 4 строка
                break;

            case Model::TypeBlock::Lblock:
                size = Model::MapSize{4, 5};
                map =  {None, None, None, None, None, // 1 строка
                        None, _typeColor, _typeColor, _typeColor, None,
                        None, None, None, _typeColor, None,
                        None, None, None, None, None}; // 4 строка
                break;

            case Model::TypeBlock::Oblock:
                size = Model::MapSize{4, 4};
                map =  {None, None, None, None, // 1 строка
                        None, _typeColor, _typeColor, None,
                        None, _typeColor, _typeColor, None,
                        None, None, None, None}; // 4 строка
                break;

            case Model::TypeBlock::Sblock:
                size = Model::MapSize{4, 5};
                map =  {None, None, None, None, None, // 1 строка
                        None, _typeColor, _typeColor, None, None,
                        None, None, _typeColor, _typeColor, None,
                        None, None, None, None, None}; // 4 строка
                break;

            case Model::TypeBlock::Tblock:
                size = Model::MapSize{4, 5};
                map =  {None, None, None, None, None, // 1 строка
                        None, _typeColor, _typeColor, _typeColor, None,
                        None, None, _typeColor, None, None,
                        None, None, None, None, None}; // 4 строка
                break;

            case Model::TypeBlock::Zblock:
                size = Model::MapSize{4, 5};
                map =  {None, None, None, None, None, // 1 строка
                        None, None, _typeColor, _typeColor, None,
                        None, _typeColor, _typeColor, None, None,
                        None, None, None, None, None}; // 4 строка
                break;

            default:
                return; // Неподдерживаемый тип блока
        }

        SetMap(map, size);
    }

    Model::TypeBlock WidgetPreviewBlock::GetType() const
    {
        return _typeShape;
    }
}