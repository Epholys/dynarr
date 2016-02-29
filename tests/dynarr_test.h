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
 *  \brief Declaration of unit tests of dynarr
 */

#include"bcut/bcut.h"
#include"dynarr.h"

/*! \brief Tests if DYNARR_PUSH behaves correctly:
 *    - The elements inserted are correctely placed at the end.
 *    - The length of the dynarr is updated.
 *  \sa bcut.h #DYNARR_PUSH
 */
BCUT_TEST(dynarr_push);

/*! \brief Tests if DYNARR_INSERT behaves correctly:
 *    - The elements are inserted are in the right position.
 *    - The length of the dynarr is updated.
 *  \sa bcut.h #DYNARR_INSERT
 */
BCUT_TEST(dynarr_insert);

/*! \brief Tests if DYNARR_POP behaves correctly:
 *    - The elements popped are expectingly virtually removed.
 *    - The length of the dynarr is updated.
 *  \sa bcut.h #DYNARR_POP
 */
BCUT_TEST(dynarr_pop);

/*! \brief Tests if DYNARR_CLEAR behaves correctly:
 *    - `elements' is virtually empty.
 *    - The length of the dynarr is updated.
 *  \sa bcut.h #DYNARR_CLEAR
 */
BCUT_TEST(dynarr_clear);
