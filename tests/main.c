/******************************************************************************
 *
 * dynarr - Dynamic and Generic Array using C macros
 * Copyright 2016 Thomas Munoz (epholys@gmail.com)
 *
 * dynarr is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * dynarr is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with dynarr.  If not, see <http://www.gnu.org/licenses/>.
 * 
 *****************************************************************************/

/*! \file 
 *  \brief Home of all the BCUT unit test suite.
 */
#include"bcut/bcut.h"
#include"dynarr_test.h"

int main()
{
    bcut_suite_run("dynarr lib", 3,
                   dynarr_push,
                   dynarr_pop,
                   dynarr_clear);
    return 0;
}
