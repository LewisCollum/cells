#include "Cell.h"
#include <algorithm>

void Cell::link(Cell& c, bool bidi)
{
	links.emplace_front(&c);
	if (bidi) c.link(*this, false);
}

void Cell::unlink(Cell& c, bool bidi)
{
	links.remove(&c);
	if (bidi) c.unlink(*this, false);
}

bool Cell::isLinked(const Cell& c) const
{
	return std::find(links.begin(), links.end(), &c) != links.end();
}

bool Cell::noLinks() const
{
	return links.empty();
}
