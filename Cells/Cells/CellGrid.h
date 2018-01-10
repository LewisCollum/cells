#pragma once

#include "ILinkBehaviorFactory.h"
#include "ILinkBehavior.h"
#include "ISelectionBehaviorFactory.h"
#include "ISelectionBehavior.h"
#include "IWriteFactory.h"
#include "Grid.h"
#include "Cell.h"

template<size_t COLS, size_t ROWS>
class CellGrid
{
	Grid<Cell, COLS, ROWS> grid;
	IWriteFactory * WriteFactory;
	ILinkBehaviorFactory * LinkBehaviorFactory;
	ISelectionBehaviorFactory * SelectionBehaviorFactory;

public:
	CellGrid(
		const IWriteFactory& W, 
		const ILinkBehaviorFactory& LB,
		const ISelectionBehaviorFactory& SB
	) : FWrite(W), LinkBehaviorFactory(LB), SelectionBehaviorFactory(SB) {}
};

