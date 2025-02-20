#pragma once

#include <Model/Forwards.h>
#include <Model/Export.h>

#include <Model/Factory/ObjectFactory.h>


namespace Tetris::Model::Blocks
{
    /// @brief Фабрика для создания блоков в игре Тетрис.
    class MODEL_EXPORT BlocksFactory final : public ObjectFactory<AbstractBlock, TypeBlock>
    {
    public:
        /// @brief Создать блок с заданным идентификатором и цветом.
        /// @param id Идентификатор блока.
        /// @param color Цвет блока.
        /// @return Указатель на созданный блок.
        [[nodiscard]] AbstractBlock* Create(TypeBlock id, TypeColor color)
        {
            return _factory[id]->Create(color);
        }

        /// @brief Получить количество инициализированных блоков.
        /// @return Количество зарегистрированных блоков.
        [[nodiscard]] int Size() const
        {
            return _factory.size();
        }
    };
} // namespace Tetris::Model::Blocks
