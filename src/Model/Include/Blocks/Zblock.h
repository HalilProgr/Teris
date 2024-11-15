#pragma once

#include "AbstractBlock.h"


namespace Tetris::Model::Blocks
{
	
	/// @brief класс Z блок
	class Zblock : public AbstractBlock
	{
	public:
		/// @brief Конструктор
		/// @param color цвет блока
		Zblock(Color color) : AbstractBlock(color) 
		{
			_stateToPositions = {
				{State::Up, {
				    Position(-1, 1 ),  // *  *  *
				    Position( 0, 1 ),  // o  o  *
				    Position( 0, 0 ),  // *  0  o
				    Position( 1, 0 )   // *  *  *
				}},
				{State::Right, {
				    Position( 1, 1 ),  // *  *  *
				    Position( 1, 0 ),  // *  *  o
				    Position( 0, 0 ),  // *  0  o
				    Position( 0,-1 )   // *  o  *
				}},
				{State::Down, {
				    Position( 1,-1 ),  // *  *  *
				    Position( 0,-1 ),  // *  *  *
				    Position( 0, 0 ),  // o  0  *
				    Position(-1, 0 )   // *  o  o
				}},
				{State::Left, {
				    Position(-1,-1 ),  // *  *  o
				    Position(-1, 0 ),  // *  0  o
				    Position( 0, 0 ),  // *  o  *
				    Position( 0, 1 )   // *  *  *
				}}  
			};

			_stateToOffset = JLSTZOffset;

		};

	};

} // namespace