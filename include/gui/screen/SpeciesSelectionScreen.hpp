/*
*   This file is part of PKSM
*   Copyright (C) 2016-2018 Bernardo Giordano, Admiral Fish, piepie62
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*   Additional Terms 7.b and 7.c of GPLv3 apply to this file:
*       * Requiring preservation of specified reasonable legal notices or
*         author attributions in that material or in the Appropriate Legal
*         Notices displayed by works containing it.
*       * Prohibiting misrepresentation of the origin of that material,
*         or requiring that modified versions of such material be marked in
*         reasonable ways as different from the original version.
*/

#ifndef SPECIESSELECTIONSCREEN_HPP
#define SPECIESSELECTIONSCREEN_HPP

#include "SelectionScreen.hpp"
#include "HidHorizontal.hpp"

class SpeciesSelectionScreen : public SelectionScreen
{
public:
    SpeciesSelectionScreen(std::shared_ptr<PKX> pkm) : SelectionScreen(pkm), hid(40, 8)
    {
        hid.update(809);
        hid.select(pkm->species() == 0 ? 0 : pkm->species() - 1);
    }
    void draw() const override;
    void update(touchPosition* touch) override;
    ScreenType type() const override { return ScreenType::SPECIES_SELECT; }
private:
    HidHorizontal hid;
};

#endif