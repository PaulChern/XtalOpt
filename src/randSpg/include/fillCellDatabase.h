/**********************************************************************
  fillCellDatabase.h - Database that contains the information needed to
                       fill a unit cell when given a cell whose
                       atoms match up with those in wyckoffDatabase.h

  Copyright (C) 2015 - 2016 by Patrick S. Avery

  This source code is released under the New BSD License, (the "License").

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
 ***********************************************************************/

#ifndef FILL_CELL_INFO_H
#define FILL_CELL_INFO_H

#include "randSpg.h"

#if (defined(_MSC_VER) && _MSC_VER <= 1600)
// We need this with MSVC 2010 and earlier
#include <array>
#endif

// This database was obtained by parsing html files at
// http://www.cryst.ehu.es/cgi-bin/cryst/programs/nph-table?from=getwp
// on 01/06/16

// First string in the pair is called 'extraDuplicates'
// If it is not empty, it gives coordinates to add to
// the wyckoff position coordinates to get all of the positions
// For instance, for number 5, there is an extraDuplicates string of
// (0.5,0.5,0). That means, to get all of the Wyckoff positions, we
// have not only (x,y,z) and (-x,y,-z), but (x+0.5,y+0.5,z) and
// (-x+0.5,y+0.5,-z) as well

// The second string in the pair is all of the Wyckoff positions
// for the most general Wyckoff position in the spacegroup

// This is the definition of fillCellInfo:
// typedef std::pair<std::string, std::string> fillCellInfo;

