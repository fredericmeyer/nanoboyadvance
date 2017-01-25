///////////////////////////////////////////////////////////////////////////////////
//
//  NanoboyAdvance is a modern Game Boy Advance emulator written in C++
//  with performance, platform independency and reasonable accuracy in mind.
//  Copyright (C) 2017 Frederic Meyer
//
//  This file is part of nanoboyadvance.
//
//  nanoboyadvance is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 2 of the License, or
//  (at your option) any later version.
//
//  nanoboyadvance is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with nanoboyadvance. If not, see <http://www.gnu.org/licenses/>.
//
///////////////////////////////////////////////////////////////////////////////////

#include "ppu.hpp"

namespace gba
{
    ppu::ppu()
    {
        reset();
    }

    void ppu::reset()
    {
        m_vcount = 0;
        m_dispstat.vblank_flag = true;
        m_dispstat.hblank_flag = false;
        m_dispstat.vcount_flag = false;
        m_dispstat.vblank_interrupt = false;
        m_dispstat.hblank_interrupt = false;
        m_dispstat.vcount_interrupt = false;
        m_dispstat.vcount_setting = 0;
    }

    void ppu::set_memory(u8* pal, u8* oam, u8* vram)
    {
        m_pal = pal;
        m_oam = oam;
        m_vram = vram;
    }
}