#if (defined(_MSC_VER) && _MSC_VER <= 1600)
std::array<fillCellInfo, 231> _fillCellVector =
{
    fillCellInfo(std::make_pair("","")),
    fillCellInfo(std::make_pair("","(x,y,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,-z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,y,-z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,y+0.5,-z)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0)","(x,y,z)(-x,y,-z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(x,-y,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(x,-y,z+0.5)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0)","(x,y,z)(x,-y,z)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0)","(x,y,z)(x,-y,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,y,-z)(-x,-y,-z)(x,-y,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,y+0.5,-z)(-x,-y,-z)(x,-y+0.5,z)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0)","(x,y,z)(-x,y,-z)(-x,-y,-z)(x,-y,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,y,-z+0.5)(-x,-y,-z)(x,-y,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,y+0.5,-z+0.5)(-x,-y,-z)(x,-y+0.5,z+0.5)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0)","(x,y,z)(-x,y,-z+0.5)(-x,-y,-z)(x,-y,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z+0.5)(-x,y,-z+0.5)(x,-y,-z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-x+0.5,y+0.5,-z)(x+0.5,-y+0.5,-z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x+0.5,-y,z+0.5)(-x,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0)","(x,y,z)(-x,-y,z+0.5)(-x,y,-z+0.5)(x,-y,-z)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)")),
    fillCellInfo(std::make_pair("(0,0.5,0.5)(0.5,0,0.5)(0.5,0.5,0)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x+0.5,-y,z+0.5)(-x,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(x,-y,z)(-x,y,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z+0.5)(x,-y,z+0.5)(-x,y,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(x,-y,z+0.5)(-x,y,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(x+0.5,-y,z)(-x+0.5,y,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z+0.5)(x+0.5,-y,z)(-x+0.5,y,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(x,-y+0.5,z+0.5)(-x,y+0.5,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x+0.5,-y,z+0.5)(x+0.5,-y,z+0.5)(-x,y,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(x+0.5,-y+0.5,z)(-x+0.5,y+0.5,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z+0.5)(x+0.5,-y+0.5,z)(-x+0.5,y+0.5,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(x+0.5,-y+0.5,z+0.5)(-x+0.5,y+0.5,z+0.5)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0)","(x,y,z)(-x,-y,z)(x,-y,z)(-x,y,z)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0)","(x,y,z)(-x,-y,z+0.5)(x,-y,z+0.5)(-x,y,z)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0)","(x,y,z)(-x,-y,z)(x,-y,z+0.5)(-x,y,z+0.5)")),
    fillCellInfo(std::make_pair("(0,0.5,0.5)","(x,y,z)(-x,-y,z)(x,-y,z)(-x,y,z)")),
    fillCellInfo(std::make_pair("(0,0.5,0.5)","(x,y,z)(-x,-y,z)(x,-y+0.5,z)(-x,y+0.5,z)")),
    fillCellInfo(std::make_pair("(0,0.5,0.5)","(x,y,z)(-x,-y,z)(x+0.5,-y,z)(-x+0.5,y,z)")),
    fillCellInfo(std::make_pair("(0,0.5,0.5)","(x,y,z)(-x,-y,z)(x+0.5,-y+0.5,z)(-x+0.5,y+0.5,z)")),
    fillCellInfo(std::make_pair("(0,0.5,0.5)(0.5,0,0.5)(0.5,0.5,0)","(x,y,z)(-x,-y,z)(x,-y,z)(-x,y,z)")),
    fillCellInfo(std::make_pair("(0.5,0,0.5)(0,0.5,0.5)(0.5,0.5,0)","(x,y,z)(-x,-y,z)(x+0.25,-y+0.25,z+0.25)(-x+0.25,y+0.25,z+0.25)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(x,-y,z)(-x,y,z)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(x+0.5,-y+0.5,z)(-x+0.5,y+0.5,z)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(x+0.5,-y,z)(-x+0.5,y,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(-x,-y,-z)(x,y,-z)(x,-y,z)(-x,y,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x+0.5,-y+0.5,z)(-x+0.5,y,-z+0.5)(x,-y+0.5,-z+0.5)(-x,-y,-z)(x+0.5,y+0.5,-z)(x+0.5,-y,z+0.5)(-x,y+0.5,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-x,y,-z+0.5)(x,-y,-z+0.5)(-x,-y,-z)(x,y,-z)(x,-y,z+0.5)(-x,y,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x+0.5,-y+0.5,z)(-x+0.5,y,-z)(x,-y+0.5,-z)(-x,-y,-z)(x+0.5,y+0.5,-z)(x+0.5,-y,z)(-x,y+0.5,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x+0.5,-y,z)(-x,y,-z)(x+0.5,-y,-z)(-x,-y,-z)(x+0.5,y,-z)(x,-y,z)(-x+0.5,y,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x+0.5,-y,z)(-x+0.5,y+0.5,-z+0.5)(x,-y+0.5,-z+0.5)(-x,-y,-z)(x+0.5,y,-z)(x+0.5,-y+0.5,z+0.5)(-x,y+0.5,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x+0.5,-y,z+0.5)(-x+0.5,y,-z+0.5)(x,-y,-z)(-x,-y,-z)(x+0.5,y,-z+0.5)(x+0.5,-y,z+0.5)(-x,y,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x+0.5,-y,z)(-x,y,-z+0.5)(x+0.5,-y,-z+0.5)(-x,-y,-z)(x+0.5,y,-z)(x,-y,z+0.5)(-x+0.5,y,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-x+0.5,y+0.5,-z)(x+0.5,-y+0.5,-z)(-x,-y,-z)(x,y,-z)(x+0.5,-y+0.5,z)(-x+0.5,y+0.5,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x+0.5,-y+0.5,z)(-x,y+0.5,-z+0.5)(x+0.5,-y,-z+0.5)(-x,-y,-z)(x+0.5,y+0.5,-z)(x,-y+0.5,z+0.5)(-x+0.5,y,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z+0.5)(-x,y+0.5,-z+0.5)(x,-y+0.5,-z)(-x,-y,-z)(x,y,-z+0.5)(x,-y+0.5,z+0.5)(-x,y+0.5,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-x+0.5,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z+0.5)(-x,-y,-z)(x,y,-z)(x+0.5,-y+0.5,z+0.5)(-x+0.5,y+0.5,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x+0.5,-y+0.5,z)(-x,y+0.5,-z)(x+0.5,-y,-z)(-x,-y,-z)(x+0.5,y+0.5,-z)(x,-y+0.5,z)(-x+0.5,y,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x+0.5,-y+0.5,z+0.5)(-x,y,-z+0.5)(x+0.5,-y+0.5,-z)(-x,-y,-z)(x+0.5,y+0.5,-z+0.5)(x,-y,z+0.5)(-x+0.5,y+0.5,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x+0.5,-y,z+0.5)(-x,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z)(-x,-y,-z)(x+0.5,y,-z+0.5)(x,-y+0.5,z+0.5)(-x+0.5,y+0.5,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x+0.5,-y,z+0.5)(-x,y+0.5,-z)(x+0.5,-y+0.5,-z+0.5)(-x,-y,-z)(x+0.5,y,-z+0.5)(x,-y+0.5,z)(-x+0.5,y+0.5,z+0.5)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0)","(x,y,z)(-x,-y,z+0.5)(-x,y,-z+0.5)(x,-y,-z)(-x,-y,-z)(x,y,-z+0.5)(x,-y,z+0.5)(-x,y,z)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0)","(x,y,z)(-x,-y+0.5,z+0.5)(-x,y+0.5,-z+0.5)(x,-y,-z)(-x,-y,-z)(x,y+0.5,-z+0.5)(x,-y+0.5,z+0.5)(-x,y,z)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(-x,-y,-z)(x,y,-z)(x,-y,z)(-x,y,z)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0)","(x,y,z)(-x,-y,z)(-x,y,-z+0.5)(x,-y,-z+0.5)(-x,-y,-z)(x,y,-z)(x,-y,z+0.5)(-x,y,z+0.5)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0)","(x,y,z)(-x,-y+0.5,z)(-x,y+0.5,-z)(x,-y,-z)(-x,-y,-z)(x,y+0.5,-z)(x,-y+0.5,z)(-x,y,z)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0)","(x,y,z)(-x+0.5,-y,z)(-x,y,-z+0.5)(x+0.5,-y,-z+0.5)(-x,-y,-z)(x+0.5,y,-z)(x,-y,z+0.5)(-x+0.5,y,z+0.5)")),
    fillCellInfo(std::make_pair("(0,0.5,0.5)(0.5,0,0.5)(0.5,0.5,0)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(-x,-y,-z)(x,y,-z)(x,-y,z)(-x,y,z)")),
    fillCellInfo(std::make_pair("(0,0.5,0.5)(0.5,0,0.5)(0.5,0.5,0)","(x,y,z)(-x+0.75,-y+0.75,z)(-x+0.75,y,-z+0.75)(x,-y+0.75,-z+0.75)(-x,-y,-z)(x+0.25,y+0.25,-z)(x+0.25,-y,z+0.25)(-x,y+0.25,z+0.25)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(-x,-y,-z)(x,y,-z)(x,-y,z)(-x,y,z)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(-x+0.5,y+0.5,-z)(x+0.5,-y+0.5,-z)(-x,-y,-z)(x,y,-z)(x+0.5,-y+0.5,z)(-x+0.5,y+0.5,z)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x+0.5,-y,z+0.5)(-x,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z)(-x,-y,-z)(x+0.5,y,-z+0.5)(x,-y+0.5,z+0.5)(-x+0.5,y+0.5,z)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x,-y+0.5,z)(-x,y+0.5,-z)(x,-y,-z)(-x,-y,-z)(x,y+0.5,-z)(x,-y+0.5,z)(-x,y,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z+0.5)(-y,x,z+0.25)(y,-x,z+0.75)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-y,x,z+0.5)(y,-x,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z+0.5)(-y,x,z+0.75)(y,-x,z+0.25)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x+0.5,-y+0.5,z+0.5)(-y,x+0.5,z+0.25)(y+0.5,-x,z+0.75)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(y,-x,-z)(-y,x,-z)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(y,-x,-z)(-y,x,-z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)(-x,-y,-z)(x,y,-z)(y,-x,-z)(-y,x,-z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-y,x,z+0.5)(y,-x,z+0.5)(-x,-y,-z)(x,y,-z)(y,-x,-z+0.5)(-y,x,-z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x+0.5,-y+0.5,z)(-y+0.5,x,z)(y,-x+0.5,z)(-x,-y,-z)(x+0.5,y+0.5,-z)(y+0.5,-x,-z)(-y,x+0.5,-z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x+0.5,-y+0.5,z)(-y,x+0.5,z+0.5)(y+0.5,-x,z+0.5)(-x,-y,-z)(x+0.5,y+0.5,-z)(y,-x+0.5,-z+0.5)(-y+0.5,x,-z+0.5)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)(-x,-y,-z)(x,y,-z)(y,-x,-z)(-y,x,-z)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x+0.5,-y,z+0.5)(-y+0.75,x+0.25,z+0.25)(y+0.75,-x+0.75,z+0.75)(-x,-y,-z)(x+0.5,y,-z+0.5)(y+0.25,-x+0.75,-z+0.75)(-y+0.25,x+0.25,-z+0.25)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)(-x,y,-z)(x,-y,-z)(y,x,-z)(-y,-x,-z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-y+0.5,x+0.5,z)(y+0.5,-x+0.5,z)(-x+0.5,y+0.5,-z)(x+0.5,-y+0.5,-z)(y,x,-z)(-y,-x,-z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z+0.5)(-y,x,z+0.25)(y,-x,z+0.75)(-x,y,-z)(x,-y,-z+0.5)(y,x,-z+0.75)(-y,-x,-z+0.25)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z+0.5)(-y+0.5,x+0.5,z+0.25)(y+0.5,-x+0.5,z+0.75)(-x+0.5,y+0.5,-z+0.25)(x+0.5,-y+0.5,-z+0.75)(y,x,-z)(-y,-x,-z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-y,x,z+0.5)(y,-x,z+0.5)(-x,y,-z)(x,-y,-z)(y,x,-z+0.5)(-y,-x,-z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-y+0.5,x+0.5,z+0.5)(y+0.5,-x+0.5,z+0.5)(-x+0.5,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z+0.5)(y,x,-z)(-y,-x,-z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z+0.5)(-y,x,z+0.75)(y,-x,z+0.25)(-x,y,-z)(x,-y,-z+0.5)(y,x,-z+0.25)(-y,-x,-z+0.75)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z+0.5)(-y+0.5,x+0.5,z+0.75)(y+0.5,-x+0.5,z+0.25)(-x+0.5,y+0.5,-z+0.75)(x+0.5,-y+0.5,-z+0.25)(y,x,-z)(-y,-x,-z+0.5)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)(-x,y,-z)(x,-y,-z)(y,x,-z)(-y,-x,-z)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x+0.5,-y+0.5,z+0.5)(-y,x+0.5,z+0.25)(y+0.5,-x,z+0.75)(-x+0.5,y,-z+0.75)(x,-y+0.5,-z+0.25)(y+0.5,x+0.5,-z+0.5)(-y,-x,-z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)(x,-y,z)(-x,y,z)(-y,-x,z)(y,x,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)(x+0.5,-y+0.5,z)(-x+0.5,y+0.5,z)(-y+0.5,-x+0.5,z)(y+0.5,x+0.5,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-y,x,z+0.5)(y,-x,z+0.5)(x,-y,z+0.5)(-x,y,z+0.5)(-y,-x,z)(y,x,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-y+0.5,x+0.5,z+0.5)(y+0.5,-x+0.5,z+0.5)(x+0.5,-y+0.5,z+0.5)(-x+0.5,y+0.5,z+0.5)(-y,-x,z)(y,x,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)(x,-y,z+0.5)(-x,y,z+0.5)(-y,-x,z+0.5)(y,x,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)(x+0.5,-y+0.5,z+0.5)(-x+0.5,y+0.5,z+0.5)(-y+0.5,-x+0.5,z+0.5)(y+0.5,x+0.5,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-y,x,z+0.5)(y,-x,z+0.5)(x,-y,z)(-x,y,z)(-y,-x,z+0.5)(y,x,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-y,x,z+0.5)(y,-x,z+0.5)(x+0.5,-y+0.5,z)(-x+0.5,y+0.5,z)(-y+0.5,-x+0.5,z+0.5)(y+0.5,x+0.5,z+0.5)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)(x,-y,z)(-x,y,z)(-y,-x,z)(y,x,z)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)(x,-y,z+0.5)(-x,y,z+0.5)(-y,-x,z+0.5)(y,x,z+0.5)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x+0.5,-y+0.5,z+0.5)(-y,x+0.5,z+0.25)(y+0.5,-x,z+0.75)(x,-y,z)(-x+0.5,y+0.5,z+0.5)(-y,-x+0.5,z+0.25)(y+0.5,x,z+0.75)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x+0.5,-y+0.5,z+0.5)(-y,x+0.5,z+0.25)(y+0.5,-x,z+0.75)(x,-y,z+0.5)(-x+0.5,y+0.5,z)(-y,-x+0.5,z+0.75)(y+0.5,x,z+0.25)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(y,-x,-z)(-y,x,-z)(-x,y,-z)(x,-y,-z)(-y,-x,z)(y,x,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(y,-x,-z)(-y,x,-z)(-x,y,-z+0.5)(x,-y,-z+0.5)(-y,-x,z+0.5)(y,x,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(y,-x,-z)(-y,x,-z)(-x+0.5,y+0.5,-z)(x+0.5,-y+0.5,-z)(-y+0.5,-x+0.5,z)(y+0.5,x+0.5,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(y,-x,-z)(-y,x,-z)(-x+0.5,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z+0.5)(-y+0.5,-x+0.5,z+0.5)(y+0.5,x+0.5,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(y,-x,-z)(-y,x,-z)(x,-y,z)(-x,y,z)(y,x,-z)(-y,-x,-z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(y,-x,-z)(-y,x,-z)(x,-y,z+0.5)(-x,y,z+0.5)(y,x,-z+0.5)(-y,-x,-z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(y,-x,-z)(-y,x,-z)(x+0.5,-y+0.5,z)(-x+0.5,y+0.5,z)(y+0.5,x+0.5,-z)(-y+0.5,-x+0.5,-z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(y,-x,-z)(-y,x,-z)(x+0.5,-y+0.5,z+0.5)(-x+0.5,y+0.5,z+0.5)(y+0.5,x+0.5,-z+0.5)(-y+0.5,-x+0.5,-z+0.5)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(y,-x,-z)(-y,x,-z)(x,-y,z)(-x,y,z)(y,x,-z)(-y,-x,-z)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(y,-x,-z)(-y,x,-z)(x,-y,z+0.5)(-x,y,z+0.5)(y,x,-z+0.5)(-y,-x,-z+0.5)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(y,-x,-z)(-y,x,-z)(-x,y,-z)(x,-y,-z)(-y,-x,z)(y,x,z)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(y,-x,-z)(-y,x,-z)(-x+0.5,y,-z+0.75)(x+0.5,-y,-z+0.75)(-y+0.5,-x,z+0.75)(y+0.5,x,z+0.75)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)(-x,y,-z)(x,-y,-z)(y,x,-z)(-y,-x,-z)(-x,-y,-z)(x,y,-z)(y,-x,-z)(-y,x,-z)(x,-y,z)(-x,y,z)(-y,-x,z)(y,x,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)(-x,y,-z+0.5)(x,-y,-z+0.5)(y,x,-z+0.5)(-y,-x,-z+0.5)(-x,-y,-z)(x,y,-z)(y,-x,-z)(-y,x,-z)(x,-y,z+0.5)(-x,y,z+0.5)(-y,-x,z+0.5)(y,x,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x+0.5,-y+0.5,z)(-y+0.5,x,z)(y,-x+0.5,z)(-x+0.5,y,-z)(x,-y+0.5,-z)(y,x,-z)(-y+0.5,-x+0.5,-z)(-x,-y,-z)(x+0.5,y+0.5,-z)(y+0.5,-x,-z)(-y,x+0.5,-z)(x+0.5,-y,z)(-x,y+0.5,z)(-y,-x,z)(y+0.5,x+0.5,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x+0.5,-y+0.5,z)(-y+0.5,x,z)(y,-x+0.5,z)(-x+0.5,y,-z+0.5)(x,-y+0.5,-z+0.5)(y,x,-z+0.5)(-y+0.5,-x+0.5,-z+0.5)(-x,-y,-z)(x+0.5,y+0.5,-z)(y+0.5,-x,-z)(-y,x+0.5,-z)(x+0.5,-y,z+0.5)(-x,y+0.5,z+0.5)(-y,-x,z+0.5)(y+0.5,x+0.5,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)(-x+0.5,y+0.5,-z)(x+0.5,-y+0.5,-z)(y+0.5,x+0.5,-z)(-y+0.5,-x+0.5,-z)(-x,-y,-z)(x,y,-z)(y,-x,-z)(-y,x,-z)(x+0.5,-y+0.5,z)(-x+0.5,y+0.5,z)(-y+0.5,-x+0.5,z)(y+0.5,x+0.5,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)(-x+0.5,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z+0.5)(y+0.5,x+0.5,-z+0.5)(-y+0.5,-x+0.5,-z+0.5)(-x,-y,-z)(x,y,-z)(y,-x,-z)(-y,x,-z)(x+0.5,-y+0.5,z+0.5)(-x+0.5,y+0.5,z+0.5)(-y+0.5,-x+0.5,z+0.5)(y+0.5,x+0.5,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x+0.5,-y+0.5,z)(-y+0.5,x,z)(y,-x+0.5,z)(-x,y+0.5,-z)(x+0.5,-y,-z)(y+0.5,x+0.5,-z)(-y,-x,-z)(-x,-y,-z)(x+0.5,y+0.5,-z)(y+0.5,-x,-z)(-y,x+0.5,-z)(x,-y+0.5,z)(-x+0.5,y,z)(-y+0.5,-x+0.5,z)(y,x,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x+0.5,-y+0.5,z)(-y+0.5,x,z)(y,-x+0.5,z)(-x,y+0.5,-z+0.5)(x+0.5,-y,-z+0.5)(y+0.5,x+0.5,-z+0.5)(-y,-x,-z+0.5)(-x,-y,-z)(x+0.5,y+0.5,-z)(y+0.5,-x,-z)(-y,x+0.5,-z)(x,-y+0.5,z+0.5)(-x+0.5,y,z+0.5)(-y+0.5,-x+0.5,z+0.5)(y,x,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-y,x,z+0.5)(y,-x,z+0.5)(-x,y,-z)(x,-y,-z)(y,x,-z+0.5)(-y,-x,-z+0.5)(-x,-y,-z)(x,y,-z)(y,-x,-z+0.5)(-y,x,-z+0.5)(x,-y,z)(-x,y,z)(-y,-x,z+0.5)(y,x,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-y,x,z+0.5)(y,-x,z+0.5)(-x,y,-z+0.5)(x,-y,-z+0.5)(y,x,-z)(-y,-x,-z)(-x,-y,-z)(x,y,-z)(y,-x,-z+0.5)(-y,x,-z+0.5)(x,-y,z+0.5)(-x,y,z+0.5)(-y,-x,z)(y,x,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x+0.5,-y+0.5,z)(-y+0.5,x,z+0.5)(y,-x+0.5,z+0.5)(-x+0.5,y,-z)(x,-y+0.5,-z)(y,x,-z+0.5)(-y+0.5,-x+0.5,-z+0.5)(-x,-y,-z)(x+0.5,y+0.5,-z)(y+0.5,-x,-z+0.5)(-y,x+0.5,-z+0.5)(x+0.5,-y,z)(-x,y+0.5,z)(-y,-x,z+0.5)(y+0.5,x+0.5,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x+0.5,-y+0.5,z)(-y+0.5,x,z+0.5)(y,-x+0.5,z+0.5)(-x+0.5,y,-z+0.5)(x,-y+0.5,-z+0.5)(y,x,-z)(-y+0.5,-x+0.5,-z)(-x,-y,-z)(x+0.5,y+0.5,-z)(y+0.5,-x,-z+0.5)(-y,x+0.5,-z+0.5)(x+0.5,-y,z+0.5)(-x,y+0.5,z+0.5)(-y,-x,z)(y+0.5,x+0.5,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-y,x,z+0.5)(y,-x,z+0.5)(-x+0.5,y+0.5,-z)(x+0.5,-y+0.5,-z)(y+0.5,x+0.5,-z+0.5)(-y+0.5,-x+0.5,-z+0.5)(-x,-y,-z)(x,y,-z)(y,-x,-z+0.5)(-y,x,-z+0.5)(x+0.5,-y+0.5,z)(-x+0.5,y+0.5,z)(-y+0.5,-x+0.5,z+0.5)(y+0.5,x+0.5,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-y+0.5,x+0.5,z+0.5)(y+0.5,-x+0.5,z+0.5)(-x+0.5,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z+0.5)(y,x,-z)(-y,-x,-z)(-x,-y,-z)(x,y,-z)(y+0.5,-x+0.5,-z+0.5)(-y+0.5,x+0.5,-z+0.5)(x+0.5,-y+0.5,z+0.5)(-x+0.5,y+0.5,z+0.5)(-y,-x,z)(y,x,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x+0.5,-y+0.5,z)(-y+0.5,x,z+0.5)(y,-x+0.5,z+0.5)(-x,y+0.5,-z)(x+0.5,-y,-z)(y+0.5,x+0.5,-z+0.5)(-y,-x,-z+0.5)(-x,-y,-z)(x+0.5,y+0.5,-z)(y+0.5,-x,-z+0.5)(-y,x+0.5,-z+0.5)(x,-y+0.5,z)(-x+0.5,y,z)(-y+0.5,-x+0.5,z+0.5)(y,x,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x+0.5,-y+0.5,z)(-y+0.5,x,z+0.5)(y,-x+0.5,z+0.5)(-x,y+0.5,-z+0.5)(x+0.5,-y,-z+0.5)(y+0.5,x+0.5,-z)(-y,-x,-z)(-x,-y,-z)(x+0.5,y+0.5,-z)(y+0.5,-x,-z+0.5)(-y,x+0.5,-z+0.5)(x,-y+0.5,z+0.5)(-x+0.5,y,z+0.5)(-y+0.5,-x+0.5,z)(y,x,z)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)(-x,y,-z)(x,-y,-z)(y,x,-z)(-y,-x,-z)(-x,-y,-z)(x,y,-z)(y,-x,-z)(-y,x,-z)(x,-y,z)(-x,y,z)(-y,-x,z)(y,x,z)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)(-x,y,-z+0.5)(x,-y,-z+0.5)(y,x,-z+0.5)(-y,-x,-z+0.5)(-x,-y,-z)(x,y,-z)(y,-x,-z)(-y,x,-z)(x,-y,z+0.5)(-x,y,z+0.5)(-y,-x,z+0.5)(y,x,z+0.5)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x+0.5,-y,z+0.5)(-y+0.25,x+0.75,z+0.25)(y+0.25,-x+0.25,z+0.75)(-x+0.5,y,-z+0.5)(x,-y,-z)(y+0.25,x+0.75,-z+0.25)(-y+0.25,-x+0.25,-z+0.75)(-x,-y,-z)(x+0.5,y,-z+0.5)(y+0.75,-x+0.25,-z+0.75)(-y+0.75,x+0.75,-z+0.25)(x+0.5,-y,z+0.5)(-x,y,z)(-y+0.75,-x+0.25,z+0.75)(y+0.75,x+0.75,z+0.25)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x+0.5,-y,z+0.5)(-y+0.25,x+0.75,z+0.25)(y+0.25,-x+0.25,z+0.75)(-x+0.5,y,-z)(x,-y,-z+0.5)(y+0.25,x+0.75,-z+0.75)(-y+0.25,-x+0.25,-z+0.25)(-x,-y,-z)(x+0.5,y,-z+0.5)(y+0.75,-x+0.25,-z+0.75)(-y+0.75,x+0.75,-z+0.25)(x+0.5,-y,z)(-x,y,z+0.5)(-y+0.75,-x+0.25,z+0.25)(y+0.75,x+0.75,z+0.75)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z)(-x+y,-x,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z+0.333333)(-x+y,-x,z+0.666667)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z+0.666667)(-x+y,-x,z+0.333333)")),
    fillCellInfo(std::make_pair("(0.666667,0.333333,0.333333)(0.333333,0.666667,0.666667)","(x,y,z)(-y,x-y,z)(-x+y,-x,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-x,-y,-z)(y,-x+y,-z)(x-y,x,-z)")),
    fillCellInfo(std::make_pair("(0.666667,0.333333,0.333333)(0.333333,0.666667,0.666667)","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-x,-y,-z)(y,-x+y,-z)(x-y,x,-z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-y,-x,-z)(-x+y,y,-z)(x,x-y,-z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(y,x,-z)(x-y,-y,-z)(-x,-x+y,-z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z+0.333333)(-x+y,-x,z+0.666667)(-y,-x,-z+0.666667)(-x+y,y,-z+0.333333)(x,x-y,-z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z+0.333333)(-x+y,-x,z+0.666667)(y,x,-z)(x-y,-y,-z+0.666667)(-x,-x+y,-z+0.333333)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z+0.666667)(-x+y,-x,z+0.333333)(-y,-x,-z+0.333333)(-x+y,y,-z+0.666667)(x,x-y,-z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z+0.666667)(-x+y,-x,z+0.333333)(y,x,-z)(x-y,-y,-z+0.333333)(-x,-x+y,-z+0.666667)")),
    fillCellInfo(std::make_pair("(0.666667,0.333333,0.333333)(0.333333,0.666667,0.666667)","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(y,x,-z)(x-y,-y,-z)(-x,-x+y,-z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-y,-x,z)(-x+y,y,z)(x,x-y,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(y,x,z)(x-y,-y,z)(-x,-x+y,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-y,-x,z+0.5)(-x+y,y,z+0.5)(x,x-y,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(y,x,z+0.5)(x-y,-y,z+0.5)(-x,-x+y,z+0.5)")),
    fillCellInfo(std::make_pair("(0.666667,0.333333,0.333333)(0.333333,0.666667,0.666667)","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-y,-x,z)(-x+y,y,z)(x,x-y,z)")),
    fillCellInfo(std::make_pair("(0.666667,0.333333,0.333333)(0.333333,0.666667,0.666667)","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-y,-x,z+0.5)(-x+y,y,z+0.5)(x,x-y,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-y,-x,-z)(-x+y,y,-z)(x,x-y,-z)(-x,-y,-z)(y,-x+y,-z)(x-y,x,-z)(y,x,z)(x-y,-y,z)(-x,-x+y,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-y,-x,-z+0.5)(-x+y,y,-z+0.5)(x,x-y,-z+0.5)(-x,-y,-z)(y,-x+y,-z)(x-y,x,-z)(y,x,z+0.5)(x-y,-y,z+0.5)(-x,-x+y,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(y,x,-z)(x-y,-y,-z)(-x,-x+y,-z)(-x,-y,-z)(y,-x+y,-z)(x-y,x,-z)(-y,-x,z)(-x+y,y,z)(x,x-y,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(y,x,-z+0.5)(x-y,-y,-z+0.5)(-x,-x+y,-z+0.5)(-x,-y,-z)(y,-x+y,-z)(x-y,x,-z)(-y,-x,z+0.5)(-x+y,y,z+0.5)(x,x-y,z+0.5)")),
    fillCellInfo(std::make_pair("(0.666667,0.333333,0.333333)(0.333333,0.666667,0.666667)","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(y,x,-z)(x-y,-y,-z)(-x,-x+y,-z)(-x,-y,-z)(y,-x+y,-z)(x-y,x,-z)(-y,-x,z)(-x+y,y,z)(x,x-y,z)")),
    fillCellInfo(std::make_pair("(0.666667,0.333333,0.333333)(0.333333,0.666667,0.666667)","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(y,x,-z+0.5)(x-y,-y,-z+0.5)(-x,-x+y,-z+0.5)(-x,-y,-z)(y,-x+y,-z)(x-y,x,-z)(-y,-x,z+0.5)(-x+y,y,z+0.5)(x,x-y,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-x,-y,z)(y,-x+y,z)(x-y,x,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z+0.333333)(-x+y,-x,z+0.666667)(-x,-y,z+0.5)(y,-x+y,z+0.833333)(x-y,x,z+0.166667)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z+0.666667)(-x+y,-x,z+0.333333)(-x,-y,z+0.5)(y,-x+y,z+0.166667)(x-y,x,z+0.833333)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z+0.666667)(-x+y,-x,z+0.333333)(-x,-y,z)(y,-x+y,z+0.666667)(x-y,x,z+0.333333)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z+0.333333)(-x+y,-x,z+0.666667)(-x,-y,z)(y,-x+y,z+0.333333)(x-y,x,z+0.666667)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-x,-y,z+0.5)(y,-x+y,z+0.5)(x-y,x,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(x,y,-z)(-y,x-y,-z)(-x+y,-x,-z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-x,-y,z)(y,-x+y,z)(x-y,x,z)(-x,-y,-z)(y,-x+y,-z)(x-y,x,-z)(x,y,-z)(-y,x-y,-z)(-x+y,-x,-z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-x,-y,z+0.5)(y,-x+y,z+0.5)(x-y,x,z+0.5)(-x,-y,-z)(y,-x+y,-z)(x-y,x,-z)(x,y,-z+0.5)(-y,x-y,-z+0.5)(-x+y,-x,-z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-x,-y,z)(y,-x+y,z)(x-y,x,z)(y,x,-z)(x-y,-y,-z)(-x,-x+y,-z)(-y,-x,-z)(-x+y,y,-z)(x,x-y,-z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z+0.333333)(-x+y,-x,z+0.666667)(-x,-y,z+0.5)(y,-x+y,z+0.833333)(x-y,x,z+0.166667)(y,x,-z+0.333333)(x-y,-y,-z)(-x,-x+y,-z+0.666667)(-y,-x,-z+0.833333)(-x+y,y,-z+0.5)(x,x-y,-z+0.166667)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z+0.666667)(-x+y,-x,z+0.333333)(-x,-y,z+0.5)(y,-x+y,z+0.166667)(x-y,x,z+0.833333)(y,x,-z+0.666667)(x-y,-y,-z)(-x,-x+y,-z+0.333333)(-y,-x,-z+0.166667)(-x+y,y,-z+0.5)(x,x-y,-z+0.833333)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z+0.666667)(-x+y,-x,z+0.333333)(-x,-y,z)(y,-x+y,z+0.666667)(x-y,x,z+0.333333)(y,x,-z+0.666667)(x-y,-y,-z)(-x,-x+y,-z+0.333333)(-y,-x,-z+0.666667)(-x+y,y,-z)(x,x-y,-z+0.333333)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z+0.333333)(-x+y,-x,z+0.666667)(-x,-y,z)(y,-x+y,z+0.333333)(x-y,x,z+0.666667)(y,x,-z+0.333333)(x-y,-y,-z)(-x,-x+y,-z+0.666667)(-y,-x,-z+0.333333)(-x+y,y,-z)(x,x-y,-z+0.666667)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-x,-y,z+0.5)(y,-x+y,z+0.5)(x-y,x,z+0.5)(y,x,-z)(x-y,-y,-z)(-x,-x+y,-z)(-y,-x,-z+0.5)(-x+y,y,-z+0.5)(x,x-y,-z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-x,-y,z)(y,-x+y,z)(x-y,x,z)(-y,-x,z)(-x+y,y,z)(x,x-y,z)(y,x,z)(x-y,-y,z)(-x,-x+y,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-x,-y,z)(y,-x+y,z)(x-y,x,z)(-y,-x,z+0.5)(-x+y,y,z+0.5)(x,x-y,z+0.5)(y,x,z+0.5)(x-y,-y,z+0.5)(-x,-x+y,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-x,-y,z+0.5)(y,-x+y,z+0.5)(x-y,x,z+0.5)(-y,-x,z+0.5)(-x+y,y,z+0.5)(x,x-y,z+0.5)(y,x,z)(x-y,-y,z)(-x,-x+y,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-x,-y,z+0.5)(y,-x+y,z+0.5)(x-y,x,z+0.5)(-y,-x,z)(-x+y,y,z)(x,x-y,z)(y,x,z+0.5)(x-y,-y,z+0.5)(-x,-x+y,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(x,y,-z)(-y,x-y,-z)(-x+y,-x,-z)(-y,-x,z)(-x+y,y,z)(x,x-y,z)(-y,-x,-z)(-x+y,y,-z)(x,x-y,-z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(x,y,-z+0.5)(-y,x-y,-z+0.5)(-x+y,-x,-z+0.5)(-y,-x,z+0.5)(-x+y,y,z+0.5)(x,x-y,z+0.5)(-y,-x,-z)(-x+y,y,-z)(x,x-y,-z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(x,y,-z)(-y,x-y,-z)(-x+y,-x,-z)(y,x,-z)(x-y,-y,-z)(-x,-x+y,-z)(y,x,z)(x-y,-y,z)(-x,-x+y,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(x,y,-z+0.5)(-y,x-y,-z+0.5)(-x+y,-x,-z+0.5)(y,x,-z)(x-y,-y,-z)(-x,-x+y,-z)(y,x,z+0.5)(x-y,-y,z+0.5)(-x,-x+y,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-x,-y,z)(y,-x+y,z)(x-y,x,z)(y,x,-z)(x-y,-y,-z)(-x,-x+y,-z)(-y,-x,-z)(-x+y,y,-z)(x,x-y,-z)(-x,-y,-z)(y,-x+y,-z)(x-y,x,-z)(x,y,-z)(-y,x-y,-z)(-x+y,-x,-z)(-y,-x,z)(-x+y,y,z)(x,x-y,z)(y,x,z)(x-y,-y,z)(-x,-x+y,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-x,-y,z)(y,-x+y,z)(x-y,x,z)(y,x,-z+0.5)(x-y,-y,-z+0.5)(-x,-x+y,-z+0.5)(-y,-x,-z+0.5)(-x+y,y,-z+0.5)(x,x-y,-z+0.5)(-x,-y,-z)(y,-x+y,-z)(x-y,x,-z)(x,y,-z)(-y,x-y,-z)(-x+y,-x,-z)(-y,-x,z+0.5)(-x+y,y,z+0.5)(x,x-y,z+0.5)(y,x,z+0.5)(x-y,-y,z+0.5)(-x,-x+y,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-x,-y,z+0.5)(y,-x+y,z+0.5)(x-y,x,z+0.5)(y,x,-z+0.5)(x-y,-y,-z+0.5)(-x,-x+y,-z+0.5)(-y,-x,-z)(-x+y,y,-z)(x,x-y,-z)(-x,-y,-z)(y,-x+y,-z)(x-y,x,-z)(x,y,-z+0.5)(-y,x-y,-z+0.5)(-x+y,-x,-z+0.5)(-y,-x,z+0.5)(-x+y,y,z+0.5)(x,x-y,z+0.5)(y,x,z)(x-y,-y,z)(-x,-x+y,z)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-x,-y,z+0.5)(y,-x+y,z+0.5)(x-y,x,z+0.5)(y,x,-z)(x-y,-y,-z)(-x,-x+y,-z)(-y,-x,-z+0.5)(-x+y,y,-z+0.5)(x,x-y,-z+0.5)(-x,-y,-z)(y,-x+y,-z)(x-y,x,-z)(x,y,-z+0.5)(-y,x-y,-z+0.5)(-x+y,-x,-z+0.5)(-y,-x,z)(-x+y,y,z)(x,x-y,z)(y,x,z+0.5)(x-y,-y,z+0.5)(-x,-x+y,z+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)")),
    fillCellInfo(std::make_pair("(0,0.5,0.5)(0.5,0,0.5)(0.5,0.5,0)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x+0.5,-y,z+0.5)(-x,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z)(z,x,y)(z+0.5,-x+0.5,-y)(-z+0.5,-x,y+0.5)(-z,x+0.5,-y+0.5)(y,z,x)(-y,z+0.5,-x+0.5)(y+0.5,-z+0.5,-x)(-y+0.5,-z,x+0.5)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x+0.5,-y,z+0.5)(-x,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z)(z,x,y)(z+0.5,-x+0.5,-y)(-z+0.5,-x,y+0.5)(-z,x+0.5,-y+0.5)(y,z,x)(-y,z+0.5,-x+0.5)(y+0.5,-z+0.5,-x)(-y+0.5,-z,x+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(-x,-y,-z)(x,y,-z)(x,-y,z)(-x,y,z)(-z,-x,-y)(-z,x,y)(z,x,-y)(z,-x,y)(-y,-z,-x)(y,-z,x)(-y,z,x)(y,z,-x)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x+0.5,-y+0.5,z)(-x+0.5,y,-z+0.5)(x,-y+0.5,-z+0.5)(z,x,y)(z,-x+0.5,-y+0.5)(-z+0.5,-x+0.5,y)(-z+0.5,x,-y+0.5)(y,z,x)(-y+0.5,z,-x+0.5)(y,-z+0.5,-x+0.5)(-y+0.5,-z+0.5,x)(-x,-y,-z)(x+0.5,y+0.5,-z)(x+0.5,-y,z+0.5)(-x,y+0.5,z+0.5)(-z,-x,-y)(-z,x+0.5,y+0.5)(z+0.5,x+0.5,-y)(z+0.5,-x,y+0.5)(-y,-z,-x)(y+0.5,-z,x+0.5)(-y,z+0.5,x+0.5)(y+0.5,z+0.5,-x)")),
    fillCellInfo(std::make_pair("(0,0.5,0.5)(0.5,0,0.5)(0.5,0.5,0)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(-x,-y,-z)(x,y,-z)(x,-y,z)(-x,y,z)(-z,-x,-y)(-z,x,y)(z,x,-y)(z,-x,y)(-y,-z,-x)(y,-z,x)(-y,z,x)(y,z,-x)")),
    fillCellInfo(std::make_pair("(0,0.5,0.5)(0.5,0,0.5)(0.5,0.5,0)","(x,y,z)(-x+0.75,-y+0.75,z)(-x+0.75,y,-z+0.75)(x,-y+0.75,-z+0.75)(z,x,y)(z,-x+0.75,-y+0.75)(-z+0.75,-x+0.75,y)(-z+0.75,x,-y+0.75)(y,z,x)(-y+0.75,z,-x+0.75)(y,-z+0.75,-x+0.75)(-y+0.75,-z+0.75,x)(-x,-y,-z)(x+0.25,y+0.25,-z)(x+0.25,-y,z+0.25)(-x,y+0.25,z+0.25)(-z,-x,-y)(-z,x+0.25,y+0.25)(z+0.25,x+0.25,-y)(z+0.25,-x,y+0.25)(-y,-z,-x)(y+0.25,-z,x+0.25)(-y,z+0.25,x+0.25)(y+0.25,z+0.25,-x)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(-x,-y,-z)(x,y,-z)(x,-y,z)(-x,y,z)(-z,-x,-y)(-z,x,y)(z,x,-y)(z,-x,y)(-y,-z,-x)(y,-z,x)(-y,z,x)(y,z,-x)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x+0.5,-y,z+0.5)(-x,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z)(z,x,y)(z+0.5,-x+0.5,-y)(-z+0.5,-x,y+0.5)(-z,x+0.5,-y+0.5)(y,z,x)(-y,z+0.5,-x+0.5)(y+0.5,-z+0.5,-x)(-y+0.5,-z,x+0.5)(-x,-y,-z)(x+0.5,y,-z+0.5)(x,-y+0.5,z+0.5)(-x+0.5,y+0.5,z)(-z,-x,-y)(-z+0.5,x+0.5,y)(z+0.5,x,-y+0.5)(z,-x+0.5,y+0.5)(-y,-z,-x)(y,-z+0.5,x+0.5)(-y+0.5,z+0.5,x)(y+0.5,z,-x+0.5)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x+0.5,-y,z+0.5)(-x,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z)(z,x,y)(z+0.5,-x+0.5,-y)(-z+0.5,-x,y+0.5)(-z,x+0.5,-y+0.5)(y,z,x)(-y,z+0.5,-x+0.5)(y+0.5,-z+0.5,-x)(-y+0.5,-z,x+0.5)(-x,-y,-z)(x+0.5,y,-z+0.5)(x,-y+0.5,z+0.5)(-x+0.5,y+0.5,z)(-z,-x,-y)(-z+0.5,x+0.5,y)(z+0.5,x,-y+0.5)(z,-x+0.5,y+0.5)(-y,-z,-x)(y,-z+0.5,x+0.5)(-y+0.5,z+0.5,x)(y+0.5,z,-x+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(y,x,-z)(-y,-x,-z)(y,-x,z)(-y,x,z)(x,z,-y)(-x,z,y)(-x,-z,-y)(x,-z,y)(z,y,-x)(z,-y,x)(-z,y,x)(-z,-y,-x)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(y+0.5,x+0.5,-z+0.5)(-y+0.5,-x+0.5,-z+0.5)(y+0.5,-x+0.5,z+0.5)(-y+0.5,x+0.5,z+0.5)(x+0.5,z+0.5,-y+0.5)(-x+0.5,z+0.5,y+0.5)(-x+0.5,-z+0.5,-y+0.5)(x+0.5,-z+0.5,y+0.5)(z+0.5,y+0.5,-x+0.5)(z+0.5,-y+0.5,x+0.5)(-z+0.5,y+0.5,x+0.5)(-z+0.5,-y+0.5,-x+0.5)")),
    fillCellInfo(std::make_pair("(0,0.5,0.5)(0.5,0,0.5)(0.5,0.5,0)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(y,x,-z)(-y,-x,-z)(y,-x,z)(-y,x,z)(x,z,-y)(-x,z,y)(-x,-z,-y)(x,-z,y)(z,y,-x)(z,-y,x)(-z,y,x)(-z,-y,-x)")),
    fillCellInfo(std::make_pair("(0,0.5,0.5)(0.5,0,0.5)(0.5,0.5,0)","(x,y,z)(-x,-y+0.5,z+0.5)(-x+0.5,y+0.5,-z)(x+0.5,-y,-z+0.5)(z,x,y)(z+0.5,-x,-y+0.5)(-z,-x+0.5,y+0.5)(-z+0.5,x+0.5,-y)(y,z,x)(-y+0.5,z+0.5,-x)(y+0.5,-z,-x+0.5)(-y,-z+0.5,x+0.5)(y+0.75,x+0.25,-z+0.75)(-y+0.25,-x+0.25,-z+0.25)(y+0.25,-x+0.75,z+0.75)(-y+0.75,x+0.75,z+0.25)(x+0.75,z+0.25,-y+0.75)(-x+0.75,z+0.75,y+0.25)(-x+0.25,-z+0.25,-y+0.25)(x+0.25,-z+0.75,y+0.75)(z+0.75,y+0.25,-x+0.75)(z+0.25,-y+0.75,x+0.75)(-z+0.75,y+0.75,x+0.25)(-z+0.25,-y+0.25,-x+0.25)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(y,x,-z)(-y,-x,-z)(y,-x,z)(-y,x,z)(x,z,-y)(-x,z,y)(-x,-z,-y)(x,-z,y)(z,y,-x)(z,-y,x)(-z,y,x)(-z,-y,-x)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x+0.5,-y,z+0.5)(-x,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z)(z,x,y)(z+0.5,-x+0.5,-y)(-z+0.5,-x,y+0.5)(-z,x+0.5,-y+0.5)(y,z,x)(-y,z+0.5,-x+0.5)(y+0.5,-z+0.5,-x)(-y+0.5,-z,x+0.5)(y+0.25,x+0.75,-z+0.75)(-y+0.25,-x+0.25,-z+0.25)(y+0.75,-x+0.75,z+0.25)(-y+0.75,x+0.25,z+0.75)(x+0.25,z+0.75,-y+0.75)(-x+0.75,z+0.25,y+0.75)(-x+0.25,-z+0.25,-y+0.25)(x+0.75,-z+0.75,y+0.25)(z+0.25,y+0.75,-x+0.75)(z+0.75,-y+0.75,x+0.25)(-z+0.75,y+0.25,x+0.75)(-z+0.25,-y+0.25,-x+0.25)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x+0.5,-y,z+0.5)(-x,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z)(z,x,y)(z+0.5,-x+0.5,-y)(-z+0.5,-x,y+0.5)(-z,x+0.5,-y+0.5)(y,z,x)(-y,z+0.5,-x+0.5)(y+0.5,-z+0.5,-x)(-y+0.5,-z,x+0.5)(y+0.75,x+0.25,-z+0.25)(-y+0.75,-x+0.75,-z+0.75)(y+0.25,-x+0.25,z+0.75)(-y+0.25,x+0.75,z+0.25)(x+0.75,z+0.25,-y+0.25)(-x+0.25,z+0.75,y+0.25)(-x+0.75,-z+0.75,-y+0.75)(x+0.25,-z+0.25,y+0.75)(z+0.75,y+0.25,-x+0.25)(z+0.25,-y+0.25,x+0.75)(-z+0.25,y+0.75,x+0.25)(-z+0.75,-y+0.75,-x+0.75)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x+0.5,-y,z+0.5)(-x,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z)(z,x,y)(z+0.5,-x+0.5,-y)(-z+0.5,-x,y+0.5)(-z,x+0.5,-y+0.5)(y,z,x)(-y,z+0.5,-x+0.5)(y+0.5,-z+0.5,-x)(-y+0.5,-z,x+0.5)(y+0.75,x+0.25,-z+0.25)(-y+0.75,-x+0.75,-z+0.75)(y+0.25,-x+0.25,z+0.75)(-y+0.25,x+0.75,z+0.25)(x+0.75,z+0.25,-y+0.25)(-x+0.25,z+0.75,y+0.25)(-x+0.75,-z+0.75,-y+0.75)(x+0.25,-z+0.25,y+0.75)(z+0.75,y+0.25,-x+0.25)(z+0.25,-y+0.25,x+0.75)(-z+0.25,y+0.75,x+0.25)(-z+0.75,-y+0.75,-x+0.75)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(y,x,z)(-y,-x,z)(y,-x,-z)(-y,x,-z)(x,z,y)(-x,z,-y)(-x,-z,y)(x,-z,-y)(z,y,x)(z,-y,-x)(-z,y,-x)(-z,-y,x)")),
    fillCellInfo(std::make_pair("(0,0.5,0.5)(0.5,0,0.5)(0.5,0.5,0)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(y,x,z)(-y,-x,z)(y,-x,-z)(-y,x,-z)(x,z,y)(-x,z,-y)(-x,-z,y)(x,-z,-y)(z,y,x)(z,-y,-x)(-z,y,-x)(-z,-y,x)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(y,x,z)(-y,-x,z)(y,-x,-z)(-y,x,-z)(x,z,y)(-x,z,-y)(-x,-z,y)(x,-z,-y)(z,y,x)(z,-y,-x)(-z,y,-x)(-z,-y,x)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(y+0.5,x+0.5,z+0.5)(-y+0.5,-x+0.5,z+0.5)(y+0.5,-x+0.5,-z+0.5)(-y+0.5,x+0.5,-z+0.5)(x+0.5,z+0.5,y+0.5)(-x+0.5,z+0.5,-y+0.5)(-x+0.5,-z+0.5,y+0.5)(x+0.5,-z+0.5,-y+0.5)(z+0.5,y+0.5,x+0.5)(z+0.5,-y+0.5,-x+0.5)(-z+0.5,y+0.5,-x+0.5)(-z+0.5,-y+0.5,x+0.5)")),
    fillCellInfo(std::make_pair("(0,0.5,0.5)(0.5,0,0.5)(0.5,0.5,0)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(y+0.5,x+0.5,z+0.5)(-y+0.5,-x+0.5,z+0.5)(y+0.5,-x+0.5,-z+0.5)(-y+0.5,x+0.5,-z+0.5)(x+0.5,z+0.5,y+0.5)(-x+0.5,z+0.5,-y+0.5)(-x+0.5,-z+0.5,y+0.5)(x+0.5,-z+0.5,-y+0.5)(z+0.5,y+0.5,x+0.5)(z+0.5,-y+0.5,-x+0.5)(-z+0.5,y+0.5,-x+0.5)(-z+0.5,-y+0.5,x+0.5)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x+0.5,-y,z+0.5)(-x,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z)(z,x,y)(z+0.5,-x+0.5,-y)(-z+0.5,-x,y+0.5)(-z,x+0.5,-y+0.5)(y,z,x)(-y,z+0.5,-x+0.5)(y+0.5,-z+0.5,-x)(-y+0.5,-z,x+0.5)(y+0.25,x+0.25,z+0.25)(-y+0.25,-x+0.75,z+0.75)(y+0.75,-x+0.25,-z+0.75)(-y+0.75,x+0.75,-z+0.25)(x+0.25,z+0.25,y+0.25)(-x+0.75,z+0.75,-y+0.25)(-x+0.25,-z+0.75,y+0.75)(x+0.75,-z+0.25,-y+0.75)(z+0.25,y+0.25,x+0.25)(z+0.75,-y+0.25,-x+0.75)(-z+0.75,y+0.75,-x+0.25)(-z+0.25,-y+0.75,x+0.75)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(y,x,-z)(-y,-x,-z)(y,-x,z)(-y,x,z)(x,z,-y)(-x,z,y)(-x,-z,-y)(x,-z,y)(z,y,-x)(z,-y,x)(-z,y,x)(-z,-y,-x)(-x,-y,-z)(x,y,-z)(x,-y,z)(-x,y,z)(-z,-x,-y)(-z,x,y)(z,x,-y)(z,-x,y)(-y,-z,-x)(y,-z,x)(-y,z,x)(y,z,-x)(-y,-x,z)(y,x,z)(-y,x,-z)(y,-x,-z)(-x,-z,y)(x,-z,-y)(x,z,y)(-x,z,-y)(-z,-y,x)(-z,y,-x)(z,-y,-x)(z,y,x)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x+0.5,-y+0.5,z)(-x+0.5,y,-z+0.5)(x,-y+0.5,-z+0.5)(z,x,y)(z,-x+0.5,-y+0.5)(-z+0.5,-x+0.5,y)(-z+0.5,x,-y+0.5)(y,z,x)(-y+0.5,z,-x+0.5)(y,-z+0.5,-x+0.5)(-y+0.5,-z+0.5,x)(y,x,-z+0.5)(-y+0.5,-x+0.5,-z+0.5)(y,-x+0.5,z)(-y+0.5,x,z)(x,z,-y+0.5)(-x+0.5,z,y)(-x+0.5,-z+0.5,-y+0.5)(x,-z+0.5,y)(z,y,-x+0.5)(z,-y+0.5,x)(-z+0.5,y,x)(-z+0.5,-y+0.5,-x+0.5)(-x,-y,-z)(x+0.5,y+0.5,-z)(x+0.5,-y,z+0.5)(-x,y+0.5,z+0.5)(-z,-x,-y)(-z,x+0.5,y+0.5)(z+0.5,x+0.5,-y)(z+0.5,-x,y+0.5)(-y,-z,-x)(y+0.5,-z,x+0.5)(-y,z+0.5,x+0.5)(y+0.5,z+0.5,-x)(-y,-x,z+0.5)(y+0.5,x+0.5,z+0.5)(-y,x+0.5,-z)(y+0.5,-x,-z)(-x,-z,y+0.5)(x+0.5,-z,-y)(x+0.5,z+0.5,y+0.5)(-x,z+0.5,-y)(-z,-y,x+0.5)(-z,y+0.5,-x)(z+0.5,-y,-x)(z+0.5,y+0.5,x+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(y+0.5,x+0.5,-z+0.5)(-y+0.5,-x+0.5,-z+0.5)(y+0.5,-x+0.5,z+0.5)(-y+0.5,x+0.5,z+0.5)(x+0.5,z+0.5,-y+0.5)(-x+0.5,z+0.5,y+0.5)(-x+0.5,-z+0.5,-y+0.5)(x+0.5,-z+0.5,y+0.5)(z+0.5,y+0.5,-x+0.5)(z+0.5,-y+0.5,x+0.5)(-z+0.5,y+0.5,x+0.5)(-z+0.5,-y+0.5,-x+0.5)(-x,-y,-z)(x,y,-z)(x,-y,z)(-x,y,z)(-z,-x,-y)(-z,x,y)(z,x,-y)(z,-x,y)(-y,-z,-x)(y,-z,x)(-y,z,x)(y,z,-x)(-y+0.5,-x+0.5,z+0.5)(y+0.5,x+0.5,z+0.5)(-y+0.5,x+0.5,-z+0.5)(y+0.5,-x+0.5,-z+0.5)(-x+0.5,-z+0.5,y+0.5)(x+0.5,-z+0.5,-y+0.5)(x+0.5,z+0.5,y+0.5)(-x+0.5,z+0.5,-y+0.5)(-z+0.5,-y+0.5,x+0.5)(-z+0.5,y+0.5,-x+0.5)(z+0.5,-y+0.5,-x+0.5)(z+0.5,y+0.5,x+0.5)")),
    fillCellInfo(std::make_pair("","(x,y,z)(-x+0.5,-y+0.5,z)(-x+0.5,y,-z+0.5)(x,-y+0.5,-z+0.5)(z,x,y)(z,-x+0.5,-y+0.5)(-z+0.5,-x+0.5,y)(-z+0.5,x,-y+0.5)(y,z,x)(-y+0.5,z,-x+0.5)(y,-z+0.5,-x+0.5)(-y+0.5,-z+0.5,x)(y+0.5,x+0.5,-z)(-y,-x,-z)(y+0.5,-x,z+0.5)(-y,x+0.5,z+0.5)(x+0.5,z+0.5,-y)(-x,z+0.5,y+0.5)(-x,-z,-y)(x+0.5,-z,y+0.5)(z+0.5,y+0.5,-x)(z+0.5,-y,x+0.5)(-z,y+0.5,x+0.5)(-z,-y,-x)(-x,-y,-z)(x+0.5,y+0.5,-z)(x+0.5,-y,z+0.5)(-x,y+0.5,z+0.5)(-z,-x,-y)(-z,x+0.5,y+0.5)(z+0.5,x+0.5,-y)(z+0.5,-x,y+0.5)(-y,-z,-x)(y+0.5,-z,x+0.5)(-y,z+0.5,x+0.5)(y+0.5,z+0.5,-x)(-y+0.5,-x+0.5,z)(y,x,z)(-y+0.5,x,-z+0.5)(y,-x+0.5,-z+0.5)(-x+0.5,-z+0.5,y)(x,-z+0.5,-y+0.5)(x,z,y)(-x+0.5,z,-y+0.5)(-z+0.5,-y+0.5,x)(-z+0.5,y,-x+0.5)(z,-y+0.5,-x+0.5)(z,y,x)")),
    fillCellInfo(std::make_pair("(0,0.5,0.5)(0.5,0,0.5)(0.5,0.5,0)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(y,x,-z)(-y,-x,-z)(y,-x,z)(-y,x,z)(x,z,-y)(-x,z,y)(-x,-z,-y)(x,-z,y)(z,y,-x)(z,-y,x)(-z,y,x)(-z,-y,-x)(-x,-y,-z)(x,y,-z)(x,-y,z)(-x,y,z)(-z,-x,-y)(-z,x,y)(z,x,-y)(z,-x,y)(-y,-z,-x)(y,-z,x)(-y,z,x)(y,z,-x)(-y,-x,z)(y,x,z)(-y,x,-z)(y,-x,-z)(-x,-z,y)(x,-z,-y)(x,z,y)(-x,z,-y)(-z,-y,x)(-z,y,-x)(z,-y,-x)(z,y,x)")),
    fillCellInfo(std::make_pair("(0,0.5,0.5)(0.5,0,0.5)(0.5,0.5,0)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(y+0.5,x+0.5,-z+0.5)(-y+0.5,-x+0.5,-z+0.5)(y+0.5,-x+0.5,z+0.5)(-y+0.5,x+0.5,z+0.5)(x+0.5,z+0.5,-y+0.5)(-x+0.5,z+0.5,y+0.5)(-x+0.5,-z+0.5,-y+0.5)(x+0.5,-z+0.5,y+0.5)(z+0.5,y+0.5,-x+0.5)(z+0.5,-y+0.5,x+0.5)(-z+0.5,y+0.5,x+0.5)(-z+0.5,-y+0.5,-x+0.5)(-x,-y,-z)(x,y,-z)(x,-y,z)(-x,y,z)(-z,-x,-y)(-z,x,y)(z,x,-y)(z,-x,y)(-y,-z,-x)(y,-z,x)(-y,z,x)(y,z,-x)(-y+0.5,-x+0.5,z+0.5)(y+0.5,x+0.5,z+0.5)(-y+0.5,x+0.5,-z+0.5)(y+0.5,-x+0.5,-z+0.5)(-x+0.5,-z+0.5,y+0.5)(x+0.5,-z+0.5,-y+0.5)(x+0.5,z+0.5,y+0.5)(-x+0.5,z+0.5,-y+0.5)(-z+0.5,-y+0.5,x+0.5)(-z+0.5,y+0.5,-x+0.5)(z+0.5,-y+0.5,-x+0.5)(z+0.5,y+0.5,x+0.5)")),
    fillCellInfo(std::make_pair("(0,0.5,0.5)(0.5,0,0.5)(0.5,0.5,0)","(x,y,z)(-x+0.75,-y+0.25,z+0.5)(-x+0.25,y+0.5,-z+0.75)(x+0.5,-y+0.75,-z+0.25)(z,x,y)(z+0.5,-x+0.75,-y+0.25)(-z+0.75,-x+0.25,y+0.5)(-z+0.25,x+0.5,-y+0.75)(y,z,x)(-y+0.25,z+0.5,-x+0.75)(y+0.5,-z+0.75,-x+0.25)(-y+0.75,-z+0.25,x+0.5)(y+0.75,x+0.25,-z+0.5)(-y,-x,-z)(y+0.25,-x+0.5,z+0.75)(-y+0.5,x+0.75,z+0.25)(x+0.75,z+0.25,-y+0.5)(-x+0.5,z+0.75,y+0.25)(-x,-z,-y)(x+0.25,-z+0.5,y+0.75)(z+0.75,y+0.25,-x+0.5)(z+0.25,-y+0.5,x+0.75)(-z+0.5,y+0.75,x+0.25)(-z,-y,-x)(-x,-y,-z)(x+0.25,y+0.75,-z+0.5)(x+0.75,-y+0.5,z+0.25)(-x+0.5,y+0.25,z+0.75)(-z,-x,-y)(-z+0.5,x+0.25,y+0.75)(z+0.25,x+0.75,-y+0.5)(z+0.75,-x+0.5,y+0.25)(-y,-z,-x)(y+0.75,-z+0.5,x+0.25)(-y+0.5,z+0.25,x+0.75)(y+0.25,z+0.75,-x+0.5)(-y+0.25,-x+0.75,z+0.5)(y,x,z)(-y+0.75,x+0.5,-z+0.25)(y+0.5,-x+0.25,-z+0.75)(-x+0.25,-z+0.75,y+0.5)(x+0.5,-z+0.25,-y+0.75)(x,z,y)(-x+0.75,z+0.5,-y+0.25)(-z+0.25,-y+0.75,x+0.5)(-z+0.75,y+0.5,-x+0.25)(z+0.5,-y+0.25,-x+0.75)(z,y,x)")),
    fillCellInfo(std::make_pair("(0,0.5,0.5)(0.5,0,0.5)(0.5,0.5,0)","(x,y,z)(-x+0.25,-y+0.75,z+0.5)(-x+0.75,y+0.5,-z+0.25)(x+0.5,-y+0.25,-z+0.75)(z,x,y)(z+0.5,-x+0.25,-y+0.75)(-z+0.25,-x+0.75,y+0.5)(-z+0.75,x+0.5,-y+0.25)(y,z,x)(-y+0.75,z+0.5,-x+0.25)(y+0.5,-z+0.25,-x+0.75)(-y+0.25,-z+0.75,x+0.5)(y+0.75,x+0.25,-z)(-y+0.5,-x+0.5,-z+0.5)(y+0.25,-x,z+0.75)(-y,x+0.75,z+0.25)(x+0.75,z+0.25,-y)(-x,z+0.75,y+0.25)(-x+0.5,-z+0.5,-y+0.5)(x+0.25,-z,y+0.75)(z+0.75,y+0.25,-x)(z+0.25,-y,x+0.75)(-z,y+0.75,x+0.25)(-z+0.5,-y+0.5,-x+0.5)(-x,-y,-z)(x+0.75,y+0.25,-z+0.5)(x+0.25,-y+0.5,z+0.75)(-x+0.5,y+0.75,z+0.25)(-z,-x,-y)(-z+0.5,x+0.75,y+0.25)(z+0.75,x+0.25,-y+0.5)(z+0.25,-x+0.5,y+0.75)(-y,-z,-x)(y+0.25,-z+0.5,x+0.75)(-y+0.5,z+0.75,x+0.25)(y+0.75,z+0.25,-x+0.5)(-y+0.25,-x+0.75,z)(y+0.5,x+0.5,z+0.5)(-y+0.75,x,-z+0.25)(y,-x+0.25,-z+0.75)(-x+0.25,-z+0.75,y)(x,-z+0.25,-y+0.75)(x+0.5,z+0.5,y+0.5)(-x+0.75,z,-y+0.25)(-z+0.25,-y+0.75,x)(-z+0.75,y,-x+0.25)(z,-y+0.25,-x+0.75)(z+0.5,y+0.5,x+0.5)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(y,x,-z)(-y,-x,-z)(y,-x,z)(-y,x,z)(x,z,-y)(-x,z,y)(-x,-z,-y)(x,-z,y)(z,y,-x)(z,-y,x)(-z,y,x)(-z,-y,-x)(-x,-y,-z)(x,y,-z)(x,-y,z)(-x,y,z)(-z,-x,-y)(-z,x,y)(z,x,-y)(z,-x,y)(-y,-z,-x)(y,-z,x)(-y,z,x)(y,z,-x)(-y,-x,z)(y,x,z)(-y,x,-z)(y,-x,-z)(-x,-z,y)(x,-z,-y)(x,z,y)(-x,z,-y)(-z,-y,x)(-z,y,-x)(z,-y,-x)(z,y,x)")),
    fillCellInfo(std::make_pair("(0.5,0.5,0.5)","(x,y,z)(-x+0.5,-y,z+0.5)(-x,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z)(z,x,y)(z+0.5,-x+0.5,-y)(-z+0.5,-x,y+0.5)(-z,x+0.5,-y+0.5)(y,z,x)(-y,z+0.5,-x+0.5)(y+0.5,-z+0.5,-x)(-y+0.5,-z,x+0.5)(y+0.75,x+0.25,-z+0.25)(-y+0.75,-x+0.75,-z+0.75)(y+0.25,-x+0.25,z+0.75)(-y+0.25,x+0.75,z+0.25)(x+0.75,z+0.25,-y+0.25)(-x+0.25,z+0.75,y+0.25)(-x+0.75,-z+0.75,-y+0.75)(x+0.25,-z+0.25,y+0.75)(z+0.75,y+0.25,-x+0.25)(z+0.25,-y+0.25,x+0.75)(-z+0.25,y+0.75,x+0.25)(-z+0.75,-y+0.75,-x+0.75)(-x,-y,-z)(x+0.5,y,-z+0.5)(x,-y+0.5,z+0.5)(-x+0.5,y+0.5,z)(-z,-x,-y)(-z+0.5,x+0.5,y)(z+0.5,x,-y+0.5)(z,-x+0.5,y+0.5)(-y,-z,-x)(y,-z+0.5,x+0.5)(-y+0.5,z+0.5,x)(y+0.5,z,-x+0.5)(-y+0.25,-x+0.75,z+0.75)(y+0.25,x+0.25,z+0.25)(-y+0.75,x+0.75,-z+0.25)(y+0.75,-x+0.25,-z+0.75)(-x+0.25,-z+0.75,y+0.75)(x+0.75,-z+0.25,-y+0.75)(x+0.25,z+0.25,y+0.25)(-x+0.75,z+0.75,-y+0.25)(-z+0.25,-y+0.75,x+0.75)(-z+0.75,y+0.75,-x+0.25)(z+0.75,-y+0.25,-x+0.75)(z+0.25,y+0.25,x+0.25)"))
};
std::vector<fillCellInfo> fillCellVector(_fillCellVector.begin(), _fillCellVector.end());
#else
// This is the standard way
std::vector<fillCellInfo> fillCellVector =
{
  { // 0 - not a real spacegroup
    "",""
  },

  { // 1
    "","(x,y,z)"
  },

  { // 2
    "","(x,y,z)(-x,-y,-z)"
  },

  { // 3
    "","(x,y,z)(-x,y,-z)"
  },

  { // 4
    "","(x,y,z)(-x,y+0.5,-z)"
  },

  { // 5
    "(0.5,0.5,0)","(x,y,z)(-x,y,-z)"
  },

  { // 6
    "","(x,y,z)(x,-y,z)"
  },

  { // 7
    "","(x,y,z)(x,-y,z+0.5)"
  },

  { // 8
    "(0.5,0.5,0)","(x,y,z)(x,-y,z)"
  },

  { // 9
    "(0.5,0.5,0)","(x,y,z)(x,-y,z+0.5)"
  },

  { // 10
    "","(x,y,z)(-x,y,-z)(-x,-y,-z)(x,-y,z)"
  },

  { // 11
    "","(x,y,z)(-x,y+0.5,-z)(-x,-y,-z)(x,-y+0.5,z)"
  },

  { // 12
    "(0.5,0.5,0)","(x,y,z)(-x,y,-z)(-x,-y,-z)(x,-y,z)"
  },

  { // 13
    "","(x,y,z)(-x,y,-z+0.5)(-x,-y,-z)(x,-y,z+0.5)"
  },

  { // 14
    "","(x,y,z)(-x,y+0.5,-z+0.5)(-x,-y,-z)(x,-y+0.5,z+0.5)"
  },

  { // 15
    "(0.5,0.5,0)","(x,y,z)(-x,y,-z+0.5)(-x,-y,-z)(x,-y,z+0.5)"
  },

  { // 16
    "","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)"
  },

  { // 17
    "","(x,y,z)(-x,-y,z+0.5)(-x,y,-z+0.5)(x,-y,-z)"
  },

  { // 18
    "","(x,y,z)(-x,-y,z)(-x+0.5,y+0.5,-z)(x+0.5,-y+0.5,-z)"
  },

  { // 19
    "","(x,y,z)(-x+0.5,-y,z+0.5)(-x,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z)"
  },

  { // 20
    "(0.5,0.5,0)","(x,y,z)(-x,-y,z+0.5)(-x,y,-z+0.5)(x,-y,-z)"
  },

  { // 21
    "(0.5,0.5,0)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)"
  },

  { // 22
    "(0,0.5,0.5)(0.5,0,0.5)(0.5,0.5,0)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)"
  },

  { // 23
    "(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)"
  },

  { // 24
    "(0.5,0.5,0.5)","(x,y,z)(-x+0.5,-y,z+0.5)(-x,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z)"
  },

  { // 25
    "","(x,y,z)(-x,-y,z)(x,-y,z)(-x,y,z)"
  },

  { // 26
    "","(x,y,z)(-x,-y,z+0.5)(x,-y,z+0.5)(-x,y,z)"
  },

  { // 27
    "","(x,y,z)(-x,-y,z)(x,-y,z+0.5)(-x,y,z+0.5)"
  },

  { // 28
    "","(x,y,z)(-x,-y,z)(x+0.5,-y,z)(-x+0.5,y,z)"
  },

  { // 29
    "","(x,y,z)(-x,-y,z+0.5)(x+0.5,-y,z)(-x+0.5,y,z+0.5)"
  },

  { // 30
    "","(x,y,z)(-x,-y,z)(x,-y+0.5,z+0.5)(-x,y+0.5,z+0.5)"
  },

  { // 31
    "","(x,y,z)(-x+0.5,-y,z+0.5)(x+0.5,-y,z+0.5)(-x,y,z)"
  },

  { // 32
    "","(x,y,z)(-x,-y,z)(x+0.5,-y+0.5,z)(-x+0.5,y+0.5,z)"
  },

  { // 33
    "","(x,y,z)(-x,-y,z+0.5)(x+0.5,-y+0.5,z)(-x+0.5,y+0.5,z+0.5)"
  },

  { // 34
    "","(x,y,z)(-x,-y,z)(x+0.5,-y+0.5,z+0.5)(-x+0.5,y+0.5,z+0.5)"
  },

  { // 35
    "(0.5,0.5,0)","(x,y,z)(-x,-y,z)(x,-y,z)(-x,y,z)"
  },

  { // 36
    "(0.5,0.5,0)","(x,y,z)(-x,-y,z+0.5)(x,-y,z+0.5)(-x,y,z)"
  },

  { // 37
    "(0.5,0.5,0)","(x,y,z)(-x,-y,z)(x,-y,z+0.5)(-x,y,z+0.5)"
  },

  { // 38
    "(0,0.5,0.5)","(x,y,z)(-x,-y,z)(x,-y,z)(-x,y,z)"
  },

  { // 39
    "(0,0.5,0.5)","(x,y,z)(-x,-y,z)(x,-y+0.5,z)(-x,y+0.5,z)"
  },

  { // 40
    "(0,0.5,0.5)","(x,y,z)(-x,-y,z)(x+0.5,-y,z)(-x+0.5,y,z)"
  },

  { // 41
    "(0,0.5,0.5)","(x,y,z)(-x,-y,z)(x+0.5,-y+0.5,z)(-x+0.5,y+0.5,z)"
  },

  { // 42
    "(0,0.5,0.5)(0.5,0,0.5)(0.5,0.5,0)","(x,y,z)(-x,-y,z)(x,-y,z)(-x,y,z)"
  },

  { // 43
    "(0.5,0,0.5)(0,0.5,0.5)(0.5,0.5,0)","(x,y,z)(-x,-y,z)(x+0.25,-y+0.25,z+0.25)(-x+0.25,y+0.25,z+0.25)"
  },

  { // 44
    "(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(x,-y,z)(-x,y,z)"
  },

  { // 45
    "(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(x+0.5,-y+0.5,z)(-x+0.5,y+0.5,z)"
  },

  { // 46
    "(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(x+0.5,-y,z)(-x+0.5,y,z)"
  },

  { // 47
    "","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(-x,-y,-z)(x,y,-z)(x,-y,z)(-x,y,z)"
  },

  { // 48
    "","(x,y,z)(-x+0.5,-y+0.5,z)(-x+0.5,y,-z+0.5)(x,-y+0.5,-z+0.5)(-x,-y,-z)(x+0.5,y+0.5,-z)(x+0.5,-y,z+0.5)(-x,y+0.5,z+0.5)"
  },

  { // 49
    "","(x,y,z)(-x,-y,z)(-x,y,-z+0.5)(x,-y,-z+0.5)(-x,-y,-z)(x,y,-z)(x,-y,z+0.5)(-x,y,z+0.5)"
  },

  { // 50
    "","(x,y,z)(-x+0.5,-y+0.5,z)(-x+0.5,y,-z)(x,-y+0.5,-z)(-x,-y,-z)(x+0.5,y+0.5,-z)(x+0.5,-y,z)(-x,y+0.5,z)"
  },

  { // 51
    "","(x,y,z)(-x+0.5,-y,z)(-x,y,-z)(x+0.5,-y,-z)(-x,-y,-z)(x+0.5,y,-z)(x,-y,z)(-x+0.5,y,z)"
  },

  { // 52
    "","(x,y,z)(-x+0.5,-y,z)(-x+0.5,y+0.5,-z+0.5)(x,-y+0.5,-z+0.5)(-x,-y,-z)(x+0.5,y,-z)(x+0.5,-y+0.5,z+0.5)(-x,y+0.5,z+0.5)"
  },

  { // 53
    "","(x,y,z)(-x+0.5,-y,z+0.5)(-x+0.5,y,-z+0.5)(x,-y,-z)(-x,-y,-z)(x+0.5,y,-z+0.5)(x+0.5,-y,z+0.5)(-x,y,z)"
  },

  { // 54
    "","(x,y,z)(-x+0.5,-y,z)(-x,y,-z+0.5)(x+0.5,-y,-z+0.5)(-x,-y,-z)(x+0.5,y,-z)(x,-y,z+0.5)(-x+0.5,y,z+0.5)"
  },

  { // 55
    "","(x,y,z)(-x,-y,z)(-x+0.5,y+0.5,-z)(x+0.5,-y+0.5,-z)(-x,-y,-z)(x,y,-z)(x+0.5,-y+0.5,z)(-x+0.5,y+0.5,z)"
  },

  { // 56
    "","(x,y,z)(-x+0.5,-y+0.5,z)(-x,y+0.5,-z+0.5)(x+0.5,-y,-z+0.5)(-x,-y,-z)(x+0.5,y+0.5,-z)(x,-y+0.5,z+0.5)(-x+0.5,y,z+0.5)"
  },

  { // 57
    "","(x,y,z)(-x,-y,z+0.5)(-x,y+0.5,-z+0.5)(x,-y+0.5,-z)(-x,-y,-z)(x,y,-z+0.5)(x,-y+0.5,z+0.5)(-x,y+0.5,z)"
  },

  { // 58
    "","(x,y,z)(-x,-y,z)(-x+0.5,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z+0.5)(-x,-y,-z)(x,y,-z)(x+0.5,-y+0.5,z+0.5)(-x+0.5,y+0.5,z+0.5)"
  },

  { // 59
    "","(x,y,z)(-x+0.5,-y+0.5,z)(-x,y+0.5,-z)(x+0.5,-y,-z)(-x,-y,-z)(x+0.5,y+0.5,-z)(x,-y+0.5,z)(-x+0.5,y,z)"
  },

  { // 60
    "","(x,y,z)(-x+0.5,-y+0.5,z+0.5)(-x,y,-z+0.5)(x+0.5,-y+0.5,-z)(-x,-y,-z)(x+0.5,y+0.5,-z+0.5)(x,-y,z+0.5)(-x+0.5,y+0.5,z)"
  },

  { // 61
    "","(x,y,z)(-x+0.5,-y,z+0.5)(-x,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z)(-x,-y,-z)(x+0.5,y,-z+0.5)(x,-y+0.5,z+0.5)(-x+0.5,y+0.5,z)"
  },

  { // 62
    "","(x,y,z)(-x+0.5,-y,z+0.5)(-x,y+0.5,-z)(x+0.5,-y+0.5,-z+0.5)(-x,-y,-z)(x+0.5,y,-z+0.5)(x,-y+0.5,z)(-x+0.5,y+0.5,z+0.5)"
  },

  { // 63
    "(0.5,0.5,0)","(x,y,z)(-x,-y,z+0.5)(-x,y,-z+0.5)(x,-y,-z)(-x,-y,-z)(x,y,-z+0.5)(x,-y,z+0.5)(-x,y,z)"
  },

  { // 64
    "(0.5,0.5,0)","(x,y,z)(-x,-y+0.5,z+0.5)(-x,y+0.5,-z+0.5)(x,-y,-z)(-x,-y,-z)(x,y+0.5,-z+0.5)(x,-y+0.5,z+0.5)(-x,y,z)"
  },

  { // 65
    "(0.5,0.5,0)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(-x,-y,-z)(x,y,-z)(x,-y,z)(-x,y,z)"
  },

  { // 66
    "(0.5,0.5,0)","(x,y,z)(-x,-y,z)(-x,y,-z+0.5)(x,-y,-z+0.5)(-x,-y,-z)(x,y,-z)(x,-y,z+0.5)(-x,y,z+0.5)"
  },

  { // 67
    "(0.5,0.5,0)","(x,y,z)(-x,-y+0.5,z)(-x,y+0.5,-z)(x,-y,-z)(-x,-y,-z)(x,y+0.5,-z)(x,-y+0.5,z)(-x,y,z)"
  },

  { // 68
    "(0.5,0.5,0)","(x,y,z)(-x+0.5,-y,z)(-x,y,-z+0.5)(x+0.5,-y,-z+0.5)(-x,-y,-z)(x+0.5,y,-z)(x,-y,z+0.5)(-x+0.5,y,z+0.5)"
  },

  { // 69
    "(0,0.5,0.5)(0.5,0,0.5)(0.5,0.5,0)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(-x,-y,-z)(x,y,-z)(x,-y,z)(-x,y,z)"
  },

  { // 70
    "(0,0.5,0.5)(0.5,0,0.5)(0.5,0.5,0)","(x,y,z)(-x+0.75,-y+0.75,z)(-x+0.75,y,-z+0.75)(x,-y+0.75,-z+0.75)(-x,-y,-z)(x+0.25,y+0.25,-z)(x+0.25,-y,z+0.25)(-x,y+0.25,z+0.25)"
  },

  { // 71
    "(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(-x,-y,-z)(x,y,-z)(x,-y,z)(-x,y,z)"
  },

  { // 72
    "(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(-x+0.5,y+0.5,-z)(x+0.5,-y+0.5,-z)(-x,-y,-z)(x,y,-z)(x+0.5,-y+0.5,z)(-x+0.5,y+0.5,z)"
  },

  { // 73
    "(0.5,0.5,0.5)","(x,y,z)(-x+0.5,-y,z+0.5)(-x,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z)(-x,-y,-z)(x+0.5,y,-z+0.5)(x,-y+0.5,z+0.5)(-x+0.5,y+0.5,z)"
  },

  { // 74
    "(0.5,0.5,0.5)","(x,y,z)(-x,-y+0.5,z)(-x,y+0.5,-z)(x,-y,-z)(-x,-y,-z)(x,y+0.5,-z)(x,-y+0.5,z)(-x,y,z)"
  },

  { // 75
    "","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)"
  },

  { // 76
    "","(x,y,z)(-x,-y,z+0.5)(-y,x,z+0.25)(y,-x,z+0.75)"
  },

  { // 77
    "","(x,y,z)(-x,-y,z)(-y,x,z+0.5)(y,-x,z+0.5)"
  },

  { // 78
    "","(x,y,z)(-x,-y,z+0.5)(-y,x,z+0.75)(y,-x,z+0.25)"
  },

  { // 79
    "(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)"
  },

  { // 80
    "(0.5,0.5,0.5)","(x,y,z)(-x+0.5,-y+0.5,z+0.5)(-y,x+0.5,z+0.25)(y+0.5,-x,z+0.75)"
  },

  { // 81
    "","(x,y,z)(-x,-y,z)(y,-x,-z)(-y,x,-z)"
  },

  { // 82
    "(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(y,-x,-z)(-y,x,-z)"
  },

  { // 83
    "","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)(-x,-y,-z)(x,y,-z)(y,-x,-z)(-y,x,-z)"
  },

  { // 84
    "","(x,y,z)(-x,-y,z)(-y,x,z+0.5)(y,-x,z+0.5)(-x,-y,-z)(x,y,-z)(y,-x,-z+0.5)(-y,x,-z+0.5)"
  },

  { // 85
    "","(x,y,z)(-x+0.5,-y+0.5,z)(-y+0.5,x,z)(y,-x+0.5,z)(-x,-y,-z)(x+0.5,y+0.5,-z)(y+0.5,-x,-z)(-y,x+0.5,-z)"
  },

  { // 86
    "","(x,y,z)(-x+0.5,-y+0.5,z)(-y,x+0.5,z+0.5)(y+0.5,-x,z+0.5)(-x,-y,-z)(x+0.5,y+0.5,-z)(y,-x+0.5,-z+0.5)(-y+0.5,x,-z+0.5)"
  },

  { // 87
    "(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)(-x,-y,-z)(x,y,-z)(y,-x,-z)(-y,x,-z)"
  },

  { // 88
    "(0.5,0.5,0.5)","(x,y,z)(-x+0.5,-y,z+0.5)(-y+0.75,x+0.25,z+0.25)(y+0.75,-x+0.75,z+0.75)(-x,-y,-z)(x+0.5,y,-z+0.5)(y+0.25,-x+0.75,-z+0.75)(-y+0.25,x+0.25,-z+0.25)"
  },

  { // 89
    "","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)(-x,y,-z)(x,-y,-z)(y,x,-z)(-y,-x,-z)"
  },

  { // 90
    "","(x,y,z)(-x,-y,z)(-y+0.5,x+0.5,z)(y+0.5,-x+0.5,z)(-x+0.5,y+0.5,-z)(x+0.5,-y+0.5,-z)(y,x,-z)(-y,-x,-z)"
  },

  { // 91
    "","(x,y,z)(-x,-y,z+0.5)(-y,x,z+0.25)(y,-x,z+0.75)(-x,y,-z)(x,-y,-z+0.5)(y,x,-z+0.75)(-y,-x,-z+0.25)"
  },

  { // 92
    "","(x,y,z)(-x,-y,z+0.5)(-y+0.5,x+0.5,z+0.25)(y+0.5,-x+0.5,z+0.75)(-x+0.5,y+0.5,-z+0.25)(x+0.5,-y+0.5,-z+0.75)(y,x,-z)(-y,-x,-z+0.5)"
  },

  { // 93
    "","(x,y,z)(-x,-y,z)(-y,x,z+0.5)(y,-x,z+0.5)(-x,y,-z)(x,-y,-z)(y,x,-z+0.5)(-y,-x,-z+0.5)"
  },

  { // 94
    "","(x,y,z)(-x,-y,z)(-y+0.5,x+0.5,z+0.5)(y+0.5,-x+0.5,z+0.5)(-x+0.5,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z+0.5)(y,x,-z)(-y,-x,-z)"
  },

  { // 95
    "","(x,y,z)(-x,-y,z+0.5)(-y,x,z+0.75)(y,-x,z+0.25)(-x,y,-z)(x,-y,-z+0.5)(y,x,-z+0.25)(-y,-x,-z+0.75)"
  },

  { // 96
    "","(x,y,z)(-x,-y,z+0.5)(-y+0.5,x+0.5,z+0.75)(y+0.5,-x+0.5,z+0.25)(-x+0.5,y+0.5,-z+0.75)(x+0.5,-y+0.5,-z+0.25)(y,x,-z)(-y,-x,-z+0.5)"
  },

  { // 97
    "(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)(-x,y,-z)(x,-y,-z)(y,x,-z)(-y,-x,-z)"
  },

  { // 98
    "(0.5,0.5,0.5)","(x,y,z)(-x+0.5,-y+0.5,z+0.5)(-y,x+0.5,z+0.25)(y+0.5,-x,z+0.75)(-x+0.5,y,-z+0.75)(x,-y+0.5,-z+0.25)(y+0.5,x+0.5,-z+0.5)(-y,-x,-z)"
  },

  { // 99
    "","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)(x,-y,z)(-x,y,z)(-y,-x,z)(y,x,z)"
  },

  { // 100
    "","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)(x+0.5,-y+0.5,z)(-x+0.5,y+0.5,z)(-y+0.5,-x+0.5,z)(y+0.5,x+0.5,z)"
  },

  { // 101
    "","(x,y,z)(-x,-y,z)(-y,x,z+0.5)(y,-x,z+0.5)(x,-y,z+0.5)(-x,y,z+0.5)(-y,-x,z)(y,x,z)"
  },

  { // 102
    "","(x,y,z)(-x,-y,z)(-y+0.5,x+0.5,z+0.5)(y+0.5,-x+0.5,z+0.5)(x+0.5,-y+0.5,z+0.5)(-x+0.5,y+0.5,z+0.5)(-y,-x,z)(y,x,z)"
  },

  { // 103
    "","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)(x,-y,z+0.5)(-x,y,z+0.5)(-y,-x,z+0.5)(y,x,z+0.5)"
  },

  { // 104
    "","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)(x+0.5,-y+0.5,z+0.5)(-x+0.5,y+0.5,z+0.5)(-y+0.5,-x+0.5,z+0.5)(y+0.5,x+0.5,z+0.5)"
  },

  { // 105
    "","(x,y,z)(-x,-y,z)(-y,x,z+0.5)(y,-x,z+0.5)(x,-y,z)(-x,y,z)(-y,-x,z+0.5)(y,x,z+0.5)"
  },

  { // 106
    "","(x,y,z)(-x,-y,z)(-y,x,z+0.5)(y,-x,z+0.5)(x+0.5,-y+0.5,z)(-x+0.5,y+0.5,z)(-y+0.5,-x+0.5,z+0.5)(y+0.5,x+0.5,z+0.5)"
  },

  { // 107
    "(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)(x,-y,z)(-x,y,z)(-y,-x,z)(y,x,z)"
  },

  { // 108
    "(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)(x,-y,z+0.5)(-x,y,z+0.5)(-y,-x,z+0.5)(y,x,z+0.5)"
  },

  { // 109
    "(0.5,0.5,0.5)","(x,y,z)(-x+0.5,-y+0.5,z+0.5)(-y,x+0.5,z+0.25)(y+0.5,-x,z+0.75)(x,-y,z)(-x+0.5,y+0.5,z+0.5)(-y,-x+0.5,z+0.25)(y+0.5,x,z+0.75)"
  },

  { // 110
    "(0.5,0.5,0.5)","(x,y,z)(-x+0.5,-y+0.5,z+0.5)(-y,x+0.5,z+0.25)(y+0.5,-x,z+0.75)(x,-y,z+0.5)(-x+0.5,y+0.5,z)(-y,-x+0.5,z+0.75)(y+0.5,x,z+0.25)"
  },

  { // 111
    "","(x,y,z)(-x,-y,z)(y,-x,-z)(-y,x,-z)(-x,y,-z)(x,-y,-z)(-y,-x,z)(y,x,z)"
  },

  { // 112
    "","(x,y,z)(-x,-y,z)(y,-x,-z)(-y,x,-z)(-x,y,-z+0.5)(x,-y,-z+0.5)(-y,-x,z+0.5)(y,x,z+0.5)"
  },

  { // 113
    "","(x,y,z)(-x,-y,z)(y,-x,-z)(-y,x,-z)(-x+0.5,y+0.5,-z)(x+0.5,-y+0.5,-z)(-y+0.5,-x+0.5,z)(y+0.5,x+0.5,z)"
  },

  { // 114
    "","(x,y,z)(-x,-y,z)(y,-x,-z)(-y,x,-z)(-x+0.5,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z+0.5)(-y+0.5,-x+0.5,z+0.5)(y+0.5,x+0.5,z+0.5)"
  },

  { // 115
    "","(x,y,z)(-x,-y,z)(y,-x,-z)(-y,x,-z)(x,-y,z)(-x,y,z)(y,x,-z)(-y,-x,-z)"
  },

  { // 116
    "","(x,y,z)(-x,-y,z)(y,-x,-z)(-y,x,-z)(x,-y,z+0.5)(-x,y,z+0.5)(y,x,-z+0.5)(-y,-x,-z+0.5)"
  },

  { // 117
    "","(x,y,z)(-x,-y,z)(y,-x,-z)(-y,x,-z)(x+0.5,-y+0.5,z)(-x+0.5,y+0.5,z)(y+0.5,x+0.5,-z)(-y+0.5,-x+0.5,-z)"
  },

  { // 118
    "","(x,y,z)(-x,-y,z)(y,-x,-z)(-y,x,-z)(x+0.5,-y+0.5,z+0.5)(-x+0.5,y+0.5,z+0.5)(y+0.5,x+0.5,-z+0.5)(-y+0.5,-x+0.5,-z+0.5)"
  },

  { // 119
    "(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(y,-x,-z)(-y,x,-z)(x,-y,z)(-x,y,z)(y,x,-z)(-y,-x,-z)"
  },

  { // 120
    "(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(y,-x,-z)(-y,x,-z)(x,-y,z+0.5)(-x,y,z+0.5)(y,x,-z+0.5)(-y,-x,-z+0.5)"
  },

  { // 121
    "(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(y,-x,-z)(-y,x,-z)(-x,y,-z)(x,-y,-z)(-y,-x,z)(y,x,z)"
  },

  { // 122
    "(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(y,-x,-z)(-y,x,-z)(-x+0.5,y,-z+0.75)(x+0.5,-y,-z+0.75)(-y+0.5,-x,z+0.75)(y+0.5,x,z+0.75)"
  },

  { // 123
    "","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)(-x,y,-z)(x,-y,-z)(y,x,-z)(-y,-x,-z)(-x,-y,-z)(x,y,-z)(y,-x,-z)(-y,x,-z)(x,-y,z)(-x,y,z)(-y,-x,z)(y,x,z)"
  },

  { // 124
    "","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)(-x,y,-z+0.5)(x,-y,-z+0.5)(y,x,-z+0.5)(-y,-x,-z+0.5)(-x,-y,-z)(x,y,-z)(y,-x,-z)(-y,x,-z)(x,-y,z+0.5)(-x,y,z+0.5)(-y,-x,z+0.5)(y,x,z+0.5)"
  },

  { // 125
    "","(x,y,z)(-x+0.5,-y+0.5,z)(-y+0.5,x,z)(y,-x+0.5,z)(-x+0.5,y,-z)(x,-y+0.5,-z)(y,x,-z)(-y+0.5,-x+0.5,-z)(-x,-y,-z)(x+0.5,y+0.5,-z)(y+0.5,-x,-z)(-y,x+0.5,-z)(x+0.5,-y,z)(-x,y+0.5,z)(-y,-x,z)(y+0.5,x+0.5,z)"
  },

  { // 126
    "","(x,y,z)(-x+0.5,-y+0.5,z)(-y+0.5,x,z)(y,-x+0.5,z)(-x+0.5,y,-z+0.5)(x,-y+0.5,-z+0.5)(y,x,-z+0.5)(-y+0.5,-x+0.5,-z+0.5)(-x,-y,-z)(x+0.5,y+0.5,-z)(y+0.5,-x,-z)(-y,x+0.5,-z)(x+0.5,-y,z+0.5)(-x,y+0.5,z+0.5)(-y,-x,z+0.5)(y+0.5,x+0.5,z+0.5)"
  },

  { // 127
    "","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)(-x+0.5,y+0.5,-z)(x+0.5,-y+0.5,-z)(y+0.5,x+0.5,-z)(-y+0.5,-x+0.5,-z)(-x,-y,-z)(x,y,-z)(y,-x,-z)(-y,x,-z)(x+0.5,-y+0.5,z)(-x+0.5,y+0.5,z)(-y+0.5,-x+0.5,z)(y+0.5,x+0.5,z)"
  },

  { // 128
    "","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)(-x+0.5,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z+0.5)(y+0.5,x+0.5,-z+0.5)(-y+0.5,-x+0.5,-z+0.5)(-x,-y,-z)(x,y,-z)(y,-x,-z)(-y,x,-z)(x+0.5,-y+0.5,z+0.5)(-x+0.5,y+0.5,z+0.5)(-y+0.5,-x+0.5,z+0.5)(y+0.5,x+0.5,z+0.5)"
  },

  { // 129
    "","(x,y,z)(-x+0.5,-y+0.5,z)(-y+0.5,x,z)(y,-x+0.5,z)(-x,y+0.5,-z)(x+0.5,-y,-z)(y+0.5,x+0.5,-z)(-y,-x,-z)(-x,-y,-z)(x+0.5,y+0.5,-z)(y+0.5,-x,-z)(-y,x+0.5,-z)(x,-y+0.5,z)(-x+0.5,y,z)(-y+0.5,-x+0.5,z)(y,x,z)"
  },

  { // 130
    "","(x,y,z)(-x+0.5,-y+0.5,z)(-y+0.5,x,z)(y,-x+0.5,z)(-x,y+0.5,-z+0.5)(x+0.5,-y,-z+0.5)(y+0.5,x+0.5,-z+0.5)(-y,-x,-z+0.5)(-x,-y,-z)(x+0.5,y+0.5,-z)(y+0.5,-x,-z)(-y,x+0.5,-z)(x,-y+0.5,z+0.5)(-x+0.5,y,z+0.5)(-y+0.5,-x+0.5,z+0.5)(y,x,z+0.5)"
  },

  { // 131
    "","(x,y,z)(-x,-y,z)(-y,x,z+0.5)(y,-x,z+0.5)(-x,y,-z)(x,-y,-z)(y,x,-z+0.5)(-y,-x,-z+0.5)(-x,-y,-z)(x,y,-z)(y,-x,-z+0.5)(-y,x,-z+0.5)(x,-y,z)(-x,y,z)(-y,-x,z+0.5)(y,x,z+0.5)"
  },

  { // 132
    "","(x,y,z)(-x,-y,z)(-y,x,z+0.5)(y,-x,z+0.5)(-x,y,-z+0.5)(x,-y,-z+0.5)(y,x,-z)(-y,-x,-z)(-x,-y,-z)(x,y,-z)(y,-x,-z+0.5)(-y,x,-z+0.5)(x,-y,z+0.5)(-x,y,z+0.5)(-y,-x,z)(y,x,z)"
  },

  { // 133
    "","(x,y,z)(-x+0.5,-y+0.5,z)(-y+0.5,x,z+0.5)(y,-x+0.5,z+0.5)(-x+0.5,y,-z)(x,-y+0.5,-z)(y,x,-z+0.5)(-y+0.5,-x+0.5,-z+0.5)(-x,-y,-z)(x+0.5,y+0.5,-z)(y+0.5,-x,-z+0.5)(-y,x+0.5,-z+0.5)(x+0.5,-y,z)(-x,y+0.5,z)(-y,-x,z+0.5)(y+0.5,x+0.5,z+0.5)"
  },

  { // 134
    "","(x,y,z)(-x+0.5,-y+0.5,z)(-y+0.5,x,z+0.5)(y,-x+0.5,z+0.5)(-x+0.5,y,-z+0.5)(x,-y+0.5,-z+0.5)(y,x,-z)(-y+0.5,-x+0.5,-z)(-x,-y,-z)(x+0.5,y+0.5,-z)(y+0.5,-x,-z+0.5)(-y,x+0.5,-z+0.5)(x+0.5,-y,z+0.5)(-x,y+0.5,z+0.5)(-y,-x,z)(y+0.5,x+0.5,z)"
  },

  { // 135
    "","(x,y,z)(-x,-y,z)(-y,x,z+0.5)(y,-x,z+0.5)(-x+0.5,y+0.5,-z)(x+0.5,-y+0.5,-z)(y+0.5,x+0.5,-z+0.5)(-y+0.5,-x+0.5,-z+0.5)(-x,-y,-z)(x,y,-z)(y,-x,-z+0.5)(-y,x,-z+0.5)(x+0.5,-y+0.5,z)(-x+0.5,y+0.5,z)(-y+0.5,-x+0.5,z+0.5)(y+0.5,x+0.5,z+0.5)"
  },

  { // 136
    "","(x,y,z)(-x,-y,z)(-y+0.5,x+0.5,z+0.5)(y+0.5,-x+0.5,z+0.5)(-x+0.5,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z+0.5)(y,x,-z)(-y,-x,-z)(-x,-y,-z)(x,y,-z)(y+0.5,-x+0.5,-z+0.5)(-y+0.5,x+0.5,-z+0.5)(x+0.5,-y+0.5,z+0.5)(-x+0.5,y+0.5,z+0.5)(-y,-x,z)(y,x,z)"
  },

  { // 137
    "","(x,y,z)(-x+0.5,-y+0.5,z)(-y+0.5,x,z+0.5)(y,-x+0.5,z+0.5)(-x,y+0.5,-z)(x+0.5,-y,-z)(y+0.5,x+0.5,-z+0.5)(-y,-x,-z+0.5)(-x,-y,-z)(x+0.5,y+0.5,-z)(y+0.5,-x,-z+0.5)(-y,x+0.5,-z+0.5)(x,-y+0.5,z)(-x+0.5,y,z)(-y+0.5,-x+0.5,z+0.5)(y,x,z+0.5)"
  },

  { // 138
    "","(x,y,z)(-x+0.5,-y+0.5,z)(-y+0.5,x,z+0.5)(y,-x+0.5,z+0.5)(-x,y+0.5,-z+0.5)(x+0.5,-y,-z+0.5)(y+0.5,x+0.5,-z)(-y,-x,-z)(-x,-y,-z)(x+0.5,y+0.5,-z)(y+0.5,-x,-z+0.5)(-y,x+0.5,-z+0.5)(x,-y+0.5,z+0.5)(-x+0.5,y,z+0.5)(-y+0.5,-x+0.5,z)(y,x,z)"
  },

  { // 139
    "(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)(-x,y,-z)(x,-y,-z)(y,x,-z)(-y,-x,-z)(-x,-y,-z)(x,y,-z)(y,-x,-z)(-y,x,-z)(x,-y,z)(-x,y,z)(-y,-x,z)(y,x,z)"
  },

  { // 140
    "(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(-y,x,z)(y,-x,z)(-x,y,-z+0.5)(x,-y,-z+0.5)(y,x,-z+0.5)(-y,-x,-z+0.5)(-x,-y,-z)(x,y,-z)(y,-x,-z)(-y,x,-z)(x,-y,z+0.5)(-x,y,z+0.5)(-y,-x,z+0.5)(y,x,z+0.5)"
  },

  { // 141
    "(0.5,0.5,0.5)","(x,y,z)(-x+0.5,-y,z+0.5)(-y+0.25,x+0.75,z+0.25)(y+0.25,-x+0.25,z+0.75)(-x+0.5,y,-z+0.5)(x,-y,-z)(y+0.25,x+0.75,-z+0.25)(-y+0.25,-x+0.25,-z+0.75)(-x,-y,-z)(x+0.5,y,-z+0.5)(y+0.75,-x+0.25,-z+0.75)(-y+0.75,x+0.75,-z+0.25)(x+0.5,-y,z+0.5)(-x,y,z)(-y+0.75,-x+0.25,z+0.75)(y+0.75,x+0.75,z+0.25)"
  },

  { // 142
    "(0.5,0.5,0.5)","(x,y,z)(-x+0.5,-y,z+0.5)(-y+0.25,x+0.75,z+0.25)(y+0.25,-x+0.25,z+0.75)(-x+0.5,y,-z)(x,-y,-z+0.5)(y+0.25,x+0.75,-z+0.75)(-y+0.25,-x+0.25,-z+0.25)(-x,-y,-z)(x+0.5,y,-z+0.5)(y+0.75,-x+0.25,-z+0.75)(-y+0.75,x+0.75,-z+0.25)(x+0.5,-y,z)(-x,y,z+0.5)(-y+0.75,-x+0.25,z+0.25)(y+0.75,x+0.75,z+0.75)"
  },

  { // 143
    "","(x,y,z)(-y,x-y,z)(-x+y,-x,z)"
  },

  { // 144
    "","(x,y,z)(-y,x-y,z+0.333333)(-x+y,-x,z+0.666667)"
  },

  { // 145
    "","(x,y,z)(-y,x-y,z+0.666667)(-x+y,-x,z+0.333333)"
  },

  { // 146
    "(0.666667,0.333333,0.333333)(0.333333,0.666667,0.666667)","(x,y,z)(-y,x-y,z)(-x+y,-x,z)"
  },

  { // 147
    "","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-x,-y,-z)(y,-x+y,-z)(x-y,x,-z)"
  },

  { // 148
    "(0.666667,0.333333,0.333333)(0.333333,0.666667,0.666667)","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-x,-y,-z)(y,-x+y,-z)(x-y,x,-z)"
  },

  { // 149
    "","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-y,-x,-z)(-x+y,y,-z)(x,x-y,-z)"
  },

  { // 150
    "","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(y,x,-z)(x-y,-y,-z)(-x,-x+y,-z)"
  },

  { // 151
    "","(x,y,z)(-y,x-y,z+0.333333)(-x+y,-x,z+0.666667)(-y,-x,-z+0.666667)(-x+y,y,-z+0.333333)(x,x-y,-z)"
  },

  { // 152
    "","(x,y,z)(-y,x-y,z+0.333333)(-x+y,-x,z+0.666667)(y,x,-z)(x-y,-y,-z+0.666667)(-x,-x+y,-z+0.333333)"
  },

  { // 153
    "","(x,y,z)(-y,x-y,z+0.666667)(-x+y,-x,z+0.333333)(-y,-x,-z+0.333333)(-x+y,y,-z+0.666667)(x,x-y,-z)"
  },

  { // 154
    "","(x,y,z)(-y,x-y,z+0.666667)(-x+y,-x,z+0.333333)(y,x,-z)(x-y,-y,-z+0.333333)(-x,-x+y,-z+0.666667)"
  },

  { // 155
    "(0.666667,0.333333,0.333333)(0.333333,0.666667,0.666667)","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(y,x,-z)(x-y,-y,-z)(-x,-x+y,-z)"
  },

  { // 156
    "","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-y,-x,z)(-x+y,y,z)(x,x-y,z)"
  },

  { // 157
    "","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(y,x,z)(x-y,-y,z)(-x,-x+y,z)"
  },

  { // 158
    "","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-y,-x,z+0.5)(-x+y,y,z+0.5)(x,x-y,z+0.5)"
  },

  { // 159
    "","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(y,x,z+0.5)(x-y,-y,z+0.5)(-x,-x+y,z+0.5)"
  },

  { // 160
    "(0.666667,0.333333,0.333333)(0.333333,0.666667,0.666667)","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-y,-x,z)(-x+y,y,z)(x,x-y,z)"
  },

  { // 161
    "(0.666667,0.333333,0.333333)(0.333333,0.666667,0.666667)","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-y,-x,z+0.5)(-x+y,y,z+0.5)(x,x-y,z+0.5)"
  },

  { // 162
    "","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-y,-x,-z)(-x+y,y,-z)(x,x-y,-z)(-x,-y,-z)(y,-x+y,-z)(x-y,x,-z)(y,x,z)(x-y,-y,z)(-x,-x+y,z)"
  },

  { // 163
    "","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-y,-x,-z+0.5)(-x+y,y,-z+0.5)(x,x-y,-z+0.5)(-x,-y,-z)(y,-x+y,-z)(x-y,x,-z)(y,x,z+0.5)(x-y,-y,z+0.5)(-x,-x+y,z+0.5)"
  },

  { // 164
    "","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(y,x,-z)(x-y,-y,-z)(-x,-x+y,-z)(-x,-y,-z)(y,-x+y,-z)(x-y,x,-z)(-y,-x,z)(-x+y,y,z)(x,x-y,z)"
  },

  { // 165
    "","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(y,x,-z+0.5)(x-y,-y,-z+0.5)(-x,-x+y,-z+0.5)(-x,-y,-z)(y,-x+y,-z)(x-y,x,-z)(-y,-x,z+0.5)(-x+y,y,z+0.5)(x,x-y,z+0.5)"
  },

  { // 166
    "(0.666667,0.333333,0.333333)(0.333333,0.666667,0.666667)","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(y,x,-z)(x-y,-y,-z)(-x,-x+y,-z)(-x,-y,-z)(y,-x+y,-z)(x-y,x,-z)(-y,-x,z)(-x+y,y,z)(x,x-y,z)"
  },

  { // 167
    "(0.666667,0.333333,0.333333)(0.333333,0.666667,0.666667)","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(y,x,-z+0.5)(x-y,-y,-z+0.5)(-x,-x+y,-z+0.5)(-x,-y,-z)(y,-x+y,-z)(x-y,x,-z)(-y,-x,z+0.5)(-x+y,y,z+0.5)(x,x-y,z+0.5)"
  },

  { // 168
    "","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-x,-y,z)(y,-x+y,z)(x-y,x,z)"
  },

  { // 169
    "","(x,y,z)(-y,x-y,z+0.333333)(-x+y,-x,z+0.666667)(-x,-y,z+0.5)(y,-x+y,z+0.833333)(x-y,x,z+0.166667)"
  },

  { // 170
    "","(x,y,z)(-y,x-y,z+0.666667)(-x+y,-x,z+0.333333)(-x,-y,z+0.5)(y,-x+y,z+0.166667)(x-y,x,z+0.833333)"
  },

  { // 171
    "","(x,y,z)(-y,x-y,z+0.666667)(-x+y,-x,z+0.333333)(-x,-y,z)(y,-x+y,z+0.666667)(x-y,x,z+0.333333)"
  },

  { // 172
    "","(x,y,z)(-y,x-y,z+0.333333)(-x+y,-x,z+0.666667)(-x,-y,z)(y,-x+y,z+0.333333)(x-y,x,z+0.666667)"
  },

  { // 173
    "","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-x,-y,z+0.5)(y,-x+y,z+0.5)(x-y,x,z+0.5)"
  },

  { // 174
    "","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(x,y,-z)(-y,x-y,-z)(-x+y,-x,-z)"
  },

  { // 175
    "","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-x,-y,z)(y,-x+y,z)(x-y,x,z)(-x,-y,-z)(y,-x+y,-z)(x-y,x,-z)(x,y,-z)(-y,x-y,-z)(-x+y,-x,-z)"
  },

  { // 176
    "","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-x,-y,z+0.5)(y,-x+y,z+0.5)(x-y,x,z+0.5)(-x,-y,-z)(y,-x+y,-z)(x-y,x,-z)(x,y,-z+0.5)(-y,x-y,-z+0.5)(-x+y,-x,-z+0.5)"
  },

  { // 177
    "","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-x,-y,z)(y,-x+y,z)(x-y,x,z)(y,x,-z)(x-y,-y,-z)(-x,-x+y,-z)(-y,-x,-z)(-x+y,y,-z)(x,x-y,-z)"
  },

  { // 178
    "","(x,y,z)(-y,x-y,z+0.333333)(-x+y,-x,z+0.666667)(-x,-y,z+0.5)(y,-x+y,z+0.833333)(x-y,x,z+0.166667)(y,x,-z+0.333333)(x-y,-y,-z)(-x,-x+y,-z+0.666667)(-y,-x,-z+0.833333)(-x+y,y,-z+0.5)(x,x-y,-z+0.166667)"
  },

  { // 179
    "","(x,y,z)(-y,x-y,z+0.666667)(-x+y,-x,z+0.333333)(-x,-y,z+0.5)(y,-x+y,z+0.166667)(x-y,x,z+0.833333)(y,x,-z+0.666667)(x-y,-y,-z)(-x,-x+y,-z+0.333333)(-y,-x,-z+0.166667)(-x+y,y,-z+0.5)(x,x-y,-z+0.833333)"
  },

  { // 180
    "","(x,y,z)(-y,x-y,z+0.666667)(-x+y,-x,z+0.333333)(-x,-y,z)(y,-x+y,z+0.666667)(x-y,x,z+0.333333)(y,x,-z+0.666667)(x-y,-y,-z)(-x,-x+y,-z+0.333333)(-y,-x,-z+0.666667)(-x+y,y,-z)(x,x-y,-z+0.333333)"
  },

  { // 181
    "","(x,y,z)(-y,x-y,z+0.333333)(-x+y,-x,z+0.666667)(-x,-y,z)(y,-x+y,z+0.333333)(x-y,x,z+0.666667)(y,x,-z+0.333333)(x-y,-y,-z)(-x,-x+y,-z+0.666667)(-y,-x,-z+0.333333)(-x+y,y,-z)(x,x-y,-z+0.666667)"
  },

  { // 182
    "","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-x,-y,z+0.5)(y,-x+y,z+0.5)(x-y,x,z+0.5)(y,x,-z)(x-y,-y,-z)(-x,-x+y,-z)(-y,-x,-z+0.5)(-x+y,y,-z+0.5)(x,x-y,-z+0.5)"
  },

  { // 183
    "","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-x,-y,z)(y,-x+y,z)(x-y,x,z)(-y,-x,z)(-x+y,y,z)(x,x-y,z)(y,x,z)(x-y,-y,z)(-x,-x+y,z)"
  },

  { // 184
    "","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-x,-y,z)(y,-x+y,z)(x-y,x,z)(-y,-x,z+0.5)(-x+y,y,z+0.5)(x,x-y,z+0.5)(y,x,z+0.5)(x-y,-y,z+0.5)(-x,-x+y,z+0.5)"
  },

  { // 185
    "","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-x,-y,z+0.5)(y,-x+y,z+0.5)(x-y,x,z+0.5)(-y,-x,z+0.5)(-x+y,y,z+0.5)(x,x-y,z+0.5)(y,x,z)(x-y,-y,z)(-x,-x+y,z)"
  },

  { // 186
    "","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-x,-y,z+0.5)(y,-x+y,z+0.5)(x-y,x,z+0.5)(-y,-x,z)(-x+y,y,z)(x,x-y,z)(y,x,z+0.5)(x-y,-y,z+0.5)(-x,-x+y,z+0.5)"
  },

  { // 187
    "","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(x,y,-z)(-y,x-y,-z)(-x+y,-x,-z)(-y,-x,z)(-x+y,y,z)(x,x-y,z)(-y,-x,-z)(-x+y,y,-z)(x,x-y,-z)"
  },

  { // 188
    "","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(x,y,-z+0.5)(-y,x-y,-z+0.5)(-x+y,-x,-z+0.5)(-y,-x,z+0.5)(-x+y,y,z+0.5)(x,x-y,z+0.5)(-y,-x,-z)(-x+y,y,-z)(x,x-y,-z)"
  },

  { // 189
    "","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(x,y,-z)(-y,x-y,-z)(-x+y,-x,-z)(y,x,-z)(x-y,-y,-z)(-x,-x+y,-z)(y,x,z)(x-y,-y,z)(-x,-x+y,z)"
  },

  { // 190
    "","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(x,y,-z+0.5)(-y,x-y,-z+0.5)(-x+y,-x,-z+0.5)(y,x,-z)(x-y,-y,-z)(-x,-x+y,-z)(y,x,z+0.5)(x-y,-y,z+0.5)(-x,-x+y,z+0.5)"
  },

  { // 191
    "","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-x,-y,z)(y,-x+y,z)(x-y,x,z)(y,x,-z)(x-y,-y,-z)(-x,-x+y,-z)(-y,-x,-z)(-x+y,y,-z)(x,x-y,-z)(-x,-y,-z)(y,-x+y,-z)(x-y,x,-z)(x,y,-z)(-y,x-y,-z)(-x+y,-x,-z)(-y,-x,z)(-x+y,y,z)(x,x-y,z)(y,x,z)(x-y,-y,z)(-x,-x+y,z)"
  },

  { // 192
    "","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-x,-y,z)(y,-x+y,z)(x-y,x,z)(y,x,-z+0.5)(x-y,-y,-z+0.5)(-x,-x+y,-z+0.5)(-y,-x,-z+0.5)(-x+y,y,-z+0.5)(x,x-y,-z+0.5)(-x,-y,-z)(y,-x+y,-z)(x-y,x,-z)(x,y,-z)(-y,x-y,-z)(-x+y,-x,-z)(-y,-x,z+0.5)(-x+y,y,z+0.5)(x,x-y,z+0.5)(y,x,z+0.5)(x-y,-y,z+0.5)(-x,-x+y,z+0.5)"
  },

  { // 193
    "","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-x,-y,z+0.5)(y,-x+y,z+0.5)(x-y,x,z+0.5)(y,x,-z+0.5)(x-y,-y,-z+0.5)(-x,-x+y,-z+0.5)(-y,-x,-z)(-x+y,y,-z)(x,x-y,-z)(-x,-y,-z)(y,-x+y,-z)(x-y,x,-z)(x,y,-z+0.5)(-y,x-y,-z+0.5)(-x+y,-x,-z+0.5)(-y,-x,z+0.5)(-x+y,y,z+0.5)(x,x-y,z+0.5)(y,x,z)(x-y,-y,z)(-x,-x+y,z)"
  },

  { // 194
    "","(x,y,z)(-y,x-y,z)(-x+y,-x,z)(-x,-y,z+0.5)(y,-x+y,z+0.5)(x-y,x,z+0.5)(y,x,-z)(x-y,-y,-z)(-x,-x+y,-z)(-y,-x,-z+0.5)(-x+y,y,-z+0.5)(x,x-y,-z+0.5)(-x,-y,-z)(y,-x+y,-z)(x-y,x,-z)(x,y,-z+0.5)(-y,x-y,-z+0.5)(-x+y,-x,-z+0.5)(-y,-x,z)(-x+y,y,z)(x,x-y,z)(y,x,z+0.5)(x-y,-y,z+0.5)(-x,-x+y,z+0.5)"
  },

  { // 195
    "","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)"
  },

  { // 196
    "(0,0.5,0.5)(0.5,0,0.5)(0.5,0.5,0)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)"
  },

  { // 197
    "(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)"
  },

  { // 198
    "","(x,y,z)(-x+0.5,-y,z+0.5)(-x,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z)(z,x,y)(z+0.5,-x+0.5,-y)(-z+0.5,-x,y+0.5)(-z,x+0.5,-y+0.5)(y,z,x)(-y,z+0.5,-x+0.5)(y+0.5,-z+0.5,-x)(-y+0.5,-z,x+0.5)"
  },

  { // 199
    "(0.5,0.5,0.5)","(x,y,z)(-x+0.5,-y,z+0.5)(-x,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z)(z,x,y)(z+0.5,-x+0.5,-y)(-z+0.5,-x,y+0.5)(-z,x+0.5,-y+0.5)(y,z,x)(-y,z+0.5,-x+0.5)(y+0.5,-z+0.5,-x)(-y+0.5,-z,x+0.5)"
  },

  { // 200
    "","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(-x,-y,-z)(x,y,-z)(x,-y,z)(-x,y,z)(-z,-x,-y)(-z,x,y)(z,x,-y)(z,-x,y)(-y,-z,-x)(y,-z,x)(-y,z,x)(y,z,-x)"
  },

  { // 201
    "","(x,y,z)(-x+0.5,-y+0.5,z)(-x+0.5,y,-z+0.5)(x,-y+0.5,-z+0.5)(z,x,y)(z,-x+0.5,-y+0.5)(-z+0.5,-x+0.5,y)(-z+0.5,x,-y+0.5)(y,z,x)(-y+0.5,z,-x+0.5)(y,-z+0.5,-x+0.5)(-y+0.5,-z+0.5,x)(-x,-y,-z)(x+0.5,y+0.5,-z)(x+0.5,-y,z+0.5)(-x,y+0.5,z+0.5)(-z,-x,-y)(-z,x+0.5,y+0.5)(z+0.5,x+0.5,-y)(z+0.5,-x,y+0.5)(-y,-z,-x)(y+0.5,-z,x+0.5)(-y,z+0.5,x+0.5)(y+0.5,z+0.5,-x)"
  },

  { // 202
    "(0,0.5,0.5)(0.5,0,0.5)(0.5,0.5,0)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(-x,-y,-z)(x,y,-z)(x,-y,z)(-x,y,z)(-z,-x,-y)(-z,x,y)(z,x,-y)(z,-x,y)(-y,-z,-x)(y,-z,x)(-y,z,x)(y,z,-x)"
  },

  { // 203
    "(0,0.5,0.5)(0.5,0,0.5)(0.5,0.5,0)","(x,y,z)(-x+0.75,-y+0.75,z)(-x+0.75,y,-z+0.75)(x,-y+0.75,-z+0.75)(z,x,y)(z,-x+0.75,-y+0.75)(-z+0.75,-x+0.75,y)(-z+0.75,x,-y+0.75)(y,z,x)(-y+0.75,z,-x+0.75)(y,-z+0.75,-x+0.75)(-y+0.75,-z+0.75,x)(-x,-y,-z)(x+0.25,y+0.25,-z)(x+0.25,-y,z+0.25)(-x,y+0.25,z+0.25)(-z,-x,-y)(-z,x+0.25,y+0.25)(z+0.25,x+0.25,-y)(z+0.25,-x,y+0.25)(-y,-z,-x)(y+0.25,-z,x+0.25)(-y,z+0.25,x+0.25)(y+0.25,z+0.25,-x)"
  },

  { // 204
    "(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(-x,-y,-z)(x,y,-z)(x,-y,z)(-x,y,z)(-z,-x,-y)(-z,x,y)(z,x,-y)(z,-x,y)(-y,-z,-x)(y,-z,x)(-y,z,x)(y,z,-x)"
  },

  { // 205
    "","(x,y,z)(-x+0.5,-y,z+0.5)(-x,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z)(z,x,y)(z+0.5,-x+0.5,-y)(-z+0.5,-x,y+0.5)(-z,x+0.5,-y+0.5)(y,z,x)(-y,z+0.5,-x+0.5)(y+0.5,-z+0.5,-x)(-y+0.5,-z,x+0.5)(-x,-y,-z)(x+0.5,y,-z+0.5)(x,-y+0.5,z+0.5)(-x+0.5,y+0.5,z)(-z,-x,-y)(-z+0.5,x+0.5,y)(z+0.5,x,-y+0.5)(z,-x+0.5,y+0.5)(-y,-z,-x)(y,-z+0.5,x+0.5)(-y+0.5,z+0.5,x)(y+0.5,z,-x+0.5)"
  },

  { // 206
    "(0.5,0.5,0.5)","(x,y,z)(-x+0.5,-y,z+0.5)(-x,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z)(z,x,y)(z+0.5,-x+0.5,-y)(-z+0.5,-x,y+0.5)(-z,x+0.5,-y+0.5)(y,z,x)(-y,z+0.5,-x+0.5)(y+0.5,-z+0.5,-x)(-y+0.5,-z,x+0.5)(-x,-y,-z)(x+0.5,y,-z+0.5)(x,-y+0.5,z+0.5)(-x+0.5,y+0.5,z)(-z,-x,-y)(-z+0.5,x+0.5,y)(z+0.5,x,-y+0.5)(z,-x+0.5,y+0.5)(-y,-z,-x)(y,-z+0.5,x+0.5)(-y+0.5,z+0.5,x)(y+0.5,z,-x+0.5)"
  },

  { // 207
    "","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(y,x,-z)(-y,-x,-z)(y,-x,z)(-y,x,z)(x,z,-y)(-x,z,y)(-x,-z,-y)(x,-z,y)(z,y,-x)(z,-y,x)(-z,y,x)(-z,-y,-x)"
  },

  { // 208
    "","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(y+0.5,x+0.5,-z+0.5)(-y+0.5,-x+0.5,-z+0.5)(y+0.5,-x+0.5,z+0.5)(-y+0.5,x+0.5,z+0.5)(x+0.5,z+0.5,-y+0.5)(-x+0.5,z+0.5,y+0.5)(-x+0.5,-z+0.5,-y+0.5)(x+0.5,-z+0.5,y+0.5)(z+0.5,y+0.5,-x+0.5)(z+0.5,-y+0.5,x+0.5)(-z+0.5,y+0.5,x+0.5)(-z+0.5,-y+0.5,-x+0.5)"
  },

  { // 209
    "(0,0.5,0.5)(0.5,0,0.5)(0.5,0.5,0)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(y,x,-z)(-y,-x,-z)(y,-x,z)(-y,x,z)(x,z,-y)(-x,z,y)(-x,-z,-y)(x,-z,y)(z,y,-x)(z,-y,x)(-z,y,x)(-z,-y,-x)"
  },

  { // 210
    "(0,0.5,0.5)(0.5,0,0.5)(0.5,0.5,0)","(x,y,z)(-x,-y+0.5,z+0.5)(-x+0.5,y+0.5,-z)(x+0.5,-y,-z+0.5)(z,x,y)(z+0.5,-x,-y+0.5)(-z,-x+0.5,y+0.5)(-z+0.5,x+0.5,-y)(y,z,x)(-y+0.5,z+0.5,-x)(y+0.5,-z,-x+0.5)(-y,-z+0.5,x+0.5)(y+0.75,x+0.25,-z+0.75)(-y+0.25,-x+0.25,-z+0.25)(y+0.25,-x+0.75,z+0.75)(-y+0.75,x+0.75,z+0.25)(x+0.75,z+0.25,-y+0.75)(-x+0.75,z+0.75,y+0.25)(-x+0.25,-z+0.25,-y+0.25)(x+0.25,-z+0.75,y+0.75)(z+0.75,y+0.25,-x+0.75)(z+0.25,-y+0.75,x+0.75)(-z+0.75,y+0.75,x+0.25)(-z+0.25,-y+0.25,-x+0.25)"
  },

  { // 211
    "(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(y,x,-z)(-y,-x,-z)(y,-x,z)(-y,x,z)(x,z,-y)(-x,z,y)(-x,-z,-y)(x,-z,y)(z,y,-x)(z,-y,x)(-z,y,x)(-z,-y,-x)"
  },

  { // 212
    "","(x,y,z)(-x+0.5,-y,z+0.5)(-x,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z)(z,x,y)(z+0.5,-x+0.5,-y)(-z+0.5,-x,y+0.5)(-z,x+0.5,-y+0.5)(y,z,x)(-y,z+0.5,-x+0.5)(y+0.5,-z+0.5,-x)(-y+0.5,-z,x+0.5)(y+0.25,x+0.75,-z+0.75)(-y+0.25,-x+0.25,-z+0.25)(y+0.75,-x+0.75,z+0.25)(-y+0.75,x+0.25,z+0.75)(x+0.25,z+0.75,-y+0.75)(-x+0.75,z+0.25,y+0.75)(-x+0.25,-z+0.25,-y+0.25)(x+0.75,-z+0.75,y+0.25)(z+0.25,y+0.75,-x+0.75)(z+0.75,-y+0.75,x+0.25)(-z+0.75,y+0.25,x+0.75)(-z+0.25,-y+0.25,-x+0.25)"
  },

  { // 213
    "","(x,y,z)(-x+0.5,-y,z+0.5)(-x,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z)(z,x,y)(z+0.5,-x+0.5,-y)(-z+0.5,-x,y+0.5)(-z,x+0.5,-y+0.5)(y,z,x)(-y,z+0.5,-x+0.5)(y+0.5,-z+0.5,-x)(-y+0.5,-z,x+0.5)(y+0.75,x+0.25,-z+0.25)(-y+0.75,-x+0.75,-z+0.75)(y+0.25,-x+0.25,z+0.75)(-y+0.25,x+0.75,z+0.25)(x+0.75,z+0.25,-y+0.25)(-x+0.25,z+0.75,y+0.25)(-x+0.75,-z+0.75,-y+0.75)(x+0.25,-z+0.25,y+0.75)(z+0.75,y+0.25,-x+0.25)(z+0.25,-y+0.25,x+0.75)(-z+0.25,y+0.75,x+0.25)(-z+0.75,-y+0.75,-x+0.75)"
  },

  { // 214
    "(0.5,0.5,0.5)","(x,y,z)(-x+0.5,-y,z+0.5)(-x,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z)(z,x,y)(z+0.5,-x+0.5,-y)(-z+0.5,-x,y+0.5)(-z,x+0.5,-y+0.5)(y,z,x)(-y,z+0.5,-x+0.5)(y+0.5,-z+0.5,-x)(-y+0.5,-z,x+0.5)(y+0.75,x+0.25,-z+0.25)(-y+0.75,-x+0.75,-z+0.75)(y+0.25,-x+0.25,z+0.75)(-y+0.25,x+0.75,z+0.25)(x+0.75,z+0.25,-y+0.25)(-x+0.25,z+0.75,y+0.25)(-x+0.75,-z+0.75,-y+0.75)(x+0.25,-z+0.25,y+0.75)(z+0.75,y+0.25,-x+0.25)(z+0.25,-y+0.25,x+0.75)(-z+0.25,y+0.75,x+0.25)(-z+0.75,-y+0.75,-x+0.75)"
  },

  { // 215
    "","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(y,x,z)(-y,-x,z)(y,-x,-z)(-y,x,-z)(x,z,y)(-x,z,-y)(-x,-z,y)(x,-z,-y)(z,y,x)(z,-y,-x)(-z,y,-x)(-z,-y,x)"
  },

  { // 216
    "(0,0.5,0.5)(0.5,0,0.5)(0.5,0.5,0)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(y,x,z)(-y,-x,z)(y,-x,-z)(-y,x,-z)(x,z,y)(-x,z,-y)(-x,-z,y)(x,-z,-y)(z,y,x)(z,-y,-x)(-z,y,-x)(-z,-y,x)"
  },

  { // 217
    "(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(y,x,z)(-y,-x,z)(y,-x,-z)(-y,x,-z)(x,z,y)(-x,z,-y)(-x,-z,y)(x,-z,-y)(z,y,x)(z,-y,-x)(-z,y,-x)(-z,-y,x)"
  },

  { // 218
    "","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(y+0.5,x+0.5,z+0.5)(-y+0.5,-x+0.5,z+0.5)(y+0.5,-x+0.5,-z+0.5)(-y+0.5,x+0.5,-z+0.5)(x+0.5,z+0.5,y+0.5)(-x+0.5,z+0.5,-y+0.5)(-x+0.5,-z+0.5,y+0.5)(x+0.5,-z+0.5,-y+0.5)(z+0.5,y+0.5,x+0.5)(z+0.5,-y+0.5,-x+0.5)(-z+0.5,y+0.5,-x+0.5)(-z+0.5,-y+0.5,x+0.5)"
  },

  { // 219
    "(0,0.5,0.5)(0.5,0,0.5)(0.5,0.5,0)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(y+0.5,x+0.5,z+0.5)(-y+0.5,-x+0.5,z+0.5)(y+0.5,-x+0.5,-z+0.5)(-y+0.5,x+0.5,-z+0.5)(x+0.5,z+0.5,y+0.5)(-x+0.5,z+0.5,-y+0.5)(-x+0.5,-z+0.5,y+0.5)(x+0.5,-z+0.5,-y+0.5)(z+0.5,y+0.5,x+0.5)(z+0.5,-y+0.5,-x+0.5)(-z+0.5,y+0.5,-x+0.5)(-z+0.5,-y+0.5,x+0.5)"
  },

  { // 220
    "(0.5,0.5,0.5)","(x,y,z)(-x+0.5,-y,z+0.5)(-x,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z)(z,x,y)(z+0.5,-x+0.5,-y)(-z+0.5,-x,y+0.5)(-z,x+0.5,-y+0.5)(y,z,x)(-y,z+0.5,-x+0.5)(y+0.5,-z+0.5,-x)(-y+0.5,-z,x+0.5)(y+0.25,x+0.25,z+0.25)(-y+0.25,-x+0.75,z+0.75)(y+0.75,-x+0.25,-z+0.75)(-y+0.75,x+0.75,-z+0.25)(x+0.25,z+0.25,y+0.25)(-x+0.75,z+0.75,-y+0.25)(-x+0.25,-z+0.75,y+0.75)(x+0.75,-z+0.25,-y+0.75)(z+0.25,y+0.25,x+0.25)(z+0.75,-y+0.25,-x+0.75)(-z+0.75,y+0.75,-x+0.25)(-z+0.25,-y+0.75,x+0.75)"
  },

  { // 221
    "","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(y,x,-z)(-y,-x,-z)(y,-x,z)(-y,x,z)(x,z,-y)(-x,z,y)(-x,-z,-y)(x,-z,y)(z,y,-x)(z,-y,x)(-z,y,x)(-z,-y,-x)(-x,-y,-z)(x,y,-z)(x,-y,z)(-x,y,z)(-z,-x,-y)(-z,x,y)(z,x,-y)(z,-x,y)(-y,-z,-x)(y,-z,x)(-y,z,x)(y,z,-x)(-y,-x,z)(y,x,z)(-y,x,-z)(y,-x,-z)(-x,-z,y)(x,-z,-y)(x,z,y)(-x,z,-y)(-z,-y,x)(-z,y,-x)(z,-y,-x)(z,y,x)"
  },

  { // 222
    "","(x,y,z)(-x+0.5,-y+0.5,z)(-x+0.5,y,-z+0.5)(x,-y+0.5,-z+0.5)(z,x,y)(z,-x+0.5,-y+0.5)(-z+0.5,-x+0.5,y)(-z+0.5,x,-y+0.5)(y,z,x)(-y+0.5,z,-x+0.5)(y,-z+0.5,-x+0.5)(-y+0.5,-z+0.5,x)(y,x,-z+0.5)(-y+0.5,-x+0.5,-z+0.5)(y,-x+0.5,z)(-y+0.5,x,z)(x,z,-y+0.5)(-x+0.5,z,y)(-x+0.5,-z+0.5,-y+0.5)(x,-z+0.5,y)(z,y,-x+0.5)(z,-y+0.5,x)(-z+0.5,y,x)(-z+0.5,-y+0.5,-x+0.5)(-x,-y,-z)(x+0.5,y+0.5,-z)(x+0.5,-y,z+0.5)(-x,y+0.5,z+0.5)(-z,-x,-y)(-z,x+0.5,y+0.5)(z+0.5,x+0.5,-y)(z+0.5,-x,y+0.5)(-y,-z,-x)(y+0.5,-z,x+0.5)(-y,z+0.5,x+0.5)(y+0.5,z+0.5,-x)(-y,-x,z+0.5)(y+0.5,x+0.5,z+0.5)(-y,x+0.5,-z)(y+0.5,-x,-z)(-x,-z,y+0.5)(x+0.5,-z,-y)(x+0.5,z+0.5,y+0.5)(-x,z+0.5,-y)(-z,-y,x+0.5)(-z,y+0.5,-x)(z+0.5,-y,-x)(z+0.5,y+0.5,x+0.5)"
  },

  { // 223
    "","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(y+0.5,x+0.5,-z+0.5)(-y+0.5,-x+0.5,-z+0.5)(y+0.5,-x+0.5,z+0.5)(-y+0.5,x+0.5,z+0.5)(x+0.5,z+0.5,-y+0.5)(-x+0.5,z+0.5,y+0.5)(-x+0.5,-z+0.5,-y+0.5)(x+0.5,-z+0.5,y+0.5)(z+0.5,y+0.5,-x+0.5)(z+0.5,-y+0.5,x+0.5)(-z+0.5,y+0.5,x+0.5)(-z+0.5,-y+0.5,-x+0.5)(-x,-y,-z)(x,y,-z)(x,-y,z)(-x,y,z)(-z,-x,-y)(-z,x,y)(z,x,-y)(z,-x,y)(-y,-z,-x)(y,-z,x)(-y,z,x)(y,z,-x)(-y+0.5,-x+0.5,z+0.5)(y+0.5,x+0.5,z+0.5)(-y+0.5,x+0.5,-z+0.5)(y+0.5,-x+0.5,-z+0.5)(-x+0.5,-z+0.5,y+0.5)(x+0.5,-z+0.5,-y+0.5)(x+0.5,z+0.5,y+0.5)(-x+0.5,z+0.5,-y+0.5)(-z+0.5,-y+0.5,x+0.5)(-z+0.5,y+0.5,-x+0.5)(z+0.5,-y+0.5,-x+0.5)(z+0.5,y+0.5,x+0.5)"
  },

  { // 224
    "","(x,y,z)(-x+0.5,-y+0.5,z)(-x+0.5,y,-z+0.5)(x,-y+0.5,-z+0.5)(z,x,y)(z,-x+0.5,-y+0.5)(-z+0.5,-x+0.5,y)(-z+0.5,x,-y+0.5)(y,z,x)(-y+0.5,z,-x+0.5)(y,-z+0.5,-x+0.5)(-y+0.5,-z+0.5,x)(y+0.5,x+0.5,-z)(-y,-x,-z)(y+0.5,-x,z+0.5)(-y,x+0.5,z+0.5)(x+0.5,z+0.5,-y)(-x,z+0.5,y+0.5)(-x,-z,-y)(x+0.5,-z,y+0.5)(z+0.5,y+0.5,-x)(z+0.5,-y,x+0.5)(-z,y+0.5,x+0.5)(-z,-y,-x)(-x,-y,-z)(x+0.5,y+0.5,-z)(x+0.5,-y,z+0.5)(-x,y+0.5,z+0.5)(-z,-x,-y)(-z,x+0.5,y+0.5)(z+0.5,x+0.5,-y)(z+0.5,-x,y+0.5)(-y,-z,-x)(y+0.5,-z,x+0.5)(-y,z+0.5,x+0.5)(y+0.5,z+0.5,-x)(-y+0.5,-x+0.5,z)(y,x,z)(-y+0.5,x,-z+0.5)(y,-x+0.5,-z+0.5)(-x+0.5,-z+0.5,y)(x,-z+0.5,-y+0.5)(x,z,y)(-x+0.5,z,-y+0.5)(-z+0.5,-y+0.5,x)(-z+0.5,y,-x+0.5)(z,-y+0.5,-x+0.5)(z,y,x)"
  },

  { // 225
    "(0,0.5,0.5)(0.5,0,0.5)(0.5,0.5,0)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(y,x,-z)(-y,-x,-z)(y,-x,z)(-y,x,z)(x,z,-y)(-x,z,y)(-x,-z,-y)(x,-z,y)(z,y,-x)(z,-y,x)(-z,y,x)(-z,-y,-x)(-x,-y,-z)(x,y,-z)(x,-y,z)(-x,y,z)(-z,-x,-y)(-z,x,y)(z,x,-y)(z,-x,y)(-y,-z,-x)(y,-z,x)(-y,z,x)(y,z,-x)(-y,-x,z)(y,x,z)(-y,x,-z)(y,-x,-z)(-x,-z,y)(x,-z,-y)(x,z,y)(-x,z,-y)(-z,-y,x)(-z,y,-x)(z,-y,-x)(z,y,x)"
  },

  { // 226
    "(0,0.5,0.5)(0.5,0,0.5)(0.5,0.5,0)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(y+0.5,x+0.5,-z+0.5)(-y+0.5,-x+0.5,-z+0.5)(y+0.5,-x+0.5,z+0.5)(-y+0.5,x+0.5,z+0.5)(x+0.5,z+0.5,-y+0.5)(-x+0.5,z+0.5,y+0.5)(-x+0.5,-z+0.5,-y+0.5)(x+0.5,-z+0.5,y+0.5)(z+0.5,y+0.5,-x+0.5)(z+0.5,-y+0.5,x+0.5)(-z+0.5,y+0.5,x+0.5)(-z+0.5,-y+0.5,-x+0.5)(-x,-y,-z)(x,y,-z)(x,-y,z)(-x,y,z)(-z,-x,-y)(-z,x,y)(z,x,-y)(z,-x,y)(-y,-z,-x)(y,-z,x)(-y,z,x)(y,z,-x)(-y+0.5,-x+0.5,z+0.5)(y+0.5,x+0.5,z+0.5)(-y+0.5,x+0.5,-z+0.5)(y+0.5,-x+0.5,-z+0.5)(-x+0.5,-z+0.5,y+0.5)(x+0.5,-z+0.5,-y+0.5)(x+0.5,z+0.5,y+0.5)(-x+0.5,z+0.5,-y+0.5)(-z+0.5,-y+0.5,x+0.5)(-z+0.5,y+0.5,-x+0.5)(z+0.5,-y+0.5,-x+0.5)(z+0.5,y+0.5,x+0.5)"
  },

  { // 227
    "(0,0.5,0.5)(0.5,0,0.5)(0.5,0.5,0)","(x,y,z)(-x+0.75,-y+0.25,z+0.5)(-x+0.25,y+0.5,-z+0.75)(x+0.5,-y+0.75,-z+0.25)(z,x,y)(z+0.5,-x+0.75,-y+0.25)(-z+0.75,-x+0.25,y+0.5)(-z+0.25,x+0.5,-y+0.75)(y,z,x)(-y+0.25,z+0.5,-x+0.75)(y+0.5,-z+0.75,-x+0.25)(-y+0.75,-z+0.25,x+0.5)(y+0.75,x+0.25,-z+0.5)(-y,-x,-z)(y+0.25,-x+0.5,z+0.75)(-y+0.5,x+0.75,z+0.25)(x+0.75,z+0.25,-y+0.5)(-x+0.5,z+0.75,y+0.25)(-x,-z,-y)(x+0.25,-z+0.5,y+0.75)(z+0.75,y+0.25,-x+0.5)(z+0.25,-y+0.5,x+0.75)(-z+0.5,y+0.75,x+0.25)(-z,-y,-x)(-x,-y,-z)(x+0.25,y+0.75,-z+0.5)(x+0.75,-y+0.5,z+0.25)(-x+0.5,y+0.25,z+0.75)(-z,-x,-y)(-z+0.5,x+0.25,y+0.75)(z+0.25,x+0.75,-y+0.5)(z+0.75,-x+0.5,y+0.25)(-y,-z,-x)(y+0.75,-z+0.5,x+0.25)(-y+0.5,z+0.25,x+0.75)(y+0.25,z+0.75,-x+0.5)(-y+0.25,-x+0.75,z+0.5)(y,x,z)(-y+0.75,x+0.5,-z+0.25)(y+0.5,-x+0.25,-z+0.75)(-x+0.25,-z+0.75,y+0.5)(x+0.5,-z+0.25,-y+0.75)(x,z,y)(-x+0.75,z+0.5,-y+0.25)(-z+0.25,-y+0.75,x+0.5)(-z+0.75,y+0.5,-x+0.25)(z+0.5,-y+0.25,-x+0.75)(z,y,x)"
  },

  { // 228
    "(0,0.5,0.5)(0.5,0,0.5)(0.5,0.5,0)","(x,y,z)(-x+0.25,-y+0.75,z+0.5)(-x+0.75,y+0.5,-z+0.25)(x+0.5,-y+0.25,-z+0.75)(z,x,y)(z+0.5,-x+0.25,-y+0.75)(-z+0.25,-x+0.75,y+0.5)(-z+0.75,x+0.5,-y+0.25)(y,z,x)(-y+0.75,z+0.5,-x+0.25)(y+0.5,-z+0.25,-x+0.75)(-y+0.25,-z+0.75,x+0.5)(y+0.75,x+0.25,-z)(-y+0.5,-x+0.5,-z+0.5)(y+0.25,-x,z+0.75)(-y,x+0.75,z+0.25)(x+0.75,z+0.25,-y)(-x,z+0.75,y+0.25)(-x+0.5,-z+0.5,-y+0.5)(x+0.25,-z,y+0.75)(z+0.75,y+0.25,-x)(z+0.25,-y,x+0.75)(-z,y+0.75,x+0.25)(-z+0.5,-y+0.5,-x+0.5)(-x,-y,-z)(x+0.75,y+0.25,-z+0.5)(x+0.25,-y+0.5,z+0.75)(-x+0.5,y+0.75,z+0.25)(-z,-x,-y)(-z+0.5,x+0.75,y+0.25)(z+0.75,x+0.25,-y+0.5)(z+0.25,-x+0.5,y+0.75)(-y,-z,-x)(y+0.25,-z+0.5,x+0.75)(-y+0.5,z+0.75,x+0.25)(y+0.75,z+0.25,-x+0.5)(-y+0.25,-x+0.75,z)(y+0.5,x+0.5,z+0.5)(-y+0.75,x,-z+0.25)(y,-x+0.25,-z+0.75)(-x+0.25,-z+0.75,y)(x,-z+0.25,-y+0.75)(x+0.5,z+0.5,y+0.5)(-x+0.75,z,-y+0.25)(-z+0.25,-y+0.75,x)(-z+0.75,y,-x+0.25)(z,-y+0.25,-x+0.75)(z+0.5,y+0.5,x+0.5)"
  },

  { // 229
    "(0.5,0.5,0.5)","(x,y,z)(-x,-y,z)(-x,y,-z)(x,-y,-z)(z,x,y)(z,-x,-y)(-z,-x,y)(-z,x,-y)(y,z,x)(-y,z,-x)(y,-z,-x)(-y,-z,x)(y,x,-z)(-y,-x,-z)(y,-x,z)(-y,x,z)(x,z,-y)(-x,z,y)(-x,-z,-y)(x,-z,y)(z,y,-x)(z,-y,x)(-z,y,x)(-z,-y,-x)(-x,-y,-z)(x,y,-z)(x,-y,z)(-x,y,z)(-z,-x,-y)(-z,x,y)(z,x,-y)(z,-x,y)(-y,-z,-x)(y,-z,x)(-y,z,x)(y,z,-x)(-y,-x,z)(y,x,z)(-y,x,-z)(y,-x,-z)(-x,-z,y)(x,-z,-y)(x,z,y)(-x,z,-y)(-z,-y,x)(-z,y,-x)(z,-y,-x)(z,y,x)"
  },

  { // 230
    "(0.5,0.5,0.5)","(x,y,z)(-x+0.5,-y,z+0.5)(-x,y+0.5,-z+0.5)(x+0.5,-y+0.5,-z)(z,x,y)(z+0.5,-x+0.5,-y)(-z+0.5,-x,y+0.5)(-z,x+0.5,-y+0.5)(y,z,x)(-y,z+0.5,-x+0.5)(y+0.5,-z+0.5,-x)(-y+0.5,-z,x+0.5)(y+0.75,x+0.25,-z+0.25)(-y+0.75,-x+0.75,-z+0.75)(y+0.25,-x+0.25,z+0.75)(-y+0.25,x+0.75,z+0.25)(x+0.75,z+0.25,-y+0.25)(-x+0.25,z+0.75,y+0.25)(-x+0.75,-z+0.75,-y+0.75)(x+0.25,-z+0.25,y+0.75)(z+0.75,y+0.25,-x+0.25)(z+0.25,-y+0.25,x+0.75)(-z+0.25,y+0.75,x+0.25)(-z+0.75,-y+0.75,-x+0.75)(-x,-y,-z)(x+0.5,y,-z+0.5)(x,-y+0.5,z+0.5)(-x+0.5,y+0.5,z)(-z,-x,-y)(-z+0.5,x+0.5,y)(z+0.5,x,-y+0.5)(z,-x+0.5,y+0.5)(-y,-z,-x)(y,-z+0.5,x+0.5)(-y+0.5,z+0.5,x)(y+0.5,z,-x+0.5)(-y+0.25,-x+0.75,z+0.75)(y+0.25,x+0.25,z+0.25)(-y+0.75,x+0.75,-z+0.25)(y+0.75,-x+0.25,-z+0.75)(-x+0.25,-z+0.75,y+0.75)(x+0.75,-z+0.25,-y+0.75)(x+0.25,z+0.25,y+0.25)(-x+0.75,z+0.75,-y+0.25)(-z+0.25,-y+0.75,x+0.75)(-z+0.75,y+0.75,-x+0.25)(z+0.75,-y+0.25,-x+0.75)(z+0.25,y+0.25,x+0.25)"
  }
};
#endif // For the _MSC_VER
#endif // Header guard
